#include "System/System.h"
#include "VM/codeHex.h"
#include "includedefines/defines.h"
#include "includedefines/sizeDefined.h"
#include "includedefines/allocs.h"
#include "includelib/libIo.h"
#include <stdio.h>

u8 destroyObject(__Objects__ *objects, data_c storagesUsing[], Long address[], Long index){
    for(; index >= 0; index--){
        switch(storagesUsing[index]){
            case STORAGE_LONG:
                free(objects->st_long[address[index]]);
                break;
            case STORAGE_INT:
                free(objects->st_int[address[index]]);
                break;
            case STORAGE_SHORT:
                free(objects->st_short[address[index]]);
                break;
            case STORAGE_CHAR:
                free(objects->st_char[address[index]]);
                break;
            case STORAGE_BYTE:
                free(objects->st_byte[address[index]]);
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
                free(System->Manager.Objects.st_long);
                break;
            case STORAGE_INT:
                free(System->Manager.Objects.st_int);
                break;
            case STORAGE_SHORT:
                free(System->Manager.Objects.st_short);
                break;
            case STORAGE_CHAR:
                free(System->Manager.Objects.st_char);
                break;
            case STORAGE_BYTE:
                free(System->Manager.Objects.st_byte);
                break;
            default:
                return 1;
        }
    }

    free(System);

    return 0;
}