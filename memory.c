#include "memory/memory.h"
#include "VM/codeHex.h"
#include <stdio.h>

void* memcopy(void *dest, void *src, u64 start, u64 size){
    if(dest == NULL || src == NULL)
        return NULL;

    u8 *destcpy = (u8*)dest;
    u8 *srccpy = (u8*)src;

    for(size_ty j = start; j < size + start; j++)
        destcpy[j - start] = srccpy[j];

    return dest;
}

void* memcpyint(void *desty, u8 *src, charsize_t size){
    u8 *srccpy;

    switch(size){
        case i64_size:
            srccpy = (u8[]){src[7], src[6], src[5], src[4], src[3], src[2], src[1], src[0]};
            *((i64*)desty) = *((i64*)srccpy);
            break;
        case i32_size: 
            srccpy = (u8[]){src[3], src[2], src[1], src[0]};
            *((i32*)desty) = *((i32*)srccpy);
            break;
        case i16_size:
            srccpy = (u8[]){src[1], src[0]};
            *((lchar*)desty) = *((lchar*)srccpy);
            break;
        case i8_size:
            srccpy = (u8[]){src[0]};
            *((i8*)desty) = *((i8*)srccpy);
            break;
    }
}

u8* byteParser(void *any, reference_types ref_anyTy, size_ty qtty){
    u8 *bytes;
    u8 startdata = 0;
    size_ty i = 0;

    switch(ref_anyTy){
        case __i64__:
        case __i32__:
        case __i16__:
        case __i8__ :
        case __Char__:
            switch(ref_anyTy){
                case __i64__:
                    bytes = UINT8ALLOC(i64_size);
                    startdata = 0x38;
                    for(; i < i64_size; i++){
                        bytes[i] = (u8)(*((i64*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;
                
                case __i32__:
                    bytes = UINT8ALLOC(i32_size);
                    startdata = 0x18;
                    for(; i < i32_size; i++){
                        bytes[i] = (u8)(*((i32*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;
                
                case __i16__:
                case __Char__:
                    bytes = UINT8ALLOC(i16_size);
                    startdata = 0x10;
                    for(; i < i16_size; i++){
                        bytes[i] = (u8)(*((lchar*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;

                case __i8__:
                    bytes = UINT8ALLOC(i8_size);
                    bytes[0] = ((u8*)any)[0];
                    break;
            }
            break;
    }

    return bytes;
}

i64 getLengthSubDataOfBuffer(u8 *buffer, u64 *init){
    i64 length = 0;
    charsize_t size = 0;
    u8 *newBuffer = NULL;

    switch(buffer[(*init)++]){
        case LONG:
            size = i64_size;
            break;
        case INT:
            size = i32_size;
            break;
        case SHORT:
        case CHAR:
            size = i16_size;
            break;
        case BYTE:
            size = i8_size;
            break;
        default:
            return -1;
    }

    newBuffer = UINT8ALLOC((size));
    memcopy(newBuffer, buffer, *init, size);
    memcpyint(&length, newBuffer, size);
    free(newBuffer);
    (*init) += size;

    return length;
}

void* initializeBuffer(void *buffer, size_ty start, size_ty end){
    if(buffer == NULL)
        return NULL;

    u8 *buffer_c = (u8*)buffer;
    for(size_ty i = start; i < start + end; i++){
        buffer_c[i - start] = 0x00;
    }
}