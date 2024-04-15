#ifndef BASICMATH_H
#define BASICMATH_H

#include "../includeclass/objectsStruct.h"

BigintObject*
sum_IntDinamic_and_IntDinamic(BigintObject *IntObject_store,
BigintObject *IntObject);

BigintObject*
sum_IntDinamic_and_IntStatic(BigintObject *IntObjectDinamic,
BigintObject *IntObjectStatic);

BigintObject*
subtract_IntDinamic_and_IntDinamic(BigintObject *IntObject1,
BigintObject* IntObject2);

#endif //BASICMATH_H