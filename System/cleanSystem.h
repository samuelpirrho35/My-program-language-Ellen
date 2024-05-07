#ifndef CLEANSYSTEM_H
#define CLEANSYSTEM_H

#include "./System.h"
#include "../includedefines/referenceTypes.h"

u8 destroyObject(__System__ *System, u8 storagesUsing[], i64 address[], i64 index);
u8 ENDPROGRAM(__System__ *System);

#endif //CLEANSYSTEM_H