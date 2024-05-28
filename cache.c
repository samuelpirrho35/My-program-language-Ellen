#include "System/System.h"
#include "System/initSystem.h"
#include "includedefines/referenceTypes.h"
#include "includedefines/defines.h"
#include "includedefines/allocs.h"
#include "includeclass/objectsStruct.h"
#include "includeEnumerator/typeObjects.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

u8 initializeListCache(CachingData ***Cache, i32 Address[],
u8 *TypeStructureCache)
{
    CachingData **CopyCache = *Cache;
    if(*TypeStructureCache != LISTCACHE){
        if(*TypeStructureCache == CACHE){
            CacheStructure GetCache;
            GetCache.TypeObject = CopyCache[Address[0]][Address[1]].TypeCache.Cache.TypeObject;
            GetCache.IdentifierName =
            strcopy(CopyCache[Address[0]][Address[1]].TypeCache.Cache.IdentifierName);

            GetCache.Calls = CopyCache[Address[0]][Address[1]].TypeCache.Cache.Calls;
            GetCache.State = CopyCache[Address[0]][Address[1]].TypeCache.Cache.State;

            if(GetCache.State == DEFINED)
                GetCache.Value = strcopy(CopyCache[Address[0]][Address[1]].TypeCache.Cache.Value);

            CopyCache[Address[0]][Address[1]].TypeCache.ListCache = (CacheStructure*)
            malloc(INITSIZELISTCACHE * sizeof(CacheStructure));

            if(CopyCache[Address[0]][Address[1]].TypeCache.ListCache == NULL)
                return 1;

            CopyCache[Address[0]][Address[1]].TypeCache.ListCache->Capacity = INITSIZELISTCACHE;
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache[0] = GetCache;
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache->Extention = 1;
        }

        else{
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache = (CacheStructure*)
            malloc(INITSIZELISTCACHE * sizeof(CacheStructure));

            if(CopyCache[Address[0]][Address[1]].TypeCache.ListCache == NULL)
                return 1;

            CopyCache[Address[0]][Address[1]].TypeCache.ListCache->Extention = 0;
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache->Capacity = INITSIZELISTCACHE;
        }

        (*TypeStructureCache) = LISTCACHE;
    }

    return 0;
}

i8 AddListCache
(CachingData ***Cache, u32 Address[], String IdentifierName,
reference_types TypeObject, u64 Calls, String Value, u8 *TypeStructureCache)
{

    //CachingData **CopyCache = *Cache;
    CacheStructure *listCache = (*Cache)[Address[0]][Address[1]].TypeCache.ListCache;

    if(listCache->Extention == listCache->Capacity - 1)
    {
        listCache->Capacity += listCache->Capacity >> 1;
        CacheStructure *newlistCache = realloc(listCache, listCache->Capacity * sizeof(CacheStructure));

        if(newlistCache == NULL)
            return -5;

        (*Cache)[Address[0]][Address[1]].TypeCache.ListCache = newlistCache;
    }

    u32 extention = listCache->Extention;
    listCache[extention].IdentifierName = strcopy(IdentifierName);
    listCache[extention].TypeObject = TypeObject;
    listCache[extention].Calls = Calls;
    
    if(Value == NULL)
        listCache[extention].State = NONE;

    else{
        listCache[extention].State = DEFINED;
        listCache[extention].Value = strcopy(Value);
    }

    listCache->Extention++;

    return 0;
}


CachingData CreateCacheData
(String IdentifierName, reference_types TypeObject,
u64 Calls, String Value)
{
    CachingData newCache;
    newCache.TypeStructureCache = CACHE;
    newCache.TypeCache.Cache.IdentifierName = strcopy(IdentifierName);
    newCache.TypeCache.Cache.TypeObject = TypeObject;
    newCache.TypeCache.Cache.Calls = Calls;

    if(Value == NULL)
        newCache.TypeCache.Cache.State = NONE;

    else{
        newCache.TypeCache.Cache.State = DEFINED;
        newCache.TypeCache.Cache.Value = strcopy(Value);
    }

    return newCache;
}

/*

cache:
    cache[0]:
        *cache = {obj,...,...,obj,obj,...,...,...,obj};
                                                  obj,
                                                  obj,
                                                  obj
    cache[1]:
        *cache = {...,...,...,...,obj,...,obj};
    cache[2]:
        *cache = {...,obj};

*/

//------------------------------------

// int main(){
//     __System__ System = __init__();
    
//     System.Manager.Cache[0][0] = CreateCacheData(L"name", __String__, 2, L"Hello, World!");
//     System.Manager.Cache[0][1] = CreateCacheData(L"number", __i64__, 3, L"35");
//     System.Manager.Cache[0][2] = CreateCacheData(L"number2", __i64__, 3, L"35");
//     System.Manager.Cache[0][3] = CreateCacheData(L"number2", __f32__, 3, L"3.14");

//     initializeListCache(&(System.Manager.Cache), (u32[]){0, 2}, &(System.Manager.Cache[0][2].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 2}, L"name", __String__, 1, L"Ellen", &(System.Manager.Cache[0][2].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 2}, L"surname", __String__, 1, L"Lohayne", &(System.Manager.Cache[0][2].TypeStructureCache));

//     initializeListCache(&(System.Manager.Cache), (u32[]){0, 4}, &(System.Manager.Cache[0][4].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 4}, L"n1", __i32__, 1, L"5", &(System.Manager.Cache[0][4].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 4}, L"n2", __i32__, 1, L"25042006", &(System.Manager.Cache[0][4].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 4}, L"str", __String__, 1, L"Ellen Lohayne", &(System.Manager.Cache[0][4].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 4}, L"pi", __f32__, 1, L"3.1415", &(System.Manager.Cache[0][4].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 4}, L"i64N", __i64__, 1, L"98239832", &(System.Manager.Cache[0][4].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 4}, L"i8", __i8__, 1, L"25", &(System.Manager.Cache[0][4].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 4}, L"s", __i16__, 1, L"523", &(System.Manager.Cache[0][4].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 4}, L"number", __i32__, 1, L"35", &(System.Manager.Cache[0][4].TypeStructureCache));

//     initializeListCache(&(System.Manager.Cache), (u32[]){0, 0}, &(System.Manager.Cache[0][0].TypeStructureCache));
//     AddListCache(&(System.Manager.Cache), (u32[]){0, 0}, L"BlackHole", __String__, 1, L"Ton-618", &(System.Manager.Cache[0][0].TypeStructureCache));

//     i8 counter;
//     for(counter = 0; counter < 5; counter++){
//         if(System.Manager.Cache[0][counter].TypeStructureCache == CACHE){
//             printf("CACHE[%d]:\n", counter);
//             printf("\tType: %d\n", System.Manager.Cache[0][counter].TypeCache.Cache.TypeObject);
//             wprintf(L"\tValue: %ls\n\n", System.Manager.Cache[0][counter].TypeCache.Cache.Value);
//         }
//         else if(System.Manager.Cache[0][counter].TypeStructureCache == LISTCACHE){
//             printf("ListCache:\n");
//             i8 i;
//             for(i = 0; i < System.Manager.Cache[0][counter].TypeCache.ListCache->Extention; i++){
//                 printf("\tList[%d]:\n", i);
//                 printf("\t\tType: %d\n", System.Manager.Cache[0][counter].TypeCache.ListCache[i].TypeObject);
//                 wprintf(L"\t\tValue: %ls\n\n", System.Manager.Cache[0][counter].TypeCache.ListCache[i].Value);
//             }
//         }
//     }

//     return 0;
// }