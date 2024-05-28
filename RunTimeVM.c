#include "System/System.h"
#include "System/initSystem.h"
#include "System/cleanSystem.h"
#include "VM/codeHex.h"
#include "memory/memory.h"
#include "includedefines/allocs.h"
#include "includedefines/defines.h"
#include "includedefines/referenceTypes.h"
#include "includedefines/sizeDefined.h"
#include "includeclass/objectsStruct.h"
#include "includeEnumerator/typeObjects.h"
#include "includelib/basicMath.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/libIo.h"
#include "includelib/libString.h"
#include "includelib/List.h"
#include "utils/utils.h"
#include <stdlib.h>

/*
----------------------------------------<=>----------------------------------------
** function that separates bytes into fields. Receives a line of bytecode,
** and separates it into two or three fields.
** does not work with all instruction types.
----------------------------------------<=>----------------------------------------
** LINE EXMPLE:
**        {
**                   ---<FIELD ONE>---                ---<FIELD TWO>---
**            INIT_SET, STORAGE_I32, END_SET, .... INIT_SET, SEND, BYTE, 0X00,
**            END_SET0, .... INIT_SET, SEND, INT, 0X00, 0X00, 0X00, 0X00, END_SET
**                                   ---<FIELD THREE>---
**        }
*/

static STATUS set_operation
(u8 *line, u64 *addr_i, i64 *count, u8 *elements, u64 **forEach_loop1,
List **forEach_loop2, u8 qttLoop)
{
    u8 bytes[i64_size] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    u8 lastLoop = 0;
    packageReceived pkrv;
    reference_types ref_ty;

    if(line[*addr_i] != INIT_SET)
        return -7;

    u64 actSize = OBJECTsQTTY;
    
    while(line[++(*addr_i)] != END_SET){
        if(*count == actSize){
            actSize += actSize >> 1;
            u8 *newElements = (u8*)realloc(elements, actSize);
            if(newElements == NULL)
                return -7;

            elements = newElements;
        }

        if(line[*addr_i] < STORAGE_LONG || line[*addr_i] > STORAGE_FN)
            return -2;

        else
            elements[(*count)++] = line[*addr_i];
    }

    if(!qttLoop)
        return 0;

    if(qttLoop == 2)
        (*forEach_loop2) = newList(*count);

    (*forEach_loop1) = UINT64ALLOC(*count);

    i64 countObjs = *count;

    (*addr_i)++;
    while(qttLoop){
        if(line[*addr_i] != INIT_SET)
            return -8;

        (*count) = 0;
        while(line[++(*addr_i)] != END_SET){
            if(*count == countObjs + 1)
                return -3;

            if((line[*addr_i] < LONG || line[*addr_i] > STRUCT) && line[*addr_i] != SEND)
                return -4;
            
            i64 value = 0;
            charu64 size_Obj = 0;

            (*addr_i)++;
            switch(line[(*addr_i)++]){
                case LONG:
                    size_Obj = i64_size;
                    ref_ty = __i64__;
                    break;

                case INT:
                    size_Obj = i32_size;
                    ref_ty = __i32__;
                    break;

                case SHORT:
                    size_Obj = i16_size;
                    ref_ty = __i16__;
                    break;
                case CHAR:
                    size_Obj = i16_size;
                    ref_ty = __Char__;
                    break;

                case BYTE:
                    size_Obj = i8_size;
                    ref_ty = __i8__;
                    value = line[*addr_i];
                    break;

                case STRING:
                    if(qttLoop == 1 && lastLoop == 0)
                        return -15;

                    u64 length = getLengthSubDataOfBuffer(line, addr_i);
                    pkrv.package_ty.pack_doublebytes = DataToString(line, length, *addr_i);
                    pkrv.pack_ty = PACK_DOUBLE_BYTES;
                    pushList(forEach_loop2, __String__, pkrv, length);
                    (*addr_i) += (length << 1) - 1;
                    free(pkrv.package_ty.pack_doublebytes);
                    break;                    
                
                default:
                    return -5;
            }

            if(size_Obj){
                if(line[*addr_i - 1] != BYTE && (line[*addr_i - 1] >= LONG &&
                   line[*addr_i - 1] <= CHAR))
                {
                    memcopy(bytes, line, *addr_i, size_Obj);
                    memcpyint(&value, bytes, size_Obj);
                    clearBuffer(bytes, 0, i64_size);
                    (*addr_i) += size_Obj - 1;
                }

                if(qttLoop == 1 && lastLoop == 2){
                    if(ref_ty >= __i8__ && ref_ty <= __Char__){
                        pkrv.package_ty.pack_integer = value;

                        pkrv.pack_ty = PACK_INTEGER;
                        String valstr = inttstr(value);
                        pushList(forEach_loop2, ref_ty, pkrv, strsize(valstr) + 1);
                        free(valstr);
                    }
                }
                    
                else
                    (*forEach_loop1)[(*count)++] = value;

                size_Obj = 0;
            }
        }

        lastLoop = qttLoop--;

        if(qttLoop == 1 && lastLoop == 2)
            (*addr_i)++;
    }

    return 0;
}

