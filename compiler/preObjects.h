#ifndef PREOBJECTS
#define PREOBJECTS

#include "../includedefines/defines.h"
#include "../includeEnumerator/tokens.h"

#define BIN 0
#define HEX 1
#define DEC 2

typedef struct{
    u8 type;
    u64 length;
    union{
        lchar        TokenError[60];
        u16          TokenKeyWord;
        u16          TokenFn;
        String       Constint;
        String       ConstValue;
        String       IdentifierName;
    }tokens;
}Tokens;

#endif //PREOBJECTS