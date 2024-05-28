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

    if(program(global2, NULL, &System))
        printf("ERROR: Fatal error during program execution");
        
    // if(program(global, local, &System))
    //      printf("ERROR: Fatal error during program execution");

    free(bytes);

    return 0;
}