/*
----------------------------------------<=>----------------------------------------
** Initialize storage instruction. Allocates memory for objects that will
** be used initially.
----------------------------------------<=>----------------------------------------
*/

inline static STATUS COMMAND_START(u8 *line, __System__ *System){
    u64 addr_i = 0x01;
    i64 count = 0;
    u8 *storages = UINT8ALLOC(OBJECTsQTTY);
    u64 *memoryAlloc;
    i8 status = 0;

    status = set_operation(line, &addr_i, &count, storages, &memoryAlloc, NULL, 1);
    if(status)
        return status;

    if(line[++addr_i] != END_INSTRUCTION){
        return -35;
    }

    clearBuffer(System->Manager.objectsUsing, 0, OBJECTsQTTY);
    memcopy(System->Manager.objectsUsing, storages, 0, count);

    initializeStorages(&(System->Manager.Objects), storages, memoryAlloc, count - 1);
    
    free(storages);
    free(memoryAlloc);

    return 0;
}

/*
----------------------------------------<=>----------------------------------------
** Instruction to assign a value to an object. receives a
** line of bytecode and breaks it into three fields using the
** set_operation function: STORAGE, ADDRESS AND VALUES.
----------------------------------------<=>----------------------------------------
*/

inline static STATUS COMMAND_ADDRE(u8 *line, __System__ *System){
    u64 addr_i = 0x01;
    i64 count = 0;
    u8 *objects = UINT8ALLOC(OBJECTsQTTY);
    u64 *address;
    List *values;
    i8 status = 0;
    
    status = set_operation(line, &addr_i, &count, objects, &address, &values, 2);
    if(status)
        return status;
    
    if(line[++addr_i] != END_INSTRUCTION)
        return -35;

    setValues(&(System->Manager.Objects), objects, values, address);
    free(objects);
    free(address);
    freeList(values);

    return 0;
}

/*
----------------------------------------<=>----------------------------------------
** Instruction for calling functions and methods. Moves the
** instruction counter to the address of the function or method.
----------------------------------------<=>----------------------------------------
*/

inline static STATUS COMMAND_CALLC(u8 *line, u8 *scope, u64 *addr_l){
    u64 addr_i = 0x01;
    charu64 sizeObj = 0;
    u8 *bytes;
    i64 value = 0;

    if(line[addr_i++] != ADDRESS_)
        return -1;

    if(line[addr_i++] != SEND)
        return -2;

    if(line[addr_i] == BYTE){
        if(line[addr_i + 2] = END_INSTRUCTION){
            (*scope) = _LOCAL;
            (*addr_l) = line[++addr_i];
            return 0;
        }
        else
            return -3;
    }

    switch(line[addr_i++]){
        case LONG:
            sizeObj = i64_size;
            break;
        case INT:
            sizeObj = i32_size;
            break;
        case SHORT:
        case CHAR:
            sizeObj = i16_size;
            break;
        default:
            return -4;
    }

    bytes = UINT8ALLOC(sizeObj);
    memcopy(bytes, line, addr_i, sizeObj);
    memcpyint(&value, bytes, sizeObj);
    (*addr_l) = value;

    addr_i += sizeObj - 1;
    free(bytes);

    if(line[addr_i] != END_INSTRUCTION)
        return -5;

    return 0;
}

/*
----------------------------------------<=>----------------------------------------
** Instruction to move the instruction counter to any part of the program,
** used for loops, and returns after the end of a function or method execution
----------------------------------------<=>----------------------------------------
*/

