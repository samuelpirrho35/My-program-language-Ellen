#ifndef OBJECTSFUNCTIONS_H
#define OBJECTSFUNCTIONS_H

#include "../includeclass/objectsStruct.h"
#include "../includedefines/defines.h"
#include "../includedefines/inttypes.h"
#include "../utils/utils.h"

/*BigintObject* create_Int_Dinamic_Object(String parseToInt);
void print_BigintObject(BigintObject *int_Object);
void free_BigintObject(BigintObject *int_Object);*/

//Identifier_Int_Static_Object* create_Int_Static_Object(String strData, reference_types IntegerType);

//StringTypeObject* create_String_Object(String data, u64 length_Data);

/*BigfloatObject* create_Float_Dinamic_Object(String DataFloat, u64 float_Length);
void print_Float_Dinamic_Object(BigfloatObject *FloatObject);
void free_Float_Dinamic_Object(BigfloatObject *float_Object);*/

List* newList(u64 size);
void freeList(List *list);
Byte printList(List **list, mode exhibition, Long start, Long end);
unsigned char pushList(List **list, reference_types ref_ty, packageReceived pkrv, size_ty size);

#endif //OBJECTSFUNCTIONS_H