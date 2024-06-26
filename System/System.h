#ifndef SYSTEM_H
#define SYSTEM_H

#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"
#include "../includedefines/sizeDefined.h"
#include "../includeclass/objectsStruct.h"
#include "../includeEnumerator/typeObjects.h"

//#define RUNTIMEVM

#ifndef RUNTIMEVM
typedef struct{
    u32             Extention;
    u32             Capacity;
    String          IdentifierName;
    reference_types TypeObject;
    u32             Calls;
    STATUS          State;
    String          Value;
}CacheStructure;


typedef struct{
    u8 TypeStructureCache;
    union{
        CacheStructure Cache;
        CacheStructure *ListCache;
    }TypeCache;
}CachingData;
#endif

typedef struct{
    String FileSourseCode;
    u8     *bytecode;
}__FilesManager__;


typedef struct{
    storage_i64Ty           st_i64;
    storage_i32Ty           st_i32;
    storage_i16Ty           st_i16;
    storage_i8Ty            st_i8;
    storage_u64Ty           st_u64;
    storage_u32Ty           st_u32;
    storage_u16Ty           st_u16;
    storage_u8Ty            st_u8;
    storage_charTy          st_char;
    storage_stringTy        st_string;
    storage_f32Ty           st_f32;
    storage_f64Ty           st_f64;
    storage_BigintTy        st_Bigint;
    storage_BigfloatTy      st_BigFloat;
    storage_ArrayListTy     st_arrayList;
    storage_VirtualArray    st_virtualArray;
    storage_ListTy          st_list;
    storage_HashMapTy       st_hashMap;
    storage_StructTy        st_struct;
    storage_ClassTy         st_class;
    storage_fnTy            st_fnAddress;
    storage_i64Ty           st_i64_array;
    storage_i32Ty           st_i32_array;
    storage_i16Ty           st_i16_array;
    storage_i8Ty            st_i8_array;
    storage_charTy          st_char_array;
    storage_f32Ty           st_f32_array;
    storage_f64Ty           st_f64_array;
}__Objects__;


typedef struct{
    #ifndef RUNTIMEVM
    CachingData       **Cache;
    u16               SizeCacheScopes;
    #endif

    __FilesManager__  FileManager;
    __Objects__       Objects;
    __Objects__       TemporaryObjects;
    u8                objectsUsing[OBJECTsQTTY];
}__Manager__;


typedef struct{
    i8      (*WRT)(List**);
    String  (*RD)(String);
}__SysFunctions__;


typedef struct{
    __Manager__ Manager;
    lchar       status;
    String      version;
    __SysFunctions__ SysFunctions;
}__System__;

#endif //SYSTEM_H