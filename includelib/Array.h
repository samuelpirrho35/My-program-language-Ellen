#ifndef ARRAY_H
#define ARRAY_H

#include "../includeclass/objectsStruct.h"
#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"

void initializeDataArray(GenericArray *Generic, u64 init, u64 end, reference_types ref_dataTy);
GenericArray* newArray(u64 capacity, u64 size, reference_types ref_dataTy);
void resizeArray(u64 newCapacity, u64 size, GenericArray *array, reference_types ref_dataTy);

#endif