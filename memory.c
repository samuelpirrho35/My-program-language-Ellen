#include "memory/memory.h"
#include <stdio.h>

void* memcopy(void *dest, void *src, size_ty start, size_ty size){
    if(dest == NULL || src == NULL)
        return NULL;

    data_c *destcpy = (data_c*)dest;
    data_c *srccpy = (data_c*)src;

    for(size_ty j = start; j < size + start; j++)
        destcpy[j - start] = srccpy[j];

    return dest;
}

void* memcpyint(void *desty, data_c *src, charsize_t size){
    data_c *srccpy;

    switch(size){
        case long_size:
            srccpy = (data_c[]){src[7], src[6], src[5], src[4], src[3], src[2], src[1], src[0]};
            *((Long*)desty) = *((Long*)srccpy);
            break;
        case int_size: 
            srccpy = (data_c[]){src[3], src[2], src[1], src[0]};
            *((Int*)desty) = *((Int*)srccpy);
            break;
        case short_size:
            srccpy = (data_c[]){src[1], src[0]};
            *((Short*)desty) = *((Short*)srccpy);
            break;
        case byte_size:
            srccpy = (data_c[]){src[0]};
            *((Byte*)desty) = *((Byte*)srccpy);
            break;
    }
}

data_c* byteParser(void *any, reference_types ref_anyTy, size_ty qtty){
    data_c *bytes;
    u8 startdata = 0;
    size_ty i = 0;

    switch(ref_anyTy){
        case __Long__:
        case __Int__:
        case __Short__:
        case __Byte__ :
        case __Char__:
            switch(ref_anyTy){
                case __Long__:
                    bytes = uByteALLOC(long_size);
                    startdata = 0x38;
                    for(; i < long_size; i++){
                        bytes[i] = (data_c)(*((Long*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;
                
                case __Int__:
                    bytes = uByteALLOC(int_size);
                    startdata = 0x18;
                    for(; i < int_size; i++){
                        bytes[i] = (data_c)(*((Int*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;
                
                case __Short__:
                case __Char__:
                    bytes = uByteALLOC(char_size);
                    startdata = 0x10;
                    for(; i < short_size; i++){
                        bytes[i] = (data_c)(*((lchar*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;

                case __Byte__:
                    bytes = uByteALLOC(byte_size);
                    bytes[0] = ((data_c*)any)[0];
                    break;
            }
            break;
    }

    return bytes;
}

void* initializeBuffer(void *buffer, size_ty start, size_ty end){
    if(buffer == NULL)
        return NULL;

    data_c *buffer_c = (data_c*)buffer;
    for(size_ty i = start; i < start + end; i++){
        buffer_c[i] = 0x00;
    }
}