#include "includedefines/inttypes.h"
#include "includedefines/defines.h"
#include "includedefines/allocs.h"
//#include "includelib/basicMath.h"
//#include "includelib/objectsFunctions.h"
#include "includelib/libString.h"
#include "includeclass/objectsStruct.h"
#include <stdlib.h>
#include <stdio.h>

String convert_intArrayToStr(u8 *intArray, Long sizeArray){
    String _str = STRALLOC(sizeArray + 1);
    register Long i;
    for(i = 0; i < sizeArray; i++){
        _str[i] = (char)intArray[i] + '0'; 
    }

    _str[sizeArray] = '\0';

    return _str;
}

lchar* inttstr(Long Integer){
    char sign = 0;
    
    if(Integer < 0){
        sign = 1;
        Integer *= -1;
    }

    char digits = 0;
    Long cpyInt = Integer;
    do{
        digits++;
    }while(cpyInt /= 10);

    lchar *result = (lchar*)malloc((digits + sign + 1) * sizeof(lchar));

    char index = digits + sign;
    result[index--] = L'\0';
    do{
        result[index--] = L'0' + (Integer % 10);
        Integer /= 10;
    }while(Integer);

    if(sign){
        result[0] = L'-';
    }

    return result;
}

Long convert_StringToInteger(String str){
    Long result = 0;
    u8 sign = 1;

    if(*str == L'-'){
        sign = -1;
        str++;
    }

    while(*str != L'\0'){
        u8 charValue = (int)*str;
        if(!(charValue >= 48 && charValue <= 57)){
            return 0;
        }
        result = result * 10 + (charValue - 48);
        str++;
    }

    result *= sign;

    return result;
}
