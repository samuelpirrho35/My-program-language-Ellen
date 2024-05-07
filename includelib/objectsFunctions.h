#ifndef OBJECTSFUNCTIONS_H
#define OBJECTSFUNCTIONS_H

#include "../includeclass/objectsStruct.h"
#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"
#include "../utils/utils.h"

//-------------<Functions for List Object>-----------------
List* newList(u64 size);
void freeList(List *list);
i8 printList(List **list, mode exhibition, i64 start, i64 end);
i8 pushList(List **list, reference_types ref_ty, packageReceived pkrv, size_ty size);

//-------------<Functions for Array Object>-----------------
void initializeDataArray(GenericArray *Generic, size_ty init, size_ty end, reference_types ref_dataTy);
GenericArray* newArray(size_ty capacity, size_ty size, reference_types ref_dataTy);
void resizeArray(size_ty newCapacity, size_ty size, GenericArray *array, reference_types ref_dataTy);

//-------------<Functions for Ouroboros Object>-----------------
Ouroboros* newOuroboros();
Ouroboros* initOuroboros(u8 data[]);
void freeOuroboros(Ouroboros *ouroboros);

#endif //OBJECTSFUNCTIONS_H