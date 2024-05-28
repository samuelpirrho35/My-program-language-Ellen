#ifndef FUNCCOMPILER_H
#define FUNCCOMPILER_H

#include "../includedefines/referenceTypes.h"
#include "./preObjects.h"

Tokens** allocTokens();
void freeTokens(Tokens **tokens, u64 nlines, u64 i);
u8 TokenParser(Tokens **tokens, u64 *line, String src);

#endif //FUNCCOMPILER_H