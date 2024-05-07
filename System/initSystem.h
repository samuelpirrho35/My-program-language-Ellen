#ifndef __SYSTEM_INIT_H__
#define __SYSTEM_INIT_H__

#include "../System/System.h"

__System__ __init__();
u8 initializeStorages(__Objects__ *objects, u8 storagesUsing[], i64 sizeForEachSt[], i64 index);
u8 allocStoragesUsing(__Objects__ *objects, u8 objectsUsing, i64 index, i64 dataSize);
u8 setValues(__Objects__ *objects, u8 objectsUsing[], List *values, i64 address[]);

#endif //__SYSTEM_INIT_H__