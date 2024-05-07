#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"
#include "../includeclass/objectsStruct.h"

#ifndef libIo_H
#define libIo_H

i8 wrt(List **objects);
#ifdef WINDOWS
unsigned char WindowsWrt(lchar *StringObject, lchar *end);
u8 wrtlchar(lchar i64Char);
#endif

String rd(String msg);
lchar geti8();

#endif //libIo_H
