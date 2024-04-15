#include "includelib/libString.h"
#include "includelib/libIo.h"
#include "includelib/convertObjectsTypes.h"
#include "includedefines/defines.h"
#include "includedefines/inttypes.h"
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

lchar* strcopy(lchar *source){
    unsigned long long len = strsize(source);
    if(source == NULL){
        return NULL;
    }

    lchar *copy = (lchar*)malloc((len + 1) * sizeof(lchar));
    lchar *cpy = copy;

    lchar *src = source;

    while(len--){
        *cpy = *src;
        cpy++;
        src++;
    }

    *cpy = L'\0';
    return copy;
}

String strfastcopy(String source, Long len){
    if(len <= 0){
        return NULL;
    }

    String copy = STRALLOC((len + 1));
    String cpy = copy;

    String src = source;

    while(len--){
        *cpy = *src;
        cpy++;
        src++;
    }

    *cpy = L'\0';
    return copy;
}

u8 strncopy(String *dstny, String source, Long limit){
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

    Long size = extention - format;
    dty = STRALLOC((size + 1));
    strncopy(&dty, format, size);

    *dstny = dty;
    *formatptr = extention;

    return 0;
}

char setBuffer(lchar *dstny, lchar *copy, unsigned long long *setposition){
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
