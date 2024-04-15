#include "System/System.h"
#include "VM/codeHex.h"
#include "includedefines/defines.h"
#include "includedefines/sizeDefined.h"
#include "includedefines/allocs.h"
//#include "includelib/objectsFunctions.h"
#include "includelib/libIo.h"
#include <stdio.h>

#ifndef JUSTVIRTUALMACHINE
CachingData** initializeCache(__Manager__ *manager){
    manager->Cache = (CachingData**)malloc(INITMANAGERCACHE * sizeof(CachingData*));
    size_ty i = 0;
    for(; i < INITMANAGERCACHE; i++){
        manager->Cache[i] = (CachingData*)malloc(INITSIZECACHE * sizeof(CachingData));
        manager->Cache[i]->TypeCache.Cache.Extention = 0;
        manager->Cache[i]->TypeCache.Cache.Capacity = INITSIZECACHE;
    }
    return manager->Cache;
}
#endif

u8 initializeStorages(__Objects__ *objects, data_c storagesUsing[], Long sizeForEachSt[], Long index){
    for(; index >= 0; index--){
        switch(storagesUsing[index]){
            case STORAGE_LONG:
                (*objects).st_long = (storage_longTy)malloc(sizeForEachSt[index] * sizeof(longObject*));
                break;
            case STORAGE_INT:
                (*objects).st_int = (storage_intTy)malloc(sizeForEachSt[index] * sizeof(intObject*));
                break;
            case STORAGE_SHORT:
                (*objects).st_short = (shortObject**)malloc(sizeForEachSt[index] * sizeof(shortObject*));
                break;
            case STORAGE_CHAR:
                (*objects).st_char = (charObject**)malloc(sizeForEachSt[index] * sizeof(charObject*));
                break;
            case STORAGE_BYTE:
                (*objects).st_byte = (byteObject**)malloc(sizeForEachSt[index] * sizeof(byteObject*));
                break;
            default:
                return 1;
        }
    }

    return 0;
}

u8 setValues(__Objects__ *objects, data_c objectsUsing[], Long values[], Long address[], Long index){
    for(; index >= 0; index--){
        switch(objectsUsing[index]){
            case STORAGE_LONG:{
                longObject *longObj = (longObject*)malloc(sizeof(longObject));
                longObj->longTy = values[index];
                (*objects).st_long[address[index]] = longObj;
                break;
            }
            case STORAGE_INT:{
                intObject *intObj = (intObject*)malloc(sizeof(intObject));
                intObj->intTy = values[index];
                (*objects).st_int[address[index]] = intObj;
                break;
            }
            case STORAGE_SHORT:{
                shortObject *shortObj = (shortObject*)malloc(sizeof(shortObject));
                shortObj->shortTy = values[index];
                (*objects).st_short[address[index]] = shortObj;
                break;
            }
            case STORAGE_CHAR:{
                charObject *charObj = (charObject*)malloc(sizeof(charObject));
                charObj->charTy = values[index];
                (*objects).st_char[address[index]] = charObj;
                break;
            }
            case STORAGE_BYTE:{
                byteObject *byteObj = (byteObject*)malloc(sizeof(byteObject));
                byteObj->byteTy = values[index];
                (*objects).st_byte[address[index]] = byteObj;
                break;
            }
            default:
                return 1;
        }
    }

    return 0;
}

__System__ __init__(){
    __System__ System;
    System.status = WORKING;
    System.version = L"0.6.7";
    System.WRT = &wrt;
    System.GETByte = &getByte;
    System.RD = &rd;

    System.Manager.IdentifiersTy.DinamicsSizeExtention.MaxSizeExtentionIntDinamic = MAX_SIZEEXTENTION_Int_Float_DINAMIC;
    System.Manager.IdentifiersTy.DinamicsSizeExtention.MaxSizeExtentionFloatDinamic = MAX_SIZEEXTENTION_Int_Float_DINAMIC;
    System.Manager.FileManager.bytecode = uByteALLOC(BUFFER_SIZE);
#ifndef JUSTVIRTUALMACHINE
    /*System.Manager.Cache = CACHEALLOC(INITSIZECACHE);
    System.Manager.Cache->Extention = INITSIZECACHE;*/
    System.Manager.SizeCacheScopes = INITMANAGERCACHE;
    System.Manager.Cache = initializeCache(&(System.Manager));
    System.Manager.FileManager.FileSourseCode = STRALLOC(BUFFER_SIZE);
#endif

    return System;
}