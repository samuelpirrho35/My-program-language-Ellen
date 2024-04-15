#ifndef PREOBJECTS
#define PREOBJECTS

#include "../includedefines/defines.h"
#include "../includeEnumerator/tokens.h"

#define DEC 0
#define HEX 1

typedef struct{
    String nameIdentifier;
    String codeName;
}IdentifierData;


typedef struct{
    String data;
    u8 addinfo;
}IdentifierConst;


typedef struct{
    u8 fnCode;
}IdentifierInternalFn;


typedef struct{
    String dataError;
}ERROR_;


typedef struct{
    TokenType type;
    union{
        IdentifierData Data;
        IdentifierConst constData;
        IdentifierInternalFn internaFn;
        ERROR_ error;
    }Identifiers;
}Token;

#endif //PREOBJECTS