#ifndef CONVERTOBJECTSTYPES_H
#define CONVERTOBJECTSTYPES_H

#include "../includedefines/defines.h"
#include "../includedefines/inttypes.h"

String convert_intArrayToStr(u8 *intArray, Long sizeArray);
lchar* inttstr(Long Integer);
Long convert_StringToInteger(String str);

#endif //CONVERTOBJECTSTYPES_H