#ifndef UTILS_H
#define UTILS_H

#include "../System/System.h"
#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"
#include "../includedefines/allocs.h"
#include "../includelib/libString.h"

u8* expandsToi8s(i64 n, charsize_t *newSize);

u32 codeString(String str);
u8 checkTokenValid(lchar actCharacter, String nextCharacters);

#ifndef RUNTIMEVM
CachingData CreateCacheData(String IdentifierName, reference_types TypeObject, i64 Calls, String Value);
u8 initializeListCache(CachingData ***Cache, i32 Address[], u8 *TypeStructureCache);
i8 AddListCache
(CachingData ***Cache, i32 Address[], String IdentifierName,
reference_types TypeObject, i64 Calls, String Value, u8 *TypeStructureCache);


#else
typedef struct{
    char pack_ty;
    union{
        u8 *pack_bytes;
        u16 *pack_doublebytes;
        i64 pack_integer;
        char character;
        f64 pack_f64;
    }package_ty;
}packageReceived;
#endif

#endif //UTILS_H