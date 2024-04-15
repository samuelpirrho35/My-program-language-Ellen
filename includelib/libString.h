#ifndef libString_H
#define libString_H

#include "../includedefines/defines.h"
#include "../includedefines/inttypes.h"
#include <stdio.h>

size_ty strsize(lchar *_String);
String strmerger(String str1, String str2);
String strfastmerger(String str1, String str2, size_ty sizestr1, size_ty sizestr2);
lchar* strcopy(lchar *source);
String strfastcopy(String source, Long len);
u8 strncopy(String *dstny, String source, Long limit);
u8 strgetnextstr(String *dstny, String *formatptr);
char setBuffer(lchar *dstny, lchar *copy, unsigned long long *setposition);

#endif // libString_H