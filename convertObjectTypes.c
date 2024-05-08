#include "includedefines/referenceTypes.h"
#include "includedefines/defines.h"
#include "includedefines/allocs.h"
//#include "includelib/basicMath.h"
//#include "includelib/objectsFunctions.h"
#include "includelib/libString.h"
#include "includeclass/objectsStruct.h"
#include <stdlib.h>
#include <stdio.h>

String convert_intArrayToStr(u8 *intArray, i64 sizeArray){
    String _str = STRALLOC(sizeArray + 1);
    register i64 i;
    for(i = 0; i < sizeArray; i++){
        _str[i] = (char)intArray[i] + '0'; 
    }

    _str[sizeArray] = '\0';

    return _str;
}

String inttstr(i64 integer){
    char sign = 0;
    
    if(integer < 0){
        sign = 1;
        integer *= -1;
    }

    char digits = 0;
    i64 cpyi32 = integer;
    do{
        digits++;
    }while(cpyi32 /= 10);

    String result = STRALLOC((digits + sign + 1));
    if(result == NULL)
        return NULL;

    char index = digits + sign;
    result[index--] = L'\0';
    do{
        result[index--] = L'0' + (integer % 10);
        integer /= 10;
    }while(integer);

    if(sign){
        result[0] = L'-';
    }

    return result;
}

i64 convert_StringToInteger(String str){
    i64 result = 0;
    i8 sign = 1, c = 0;

    if(str[0] == L'-'){
        sign = -1;
        c++;
    }

    while(str[c] != L'\0'){
        u8 charValue = (int)str[c];
        if(!(charValue >= 48 && charValue <= 57)){
            return 0;
        }
        result = result * 10 + (charValue - 48);
        c++;
    }

    result *= sign;

    return result;
}
