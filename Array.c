#include "includeclass/objectsStruct.h"
#include "includedefines/defines.h"
#include "includedefines/referenceTypes.h"
#include "includedefines/allocs.h"
#include "includelib/libIo.h"
#include "includelib/libString.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/compressBytes.h"
#include "includeEnumerator/typeObjects.h"


void initializeDataArray
(GenericArray *Generic, u64 init, u64 end,
reference_types ref_dataTy)
{
    switch(ref_dataTy){
        case __ARRAYi64__:{
            Array_i64Ty *array = (Array_i64Ty*)Generic;
            for(u64 i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYi32__:{
            Array_i32Ty *array = (Array_i32Ty*)Generic;
            for(u64 i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYi16__:{
            Array_i16Ty *array = (Array_i16Ty*)Generic;
            for(u64 i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYi8__:{
            Array_i8Ty *array = (Array_i8Ty*)Generic;
            for(u64 i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYCHAR__:{
            Array_charTy *array = (Array_charTy*)Generic;
            for(u64 i = init; i < end; i++){
                array->data[i] = 0;
            }
            break;
        }
        case __ARRAYf32__:{
            Array_f32Ty *array = (Array_f32Ty*)Generic;
            for(u64 i = init; i < end; i++){
                array->data[i] = 0.0f;
            }
            break;
        }
        case __ARRAYf64__:{
            Array_f64Ty *array = (Array_f64Ty*)Generic;
            for(u64 i = init; i < end; i++){
                array->data[i] = 0.0;
            }
            break;
        }
    }
}


GenericArray* newArray(u64 capacity, u64 size, reference_types ref_dataTy){
    GenericArray *newArray = (GenericArray*)malloc(size);
    newArray->data = malloc(capacity * size);
    initializeDataArray(newArray, 0, capacity, ref_dataTy);
    newArray->GN_Fields.capacity = capacity;
    newArray->GN_Fields.extention = 0;
    return newArray;
}


void resizeArray(u64 newCapacity, u64 size, GenericArray *array, reference_types ref_dataTy){
    void *newDataArray = realloc(array->data, newCapacity * size);
    array->data = newDataArray;
    initializeDataArray(array, array->GN_Fields.extention + 1, newCapacity, ref_dataTy);
    array->GN_Fields.capacity = newCapacity;
}