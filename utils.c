#include "utils/utils.h"

u8* expandsToi8s(i64 n, charu64 *newSize){
    u8 *bytes;
    char sign = STARTBYTE_0X0E;
    if(n < 0){
        sign = STARTBYTE_0X0F;
        n *= -1;
    }

    char qttyDigits = 0;
    
    if(n >= 10){
        i64 ncpy = n;
        while(ncpy){
            qttyDigits++;
            ncpy /= 10;
        }

        (*newSize) = qttyDigits + 2;
    }

    else{
        (*newSize) = 3;
        bytes = (u8*)malloc(3);
        bytes[0] = sign;
        bytes[1] = n;
        bytes[2] = ENDBYTE;
        return bytes;
    }

    bytes = (u8*)malloc(qttyDigits + 2);
    
    bytes[0] = sign;
    bytes[qttyDigits + 1] = ENDBYTE;
    
    do{
        bytes[qttyDigits--] = n % 10;
        n /= 10;
    }while(n);

    return bytes;
}
