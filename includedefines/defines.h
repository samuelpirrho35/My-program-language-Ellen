#ifndef DEFINES_H
#define DEFINES_H

#include "./referenceTypes.h"

#define INITSIZEOBJECTSMANAGER 0xA
#define INITARRAYOBJECTSCOPE 0x20

#define INITMANAGERCACHE  64
#define INITSIZECACHE     64
#define INITSIZELISTCACHE 64

#define CACHE     1
#define LISTCACHE 2

#define VARIABLE 0
#define DATASTRUCTURE 1

#define NONE -1
#define DEFINED 1

#define VIEW 1
#define HIDDEN 0

#define _GLOBAL 0
#define _LOCAL 1

#define PACK_BYTES         0
#define PACK_DOUBLE_BYTES  1
#define PACK_INTEGER       2
#define PACK_FLOAT         3
#define PACK_CHAR          4
#define PACK_ANY_INTEGER   5

#define MODE_PRINT_FUNC 0
#define MODE_PRINT_LIST 1

#define MODE_DATA_INTEGER 0
#define MODE_DATA_FLOAT   1
#define MODE_DATA_STRING  3

#define STARTBYTE_0X0E 0x0E
#define STARTBYTE_0X0F 0x0F
#define ENDBYTE        0x0A

#define WORKING 1
#define STATUSERROR -1

#define WINDOWS
//#define LINUX

#endif // DEFINES_H