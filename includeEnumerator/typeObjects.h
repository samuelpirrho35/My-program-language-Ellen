#ifndef TYPEOBJECTS_H
#define TYPEOBJECTS_H

typedef enum{
    __HOLLOW__ = 1,
    __Byte__,
    __Short__,
    __Int__,
    __Long__,
    __Float__,
    __Double__,
    __Char__,
    __String__,
    __BIGINT__,
    __BIGFLOAT__,
    __ARRAYLONG__,
    __ARRAYINT__,
    __ARRAYSHORT__,
    __ARRAYBYTE__,
    __ARRAYCHAR__,
    __ARRAYSTRING__,
    __ARRAYFLOAT__,
    __ARRAYDOUBLE__,
    __ARRAYBIGINT__,
    __ARRAYBIGFLOAT__,
    __LIST__,
    __HASHMAP__,
    __CLASS__,
    __ARRAYLIST__,
    __STRUCT__
}reference_types;

#endif //TYPEOBJECTS_H