#include "System/System.h"
#include "System/initSystem.h"
#include "memory/memory.h"
#include "VM/RunTimeVM.h"
#include "VM/codeHex.h"
#include "includedefines/inttypes.h"
#include "includedefines/defines.h"
#include "includedefines/sizeDefined.h"
#include "includedefines/allocs.h"
#include "includelib/basicMath.h"
#include "includelib/objectsFunctions.h"
#include "includelib/libString.h"
#include "includelib/convertObjectsTypes.h"
#include "includeclass/objectsStruct.h"
#include "includeEnumerator/typeObjects.h"

#ifndef JUSTVIRTUALMACHINE

#include "compiler/preObjects.h"
#include "compiler/TokenGenerator.h"

#endif

int main(int argc, char *argv[]){
    __System__ System = __init__();
    
#ifndef JUSTVIRTUALMACHINE
    Token *Tokens = (Token*)malloc(sizeof(Token) * 100);
    Long indexToken = 0;
    TokenGenerator(L"", Tokens, &indexToken);
#endif

    Long n = 305419896;
    data_c *bytes = byteParser(&n, __Long__, 0);

    data_c global[][50] = {
        {PROGRAM},

        {START, INIT_SET, STORAGE_LONG, STORAGE_CHAR, STORAGE_BYTE, END_SET, INIT_SET, SEND, BYTE, 0x01, SEND, BYTE, 0x01,
        SEND, BYTE, 0x01, END_SET, END_INSTRUCTION},
        {ADDRE, INIT_SET, STORAGE_LONG, STORAGE_CHAR, STORAGE_BYTE, END_SET, INIT_SET, SEND, LONG, bytes[0], bytes[1], bytes[2], bytes[3], bytes[4],
        bytes[5], bytes[6], bytes[7], SEND, CHAR, 0x00, 0x20, SEND, BYTE, 0x19, END_SET, INIT_SET, SEND, BYTE, 0X00,
        SEND, BYTE, 0x00, SEND, BYTE, 0x00, END_SET, END_INSTRUCTION},
        {CALLC, ADDRESS_, SEND, BYTE, 0x00, END_INSTRUCTION},
        {DESTR, INIT_SET, STORAGE_LONG, STORAGE_CHAR, STORAGE_BYTE, END_SET, INIT_SET, SEND, BYTE, 0x00, SEND, BYTE, 0x00,
        SEND, BYTE, 0x00, END_SET, END_INSTRUCTION},
        {END},

        {END_PROGRAM}
    };

    data_c local[][50] = {
        {SYSOT, INIT_SET, STORAGE_LONG, STORAGE_CHAR, STORAGE_BYTE, END_SET, INIT_SET,
         SEND, BYTE, 0x00, SEND, BYTE, 0x00, SEND, BYTE, 0x00, END_SET, END_INSTRUCTION},
        {JUMPC, ADDRESS_, _GLOBAL, SEND, BYTE, 0x04, END_INSTRUCTION}
    };

    program(global, local, &System);

    return 0;
}
