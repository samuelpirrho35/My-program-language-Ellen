#ifndef TYPEOBJECTS_H
#define TYPEOBJECTS_H

typedef enum{
    __HOLLOW__ = 1,
    __i8__,
    __i16__,
    __i32__,
    __i64__,
    __u8__,
    __u16__,
    __u32__,
    __u64__,
    __f32__,
    __f64__,
    __Char__,
    __String__,
    __BIGINT__,
    __BIGFLOAT__,
    __ARRAYi64__,
    __ARRAYi32__,
    __ARRAYi16__,
    __ARRAYi8__,
    __ARRAYu64__,
    __ARRAYu32__,
    __ARRAYu16__,
    __ARRAYu8__,
    __ARRAYCHAR__,
    __ARRAYSTRING__,
    __ARRAYf32__,
    __ARRAYf64__,
    __ARRAYBIGINT__,
    __ARRAYBIGFLOAT__,
    __LIST__,
    __HASHMAP__,
    __CLASS__,
    __ARRAYLIST__,
    __STRUCT__
}reference_types;

#endif //TYPEOBJECTS_H