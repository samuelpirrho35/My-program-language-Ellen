#include "System/System.h"
#include "includeclass/objectsStruct.h"
#include "includedefines/defines.h"
#include "includedefines/inttypes.h"
#include "includedefines/allocs.h"
#include "includelib/libIo.h"
#include "includelib/libString.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/compressBytes.h"
#include "includeEnumerator/typeObjects.h"
#include "utils/utils.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <String.h>
#include <stdio.h>


//-------------<Functions for List Object>-----------------


List* newList(u64 size){
    List *list = (List*)malloc(size * sizeof(List));
    list->GN_Fields.extention = 0;
    list->GN_Fields.capacity = START_DATA_STRUCTURE;
    list->GN_Fields.lengthstr = 3;
    list->GN_Fields.modify_flag = 0;
    return list;
}


void freeList(List *list){
    size_ty i = 0;
    for(; i < list->GN_Fields.extention; i++){
        if(list[i].ref_ty == __String__){
            if(list[i].types.primitiveTys.string_ty != NULL){
                free(list[i].types.primitiveTys.string_ty);
            }
        }
    }

    if(list->GN_Fields.dataStructurestr != NULL){
        free(list->GN_Fields.dataStructurestr);
    }
    free(list);
}


Byte printList(List **list, mode exhibition, Long start, Long end){
    if((*list)->GN_Fields.modify_flag){
        (*list)->GN_Fields.dataStructurestr = compressListToString(list, exhibition, start, end);
    }
    
#ifdef WINDOWS
    if((*list)->GN_Fields.dataStructurestr != NULL){
        WindowsWrt((*list)->GN_Fields.dataStructurestr, L"\n");
        return 0;
    }
    else{
        WindowsWrt(L"ERROR: ", L"Corrupted List\n");
        return -1;
    }
#endif
}


unsigned char pushList(List **list, reference_types ref_ty, packageReceived pkrv, size_ty size){
    (*list)->GN_Fields.extention++;
    size_ty extention = (*list)->GN_Fields.extention, index = extention - 1;
    (*list)->GN_Fields.lengthstr += size + 3;

    if(extention == (*list)->GN_Fields.capacity - 1){
        (*list)->GN_Fields.capacity += (*list)->GN_Fields.capacity / 2;
        (*list) = (List*)realloc((*list), (*list)->GN_Fields.capacity * sizeof(List));
    }

    if(pkrv.pack_ty == PACK_INTEGER){
        switch(ref_ty){
            case __Long__:
                (*list)[index].types.primitiveTys.intTys.long_ty = pkrv.package_ty.pack_anyInteger;
                printf("list->long: %lld\n", (*list)[index].types.primitiveTys.intTys.long_ty);
                break;
            case __Int__:
                (*list)[index].types.primitiveTys.intTys.int_ty = pkrv.package_ty.pack_integer;
                break;
            case __Short__:
                (*list)[index].types.primitiveTys.intTys.short_ty = pkrv.package_ty.pack_integer;
                break;
            case __Byte__:
                (*list)[index].types.primitiveTys.intTys.byte_ty = pkrv.package_ty.pack_integer;
                printf("list->byte: %d\n", (*list)[index].types.primitiveTys.intTys.byte_ty);
                break;
            case __Char__:
                (*list)[index].types.primitiveTys.intTys.char_ty = pkrv.package_ty.pack_integer;
                printf("list->char: %d\n", (*list)[index].types.primitiveTys.intTys.char_ty);
                break;
        }
    }

    else{
        switch(ref_ty){
            case __Long__:
                (*list)[index].types.primitiveTys.intTys.long_ty = compressToInteger(pkrv.package_ty.pack_bytes);
                break;
            case __Int__:
                (*list)[index].types.primitiveTys.intTys.int_ty = compressToInteger(pkrv.package_ty.pack_bytes);
                break;
            case __Short__:
                (*list)[index].types.primitiveTys.intTys.short_ty = compressToInteger(pkrv.package_ty.pack_bytes);
                break;
            case __Byte__:
                (*list)[index].types.primitiveTys.intTys.byte_ty = compressToInteger(pkrv.package_ty.pack_bytes);
                break;
            case __String__:
                (*list)[index].types.primitiveTys.string_ty = (lchar*)malloc(size * sizeof(lchar));
                (*list)[index].types.primitiveTys.string_ty = strcopy(pkrv.package_ty.pack_doubleBytes);
                break;
            default:
                printf("Unsupported type or invalid type in pushList\n");
                return 1;
        }
    }

    (*list)[index].ref_ty = ref_ty;
    printf("list->ref_ty: %d\n", ref_ty);
    (*list)[index].GN_Fields.modify_flag = 1;
    return 0;
}


