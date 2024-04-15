#include "includedefines/inttypes.h"
#include "includedefines/defines.h"
#include "includedefines/allocs.h"
#include "includeerror/errors.h"
#include "includelib/libIo.h"
#include <stdio.h>
#include <stdlib.h>

Long getFileSize(FILE *file) {
    Long size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    return size;
}

u16 GetUTF(u8 byte[], Byte *Error, Long *setptr){
    if(byte[*setptr] < 0x80){
        return byte[*setptr];
    }

    else if((byte[*setptr] & 0xE0) == 0xC0){
        u16 lastByte = byte[*setptr];
        (*setptr)++;

        if((byte[*setptr] & 0xC0) == 0x80){
            lastByte &= 0x1F;
            lastByte <<= 6;
            byte[*setptr] &= 0x3F;
            return lastByte | byte[*setptr];
        }
        else{
            (*Error) = ERRORUTF2BYTES;
            return 0x0;
        }
    }

    else if((byte[*setptr] & 0xF0) == 0xE0){
        u16 firstByte = byte[(*setptr)++];
        u16 secondByte = byte[(*setptr)++];
        u8 thirdByte = byte[*setptr];

        if((secondByte & 0xC0) == 0x80 && (thirdByte & 0xC0) == 0x80){
            firstByte &= 0x0F;
            firstByte <<= 12;
            secondByte &= 0x3F;
            secondByte <<= 6;
            thirdByte &= 0x3F;
            return firstByte | secondByte | thirdByte;
        }
        else{
            (*Error) = ERRORUTF3BYTES;
            return 0x0;
        }
    }

    else if((byte[*setptr] & 0xF8) == 0xF0){
        u16 firstByte = byte[(*setptr)++];
        u16 secondByte = byte[(*setptr)++];
        u8 thirdByte = byte[(*setptr)++];
        u8 fourthByte = byte[*setptr];

        if((secondByte & 0xC0) == 0x80 && (thirdByte & 0xC0) == 0x80 && (fourthByte & 0xC0) == 0x80){
            firstByte &= 0x07;
            firstByte <<= 18;
            secondByte &= 0x3F;
            secondByte <<= 12;
            thirdByte &= 0x3F;
            thirdByte <<= 6;
            fourthByte &= 0x3F;
            return firstByte | secondByte | thirdByte | fourthByte;
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

String GetSourceCode(String path, Byte *Error){
    FILE *f = _wfopen(path, L"rb");
    Long len = getFileSize(f), counter = 0, setptr = 0;
    String rune = STRALLOC(len);

    if(f == NULL){
        (*Error) = ERROROPENFILE;
        return NULL;
    }

    u8 *byte = uByteALLOC(len);
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
    Byte Error;
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