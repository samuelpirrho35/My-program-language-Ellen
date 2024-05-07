#ifndef OBJECTSSTRUCT_H
#define OBJECTSSTRUCT_H

#include "../includedefines/referenceTypes.h"
#include "../includedefines/sizeDefined.h"
#include "../includeEnumerator/typeObjects.h"


//-----------<Generic Data>-----------

typedef union{
    i64   i64_ty;
    i32   i32_ty;
    i16   i16_ty;
    i8    i8_ty;
    u64   u64_ty;
    u32   u32_ty;
    u16   u16_ty;
    u8    u8_ty;
    lchar char_ty;
}integers;


typedef struct{
    u32     extention;
    u32     capacity;
    u32     lengthstr;
    String  dataStructurestr;
    char    modify_flag;
}GNFieldsStructures;


typedef struct{
    size_ty extention;
    size_ty capacity;
}GNFieldsArrays;


//-----------<OBJECTS>---------------

typedef struct List List;
typedef struct HashMap HashMap;
typedef struct Class Class;
typedef struct Struct Struct;
typedef struct Ouroboros Ouroboros;


typedef struct{
    i64 i64Ty;
}i64Object;


typedef struct{
    i32 i32Ty;
}i32Object;


typedef struct{
    i16 i16Ty;
}i16Object;


typedef struct{
    i8 i8Ty;
}i8Object;


typedef struct{
    u64 u64Ty;
}u64Object;


typedef struct{
    u32 u32Ty;
}u32Object;


typedef struct{
    u16 u16Ty;
}u16Object;


typedef struct{
    u8 u8Ty;
}u8Object;


typedef struct{
    lchar charTy;
}charObject;


typedef struct{
    f32 i64Ty;
}f32Object;


typedef struct{
    f64 i64Ty;
}f64Object;


typedef struct{
    u32    length;
    String stringTy;
}stringObject;


typedef union{
    integers intTys;
    String   string_ty;
    lchar    char_ty;
    f32      f32_ty;
    f64      f64_ty;
}PrimitiveTypes;


typedef struct Ouroboros{
    u8        val;
    Ouroboros *next;
    Ouroboros *previous;
}Ouroboros;


typedef struct{
    GNFieldsArrays GN_Fields;
    i64            *data;
}Array_i64Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    i32            *data;
}Array_i32Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    i16            *data;
}Array_i16Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    i8             *data;
}Array_i8Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    u64            *data;
}Array_u64Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    u32            *data;
}Array_u32Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    u16            *data;
}Array_u16Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    u8             *data;
}Array_u8Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    lchar          *data;
}Array_charTy;


typedef struct{
    GNFieldsArrays GN_Fields;
    f32            *data;
}Array_f32Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    f64            *data;
}Array_f64Ty;


typedef struct{
    GNFieldsArrays GN_Fields;
    void*          data;
}GenericArray;


typedef union{
    Array_i64Ty  a_i64Ty;
    Array_i32Ty  a_i32Ty;
    Array_i16Ty  a_i16Ty;
    Array_i8Ty   a_i8Ty;
    Array_u64Ty  a_u64Ty;
    Array_u32Ty  a_u32Ty;
    Array_u16Ty  a_u16Ty;
    Array_u8Ty   a_u8Ty;
    Array_charTy a_charTy;
    Array_f32Ty  a_f32Ty;
    Array_f64Ty  a_f64Ty;
}All_Arrays;


typedef struct{
    GNFieldsStructures GN_Fields;
    reference_types    Array_ty;
    All_Arrays         all_arrays;
}ArrayList;


typedef struct{
    reference_types hollow_ty;
    PrimitiveTypes  primitiveTys;
}VarHollow;


typedef struct{
    reference_types hollow_ty;
    union{
        All_Arrays all_arrays;
        ArrayList  *arrayList;
        List       *list;
        HashMap    *hashMap;
        Struct     *StructObj;
    }HollowDsType;
}DSHollow;


typedef struct List{
    GNFieldsStructures GN_Fields;
    reference_types    ref_ty;
    union{
        PrimitiveTypes primitiveTys;
        Ouroboros      *BigintType;
        Ouroboros      *BigfloatType;
        All_Arrays     all_arrays;
        ArrayList      *ArrayList;
        HashMap        *HashObject;
        List           *ListObject;
        Class          *classObject;
        Struct         *StructObject;
        ADDRESS        fn__address__;
    }types;
}List;


typedef struct Class{
    List    *private__This__;
    List    *public__This__;
    List    *__Attributes__;
    ADDRESS *Address_private__Methods__;
    ADDRESS *Address_public__Methods__;
    Class   **extends;
}Class;


typedef struct HashMap{
    i64             Key;
    reference_types ref_keyTy;
    union{
        PrimitiveTypes primitiveTy;
        Ouroboros      *BigintType;
        Ouroboros      *BigfloatType;
        All_Arrays     all_arrays;
        ArrayList      *ArrayList;
        List           *ListObject;
        HashMap        *HashObject;
        Class          ClassObject;
        ADDRESS        fn__address__;
        Struct         *StructObject;
    }Value;
}HashMap;


typedef struct fn{
    reference_types *params;
    reference_types *returns;
}fn;


typedef struct Struct{
    reference_types    ref_StructTy;
    union{
        PrimitiveTypes primitiveTy;
        Ouroboros      *BigintType;
        Ouroboros      *BigfloatType;
        All_Arrays     all_arrays;
        ArrayList      *ArrayList;
        List           *ListObject;
        HashMap        *HashObject;
        Class          classObject;
        ADDRESS        fn__address__;
    }TypeFieldStruct;
}Struct;


typedef struct{
    reference_types ref_constTy;
    union{
        i64         i64Type;
        u64         u64Type;
        f32         f32Type;
        f64         f64Type;
        Ouroboros   *BigintType;
        Ouroboros   *BigfloatType;
        ArrayList   *arrayList;
        HashMap     *hash;
        List        *list;
    }constObjects;
}Const;


//-----------<Array storage objects>-----------

typedef i64Object**  storage_i64Ty;
typedef i32Object**  storage_i32Ty;
typedef i16Object**  storage_i16Ty;
typedef i8Object**   storage_i8Ty;
typedef u64Object**  storage_u64Ty;
typedef u32Object**  storage_u32Ty;
typedef u16Object**  storage_u16Ty;
typedef u8Object**   storage_u8Ty;
typedef charObject** storage_charTy;
typedef String*      storage_stringTy;
typedef f32Object**  storage_f32Ty;
typedef f64Object**  storage_f64Ty;
typedef VarHollow**  storage_varhollowTy;
typedef DSHollow**   storage_dshollowTy;

typedef Ouroboros**  storage_Bigi32Ty;
typedef Ouroboros**  storage_Bigf32Ty;
typedef ArrayList**  storage_ArrayListTy;
typedef List**       storage_ListTy;
typedef HashMap**    storage_HashMapTy;
typedef Struct**     storage_StructTy;
typedef Class**      storage_ClassTy;
typedef fn**         storage_fnTy;

#endif //OBJECTSSTRUCT_H