//-------------<Functions for Array Object>-----------------


void* initializeDataArray(GenericArray *Generic, size_ty init, size_ty end, reference_types ref_dataTy){
    switch(ref_dataTy){
        case __ARRAYLONG__:{
            Array_longTy *array = (Array_longTy*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYINT__:{
            Array_intTy *array = (Array_intTy*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYSHORT__:{
            Array_shortTy *array = (Array_shortTy*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYBYTE__:{
            Array_byteTy *array = (Array_byteTy*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYCHAR__:{
            Array_charTy *array = (Array_charTy*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYFLOAT__:{
            Array_floatTy *array = (Array_floatTy*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0.0f;
            }
            break;
        }
        case __ARRAYDOUBLE__:{
            Array_doubleTy *array = (Array_doubleTy*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0.0;
            }
            break;
        }
    }
}


GenericArray* newArray(size_ty capacity, size_ty size, reference_types ref_dataTy){
    GenericArray *newArray = (GenericArray*)malloc(size);
    newArray->data = malloc(capacity * size);
    initializeDataArray(newArray, 0, capacity, ref_dataTy);
    newArray->GN_Fields.capacity = capacity;
    newArray->GN_Fields.extention = 0;
    return newArray;
}


void resizeArray(size_ty newCapacity, size_ty size, GenericArray *array, reference_types ref_dataTy){
    array->data = realloc(array->data, newCapacity * size);
    initializeDataArray(array, array->GN_Fields.extention + 1, newCapacity, ref_dataTy);
    array->GN_Fields.capacity = newCapacity;
}


/*int main(){
    Array_byteTy *arrBty = (Array_byteTy*)newArray(10, sizeof(Array_byteTy), __ARRAYBYTE__);
    int i = 0;

    for(i = 0; i < arrBty->GN_Fields.capacity; i++){
        arrBty->data[i] = i + 1;
        printf("%d -> ", arrBty->data[i]);
    }
    printf("end\n");

    Array_floatTy *arrflt = (Array_floatTy*)newArray(10, sizeof(Array_floatTy), __ARRAYFLOAT__);

    for(i = 0; i < arrflt->GN_Fields.capacity; i++){
        arrflt->data[i] = i * 0.3445;
        arrflt->GN_Fields.extention++;
        printf("%f -> ", arrflt->data[i]);
    }
    printf("end\n");

    resizeArray(15, sizeof(Array_floatTy), (GenericArray*)arrflt, __ARRAYFLOAT__);
    for(i = 0; i < arrflt->GN_Fields.capacity; i++){
        printf("%f -> ", arrflt->data[i]);
    }

    printf("\n");


    Array_stringTy *arrStr = (Array_stringTy*)newArray(7, sizeof(Array_stringTy), __ARRAYSTRING__);
    for(i = 0; i < arrStr->GN_Fields.capacity; i++){
        printf("string[%d]: ", i);
        if(arrStr->data[i] == NULL){
            printf("string null\n");
        }
        else{
            WindowsWrt(arrStr->data[i], L"\n");
        }
    }


    free(arrBty);
    free(arrBty->data);
    free(arrflt);
    free(arrflt->data);
}
*/

int mainn(){
    List *list = newList(START_DATA_STRUCTURE);

    unsigned char *bytes;
    packageReceived pkrv;

    lchar *i_n = NULL;

    pkrv.pack_ty = PACK_BYTES;

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X00, 0x09, 0x02, 0x02, ENDBYTE};
    pushList(&list, __Long__, pkrv, 4);

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X00, 0x03, 0x05, ENDBYTE};
    pushList(&list, __Long__, pkrv, 3);

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X01, 0x03, 0x05, ENDBYTE};
    pushList(&list, __Byte__, pkrv, 3);

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X00, 0x03, 0x05, 0x00, ENDBYTE};
    pushList(&list, __Short__, pkrv, 4);

    Long limit = 1000000;
    for(Long i = 0; i < limit; i++){
        if(i % 7 == 0){
            pkrv.pack_ty = PACK_DOUBLE_BYTES;
            i_n = inttstr(i);
            pkrv.package_ty.pack_doubleBytes = i_n;
            pushList(&list, __String__, pkrv, strsize(i_n) + 1);
        }

        else{
            pkrv.pack_ty = PACK_BYTES;
            char size = 0;
            bytes = expandsToBytes(i, &size);
            pkrv.package_ty.pack_bytes = bytes;

            if(i <= 127 && i >= -128){
                pushList(&list, __Byte__, pkrv, (unsigned long long)size);
            }

            else if(i <= 32767 && i >= -32768){
                pushList(&list, __Short__, pkrv, (unsigned long long)size);
            }

            else if(i % 2 == 0){
                pushList(&list, __Int__, pkrv, (unsigned long long)size);
            }

            else{
                pkrv.pack_ty = PACK_INTEGER;
                pkrv.package_ty.pack_integer = i;
                pushList(&list, __Long__, pkrv, (unsigned long long)size);
            }
        }
    }

    free(bytes);
    free(i_n);

    pkrv.pack_ty = PACK_BYTES;

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X00, 0x03, 0x05, 0x00, 0x00, 0x00, ENDBYTE};
    pushList(&list, __Long__, pkrv, 6);
    pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X01;
    pushList(&list, __Long__, pkrv, 6);

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X00, 0x03, 0x05, 0x00, 0x00, ENDBYTE};
    pushList(&list, __Int__, pkrv, 5);
    pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X01;
    pushList(&list, __Int__, pkrv, 5);

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X00, 0x03, 0x05, 0x00, ENDBYTE};
    pushList(&list, __Short__, pkrv, 4);
    pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X01;
    pushList(&list, __Short__, pkrv, 4);

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X00, 0x03, 0x05, ENDBYTE};
    pushList(&list, __Byte__, pkrv, 3);
    pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X01;
    pushList(&list, __Byte__, pkrv, 3);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    lchar hello_world[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x00};
    pkrv.package_ty.pack_doubleBytes = hello_world;
    pushList(&list, __String__, pkrv, 14);

    lchar input[] = L"Todos esses momentos se perderão no tempo, como lágrimas na chuva...";
    pkrv.package_ty.pack_doubleBytes = input;
    pushList(&list, __String__, pkrv, 69);

    lchar blade_runner[] = L"Blade Runner: Melhor filme de toda a história do cinema!";
    pkrv.package_ty.pack_doubleBytes = blade_runner;
    pushList(&list, __String__, pkrv, 43);

    lchar *games[] = {
                        L"Dark Souls Remaster", L"Hollow Knight", L"Elden Ring",
                        L"Cyberpunk 2077", L"Dark Souls III", L"Batman: Arkham Knight",
                        L"Red Dead Redemption 2", L"Lies Of P", L"BloodBorne",
                        L"Sekiro", L"Dark Souls II"
                      };

    for(char y = 0; y < 11; y++){
        pkrv.package_ty.pack_doubleBytes = games[y];
        pushList(&list, __String__, pkrv, strsize(games[y]) + 1);
    }

    lchar maxnum_long_long[] = L"9223372036854775807";
    Long max_nLL = convert_StringToInteger(L"9223372036854775807");

    pkrv.pack_ty = PACK_BYTES;

    charsize_t len = 0;
    data_c *newData_c = expandsToBytes(max_nLL, &len);
    pkrv.package_ty.pack_bytes = newData_c;
    pushList(&list, __Long__, pkrv, (Long)len);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    free(newData_c);
    pkrv.package_ty.pack_doubleBytes = maxnum_long_long;
    pushList(&list, __String__, pkrv, strsize(maxnum_long_long) + 1);

    lchar ellen[] = L"Ellen, morzinho di mi vida";
    pkrv.package_ty.pack_doubleBytes = ellen;
    pushList(&list, __String__, pkrv, strsize(ellen) + 1);

    pkrv.pack_ty = PACK_BYTES;

    pkrv.package_ty.pack_bytes = (data_c[]){STARTBYTE_0X00, 0x09, 0x02, 0x02, 0x03, 0x03, 0x07, 0x02, 0x00, 0x03, 0x06, ENDBYTE};
    pushList(&list, __Long__, pkrv, 11);

    pkrv.pack_ty = PACK_INTEGER;

    pkrv.package_ty.pack_integer = 9223372036854775807;
    pushList(&list, __Long__, pkrv, strsize(L"9223372036854775807") + 1);

    pkrv.package_ty.pack_integer = 25042006;
    pushList(&list, __Int__, pkrv, strsize(L"25042006") + 1);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    pkrv.package_ty.pack_doubleBytes = L"Ton-618";
    pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doubleBytes) + 1);

    pkrv.package_ty.pack_doubleBytes = L"I Love You Ellen";
    pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doubleBytes) + 1);

    pkrv.package_ty.pack_doubleBytes = L"End List";
    pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doubleBytes) + 1);

    printList(&list, MODE_PRINT_LIST, 0, list->GN_Fields.extention);
    freeList(list);
}