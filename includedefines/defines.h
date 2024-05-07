#ifndef DEFINES_H
#define DEFINES_H

#include "./referenceTypes.h"

#define SYSTEM64 0x40
#define SYSTEM32 0x20
#define SYSTEM16 0x10
#define SYSTEM08 0x8

#define INITSIZEOBJECTSMANAGER 0xA
#define INITARRAYOBJECTSCOPE 0x20

#define INITMANAGERCACHE 0x5
#define INITSIZECACHE 0x64
#define INITSIZELISTCACHE 0x5
#define HASHCACHE 1
#define LISTCACHE 2

#define VARIABLE 0
#define DATASTRUCTURE 1

#define NONE -1
#define DEFINED 1

#define VIEW 1
#define HIDDEN 0

#define _GLOBAL 0
#define _LOCAL 1

#define _INTERNAL_FNCHARPOINTERNUMCODE 46
#define ALLCHARACTERES L"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789_çÇãÃõÕâÂôÔêÊîÎûÛáÁóÓéÉíÍúÚ"
#define TOKENSCHARACTERES L"+-*/|&!?°ºª<>,.:;^~´`{}[]()¹²³£¢¬@#$%%¨&=_§"

#define PACK_BYTES              0
#define PACK_DOUBLE_BYTES       1
#define PACK_INTEGER            2
#define PACK_FLOAT              3
#define PACK_CHAR               4
#define PACK_ANY_INTEGER        5

#define MODE_PRINT_FUNC 0
#define MODE_PRINT_LIST 1

#define MODE_DATA_INTEGER 0
#define MODE_DATA_FLOAT   1
#define MODE_DATA_STRING  3

#define STARTBYTE_0X0E 0x0E
#define STARTBYTE_0X0F 0x0F
#define ENDBYTE 0x0A

#define WORKING 1
#define STATUSERROR -1

#define WINDOWS
//#define LINUX
//#define MACB
//#define ANDROID

#endif // DEFINES_H