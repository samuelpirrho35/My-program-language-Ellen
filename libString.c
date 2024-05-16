#include "includelib/libString.h"
#include "includelib/libIo.h"
#include "includelib/convertObjectsTypes.h"
#include "includedefines/defines.h"
#include "includedefines/referenceTypes.h"
#include "includedefines/allocs.h"
#include <stdlib.h>
#include <stdio.h>

size_ty strsize(lchar *_String){
    size_ty length = 0;
    while(_String[length] != '\0'){
        length++;
    }

    return length;
}

String strmerger(String str1, String str2){
    if(str1 == NULL || str2 == NULL){
        return NULL;
    }

    size_ty sizestr1 = strsize(str1);
    size_ty sizestr2 = strsize(str2);
    size_ty totalSize = sizestr1 + sizestr2 + 1;

    String newstr = STRALLOC(totalSize);
    String nstr = newstr;

    while(sizestr1--){
        *nstr = *str1;
        nstr++;
        str1++;
    }

    while(sizestr2--){
        *nstr = *str2;
        nstr++;
        str2++;
    }

    *nstr = L'\0';
    return newstr;
}

String strfastmerger(String str1, String str2, size_ty sizestr1, size_ty sizestr2){
    if(str1 == NULL || str2 == NULL){
        return NULL;
    }
    size_ty totalSize = sizestr1 + sizestr2 + 1;

    String newstr = STRALLOC(totalSize);
    String nstr = newstr;

    while(sizestr1--){
        *nstr = *str1;
        nstr++;
        str1++;
    }

    while(sizestr2--){
        *nstr = *str2;
        nstr++;
        str2++;
    }

    *nstr = '\0';
    return newstr;
}

String strcopy(String source){
    i64 len = strsize(source) + 1;
    if(source == NULL){
        return NULL;
    }

    String copy = STRALLOC((len + 1));
    copy[--len] = L'\0';

    while(len--)
        copy[len] = source[len];

    return copy;
}

String strfastcopy(String source, i64 len){
    if(len <= 0){
        return NULL;
    }

    String copy = STRALLOC((len + 1));
    copy[--len] = L'\0';

    while(len--)
        copy[len] = source[len];

    return copy;
}

u8 strncopy(String *dstny, String source, i64 limit){
    if(!((limit <= strsize(source) && limit > 0))){
        return 1;
    }

    String d = *dstny;
    String s = source;

    while(limit-- && *s){
        *d = *s;
        d++;
        s++;
    }

    *d = L'\0';
    return 0;
}

u8 strcompare(String str1, String str2){
    if(str1 == NULL || str2 == NULL)
        return 0;

    u64 len1 = strsize(str1), len2 = strsize(str2);
    if(len1 != len2)
        return 0;

    for(; *str1; str1++){
        if(*str1 != *str2)
            return 0;
        
        str2++;
    }

    return 1;
}

u8 strfastcompare(String str1, String str2, u64 len1){
    if(str1 == NULL || str2 == NULL)
        return 0;

    u64 len2 = strsize(str2);
    if(len1 != len2)
        return 0;

    for(; *str1; str1++){
        if(*str1 != *str2)
            return 0;
        
        str2++;
    }

    return 1;
}

void copyToStaticBuffer(lchar copy[], String src, u64 len){
    copy[--len] = L'\0';

    while(len--)
        copy[len] = src[len];
}

u8 strgetnextstr(String *dstny, String *formatptr){
    String format = *formatptr;
    String dty;

    while(*format == L' '){
        format++;
    }

    if(*format == L'\0'){
        *formatptr = format;
        return 1;
    }

    String extention = format;
    while(*extention != L' ' && *extention != L'\0'){
        extention++;
    }

    i64 size = extention - format;
    dty = STRALLOC((size + 1));
    strncopy(&dty, format, size);

    *dstny = dty;
    *formatptr = extention;

    return 0;
}

i8 setBuffer(String dstny, String copy, u64 *setposition){
    lchar *cpy = copy;
    
    if(dstny == NULL || cpy == NULL){
        return 1;
    }

    while(*cpy){
        dstny[(*setposition)++] = *cpy;
        cpy++;
    }

    dstny[*setposition] = L'\0';

    return 0;
}

String DataToString(u8 data[], i64 size, i64 start){
    if(size <= 0)
        return NULL;

    String newString = STRALLOC(size);
    i64 i = start, j = start;
    for(; i < start + size; i++)
        newString[i - start] = ((data[j++] << 8) | data[j++]);

    return newString;
}
