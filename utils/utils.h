#ifndef UTILS_H
#define UTILS_H

#include "../System/System.h"
#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"
#include "../includedefines/allocs.h"
#include "../includelib/libString.h"

u8* expandsToi8s(i64 n, charu64 *newSize);


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

#endif //UTILS_H