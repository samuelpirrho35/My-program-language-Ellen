#include "../includedefines/defines.h"
#include "../includedefines/inttypes.h"
#include "../includeclass/objectsStruct.h"

#ifndef libIo_H
#define libIo_H

Byte wrt(List **objects);
#ifdef WINDOWS
unsigned char WindowsWrt(lchar *StringObject, lchar *end);
u8 wrtlchar(lchar LongChar);
#endif

String rd(String msg);
lchar getByte();

#endif //libIo_H
