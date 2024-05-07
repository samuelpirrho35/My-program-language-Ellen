#ifndef MEMORY_H
#define MEMORY_H

#include "../includedefines/allocs.h"
#include "../includedefines/referenceTypes.h"

void *memcopy(void *dest, void *src, u64 start, u64 size);
void* memcpyint(void *desty, u8 *src, charsize_t size);
u8* byteParser(void *any, reference_types ref_anyTy, size_ty qtty);
i64 getLengthSubDataOfBuffer(u8 *buffer, u64 *init);
void* initializeBuffer(void *buffer, size_ty start, size_ty end);

#endif //MEMORY_H