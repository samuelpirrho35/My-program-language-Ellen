#ifndef UTILS_H
#define UTILS_H

#include "../System/System.h"
#include "../includedefines/defines.h"
#include "../includedefines/inttypes.h"
#include "../includedefines/allocs.h"
#include "../includelib/libString.h"

data_c* expandsToBytes(Long n, charsize_t *newSize);

Long codeString(String str);
Long keyWordIdentify(String str, String *KeyWordTable, u8 lengthTable);
Byte checkTokenValid(lchar actCharacter, String nextCharacters);
CachingData CreateCacheData(String IdentifierName, reference_types TypeObject, Long Calls, String Value);

u8 initializeListCache(CachingData ***Cache, Int Address[], u8 *TypeStructureCache);
u8 AddListCache
(CachingData ***Cache, Int Address[], String IdentifierName,
reference_types TypeObject, Long Calls, String Value, u8 *TypeStructureCache);

typedef struct{
    char pack_ty;
    union{
        data_c *pack_bytes;
        data_s *pack_doubleBytes;
        Long pack_integer;
        char character;
        double pack_float;
        Long pack_anyInteger;
    }package_ty;
}packageReceived;

#endif //UTILS_H