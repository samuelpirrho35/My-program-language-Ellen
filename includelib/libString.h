#ifndef libString_H
#define libString_H

#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"
#include <stdio.h>

size_ty strsize(lchar *_String);
String strmerger(String str1, String str2);
String strfastmerger(String str1, String str2, size_ty sizestr1, size_ty sizestr2);
String strcopy(String source);
String strfastcopy(String source, i64 len);
u8 strncopy(String *dstny, String source, i64 limit);
u8 strcompare(String str1, String str2);
u8 strfastcompare(String str1, String str2, u64 len1);
void copyToStaticBuffer(lchar copy[], String src, u64 len);
u8 strgetnextstr(String *dstny, String *formatptr);
i8 setBuffer(String dstny, String copy, u64 *setposition);
String DataToString(u8 data[], i64 size, i64 start);

#endif // libString_H