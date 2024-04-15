#ifndef __SYSTEM_INIT_H__
#define __SYSTEM_INIT_H__

#include "../System/System.h"

__System__ __init__();
u8 initializeStorages(__Objects__ *objects, data_c storagesUsing[], Long sizeForEachSt[], Long index);
u8 setValues(__Objects__ *objects, data_c objectsUsing[], Long values[], Long address[], Long index);

#endif //__SYSTEM_INIT_H__