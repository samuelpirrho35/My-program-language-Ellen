#include "System/System.h"
#include "VM/codeHex.h"
#include "includedefines/defines.h"
#include "includedefines/sizeDefined.h"
#include "includedefines/allocs.h"
#include "includelib/objectsFunctions.h"
#include "includelib/libIo.h"
#include <stdio.h>

#ifndef RUNTIMEVM
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

u8 initializeStorages(__Objects__ *objects, u8 storagesUsing[], i64 sizeForEachSt[], i64 index){
    for(; index >= 0; index--){
        switch(storagesUsing[index]){
            case STORAGE_LONG:
                (*objects).st_i64 = (storage_i64Ty)malloc(sizeForEachSt[index] * sizeof(i64Object*));
                break;
            case STORAGE_INT:
                (*objects).st_i32 = (storage_i32Ty)malloc(sizeForEachSt[index] * sizeof(i32Object*));
                break;
            case STORAGE_SHORT:
                (*objects).st_i16 = (storage_i16Ty)malloc(sizeForEachSt[index] * sizeof(i16Object*));
                break;
            case STORAGE_CHAR:
                (*objects).st_char = (storage_charTy)malloc(sizeForEachSt[index] * sizeof(charObject*));
                break;
            case STORAGE_BYTE:
                (*objects).st_i8 = (storage_i8Ty)malloc(sizeForEachSt[index] * sizeof(i8Object*));
                break;
            default:
                return 1;
        }
    }

    return 0;
}

u8 allocStoragesUsing(__Objects__ *objects, u8 objectsUsing, i64 index, i64 dataSize){
    switch(objectsUsing){
        case STORAGE_LONG:
            objects->st_i64[index] = (i64Object*)malloc(sizeof(i64Object));
            break;
        
        case STORAGE_INT:
            objects->st_i32[index] = (i32Object*)malloc(sizeof(i32Object));
            break;
        
        case STORAGE_SHORT:
            objects->st_i16[index] = (i16Object*)malloc(sizeof(i16Object));
            break;
        
        case STORAGE_CHAR:
            objects->st_char[index] = (charObject*)malloc(sizeof(charObject));
            break;
        
        case STORAGE_BYTE:
            objects->st_i8[index] = (i8Object*)malloc(sizeof(i8Object));
            break;

        case STORAGE_STRING:
            objects->st_string[index] = STRALLOC(dataSize);
            break;
        
        default:
            return 1;
    }

    return 0;
}

u8 setValues(__Objects__ *objects, u8 objectsUsing[], List *values, i64 address[]){
    i64 index = 0, dataSize = 0;
    for(; index < values->GN_Fields.extention; index++){
        //if(objectsUsing[index] >= STORAGE_STRING && objectsUsing[index] <= STOREGE_STRUCT){
            
        //}

        allocStoragesUsing(objects, objectsUsing[index], address[index], dataSize);
        switch(objectsUsing[index]){
            case STORAGE_LONG:
                objects->st_i64[address[index]]->i64Ty = values[index].types.primitiveTys.intTys.i64_ty;
                break;
            
            case STORAGE_INT:
                objects->st_i32[address[index]]->i32Ty = values[index].types.primitiveTys.intTys.i32_ty;
                break;
            
            case STORAGE_SHORT:
                objects->st_i16[address[index]]->i16Ty = values[index].types.primitiveTys.intTys.i16_ty;
                break;
            
            case STORAGE_CHAR:
                objects->st_char[address[index]]->charTy = values[index].types.primitiveTys.intTys.char_ty;
                break;
            
            case STORAGE_BYTE:
                objects->st_i8[address[index]]->i8Ty = values[index].types.primitiveTys.intTys.i8_ty;
                break;
            
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
    System.RD = &rd;
#ifndef RUNTIMEVM
    System->Manager.SizeCacheScopes = INITMANAGERCACHE;
    System->Manager.Cache = initializeCache(&(System.Manager));
    System.Manager.FileManager.bytecode = UINT8ALLOC(BUFFER_SIZE);
    System->Manager.FileManager.FileSourseCode = STRALLOC(BUFFER_SIZE);
#endif

    return System;
}