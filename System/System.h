#ifndef SYSTEM_H
#define SYSTEM_H

#include "../includedefines/defines.h"
#include "../includedefines/inttypes.h"
#include "../includedefines/sizeDefined.h"
#include "../includeclass/objectsStruct.h"
#include "../includeEnumerator/typeObjects.h"

#define JUSTVIRTUALMACHINE

typedef struct{
    u32 MaxSizeExtentionIntDinamic;
    u32 MaxSizeExtentionFloatDinamic;
}__DinamicsSizeExtention__;


typedef struct{
    __DinamicsSizeExtention__ DinamicsSizeExtention;
}__Types__;


typedef struct{
    u16 Extention;
    u16 Capacity;
    String IdentifierName;
    reference_types TypeObject;
    u16 Calls;
    STATUS State;
    String Value;
}CacheStructure;


typedef struct{
    u8 TypeStructureCache;
    union{
        CacheStructure Cache;
        CacheStructure *ListCache;
    }TypeCache;
}CachingData;


typedef struct{
    String FileSourseCode;
    data_c *bytecode;
}__FilesManager__;


typedef struct{
    storage_longTy st_long;
    storage_intTy st_int;
    storage_shortTy st_short;
    storage_byteTy st_byte;
    storage_charTy st_char;
    storage_stringTy st_string;
    storage_floatTy st_float;
    storage_doubleTy st_double;
    storage_varhollowTy st_varhollow;
    storage_dshollowTy st_dshollow;
    storage_BigintTy st_Bigint;
    storage_BigfloatTy st_BigFloat;
    storage_ArrayListTy st_arraylist;
    storage_ListTy st_list;
    storage_HashMapTy st_hashMap;
    storage_StructTy st_struct;
    storage_ClassTy st_class;
    storage_fnTy st_fnAddress;
    storage_longTy st_long_array;
    storage_intTy st_int_array;
    storage_shortTy st_short_array;
    storage_byteTy st_byte_array;
    storage_charTy st_char_array;
    storage_floatTy st_float_array;
    storage_doubleTy st_double_array;
}__Objects__;


typedef struct{
    __Types__ IdentifiersTy;
    CachingData **Cache;
    __FilesManager__ FileManager;
    u16 SizeCacheScopes;
    data_c objectsUsing[OBJECTsQTTY];
    __Objects__ Objects;
}__Manager__;


typedef struct{
    __Manager__ Manager;
    lchar status;
    String version;
    Byte (*WRT)(List**);
    lchar (*GETByte)();
    String (*RD)(String);
}__System__;

#endif //SYSTEM_H