inline static STATUS COMMAND_JUMPC(u8 *line, u8 *scope, u64 *addr_l){
    u64 addr_i = 0x01;
    charu64 sizeObj = 0;
    u8 *bytes;
    i64 value = 0;

    if(line[addr_i++] != ADDRESS_)
        return -1;

    if(line[addr_i] == _GLOBAL)
        (*scope) = _GLOBAL;

    else if(line[addr_i] != _LOCAL){
        return -2;
    }

    if(line[++addr_i] != SEND)
        return -3;

    if(line[++addr_i] == BYTE){
        if(line[addr_i + 2] = END_INSTRUCTION){
            (*addr_l) = line[++addr_i];
            return 0;
        }
        else
            return -3;
    }

    switch(line[addr_i++]){
        case LONG:
            sizeObj = i64_size;
            break;
        case INT:
            sizeObj = i32_size;
            break;
        case SHORT:
        case CHAR:
            sizeObj = i16_size;
            break;
        default:
            return -4;
    }

    bytes = (u8*)malloc(sizeObj);
    memcopy(bytes, line, addr_i, sizeObj);
    memcpyint(&value, bytes, sizeObj);
    (*addr_l) = value;

    addr_i += sizeObj - 1;
    free(bytes);

    if(line[addr_i] != END_INSTRUCTION)
        return -5;

    return 0;
}

/*
----------------------------------------<=>----------------------------------------
** Output instruction. makes a call to the operating system.
** Receives a set of bytes, assembles an object list with the
** values ​​received and converts the object list to a string.
----------------------------------------<=>----------------------------------------
*/

inline static STATUS COMMAND_SYSOT(u8 *line, __System__ System){
    u64 addr_i = 0x01;
    i64 count = 0;
    u8 *objects = UINT8ALLOC(OBJECTsQTTY);
    u64 *address;
    
    set_operation(line, &addr_i, &count, objects, &address, NULL, 1);
    if(line[++addr_i] != END_INSTRUCTION)
        return -35;

    List *list = newList(count);
    packageReceived pkrv;
    reference_types ref_ty;
    charu64 sizeObj = 0;

    for(i64 index = 0; index < count; index++){
        switch(objects[index]){
            case STORAGE_LONG:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_i64[address[index]]->i64Ty;
                ref_ty = __i64__;
                break;
            case STORAGE_INT:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_i32[address[index]]->i32Ty;
                ref_ty = __i32__;
                break;
            case STORAGE_SHORT:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_i16[address[index]]->i16Ty;
                ref_ty = __i16__;
                break;
            case STORAGE_BYTE:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_i8[address[index]]->i8Ty;
                ref_ty = __i8__;
                break;
            case STORAGE_CHAR:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_char[address[index]]->charTy;
                ref_ty = __Char__;
                break;
            default:
                return -10;
        }

        if(objects[index] == STORAGE_LONG || objects[index] == STORAGE_INT || objects[index] == STORAGE_SHORT ||
           objects[index] == STORAGE_CHAR || objects[index] == STORAGE_BYTE)
        {
            pkrv.pack_ty = PACK_INTEGER;
            String intstr = inttstr(pkrv.package_ty.pack_integer);
            pushList(&list, ref_ty, pkrv, strsize(intstr) + 1);
            free(intstr);
        }
    }

    //printf("OUTPUT:\n\t");
    System.SysFunctions.WRT(&list);
    free(objects);
    free(address);
    freeList(list);

    return 0;
}

/*
----------------------------------------<=>----------------------------------------
** Input instruction. makes a call to the operating system to receive 
** data from the keyboard. By default, a string is received, but it can 
** be converted to the requested object.
----------------------------------------<=>----------------------------------------
*/

