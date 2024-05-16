#ifndef ARRAY_H
#define ARRAY_H

#include "../includeclass/objectsStruct.h"
#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"

void initializeDataArray(GenericArray *Generic, size_ty init, size_ty end, reference_types ref_dataTy);
GenericArray* newArray(size_ty capacity, size_ty size, reference_types ref_dataTy);
void resizeArray(size_ty newCapacity, size_ty size, GenericArray *array, reference_types ref_dataTy);

#endif