#include "includelib/List.h"
#include "includedefines/allocs.h"
#include "includelib/libIo.h"
#include "includelib/libString.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/compressBytes.h"
#include "includeEnumerator/typeObjects.h"
#include "utils/utils.h"

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
    u64 i = 0;
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


i8 pushList(List **list, reference_types ref_ty, packageReceived pkrv, u64 size){
    (*list)->GN_Fields.extention++;
    u64 extention = (*list)->GN_Fields.extention, index = extention - 1;
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
                (*list)[index].types.primitiveTys.intTys.i32_ty = (i32)pkrv.package_ty.pack_integer;
                break;
            case __i16__:
                (*list)[index].types.primitiveTys.intTys.i16_ty = (i16)pkrv.package_ty.pack_integer;
                break;
            case __i8__:
                (*list)[index].types.primitiveTys.intTys.i8_ty = (i8)pkrv.package_ty.pack_integer;
                break;
            case __Char__:
                (*list)[index].types.primitiveTys.intTys.char_ty = (lchar)pkrv.package_ty.pack_integer;
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
                (*list)[index].types.primitiveTys.string_ty = strfastcopy(pkrv.package_ty.pack_doublebytes, size);
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