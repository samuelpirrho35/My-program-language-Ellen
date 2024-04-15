#include "System/System.h"
#include "System/initSystem.h"
#include "System/cleanSystem.h"
#include "VM/codeHex.h"
#include "memory/memory.h"
#include "includedefines/allocs.h"
#include "includedefines/defines.h"
#include "includedefines/inttypes.h"
#include "includedefines/sizeDefined.h"
#include "includeclass/objectsStruct.h"
#include "includeEnumerator/typeObjects.h"
#include "includelib/basicMath.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/libIo.h"
#include "includelib/libString.h"
#include "includelib/objectsFunctions.h"

STATUS set_operation(data_c *line, u64 *addr_i, Long *count, u8 *elements, Long **forEach_loop1, Long **forEach_loop2, u8 qttLoop){
    data_c *bytes;
    u8 lastLoop = 0;

    if(line[*addr_i] != INIT_SET)
        return -7;

    Long actSize = OBJECTsQTTY;
    
    while(line[++(*addr_i)] != END_SET){
        if(*count == actSize){
            actSize += actSize >> 1;
            elements = (data_c*)realloc(elements, actSize);
        }

        if(line[*addr_i] < STORAGE_LONG || line[*addr_i] > STORAGE_FN)
            return -2;

        else
            elements[(*count)++] = line[*addr_i];
    }

    if(!qttLoop)
        return 0;

    if(qttLoop == 2){
        (*forEach_loop1) = EIGHTByteALLOC(*count);
        (*forEach_loop2) = EIGHTByteALLOC(*count);
    }

    else
        (*forEach_loop1) = EIGHTByteALLOC(*count);

    (*addr_i)++;
    while(qttLoop){
        if(line[*addr_i] != INIT_SET)
            return -8;

        (*count) = 0;
        while(line[++(*addr_i)] != END_SET){
            if(*count == OBJECTsQTTY)
                return -3;

            else if((line[*addr_i] < LONG || line[*addr_i] > STRUCT) && line[*addr_i] != SEND)
                return -4;

            else{
                Long value = 0;
                charsize_t size_Obj = 0;

                if(line[(*addr_i)++] == SEND){
                    switch(line[(*addr_i)++]){
                        case LONG:
                            size_Obj = long_size;
                            break;

                        case INT:
                            size_Obj = int_size;
                            break;

                        case SHORT:
                        case CHAR:
                            size_Obj = char_size;
                            break;

                        case BYTE:
                            value = line[*addr_i];
                            break;
                        
                        default:
                            return -5;
                    }

                    if(line[*addr_i - 1] != BYTE){
                        bytes = (data_c*)malloc(size_Obj);
                        memcopy(bytes, line, *addr_i, size_Obj);
                        memcpyint(&value, bytes, size_Obj);
                        (*addr_i) += size_Obj - 1;
                        free(bytes);
                    }

                    if(qttLoop == 1 && lastLoop == 2)
                        (*forEach_loop2)[(*count)++] = value;
                    else
                        (*forEach_loop1)[(*count)++] = value;
                }

                else
                    return -6;
            }
        }
        lastLoop = qttLoop;
        qttLoop--;

        if(qttLoop == 1 && lastLoop == 2){
            (*addr_i)++;
        }
    }

    return 0;
}


STATUS COMMAND_START(data_c *line, __System__ *System){
    u64 addr_i = 0x01;
    Long count = 0;
    u8 *storages = uByteALLOC(OBJECTsQTTY);
    Long *memoryAlloc;

    set_operation(line, &addr_i, &count, storages, &memoryAlloc, NULL, 1);
    if(line[++addr_i] != END_INSTRUCTION)
        return -35;

    initializeStorages(&(System->Manager.Objects), storages, memoryAlloc, count - 1);
    initializeBuffer((*System).Manager.objectsUsing, 0, count - 1);
    memcopy((*System).Manager.objectsUsing, storages, 0, count - 1);
    free(storages);
    free(memoryAlloc);
    return 0;
}


STATUS COMMAND_ADDRE(data_c *line, __System__ *System){
    u64 addr_i = 0x01;
    Long count = 0;
    u8 *objects = uByteALLOC(OBJECTsQTTY);
    Long *values;
    Long *address;

    set_operation(line, &addr_i, &count, objects, &values, &address, 2);
    if(line[++addr_i] != END_INSTRUCTION)
        return -35;

    setValues(&(System->Manager.Objects), objects, values, address, count - 1);
    free(objects);
    free(values);
    free(address);
    return 0;
}


STATUS COMMAND_CALLC(data_c *line, u8 *scope, u64 *addr_l){
    u64 addr_i = 0x01;
    charsize_t sizeObj = 0;
    data_c *bytes;
    Long value = 0;

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
            sizeObj = long_size;
            break;
        case INT:
            sizeObj = int_size;
            break;
        case SHORT:
        case CHAR:
            sizeObj = char_size;
            break;
        default:
            return -4;
    }

    bytes = (data_c*)malloc(sizeObj);
    memcopy(bytes, line, addr_i, sizeObj);
    memcpyint(&value, bytes, sizeObj);
    (*addr_l) = value;

    addr_i += sizeObj - 1;
    free(bytes);

    if(line[addr_i] != END_INSTRUCTION)
        return -5;

    return 0;
}


