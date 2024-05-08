#include "System/System.h"
#include "System/initSystem.h"
#include "memory/memory.h"
#include "VM/RunTimeVM.h"
#include "VM/codeHex.h"
#include "includedefines/referenceTypes.h"
#include "includedefines/defines.h"
#include "includedefines/sizeDefined.h"
#include "includedefines/allocs.h"
#include "includelib/basicMath.h"
#include "includelib/objectsFunctions.h"
#include "includelib/libString.h"
#include "includelib/convertObjectsTypes.h"
#include "includeclass/objectsStruct.h"
#include "includeEnumerator/typeObjects.h"

#ifndef RUNTIMEVM

#include "compiler/preObjects.h"
#include "compiler/TokenGenerator.h"

#endif

int main(int argc, char *argv[]){
    __System__ System = __init__();
    
#ifndef RUNTIMEVM
    Token *Tokens = (Token*)malloc(sizeof(Token) * 100);
    i64 indexToken = 0;
    TokenGenerator(L"", Tokens, &indexToken);
#endif

    i64 n = 305419896;
    u8 *bytes = byteParser(&n, __i64__, 0);

    u8 global[][1000] = {
        {PROGRAM},

        {START, INIT_SET, STORAGE_LONG, STORAGE_CHAR, STORAGE_BYTE, END_SET, INIT_SET, SEND, BYTE, 0x01, SEND, BYTE, 0x01,
         SEND, BYTE, 0x01, END_SET, END_INSTRUCTION},
        {ADDRE, INIT_SET, STORAGE_LONG, STORAGE_CHAR, END_SET, INIT_SET, SEND, BYTE, 0x00, SEND, BYTE, 0x00, END_SET,
         INIT_SET, SEND, LONG, bytes[0], bytes[1], bytes[2], bytes[3], bytes[4],
         bytes[5], bytes[6], bytes[7], SEND, CHAR, 0x00, 0x20, END_SET, END_INSTRUCTION},
        {SYSIN, BYTE, INIT_SET, STORAGE_BYTE, END_SET, INIT_SET, SEND, BYTE, 0X00, END_SET, INIT_SET, SEND, STRING,
         BYTE, 0x04, 0x00, '>', 0x00, '>', 0x00, ' ', 0x00, 0x00, END_SET, END_INSTRUCTION},
        {CALLC, ADDRESS_, SEND, BYTE, 0x00, END_INSTRUCTION},
        {DESTR, INIT_SET, STORAGE_LONG, STORAGE_CHAR, STORAGE_BYTE, END_SET, INIT_SET, SEND, BYTE, 0x00, SEND, BYTE, 0x00,
         SEND, BYTE, 0x00, END_SET, END_INSTRUCTION},
        {END},

        {END_PROGRAM}
    };

    u8 local[][1000] = {
        {SYSOT, INIT_SET, STORAGE_LONG, STORAGE_CHAR, STORAGE_BYTE, END_SET, INIT_SET,
         SEND, BYTE, 0x00, SEND, BYTE, 0x00, SEND, BYTE, 0x00, END_SET, END_INSTRUCTION},
        {JUMPC, ADDRESS_, _GLOBAL, SEND, BYTE, 0x05, END_INSTRUCTION}
    };


    u8 global2[][1000] = {
        {PROGRAM},

        {START, INIT_SET, STORAGE_INT, END_SET, INIT_SET, SEND, BYTE, 0x01, END_SET, END_INSTRUCTION},
        {SYSIN, INT, INIT_SET, STORAGE_INT, END_SET, INIT_SET, SEND, BYTE, 0x00, END_SET, INIT_SET,
         SEND, STRING, BYTE, 0x0C, 0x00, 'E', 0x00, 'n', 0x00, 't', 0x00, 'e', 0x00, 'r', 0x00, ' ', 0x00, 'a',
         0x00, 'g', 0x00, 'e', 0x00, ':', 0x00, ' ', 0x00, 0x00, END_SET, END_INSTRUCTION},
        {SYSOT, INIT_SET, STORAGE_INT, END_SET, INIT_SET, SEND, BYTE, 0x00, END_SET, END_INSTRUCTION},
        {DESTR, INIT_SET, STORAGE_INT, END_SET, INIT_SET, SEND, BYTE, 0x00, END_SET, END_INSTRUCTION},
        {END},
        
        {END_PROGRAM}
    };


    u8 global3[][1000] = {
        {PROGRAM},

        {START, INIT_SET, STORAGE_CHAR, END_SET, INIT_SET, SEND, BYTE, 37, END_SET, END_INSTRUCTION},
        {ADDRE,
         INIT_SET,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR,
         END_SET,

         INIT_SET,
            SEND, BYTE,  0, SEND, BYTE,  1, SEND, BYTE,  2, SEND, BYTE,  3, SEND, BYTE,  4,
            SEND, BYTE,  5, SEND, BYTE,  6, SEND, BYTE,  7, SEND, BYTE,  8, SEND, BYTE,  9, SEND, BYTE, 10,
            SEND, BYTE, 11, SEND, BYTE, 12, SEND, BYTE, 13, SEND, BYTE, 14, SEND, BYTE, 15, SEND, BYTE, 16,
            SEND, BYTE, 17, SEND, BYTE, 18, SEND, BYTE, 19, SEND, BYTE, 20, SEND, BYTE, 21, SEND, BYTE, 22,
            SEND, BYTE, 23, SEND, BYTE, 24, SEND, BYTE, 25, SEND, BYTE, 26, SEND, BYTE, 27, SEND, BYTE, 28,
            SEND, BYTE, 29, SEND, BYTE, 30, SEND, BYTE, 31, SEND, BYTE, 32, SEND, BYTE, 33, SEND, BYTE, 34,
            SEND, BYTE, 35, SEND, BYTE, 36,
         END_SET,

         INIT_SET,
            SEND, CHAR, 0X00, 'E', SEND, CHAR, 0X00, 'l', SEND, CHAR, 0X00, 'l', SEND, CHAR, 0X00, 'e',
            SEND, CHAR, 0X00, 'n', SEND, CHAR, 0X00, ',', SEND, CHAR, 0X00, ' ', SEND, CHAR, 0X00, 'q',
            SEND, CHAR, 0X00, 'u', SEND, CHAR, 0X00, 'e', SEND, CHAR, 0X00, 'r', SEND, CHAR, 0X00, 'f',
            SEND, CHAR, 0X00, 'i', SEND, CHAR, 0X00, 'n', SEND, CHAR, 0X00, 'a', SEND, CHAR, 0X00, 'n',
            SEND, CHAR, 0X00, 'c', SEND, CHAR, 0X00, 'i', SEND, CHAR, 0X00, 'a', SEND, CHAR, 0X00, 'r',
            SEND, CHAR, 0X00, ' ', SEND, CHAR, 0X00, 'u', SEND, CHAR, 0X00, 'm', SEND, CHAR, 0X00, 'a',
            SEND, CHAR, 0X00, ' ', SEND, CHAR, 0X00, 'c', SEND, CHAR, 0X00, 'a', SEND, CHAR, 0X00, 's',
            SEND, CHAR, 0X00, 'a', SEND, CHAR, 0X00, ' ', SEND, CHAR, 0X00, 'c', SEND, CHAR, 0X00, 'o',
            SEND, CHAR, 0X00, 'm', SEND, CHAR, 0X00, 'i', SEND, CHAR, 0X00, 'g', SEND, CHAR, 0X00, 'o',
            SEND, CHAR, 0X00, '?',
         END_SET,
         END_INSTRUCTION},
        {SYSOT,
         INIT_SET,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR,
         END_SET,
         
         INIT_SET,
            SEND, BYTE,  0, SEND, BYTE,  1, SEND, BYTE,  2, SEND, BYTE,  3, SEND, BYTE,  4,
            SEND, BYTE,  5, SEND, BYTE,  6, SEND, BYTE,  7, SEND, BYTE,  8, SEND, BYTE,  9, SEND, BYTE, 10,
            SEND, BYTE, 11, SEND, BYTE, 12, SEND, BYTE, 13, SEND, BYTE, 14, SEND, BYTE, 15, SEND, BYTE, 16,
            SEND, BYTE, 17, SEND, BYTE, 18, SEND, BYTE, 19, SEND, BYTE, 20, SEND, BYTE, 21, SEND, BYTE, 22,
            SEND, BYTE, 23, SEND, BYTE, 24, SEND, BYTE, 25, SEND, BYTE, 26, SEND, BYTE, 27, SEND, BYTE, 28,
            SEND, BYTE, 29, SEND, BYTE, 30, SEND, BYTE, 31, SEND, BYTE, 32, SEND, BYTE, 33, SEND, BYTE, 34,
            SEND, BYTE, 35, SEND, BYTE, 36,
         END_SET,
         END_INSTRUCTION},
        {DESTR,
         INIT_SET,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR, STORAGE_CHAR,
            STORAGE_CHAR,
         END_SET,
         
         INIT_SET,
            SEND, BYTE,  0, SEND, BYTE,  1, SEND, BYTE,  2, SEND, BYTE,  3, SEND, BYTE,  4,
            SEND, BYTE,  5, SEND, BYTE,  6, SEND, BYTE,  7, SEND, BYTE,  8, SEND, BYTE,  9, SEND, BYTE, 10,
            SEND, BYTE, 11, SEND, BYTE, 12, SEND, BYTE, 13, SEND, BYTE, 14, SEND, BYTE, 15, SEND, BYTE, 16,
            SEND, BYTE, 17, SEND, BYTE, 18, SEND, BYTE, 19, SEND, BYTE, 20, SEND, BYTE, 21, SEND, BYTE, 22,
            SEND, BYTE, 23, SEND, BYTE, 24, SEND, BYTE, 25, SEND, BYTE, 26, SEND, BYTE, 27, SEND, BYTE, 28,
            SEND, BYTE, 29, SEND, BYTE, 30, SEND, BYTE, 31, SEND, BYTE, 32, SEND, BYTE, 33, SEND, BYTE, 34,
            SEND, BYTE, 35, SEND, BYTE, 36,
         END_SET,
         END_INSTRUCTION},
        {END},

        {END_PROGRAM}
    };

    // if(program(global2, NULL, &System))
    //     printf("ERROR: Fatal error during program execution");
        
    // if(program(global, local, &System))
    //    printf("ERROR: Fatal error during program execution");

    program(global3, NULL, &System);

    free(bytes);

    return 0;
}
