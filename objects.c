#include "System/System.h"
#include "System/initSystem.h"
#include "includedefines/referenceTypes.h"
#include "includedefines/defines.h"
#include "includedefines/allocs.h"
//#include "includelib/basicMath.h"
//#include "includelib/objectsFunctions.h"
//#include "includelib/libString.h"
#include "includeclass/objectsStruct.h"
#include "includeEnumerator/typeObjects.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

//------------------------------------

int main(){
    __System__ System = __init__();
    
    System.Manager.Cache[0][0] = CreateCacheData(L"name", __String__, 2, L"Hello, World!");
    System.Manager.Cache[0][1] = CreateCacheData(L"number", __i64__, 3, L"35");
    System.Manager.Cache[0][2] = CreateCacheData(L"number2", __i64__, 3, L"35");
    System.Manager.Cache[0][3] = CreateCacheData(L"number2", __f32__, 3, L"3.14");

    initializeListCache(&(System.Manager.Cache), (i32[]){0, 2}, &(System.Manager.Cache[0][2].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 2}, L"name", __String__, 1, L"Ellen", &(System.Manager.Cache[0][2].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 2}, L"surname", __String__, 1, L"Lohayne", &(System.Manager.Cache[0][2].TypeStructureCache));

    initializeListCache(&(System.Manager.Cache), (i32[]){0, 4}, &(System.Manager.Cache[0][4].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 4}, L"n1", __i32__, 1, L"5", &(System.Manager.Cache[0][4].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 4}, L"n2", __i32__, 1, L"25042006", &(System.Manager.Cache[0][4].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 4}, L"str", __String__, 1, L"Ellen Lohayne", &(System.Manager.Cache[0][4].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 4}, L"pi", __f32__, 1, L"3.1415", &(System.Manager.Cache[0][4].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 4}, L"i64N", __i64__, 1, L"98239832", &(System.Manager.Cache[0][4].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 4}, L"i8", __i8__, 1, L"25", &(System.Manager.Cache[0][4].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 4}, L"s", __i16__, 1, L"523", &(System.Manager.Cache[0][4].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 4}, L"number", __i32__, 1, L"35", &(System.Manager.Cache[0][4].TypeStructureCache));

    initializeListCache(&(System.Manager.Cache), (i32[]){0, 0}, &(System.Manager.Cache[0][0].TypeStructureCache));
    AddListCache(&(System.Manager.Cache), (i32[]){0, 0}, L"BlackHole", __String__, 1, L"Ton-618", &(System.Manager.Cache[0][0].TypeStructureCache));

    i8 counter;
    for(counter = 0; counter < 5; counter++){
        if(System.Manager.Cache[0][counter].TypeStructureCache == HASHCACHE){
            printf("HashCache[%d]:\n", counter);
            printf("\tType: %d\n", System.Manager.Cache[0][counter].TypeCache.Cache.TypeObject);
            wprintf(L"\tName: %ls\n", System.Manager.Cache[0][counter].TypeCache.Cache.IdentifierName);
            wprintf(L"\tValue: %ls\n\n", System.Manager.Cache[0][counter].TypeCache.Cache.Value);
        }
        else if(System.Manager.Cache[0][counter].TypeStructureCache == LISTCACHE){
            printf("ListCache:\n");
            i8 i;
            for(i = 0; i < System.Manager.Cache[0][counter].TypeCache.ListCache->Extention; i++){
                printf("\tList[%d]:\n", i);
                printf("\t\tType: %d\n", System.Manager.Cache[0][counter].TypeCache.ListCache[i].TypeObject);
                wprintf(L"\t\tName: %ls\n", System.Manager.Cache[0][counter].TypeCache.ListCache[i].IdentifierName);
                wprintf(L"\t\tValue: %ls\n\n", System.Manager.Cache[0][counter].TypeCache.ListCache[i].Value);
            }
        }
    }

    return 0;
}