#ifndef MEMORY_H
#define MEMORY_H

#include "../includedefines/allocs.h"
#include "../includedefines/inttypes.h"

void *memcopy(void *dest, void *src, size_ty start, size_ty size);
void* memcpyint(void *desty, data_c *src, charsize_t size);
data_c* byteParser(void *any, reference_types ref_anyTy, size_ty qtty);
void* initializeBuffer(void *buffer, size_ty start, size_ty end);

#endif //MEMORY_H