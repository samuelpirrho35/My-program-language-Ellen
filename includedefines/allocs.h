#ifndef ALLOC_H
#define ALLOC_H

#include "../System/System.h"
#include "../includedefines/referenceTypes.h"
#include "../includeclass/objectsStruct.h"
#include <stdlib.h>

#define STRALLOC(SIZE) ((lchar*)malloc(SIZE * sizeof(lchar)))
#define ARRAYSTRALLOC(SIZE) ((ARRAYSTR)malloc(SIZE * sizeof(String)))
#define INT8ALLOC(SIZE) ((i8*)malloc(SIZE))
#define UINT8ALLOC(SIZE) ((u8*)malloc(SIZE))
#define INT16ALLOC(SIZE) ((i16*)malloc(SIZE * sizeof(i16)))
#define uINT16ALLOC(SIZE) ((u16*)malloc(SIZE * sizeof(u16)))
#define INT32ALLOC(SIZE) ((i32*)malloc(SIZE * sizeof(i32)))
#define UINT32ALLOC(SIZE) ((u32*)malloc(SIZE * sizeof(u32)))
#define INT64ALLOC(SIZE) ((i64*)malloc(SIZE * sizeof(i64)))
#define UINT64ALLOC(SIZE) ((u64*)malloc(SIZE * sizeof(u64)))
#define FLOAT32ALLOC(SIZE) ((f32Object*)malloc(SIZE * sizeof(f32Object)))
#define FLOAT64ALLOC(SIZE) ((f64Object*)malloc(SIZE * sizeof(f64Object)))
#define STROBJALLOC(SIZE) ((String*)malloc(SIZE * sizeof(String)))
#define CHARALLOC(SIZE) (charObject*)malloc(SIZE * sizeof(charObject))
#define LISTALLOC(SIZE) ((List*)malloc(SIZE * sizeof(List)))

#ifndef RUNTIMEVM
#define CACHEALLOC(SIZE) (((CachingData*)malloc(SIZE * sizeof(CachingData))))
#endif

#endif //ALLOC_H