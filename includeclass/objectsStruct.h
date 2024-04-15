#ifndef OBJECTSSTRUCT_H
#define OBJECTSSTRUCT_H

#include "../includedefines/inttypes.h"
#include "../includedefines/sizeDefined.h"
#include "../includedefines/defines.h"
#include "../includeEnumerator/typeObjects.h"


//-----------<Generic Data>-----------

typedef union{
    Long long_ty;
    Int int_ty;
    Short short_ty;
    lchar char_ty;
    Byte byte_ty;
}Integers;


typedef struct{
    size_ty extention;
    size_ty capacity;
    size_ty lengthstr;
    String dataStructurestr;
    char modify_flag;
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


typedef struct{
    Long longTy;
}longObject;


typedef struct{
    Int intTy;
}intObject;


typedef struct{
    Short shortTy;
}shortObject;


typedef struct{
    Byte byteTy;
}byteObject;


typedef struct{
    lchar charTy;
}charObject;


typedef struct{
    float longTy;
}floatObject;


typedef struct{
    double longTy;
}doubleObject;


typedef union{
    Integers intTys;
    lchar *string_ty;
    lchar char_ty;
    float float_ty;
    double double_ty;
}PrimitiveTypes;


typedef struct{
    size_ty extention;
    data_c *data;
}BigintObject;


typedef struct{
    size_ty extfData;
    data_c *data_float;
}BigfloatObject;


typedef struct{
    GNFieldsArrays GN_Fields;
    Long *data;
}Array_longTy;


typedef struct{
    GNFieldsArrays GN_Fields;
    Int *data;
}Array_intTy;


typedef struct{
    GNFieldsArrays GN_Fields;
    Short *data;
}Array_shortTy;


typedef struct{
    GNFieldsArrays GN_Fields;
    Byte *data;
}Array_byteTy;


typedef struct{
    GNFieldsArrays GN_Fields;
    lchar *data;
}Array_charTy;


typedef struct{
    GNFieldsArrays GN_Fields;
    float *data;
}Array_floatTy;


typedef struct{
    GNFieldsArrays GN_Fields;
    double *data;
}Array_doubleTy;


typedef struct{
    GNFieldsArrays GN_Fields;
    void* data;
}GenericArray;


typedef union{
    Array_longTy a_longTy;
    Array_intTy a_intTy;
    Array_shortTy a_shortTy;
    Array_byteTy a_byteTy;
    Array_charTy a_charTy;
    Array_floatTy a_floatTy;
    Array_doubleTy a_doubleTy;
}All_Arrays;


typedef struct{
    GNFieldsStructures GN_Fields;
    reference_types Array_ty;
    All_Arrays all_arrays;
}ArrayList;


typedef struct{
    reference_types hollow_ty;
    PrimitiveTypes primitiveTys;
}VarHollow;


typedef struct{
    reference_types hollow_ty;
    union{
        All_Arrays all_arrays;
        ArrayList *arrayList;
        List *list;
        HashMap *hashMap;
        Struct *StructObj;
    }HollowDsType;
}DSHollow;


typedef struct List{
    GNFieldsStructures GN_Fields;
    reference_types ref_ty;
    union{
        PrimitiveTypes primitiveTys;
        BigintObject IntDinamicType;
        BigfloatObject FloatDinamicType;
        All_Arrays all_arrays;
        ArrayList *ArrayList;
        HashMap *HashObject;
        List *ListObject;
        Class *classObject;
        Struct *StructObject;
        ADDRESS fn__address__;
    }types;
}List;


typedef struct Class{
    List *private__This__;
    List *public__This__;
    List *__Attributes__;
    ADDRESS *Address_private__Methods__;
    ADDRESS *Address_public__Methods__;
    Class **extends;
}Class;


typedef struct HashMap{
    Long Key;
    reference_types ref_keyTy;
    union{
        PrimitiveTypes primitiveTy;
        BigintObject IntDinamicType;
        BigfloatObject FloatDinamicType;
        All_Arrays all_arrays;
        ArrayList *ArrayList;
        List *ListObject;
        HashMap *HashObject;
        Class ClassObject;
        ADDRESS fn__address__;
        Struct *StructObject;
    }Value;
}HashMap;


typedef struct fn{
    reference_types *params;
    reference_types *returns;
}fn;


typedef struct Struct{
    reference_types ref_StructTy;
    union{
        PrimitiveTypes primitiveTy;
        BigintObject IntDinamicType;
        BigfloatObject FloatDinamicType;
        All_Arrays all_arrays;
        ArrayList *ArrayList;
        List *ListObject;
        HashMap *HashObject;
        Class classObject;
        ADDRESS fn__address__;
    }TypeFieldStruct;
}Struct;


typedef struct{
    reference_types ref_constTy;
    union{
        Long integerType;
        double floatType;
        BigintObject BigintType;
        BigfloatObject BigfloatType;
        ArrayList *arrayList;
        HashMap *hash;
        List *list;
    }constObjects;
}Const;


//-----------<Array storage objects>-----------

typedef longObject** storage_longTy;
typedef intObject** storage_intTy;
typedef shortObject** storage_shortTy;
typedef byteObject** storage_byteTy;
typedef charObject** storage_charTy;
typedef String* storage_stringTy;
typedef float* storage_floatTy;
typedef double* storage_doubleTy;
typedef VarHollow** storage_varhollowTy;
typedef DSHollow** storage_dshollowTy;

typedef BigintObject** storage_BigintTy;
typedef BigfloatObject** storage_BigfloatTy;
typedef ArrayList** storage_ArrayListTy;
typedef List** storage_ListTy;
typedef HashMap** storage_HashMapTy;
typedef Struct** storage_StructTy;
typedef Class** storage_ClassTy;
typedef fn** storage_fnTy;


#endif //OBJECTSSTRUCT_H