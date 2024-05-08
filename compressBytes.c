#include "includedefines/referenceTypes.h"
#include "includedefines/allocs.h"
#include "includeclass/objectsStruct.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/libString.h"
#include "includelib/libIo.h"
#include "memory/memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

i64 compressToi32eger(u8 bytes[]){
    i64 comprssBty = 0;
    char sign = 1;

    if(bytes[0]){
        sign = -1;
    }

    i64 i = 1;
    while(bytes[i] != ENDBYTE){
        comprssBty = comprssBty * 10 + bytes[i++];
    }

    return comprssBty * sign;
}

String compressListToString(List **list, mode exhibition, i64 start, i64 end){
    if((start < 0 || start > (*list)->GN_Fields.extention) || (end < 0 || end > (*list)->GN_Fields.extention))
        return NULL;

    String liststr = STRALLOC(((*list)->GN_Fields.lengthstr + 1));
    String str = NULL;
    u64 setposition = 0;

    (exhibition == MODE_PRINT_LIST) ? setBuffer(liststr, L"[", &setposition) : (void)0;

    for(; start < end; start++){
        i64 v;

        switch((*list)[start].ref_ty){
            case __i64__:
                v = (*list)[start].types.primitiveTys.intTys.i64_ty;
                str = inttstr(v);
                break;

            case __i32__:
                v = (*list)[start].types.primitiveTys.intTys.i32_ty;
                str = inttstr(v);
                break;

            case __i16__:
                v = (*list)[start].types.primitiveTys.intTys.i16_ty;
                str = inttstr(v);
                break;

            case __Char__:
                str = strcopy((lchar[]){(*list)[start].types.primitiveTys.char_ty, L'\0'});
                break;

            case __i8__:
                v = (*list)[start].types.primitiveTys.intTys.i8_ty;
                str = inttstr(v);
                break;

            case __String__:
            {
                u64 lenstr = strsize((*list)[start].types.primitiveTys.string_ty) + 4;
                str = STRALLOC(lenstr);
                (exhibition == MODE_PRINT_LIST) ? str[0] = L'"' : (void)0;
                i64 setpos = (exhibition == MODE_PRINT_LIST) ? 1 : 0;
                setBuffer(str, (*list)[start].types.primitiveTys.string_ty, &setpos);
                (exhibition == MODE_PRINT_LIST) ? setBuffer(str, L"\"", &setpos) : (void)0;
                break;
            }

            default:
                printf("Unsupported type or invalid type in compress\n");
                free(liststr);
                return NULL;
        }
        
        if(str == NULL)
            return NULL;

        setBuffer(liststr, str, &setposition);

        if(start != end - 1 && exhibition == MODE_PRINT_LIST){
            setBuffer(liststr, L", ", &setposition);
        }

        free(str);
    }

    (exhibition == MODE_PRINT_LIST) ? setBuffer(liststr, L"]", &setposition) : (void)0;

    (*list)->GN_Fields.modify_flag = 0;
    return liststr;
}