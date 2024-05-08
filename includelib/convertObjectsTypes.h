#ifndef CONVERTOBJECTSTYPES_H
#define CONVERTOBJECTSTYPES_H

#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"

String convert_intArrayToStr(u8 *intArray, i64 sizeArray);
lchar* inttstr(i64 integer);
i64 convert_StringToInteger(String str);

#endif //CONVERTOBJECTSTYPES_H