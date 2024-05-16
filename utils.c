#include "utils/utils.h"

u8* expandsToi8s(i64 n, charsize_t *newSize){
    u8 *bytes;
    char sign = STARTBYTE_0X0E;
    if(n < 0){
        sign = STARTBYTE_0X0F;
        n *= -1;
    }

    char qttyDigits = 0;
    
    if(n >= 10){
        i64 ncpy = n;
        while(ncpy){
            qttyDigits++;
            ncpy /= 10;
        }

        (*newSize) = qttyDigits + 2;
    }

    else{
        (*newSize) = 3;
        bytes = (u8*)malloc(3);
        bytes[0] = sign;
        bytes[1] = n;
        bytes[2] = ENDBYTE;
        return bytes;
    }

    bytes = (u8*)malloc(qttyDigits + 2);
    
    bytes[0] = sign;
    bytes[qttyDigits + 1] = ENDBYTE;
    
    do{
        bytes[qttyDigits--] = n % 10;
        n /= 10;
    }while(n);

    return bytes;
}

u32 codeString(String str){
    u32 code = 0;
    lchar lastchar = 0;

    while(*str){
        code += ((lchar)*str << 1) + (lastchar - 47);
        lastchar = *str;
        str++;
    }

    return code;
}

u8 checkTokenValid(lchar actCharacter, String nextCharacters){
    while(*nextCharacters){
        if(actCharacter == *nextCharacters){
            return 1;
        }
        nextCharacters++;
    }

    return 0;
}

i32 HashCode(String str, f32 Multiplier){
    i64 code = 0;

    while(*str){
        u16 characterUniCode = *str;
        code += characterUniCode;
        str++;
    }

    return code % (i32)(0x64 * Multiplier);
}

#ifndef RUNTIMEVM
u8 initializeListCache(CachingData ***Cache, i32 Address[], u8 *TypeStructureCache)
{
    CachingData **CopyCache = *Cache;
    if(*TypeStructureCache != LISTCACHE){
        if(*TypeStructureCache == HASHCACHE){
            CacheStructure GetCache;
            GetCache.TypeObject = CopyCache[Address[0]][Address[1]].TypeCache.Cache.TypeObject;
            GetCache.IdentifierName = strcopy(CopyCache[Address[0]][Address[1]].TypeCache.Cache.IdentifierName);
            GetCache.Calls = CopyCache[Address[0]][Address[1]].TypeCache.Cache.Calls;
            GetCache.State = CopyCache[Address[0]][Address[1]].TypeCache.Cache.State;
            if(GetCache.State == DEFINED){
                GetCache.Value = strcopy(CopyCache[Address[0]][Address[1]].TypeCache.Cache.Value);
            }

            CopyCache[Address[0]][Address[1]].TypeCache.ListCache = (CacheStructure*)
            malloc(INITSIZELISTCACHE * sizeof(CacheStructure));
            if(CopyCache[Address[0]][Address[1]].TypeCache.ListCache == NULL){
                return 1;
            }

            CopyCache[Address[0]][Address[1]].TypeCache.ListCache->Capacity = INITSIZELISTCACHE;
            
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache[0] = GetCache;
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache->Extention = 1;
        }

        else{
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache = (CacheStructure*)
            malloc(INITSIZELISTCACHE * sizeof(CacheStructure));
            if(CopyCache[Address[0]][Address[1]].TypeCache.ListCache == NULL){
                return 1;
            }
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache->Extention = 0;
            CopyCache[Address[0]][Address[1]].TypeCache.ListCache->Capacity = INITSIZELISTCACHE;
        }

        (*TypeStructureCache) = LISTCACHE;
    }
    return 0;
}

i8 AddListCache
(CachingData ***Cache, i32 Address[], String IdentifierName,
reference_types TypeObject, i64 Calls, String Value, u8 *TypeStructureCache)
{

    CachingData **CopyCache = *Cache;
    CacheStructure *listCache = CopyCache[Address[0]][Address[1]].TypeCache.ListCache;

    if(listCache->Extention == listCache->Capacity - 1)
    {
        listCache->Capacity += listCache->Capacity / 2;
        CacheStructure *newlistCache = realloc(listCache, listCache->Capacity * sizeof(CacheStructure));
        if(newlistCache == NULL)
            return -5;
        if(listCache == NULL){
            return 1;
        }
        CopyCache[Address[0]][Address[1]].TypeCache.ListCache = listCache;
    }

    i32 extention = listCache->Extention;
    listCache[extention].IdentifierName = strcopy(IdentifierName);
    listCache[extention].TypeObject = TypeObject;
    listCache[extention].Calls = Calls;
    
    if(Value == NULL){
        listCache[extention].State = NONE;
    }
    else{
        listCache[extention].State = DEFINED;
        listCache[extention].Value = strcopy(Value);
    }

    listCache->Extention++;

    return 0;
}


CachingData CreateCacheData
(String IdentifierName, reference_types TypeObject,
i64 Calls, String Value)
{
    CachingData newCache;
    newCache.TypeStructureCache = HASHCACHE;
    newCache.TypeCache.Cache.IdentifierName = strcopy(IdentifierName);
    newCache.TypeCache.Cache.TypeObject = TypeObject;
    newCache.TypeCache.Cache.Calls = Calls;
    if(Value == NULL){
        newCache.TypeCache.Cache.State = NONE;
    }
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
#endif