inline static STATUS COMMAND_SYSIN(u8 *line, __System__ *System){
    u64 addr_i = 0x01;
    i64 count = 0;
    u8 *objects = UINT8ALLOC(OBJECTsQTTY), casting = 0;
    u64 *address;
    List *values;

    casting = line[addr_i++];

    if(!(casting >= LONG && casting <= STRUCT))
        return -1;

    set_operation(line, &addr_i, &count, objects, &address, &values, 2);
    if(line[++addr_i] != END_INSTRUCTION)
        return -35;

    String input = System->SysFunctions.RD(values[0].types.primitiveTys.string_ty);

    allocStoragesUsing(&(System->Manager.Objects), objects[0], address[0], 0);

    switch(casting){
        case LONG:
            if(objects[0] != STORAGE_LONG)
                return -3;

            System->Manager.Objects.st_i64[address[0]]->i64Ty =
            convert_StringToInteger(input);
            break;
        case INT:
            if(objects[0] != STORAGE_INT)
                return -3;

            System->Manager.Objects.st_i32[address[0]]->i32Ty =
            (i32)convert_StringToInteger(input);
            break;
        case SHORT:
            if(objects[0] != STORAGE_SHORT)
                return -3;

            System->Manager.Objects.st_i16[address[0]]->i16Ty =
            convert_StringToInteger(input);
            break;
        case CHAR:
            if(objects[0] != STORAGE_CHAR)
                return -3;

            System->Manager.Objects.st_char[address[0]]->charTy =
            convert_StringToInteger(input);
            break;
        case BYTE:
            if(objects[0] != STORAGE_BYTE)
                return -3;

            System->Manager.Objects.st_i8[address[0]]->i8Ty =
            convert_StringToInteger(input);
            break;
        case STRING:
            if(objects[0] != STORAGE_STRING)
                return -3;

            System->Manager.Objects.st_string[address[0]] =
            strcopy(input);
            break;
        default:
            return -2;
    }    

    free(input);
    free(objects);
    free(address);
    freeList(values);

    return 0;
}

/*
----------------------------------------<=>----------------------------------------
** Instruction to destroy an object or set of objects from memory.
----------------------------------------<=>----------------------------------------
*/

inline static STATUS COMMAND_DESTR(u8 *line, __System__ *System){
    u64 addr_i = 0x01;
    i64 count = 0;
    u8 *objects = UINT8ALLOC(OBJECTsQTTY);
    u64 *address;
    
    set_operation(line, &addr_i, &count, objects, &address, NULL, 1);
    if(line[++addr_i] != END_INSTRUCTION)
        return -35;

    destroyObject(System, objects, address, count - 1);

    free(objects);
    free(address);

    return 0;
}


int program(u8 global[][1000], u8 local[][1000], __System__ *System){
    u8 scope = _GLOBAL, error = 0;
    u64 addr_l = 0x00;
    COMMAND command = 0x00;
    int status = 0;

    if(global[addr_l++][0x00] != PROGRAM)
        return -1;

    command = global[addr_l][0x00];

    while(command != END){
        switch(command){
            case START:
                // printf("command start\n\n");
                // printf("return start: %d\n", COMMAND_START((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System));
                status = COMMAND_START((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System);
                addr_l++;
                break;

            case ADDRE:
                // printf("command addre\n\n");
                // printf("return addre: %d\n", COMMAND_ADDRE((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System));
                status = COMMAND_ADDRE((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System);
                addr_l++;
                break;

            case DESTR:
                // printf("command destr\n\n");
                // printf("return destr: %d\n", COMMAND_DESTR((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System));
                status = COMMAND_DESTR((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System);
                addr_l++;
                break;

            case CALLC:
                // printf("command callc\n\n");
                // printf("return callc: %d\n", COMMAND_CALLC((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), &scope, &addr_l));
                status = COMMAND_CALLC((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), &scope, &addr_l);
                break;

            case JUMPC:
                // printf("command jumpc\n\n");
                // printf("return jumpc: %d\n", COMMAND_JUMPC((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), &scope, &addr_l));
                status = COMMAND_JUMPC((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), &scope, &addr_l);
                break;

            case SYSOT:
                // printf("command sysot\n\n");
                // printf("return sysot: %d\n", COMMAND_SYSOT((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), *System));
                status = COMMAND_SYSOT((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), *System);
                addr_l++;
                break;

            case SYSIN:
                // printf("command sysin\n\n");
                // printf("return sysin: %d\n", COMMAND_SYSIN((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System));
                status = COMMAND_SYSIN((u8*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System);
                addr_l++;
                break;

            default:
                printf("intruction 0X%X\n", addr_l);
                addr_l++;
        }

        if(status)
            return 404;

        command = (scope == _GLOBAL) ? global[addr_l][0] : local[addr_l][0];
    }

    if(global[++addr_l][0] != END_PROGRAM)
        return -100;

    if(ENDPROGRAM(System))
        return -404;

        //printf("END_PROGRAM\n");

    return 0;
}