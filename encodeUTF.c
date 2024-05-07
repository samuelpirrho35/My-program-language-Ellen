#include "includedefines/referenceTypes.h"
#include "includedefines/defines.h"
#include "includedefines/allocs.h"
#include "includeerror/errors.h"
#include "includelib/libIo.h"
#include <stdio.h>
#include <stdlib.h>

i64 getFileSize(FILE *file) {
    i64 size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    return size;
}

u16 GetUTF(u8 byte[], i8 *Error, i64 *setptr){
    if(byte[*setptr] < 0x80){
        return byte[*setptr];
    }

    else if((byte[*setptr] & 0xE0) == 0xC0){
        u16 lasti8 = byte[*setptr];
        (*setptr)++;

        if((byte[*setptr] & 0xC0) == 0x80){
            lasti8 &= 0x1F;
            lasti8 <<= 6;
            byte[*setptr] &= 0x3F;
            return lasti8 | byte[*setptr];
        }
        else{
            (*Error) = ERRORUTF2BYTES;
            return 0x0;
        }
    }

    else if((byte[*setptr] & 0xF0) == 0xE0){
        u16 firsti8 = byte[(*setptr)++];
        u16 secondi8 = byte[(*setptr)++];
        u8 thirdi8 = byte[*setptr];

        if((secondi8 & 0xC0) == 0x80 && (thirdi8 & 0xC0) == 0x80){
            firsti8 &= 0x0F;
            firsti8 <<= 12;
            secondi8 &= 0x3F;
            secondi8 <<= 6;
            thirdi8 &= 0x3F;
            return firsti8 | secondi8 | thirdi8;
        }
        else{
            (*Error) = ERRORUTF3BYTES;
            return 0x0;
        }
    }

    else if((byte[*setptr] & 0xF8) == 0xF0){
        u16 firsti8 = byte[(*setptr)++];
        u16 secondi8 = byte[(*setptr)++];
        u8 thirdi8 = byte[(*setptr)++];
        u8 fourthi8 = byte[*setptr];

        if((secondi8 & 0xC0) == 0x80 && (thirdi8 & 0xC0) == 0x80 && (fourthi8 & 0xC0) == 0x80){
            firsti8 &= 0x07;
            firsti8 <<= 18;
            secondi8 &= 0x3F;
            secondi8 <<= 12;
            thirdi8 &= 0x3F;
            thirdi8 <<= 6;
            fourthi8 &= 0x3F;
            return firsti8 | secondi8 | thirdi8 | fourthi8;
        }
        else{
            (*Error) = ERRORUTF4BYTES;
            return 0x0;
        }
    }

    else{
        (*Error) = ERRORUTFINVALID;
        return 0x0;
    }
}

String GetSourceCode(String path, i8 *Error){
    FILE *f = _wfopen(path, L"rb");
    i64 len = getFileSize(f), counter = 0, setptr = 0;
    String rune = STRALLOC(len);

    if(f == NULL){
        (*Error) = ERROROPENFILE;
        return NULL;
    }

    u8 *byte = UINT8ALLOC(len);
    fread(byte, sizeof(u8), len, f);

    while(setptr < len){
        rune[counter] = GetUTF(byte, Error, &setptr);
        if(*Error || rune[counter] == 0x0){
            return NULL;
        }
    
        counter++;
        setptr++;
    }

    fclose(f);
    rune[counter] = L'\0';
    return rune;
}

int main(){
    i8 Error;
    String path = L"pi.txt";
    String rune = GetSourceCode(path, &Error);

    if(rune == NULL){
        switch(Error){
            case ERRORUTFINVALID:
                WindowsWrt(L"Invalid character in file: ", path);
                break;
            case ERROROPENFILE:
                WindowsWrt(L"File not found in your dictory", L"");
                break;
            case ERRORUTF2BYTES:
                WindowsWrt(L"Two-byte character detected, but it is corrupt", L"");
                break;
            case ERRORUTF3BYTES:
                WindowsWrt(L"Three-byte character detected, but it is corrupt", L"");
                break;
            case ERRORUTF4BYTES:
                WindowsWrt(L"Four-byte character detected, but it is corrupt", L"");
                break;
            default:
                WindowsWrt(L"Unknown Error. Please, report the error to the developer", L"");
        }
    }

    else{
        WindowsWrt(rune, L"");
    }
    free(rune);
}