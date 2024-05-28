#ifndef LIST_H
#define LIST_H

#include "../includeclass/objectsStruct.h"
#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"
#include "../utils/utils.h"

List* newList(u64 size);
void freeList(List *list);
i8 printList(List **list, mode exhibition, i64 start, i64 end);
i8 pushList(List **list, reference_types ref_ty, packageReceived pkrv, u64 size);

#endif //LIST_H