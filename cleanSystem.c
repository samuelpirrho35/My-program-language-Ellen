#include "System/System.h"
#include "VM/codeHex.h"
#include "includedefines/defines.h"
#include "includedefines/sizeDefined.h"
#include "includedefines/allocs.h"
#include "includelib/libIo.h"
#include <stdio.h>

u8 destroyObject(__System__ *System, u8 storagesUsing[], i64 address[], i64 index){
    for(; index >= 0; index--){
        switch(storagesUsing[index]){
            case STORAGE_LONG:
                free(System->Manager.Objects.st_i32[address[index]]);
                break;
            case STORAGE_INT:
                free(System->Manager.Objects.st_i32[address[index]]);
                break;
            case STORAGE_SHORT:
                free(System->Manager.Objects.st_i16[address[index]]);
                break;
            case STORAGE_CHAR:
                free(System->Manager.Objects.st_char[address[index]]);
                break;
            case STORAGE_BYTE:
                free(System->Manager.Objects.st_i8[address[index]]);
                break;
            default:
                return 1;
        }
    }

    return 0;
}

u8 ENDPROGRAM(__System__ *System){
    char index = 0;
    while(System->Manager.objectsUsing[index] && index < OBJECTsQTTY){
        switch(System->Manager.objectsUsing[index++]){
            case STORAGE_LONG:
                free(System->Manager.Objects.st_i64);
                break;
            case STORAGE_INT:
                free(System->Manager.Objects.st_i32);
                break;
            case STORAGE_SHORT:
                free(System->Manager.Objects.st_i16);
                break;
            case STORAGE_CHAR:
                free(System->Manager.Objects.st_char);
                break;
            case STORAGE_BYTE:
                free(System->Manager.Objects.st_i8);
                break;
            default:
                return 1;
        }
    }

    return 0;
}