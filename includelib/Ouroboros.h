#ifndef OBJECTSFUNCTIONS_H
#define OBJECTSFUNCTIONS_H

#include "../includeclass/objectsStruct.h"
#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"

Ouroboros* newOuroboros();
Ouroboros* initOuroboros(u8 data[]);
void freeOuroboros(Ouroboros *ouroboros);

#endif //OBJECTSFUNCTIONS_H