STATUS COMMAND_JUMPC(data_c *line, u8 *scope, u64 *addr_l){
    u64 addr_i = 0x01;
    charsize_t sizeObj = 0;
    data_c *bytes;
    Long value = 0;

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
            sizeObj = long_size;
            break;
        case INT:
            sizeObj = int_size;
            break;
        case SHORT:
        case CHAR:
            sizeObj = char_size;
            break;
        default:
            return -4;
    }

    bytes = (data_c*)malloc(sizeObj);
    memcopy(bytes, line, addr_i, sizeObj);
    memcpyint(&value, bytes, sizeObj);
    (*addr_l) = value;

    addr_i += sizeObj - 1;
    free(bytes);

    if(line[addr_i] != END_INSTRUCTION)
        return -5;

    return 0;
}


STATUS COMMAND_SYSOT(data_c *line, __System__ System){
    u64 addr_i = 0x01;
    Long count = 0;
    u8 *objects = uByteALLOC(OBJECTsQTTY);
    Long *address;
    
    set_operation(line, &addr_i, &count, objects, &address, NULL, 1);
    if(line[++addr_i] != END_INSTRUCTION)
        return -35;

    List *list = newList(count);
    packageReceived pkrv;
    reference_types ref_ty;
    charsize_t sizeObj = 0;

    for(Long index = 0; index < count; index++){
        switch(objects[index]){
            case STORAGE_LONG:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_long[address[index]]->longTy;
                ref_ty = __Long__;
                break;
            case STORAGE_INT:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_int[address[index]]->intTy;
                ref_ty = __Int__;
                break;
            case STORAGE_SHORT:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_short[address[index]]->shortTy;
                ref_ty = __Short__;
                break;
            case STORAGE_CHAR:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_char[address[index]]->charTy;
                ref_ty = __Char__;
                break;
            case STORAGE_BYTE:
                pkrv.package_ty.pack_integer = System.Manager.Objects.st_byte[address[index]]->byteTy;
                ref_ty = __Byte__;
                break;
            default:
                return -10;
        }

        if(objects[index] == STORAGE_LONG || objects[index] == STORAGE_INT || objects[index] == STORAGE_SHORT ||
           objects[index] == STORAGE_CHAR || objects[index] == STORAGE_BYTE)
        {
            pkrv.pack_ty = PACK_INTEGER;
            pushList(&list, ref_ty, pkrv, strsize(inttstr(pkrv.package_ty.pack_integer)) + 1);
        }
    }

    System.WRT(&list);

    return 0;
}


STATUS COMMAND_DESTR(data_c *line, __System__ *System){
    u64 addr_i = 0x01;
    Long count = 0;
    u8 *objects = uByteALLOC(OBJECTsQTTY);
    Long *address;
    
    set_operation(line, &addr_i, &count, objects, &address, NULL, 1);
    if(line[++addr_i] != END_INSTRUCTION)
        return -35;

    destroyObject(&(System->Manager.Objects), objects, address, count - 1);
    free(objects);
    free(address);
    return 0;
}


int program(data_c global[][50], data_c local[][50], __System__ *System){
    u8 scope = _GLOBAL, error = 0;
    u64 addr_l = 0x00;

    COMMAND command = 0x00;

    if(global[addr_l++][0x00] != PROGRAM)
        return -1;

    command = global[addr_l][0x00];

    while(command != END){
        switch(command){
            case START:
                printf("command start\n\n");
                printf("return start: %d\n", COMMAND_START((data_c*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System));
                addr_l++;
                break;

            case ADDRE:
                printf("command addre\n\n");
                printf("return addre: %d\n", COMMAND_ADDRE((data_c*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System));
                addr_l++;
                break;

            case DESTR:
                printf("command destr\n\n");
                printf("return destr: %d\n", COMMAND_DESTR((data_c*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), System));
                addr_l++;
                break;

            case CALLC:
                printf("command callc\n\n");
                printf("return callc: %d\n", COMMAND_CALLC((data_c*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), &scope, &addr_l));
                break;

            case JUMPC:
                printf("command jumpc\n\n");
                printf("return jumpc: %d\n", COMMAND_JUMPC((data_c*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), &scope, &addr_l));
                break;

            case SYSOT:
                printf("command sysot\n\n");
                printf("return sysot: %d\n", COMMAND_SYSOT((data_c*)((scope == _GLOBAL) ? global[addr_l] : local[addr_l]), *System));
                addr_l++;
                break;

            default:
                printf("intruction 0X%X\n", addr_l);
                addr_l++;
        }

        command = (scope == _GLOBAL) ? global[addr_l][0] : local[addr_l][0];
    }

    if(global[++addr_l][0] == END_PROGRAM){
        ENDPROGRAM(System);
        printf("END_PROGRAM\n");
    }

    else
        return -100;

    return 0;
}