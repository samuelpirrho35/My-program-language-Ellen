#ifndef MEMORY_H
#define MEMORY_H

#include "../includedefines/allocs.h"
#include "../includedefines/referenceTypes.h"

void *memcopy(void *dest, void *src, u64 start, u64 size);
void* memcpyint(void *desty, u8 *src, charu64 size);
void* clearBuffer(void *buffer, u64 start, u64 end);
u8*   byteParser(void *any, reference_types ref_anyTy, u64 qtty);
u64   getLengthSubDataOfBuffer(u8 *buffer, u64 *init);

#endif //MEMORY_H