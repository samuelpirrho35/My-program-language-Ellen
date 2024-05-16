#ifndef TOKENGENERATOR_H
#define TOKENGENERATOR_H

#include "../includedefines/defines.h"
#include "../includedefines/referenceTypes.h"
#include "./preObjects.h"

#define START_TOKENS 128
#define START_LINE   128
#define START_WORD   256

#define keyqdrtlen   12
#define fnqdrtlen    5

#define keyfirst_quadrant   _U16
#define keysecond_quadrant  THIS
#define keythird_quadrant   RESIZE
#define keyfourth_quadrant  ATTRIBUTE

#define fnfirst_quadrant    COPY
#define fnsecond_quadrant   LENGTH
#define fnthird_quadrant    REVERSE
#define fnfourth_quadrant   READFILELINE

#define keyqdrt1     {0,              keyqdrtlen    }
#define keyqdrt2     {keyqdrtlen,     keyqdrtlen * 2}
#define keyqdrt3     {keyqdrtlen * 2, keyqdrtlen * 3}
#define keyqdrt4     {keyqdrtlen * 3, keyqdrtlen * 4}

#define fnqdrt1      {0,             fnqdrtlen    }
#define fnqdrt2      {fnqdrtlen,     fnqdrtlen * 2}
#define fnqdrt3      {fnqdrtlen * 2, fnqdrtlen * 3}
#define fnqdrt4      {fnqdrtlen * 3, fnqdrtlen * 4}

#define allqdrtlen  (char[][2]){                                             \
                                    keyqdrt1, keyqdrt2, keyqdrt3, keyqdrt4,  \
                                    fnqdrt1,  fnqdrt2,  fnqdrt3,  fnqdrt4    \
                               }

#define allqdrt     (short[]){                                          \
                                keyfirst_quadrant, keysecond_quadrant,  \
                                keythird_quadrant, keyfourth_quadrant,  \
                                fnfirst_quadrant,  fnsecond_quadrant,   \
                                fnthird_quadrant,  fnfourth_quadrant    \
                             }

#define copyerror(ERR, TOK, LINE, INDEX) copyToStaticBuffer(TOK[LINE][INDEX].tokens.TokenError, ErrorsTable[ERR], ErrosTableSizes[ERR])

#define INIINTERNFN 4

#define TABLEKEY 0
#define TABLEFN  1

#define sLen 2
#define bLen 12

#define zero L'0'
#define nine L'9'

#define OK     1
#define NOT_OK 0

#define SPACE 255

typedef enum{
    ALLOCWORD = (25), REALLOCWORD, TKIREALLOC,   TKREALLOC,
    NOTNUMBER,        COMMENT,     COMMENTERROR, TKMREALLOC
}TokenReturn;

typedef struct{
    i8  ini;
    i8  end;
    u32 len;
    u32 cod;
}InfoWord;

typedef struct{
    lchar key[15];
    u32   cod;
}TokensTable;

#define INTERRUPTIONCHARS L"*/+-=%%^´!'\"&¨%#@?°ºª¹²³£¢¬§|[]{}()<>,.:; \r\b\n\e\t\a\f\v\\"


#define KeyWordTable      (TokensTable[]){                                                                         \
    {L"i8", _I8},               {L"u8", _U8},               {L"f32", _F32},             {L"if", IF},               \
    {L"i32", _I32},             {L"i16", _I16},             {L"f64", _F64},             {L"fn", FN},               \
    {L"i64", _I64},             {L"in", IN},                {L"u32", _U32},             {L"u16", _U16},            \
    {L"or", OR},                {L"u64", _U64},             {L"FILE", _FILE},           {L"and", AND},             \
    {L"all", ALL},              {L"Try", TRY},              {L"nil", NIL},              {L"key", KEY},             \
    {L"for", FOR},              {L"new", NEW},              {L"not", NOT},              {L"This", THIS},           \
    {L"List", LIST},            {L"char", CHAR},            {L"case", CASE},            {L"elif", ELIF},           \
    {L"else", ELSE},            {L"Catch", CATCH},          {L"Class", CLASS},          {L"break", BREAK},         \
    {L"while", WHILE},          {L"const", CONST},          {L"Method", METHOD},        {L"Resize", RESIZE},       \
    {L"thread", THREAD},        {L"public", PUBLIC},        {L"HashMap", HASHMAP},      {L"switch", SWITCH},       \
    {L"import", IMPORT},        {L"string", STRING},        {L"return", RETURN},        {L"default", DEFAULT},     \
    {L"private", PRIVATE},      {L"continue", CONTINUE},    {L"ArrayList", ARRAYLIST},  {L"Attribute", ATTRIBUTE}  \
}


#define internalOperTable (TokensTable[]){                                                                              \
    {L"rd", RD},                {L"pop", POP},              {L"wrt", WRT},             {L"Type", TYPE},                 \
    {L"copy", COPY},            {L"keys", KEYS},            {L"push", PUSH},           {L"clear", CLEAR},               \
    {L"items", ITEMS},          {L"length", LENGTH},        {L"update", UPDATE},       {L"values", VALUES},             \
    {L"remove", REMOVE},        {L"ReadFile", READFILE},    {L"reverse", REVERSE},     {L"FileOpen", FILEOPEN},         \
    {L"FileClose", FILECLOSE},  {L"WriteFile", WRITEFILE},  {L"strtolist", STRTOLIST}, {L"ReadFileLine", READFILELINE}  \
}


#endif //TOKENGENERATOR_H