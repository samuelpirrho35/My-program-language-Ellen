#include "../System/System.h"
#include "../includedefines/inttypes.h"
#include "../includeclass/objectsStruct.h"
#include <stdlib.h>

#define STRALLOC(SIZE) ((lchar*)malloc(SIZE * sizeof(lchar)))
#define ARRAYSTRALLOC(SIZE) ((ARRAYSTR)malloc(SIZE * sizeof(String)))
#define ByteALLOC(SIZE) ((Byte*)malloc(SIZE))
#define uByteALLOC(SIZE) ((u8*)malloc(SIZE))
#define TWOByteALLOC(SIZE) ((Short*)malloc(SIZE * sizeof(Short)))
#define uTWOByteALLOC(SIZE) ((u16*)malloc(SIZE * sizeof(u16)))
#define FOURByteALLOC(SIZE) ((Int*)malloc(SIZE * sizeof(Int)))
#define uFOURByteALLOC(SIZE) ((u32*)malloc(SIZE * sizeof(u32)))
#define EIGHTByteALLOC(SIZE) ((Long*)malloc(SIZE * sizeof(Long)))
#define uEIGHTByteALLOC(SIZE) ((u64*)malloc(SIZE * sizeof(u64)))
#define DIntALLOC(SIZE) ((BigintObject*)malloc(SIZE * sizeof(BigintObject)))
#define IntALLOC(SIZE) ((BigintObject*)malloc(SIZE * sizeof(BigintObject)))
#define DFloatALLOC(SIZE) ((BigfloatObject*)malloc(SIZE * sizeof(BigfloatObject)))
#define FloatALLOC(SIZE) ((floatObject*)malloc(SIZE * sizeof(floatObject)))
#define STROBJALLOC(SIZE) ((String*)malloc(SIZE * sizeof(String)))
#define CHARALLOC(SIZE) (charObject*)malloc(SIZE * sizeof(charObject))
#define LISTALLOC(SIZE) ((List*)malloc(SIZE * sizeof(List)))
#define OBJECTGLOBALALLOC(SIZE) ((Objects**)malloc(SIZE * sizeof(Objects*)))
#define CACHEALLOC(SIZE) (((CachingData*)malloc(SIZE * sizeof(CachingData))))