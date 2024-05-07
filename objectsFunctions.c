#include "System/System.h"
#include "includeclass/objectsStruct.h"
#include "includedefines/defines.h"
#include "includedefines/referenceTypes.h"
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
    List *list = LISTALLOC(size);
    list->GN_Fields.extention = 0;
    list->GN_Fields.capacity = START_DATA_STRUCTURE;
    list->GN_Fields.lengthstr = 3;
    list->GN_Fields.modify_flag = 0;
    list->GN_Fields.dataStructurestr = NULL;
    return list;
}


void freeList(List *list){
    size_ty i = 0;
    for(; i < list->GN_Fields.extention; i++){
        if(list[i].ref_ty == __String__){
            if(list[i].types.primitiveTys.string_ty != NULL)
                free(list[i].types.primitiveTys.string_ty);
        }
    }

    if(list->GN_Fields.dataStructurestr != NULL)
        free(list->GN_Fields.dataStructurestr);
    
    free(list);
}


i8 printList(List **list, mode exhibition, i64 start, i64 end){
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


i8 pushList(List **list, reference_types ref_ty, packageReceived pkrv, size_ty size){
    (*list)->GN_Fields.extention++;
    size_ty extention = (*list)->GN_Fields.extention, index = extention - 1;
    (*list)->GN_Fields.lengthstr += size + 3;

    if(extention == (*list)->GN_Fields.capacity - 1){
        (*list)->GN_Fields.capacity += (*list)->GN_Fields.capacity / 2;
        List *NewList = (List*)realloc((*list), (*list)->GN_Fields.capacity * sizeof(List));
        if(NewList == NULL)
            return -7;

        (*list) = NewList;
    }

    if(pkrv.pack_ty == PACK_INTEGER){
        switch(ref_ty){
            case __i64__:
                (*list)[index].types.primitiveTys.intTys.i64_ty = pkrv.package_ty.pack_integer;
                break;
            case __i32__:
                (*list)[index].types.primitiveTys.intTys.i32_ty = pkrv.package_ty.pack_integer;
                break;
            case __i16__:
                (*list)[index].types.primitiveTys.intTys.i16_ty = pkrv.package_ty.pack_integer;
                break;
            case __i8__:
                (*list)[index].types.primitiveTys.intTys.i8_ty = pkrv.package_ty.pack_integer;
                break;
            case __Char__:
                (*list)[index].types.primitiveTys.intTys.char_ty = pkrv.package_ty.pack_integer;
                break;
        }
    }

    else{
        switch(ref_ty){
            case __i64__:
                (*list)[index].types.primitiveTys.intTys.i64_ty = compressToi32eger(pkrv.package_ty.pack_bytes);
                break;
            case __i32__:
                (*list)[index].types.primitiveTys.intTys.i32_ty = compressToi32eger(pkrv.package_ty.pack_bytes);
                break;
            case __i16__:
                (*list)[index].types.primitiveTys.intTys.i16_ty = compressToi32eger(pkrv.package_ty.pack_bytes);
                break;
            case __i8__:
                (*list)[index].types.primitiveTys.intTys.i8_ty = compressToi32eger(pkrv.package_ty.pack_bytes);
                break;
            case __String__:
                (*list)[index].types.primitiveTys.string_ty = strfastcopy(pkrv.package_ty.pack_f64i8s, size);
                break;
            default:
                printf("Unsupported type or invalid type in pushList\n");
                return 1;
        }
    }

    (*list)[index].ref_ty = ref_ty;
    (*list)[index].GN_Fields.modify_flag = 1;

    return 0;
}


//-------------<Functions for Array Object>-----------------


void initializeDataArray(GenericArray *Generic, size_ty init, size_ty end, reference_types ref_dataTy){
    switch(ref_dataTy){
        case __ARRAYi64__:{
            Array_i64Ty *array = (Array_i64Ty*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYi32__:{
            Array_i32Ty *array = (Array_i32Ty*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYi16__:{
            Array_i16Ty *array = (Array_i16Ty*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYi8__:{
            Array_i8Ty *array = (Array_i8Ty*)Generic;
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
        case __ARRAYf32__:{
            Array_f32Ty *array = (Array_f32Ty*)Generic;
            for(size_ty i = init; i < end; i++){
                array->data[i] = 0.0f;
            }
            break;
        }
        case __ARRAYf64__:{
            Array_f64Ty *array = (Array_f64Ty*)Generic;
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
    void *newDataArray = realloc(array->data, newCapacity * size);
    array->data = newDataArray;
    initializeDataArray(array, array->GN_Fields.extention + 1, newCapacity, ref_dataTy);
    array->GN_Fields.capacity = newCapacity;
}


//-------------<Functions for Ouroboros Object>-----------------

Ouroboros* newOuroboros(){
    Ouroboros *ouroboros = (Ouroboros*)malloc(sizeof(Ouroboros));
    return ouroboros;
}


Ouroboros* initOuroboros(u8 data[]){
    Ouroboros *Lefti8 = newOuroboros();
    Ouroboros *Righti8 = newOuroboros();
    Lefti8->previous = Righti8;
    Righti8->next = Lefti8;

    Lefti8->val = data[0];
    Righti8->val = data[0];

    Ouroboros *aux1 = Lefti8;
    Ouroboros *aux2;

    u16 j = 1;
    while(data[j] != ENDBYTE){
        aux1->next = newOuroboros();
        aux2 = aux1;
        aux1 = aux1->next;
        aux1->previous = aux2;
        aux1->val = data[j++];
    }

    aux1->next = Righti8;
    Righti8->previous = aux1;

    return Lefti8;
}


void freeOuroboros(Ouroboros *ouroboros){
    Ouroboros *_ouroboros = ouroboros->next;
    Ouroboros *__ouroboros;
    free(ouroboros);
    while(_ouroboros != ouroboros){
        __ouroboros = _ouroboros->next;
        free(__ouroboros);
        _ouroboros = __ouroboros;
    }
}


Ouroboros* sumOuroboros(Ouroboros *ouroboros1, Ouroboros *ouroboros2){
    Ouroboros *ouroboros_left = newOuroboros();
    Ouroboros *ouroboros_right = newOuroboros();
    Ouroboros *aux, *aux2;
    
    ouroboros_left->previous = ouroboros_right;
    ouroboros_right->next = ouroboros_left;
    
    ouroboros_left->val = STARTBYTE_0X0E;
    ouroboros_right->val = STARTBYTE_0X0E;
    
    u8 val1, val2, upone = 0, sum = 0;
    aux = ouroboros_right;
    aux->next = ouroboros_right;

    while(1){
        if(ouroboros1->val == STARTBYTE_0X0E || ouroboros1->val == STARTBYTE_0X0F)
            val1 = 0;

        else{
            val1 = ouroboros1->val;
            ouroboros1 = ouroboros1->previous;
        }

        if(ouroboros2->val == STARTBYTE_0X0E || ouroboros2->val == STARTBYTE_0X0F)
            val2 = 0;

        else{
            val2 = ouroboros2->val;
            ouroboros2 = ouroboros2->previous;
        }


        sum = val1 + val2 + upone;
        upone = (sum > 9) ? 1 : 0;
        aux->previous = newOuroboros();
        aux->previous->val = sum % 10;
        aux2 = aux;
        aux = aux->previous;
        aux->next = aux2;
        
        if((ouroboros1->val == STARTBYTE_0X0E || ouroboros1->val == STARTBYTE_0X0F) &&
           (ouroboros2->val == STARTBYTE_0X0E || ouroboros2->val == STARTBYTE_0X0F))
            break;
    }

    if(upone){
        aux->previous = newOuroboros();
        aux->previous->next = aux;
        aux = aux->previous;
        aux->val = upone;
    }

    aux->previous = ouroboros_left;
    ouroboros_left->next = aux;
    
    return ouroboros_left;
}


/*int main(){
    Array_i8Ty *arrBty = (Array_i8Ty*)newArray(10, sizeof(Array_i8Ty), __ARRAYi8__);
    int i = 0;

    for(i = 0; i < arrBty->GN_Fields.capacity; i++){
        arrBty->data[i] = i + 1;
        printf("%d -> ", arrBty->data[i]);
    }
    printf("end\n");

    Array_f32Ty *arrflt = (Array_f32Ty*)newArray(10, sizeof(Array_f32Ty), __ARRAYf32__);

    for(i = 0; i < arrflt->GN_Fields.capacity; i++){
        arrflt->data[i] = i * 0.3445;
        arrflt->GN_Fields.extention++;
        printf("%f -> ", arrflt->data[i]);
    }
    printf("end\n");

    resizeArray(15, sizeof(Array_f32Ty), (GenericArray*)arrflt, __ARRAYf32__);
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

// int mainn(){
//     List *list = newList(START_DATA_STRUCTURE);

//     unsigned char *bytes;
//     packageReceived pkrv;

//     lchar *i_n = NULL;

//     pkrv.pack_ty = PACK_BYTES;

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x09, 0x02, 0x02, ENDBYTE};
//     pushList(&list, __i64__, pkrv, 4);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, ENDBYTE};
//     pushList(&list, __i64__, pkrv, 3);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0F, 0x03, 0x05, ENDBYTE};
//     pushList(&list, __i8__, pkrv, 3);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, 0x00, ENDBYTE};
//     pushList(&list, __i16__, pkrv, 4);

//     i64 limit = 1000000;
//     for(i64 i = 0; i < limit; i++){
//         if(i % 7 == 0){
//             pkrv.pack_ty = PACK_DOUBLE_BYTES;
//             i_n = inttstr(i);
//             pkrv.package_ty.pack_f64i8s = i_n;
//             pushList(&list, __String__, pkrv, strsize(i_n) + 1);
//         }

//         else{
//             pkrv.pack_ty = PACK_BYTES;
//             char size = 0;
//             bytes = expandsToi8s(i, &size);
//             pkrv.package_ty.pack_bytes = bytes;

//             if(i <= 127 && i >= -128){
//                 pushList(&list, __i8__, pkrv, (unsigned long long)size);
//             }

//             else if(i <= 32767 && i >= -32768){
//                 pushList(&list, __i16__, pkrv, (unsigned long long)size);
//             }

//             else if(i % 2 == 0){
//                 pushList(&list, __i32__, pkrv, (unsigned long long)size);
//             }

//             else{
//                 pkrv.pack_ty = PACK_INTEGER;
//                 pkrv.package_ty.pack_integer = i;
//                 pushList(&list, __i64__, pkrv, (unsigned long long)size);
//             }
//         }
//     }

//     free(bytes);
//     free(i_n);

//     pkrv.pack_ty = PACK_BYTES;

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, 0x00, 0x00, 0x00, ENDBYTE};
//     pushList(&list, __i64__, pkrv, 6);
//     pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X0F;
//     pushList(&list, __i64__, pkrv, 6);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, 0x00, 0x00, ENDBYTE};
//     pushList(&list, __i32__, pkrv, 5);
//     pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X0F;
//     pushList(&list, __i32__, pkrv, 5);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, 0x00, ENDBYTE};
//     pushList(&list, __i16__, pkrv, 4);
//     pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X0F;
//     pushList(&list, __i16__, pkrv, 4);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, ENDBYTE};
//     pushList(&list, __i8__, pkrv, 3);
//     pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X0F;
//     pushList(&list, __i8__, pkrv, 3);

//     pkrv.pack_ty = PACK_DOUBLE_BYTES;

//     lchar hello_world[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x00};
//     pkrv.package_ty.pack_f64i8s = hello_world;
//     pushList(&list, __String__, pkrv, 14);

//     lchar input[] = L"Todos esses momentos se perderão no tempo, como lágrimas na chuva...";
//     pkrv.package_ty.pack_f64i8s = input;
//     pushList(&list, __String__, pkrv, 69);

//     lchar blade_runner[] = L"Blade Runner: Melhor filme de toda a história do cinema!";
//     pkrv.package_ty.pack_f64i8s = blade_runner;
//     pushList(&list, __String__, pkrv, 43);

//     lchar *games[] = {
//                         L"Dark Souls Remaster", L"Hollow Knight", L"Elden Ring",
//                         L"Cyberpunk 2077", L"Dark Souls III", L"Batman: Arkham Knight",
//                         L"Red Dead Redemption 2", L"Lies Of P", L"BloodBorne",
//                         L"Sekiro", L"Dark Souls II"
//                       };

//     for(char y = 0; y < 11; y++){
//         pkrv.package_ty.pack_f64i8s = games[y];
//         pushList(&list, __String__, pkrv, strsize(games[y]) + 1);
//     }

//     lchar maxnum_long_long[] = L"9223372036854775807";
//     i64 max_nLL = convert_StringToi32eger(L"9223372036854775807");

//     pkrv.pack_ty = PACK_BYTES;

//     charsize_t len = 0;
//     u8 *newData_c = expandsToi8s(max_nLL, &len);
//     pkrv.package_ty.pack_bytes = newData_c;
//     pushList(&list, __i64__, pkrv, (i64)len);

//     pkrv.pack_ty = PACK_DOUBLE_BYTES;

//     free(newData_c);
//     pkrv.package_ty.pack_f64i8s = maxnum_long_long;
//     pushList(&list, __String__, pkrv, strsize(maxnum_long_long) + 1);

//     lchar ellen[] = L"Ellen, morzinho di mi vida";
//     pkrv.package_ty.pack_f64i8s = ellen;
//     pushList(&list, __String__, pkrv, strsize(ellen) + 1);

//     pkrv.pack_ty = PACK_BYTES;

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x09, 0x02, 0x02, 0x03, 0x03, 0x07, 0x02, 0x00, 0x03, 0x06, ENDBYTE};
//     pushList(&list, __i64__, pkrv, 11);

//     pkrv.pack_ty = PACK_INTEGER;

//     pkrv.package_ty.pack_integer = 9223372036854775807;
//     pushList(&list, __i64__, pkrv, strsize(L"9223372036854775807") + 1);

//     pkrv.package_ty.pack_integer = 25042006;
//     pushList(&list, __i32__, pkrv, strsize(L"25042006") + 1);

//     pkrv.pack_ty = PACK_DOUBLE_BYTES;

//     pkrv.package_ty.pack_f64i8s = L"Ton-618";
//     pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_f64i8s) + 1);

//     pkrv.package_ty.pack_f64i8s = L"I Love You Ellen";
//     pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_f64i8s) + 1);

//     pkrv.package_ty.pack_f64i8s = L"End List";
//     pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_f64i8s) + 1);

//     printList(&list, MODE_PRINT_LIST, 0, list->GN_Fields.extention);
//     freeList(&list);
// }