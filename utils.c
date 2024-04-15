#include "utils/utils.h"

data_c* expandsToBytes(Long n, charsize_t *newSize){
    data_c *bytes;
    char sign = STARTBYTE_0X00;
    if(n < 0){
        sign = STARTBYTE_0X01;
        n *= -1;
    }

    char qttyDigits = 0;
    
    if(n >= 10){
        Long ncpy = n;
        while(ncpy){
            qttyDigits++;
            ncpy /= 10;
        }

        (*newSize) = qttyDigits + 2;
    }

    else{
        (*newSize) = 3;
        bytes = (data_c*)malloc(3);
        bytes[0] = sign;
        bytes[1] = n;
        bytes[2] = ENDBYTE;
        return bytes;
    }

    bytes = (data_c*)malloc(qttyDigits + 2);
    
    bytes[0] = sign;
    bytes[qttyDigits + 1] = ENDBYTE;
    
    do{
        bytes[qttyDigits--] = n % 10;
        n /= 10;
    }while(n);

    return bytes;
}

Long codeString(String str){
    Int code = 0;

    while(*str){
        Int characterUniCode = (u16)*str;
        code += characterUniCode;
        *str++;
    }

    return code;
}

Long keyWordIdentify(String str, String *KeyWordTable, u8 lengthTable){
    register Long strEqualKey_word = 0, lenStr = strsize(str);
    register Byte index = 0;
    while(index < lengthTable){
        register Byte lenKeyIndex = strsize(KeyWordTable[index]), countChar = 0;
        if(lenStr == lenKeyIndex){
            while(countChar < lenStr){
                if(str[countChar] != KeyWordTable[index][countChar]){
                    break;
                }
                else if((countChar == lenKeyIndex - 1) && str[countChar] == KeyWordTable[index][countChar]){
                    strEqualKey_word = codeString(str);
                }
                countChar++;
            }
        }
        if(strEqualKey_word){
            break;
        }
        index++;
    }

    return strEqualKey_word;
}

Byte checkTokenValid(lchar actCharacter, String nextCharacters){
    while(*nextCharacters){
        if(actCharacter == *nextCharacters){
            return 1;
        }
        nextCharacters++;
    }

    return 0;
}

Int HashCode(String str, float Multiplier){
    Long code = 0;

    while(*str){
        u16 characterUniCode = *str;
        code += characterUniCode;
        *str++;
    }

    return code % (Int)(0x64 * Multiplier);
}

u8 initializeListCache(CachingData ***Cache, Int Address[], u8 *TypeStructureCache)
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

u8 AddListCache
(CachingData ***Cache, Int Address[], String IdentifierName,
reference_types TypeObject, Long Calls, String Value, u8 *TypeStructureCache)
{

    CachingData **CopyCache = *Cache;
    CacheStructure *listCache = CopyCache[Address[0]][Address[1]].TypeCache.ListCache;

    if(listCache->Extention == listCache->Capacity - 1)
    {
        listCache->Capacity += listCache->Capacity / 2;
        listCache = realloc(listCache, listCache->Capacity * sizeof(CacheStructure));
        if(listCache == NULL){
            return 1;
        }
        CopyCache[Address[0]][Address[1]].TypeCache.ListCache = listCache;
    }

    Int extention = listCache->Extention;
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
Long Calls, String Value)
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