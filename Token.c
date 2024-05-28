#include "includedefines/referenceTypes.h"
#include "includedefines/sizeDefined.h"
#include "includedefines/allocs.h"
#include "includeerror/errors.h"
#include "compiler/preObjects.h"
#include "compiler/Token.h"
#include "includelib/libString.h"
#include "includelib/libIo.h"
#include "memory/memory.h"
#include <stdio.h>
#include <stdlib.h>

static u32 codeString(String str){
    u32 code = 0;
    lchar lastchar = 0;

    while(*str){
        code += ((lchar)*str << 1) + (lastchar - 47);
        lastchar = *str;
        str++;
    }

    return code;
}

static u8 checkTokenValid(lchar actCharacter, String nextCharacters){
    while(*nextCharacters){
        if(actCharacter == *nextCharacters)
            return 1;

        nextCharacters++;
    }

    return 0;
}

static void getQuadrant
(u32 cod, u8 inittable, InfoWord *info, u32 length){
    u8 i = inittable;

    if(length < sLen || length > bLen)
        return;

    for(; i < inittable + 4; i++){
        if(cod <= allqdrt[i]){
            info->ini = allqdrtlen[i][0];
            info->end = allqdrtlen[i][1];
            info->cod = cod;
            return;
        }
    }
}

static u32 verifyIfStringInTable
(TokensTable word, InfoWord info, TokensTable Table[])
{
    u8 ini = info.ini, end = info.end;

    if(!end)
        return 0;
    
    for(; ini < end; ini++)
        if(word.cod == Table[ini].cod)
            if(strfastcompare(word.key, Table[ini].key, info.len))
                return info.cod;

    return 0;
}

static u8 verifyKeyOrFn
(String word, Tokens **tokens, u64 line,
u32 index, u32 length)
{
    u8 tf = 0;
    u32 isfn = 0, iskey = 0;

    InfoWord info;
    info.end = 0;
    info.len = length;

    TokensTable wordt;
    wordt.cod = codeString(word);
    copyToStaticBuffer(wordt.key, word, length);

    getQuadrant(wordt.cod, INIINTERNFN, &info, length);
    isfn = verifyIfStringInTable(wordt, info, internalOperTable);
    if(isfn){
        tokens[line][index].type = _INTERNAL_FN;
        tokens[line][index].tokens.TokenFn = isfn;
        tf = 1;
    }

    else{
        getQuadrant(wordt.cod, 0, &info, length);
        iskey = verifyIfStringInTable(wordt, info, KeyWordTable);

        if(iskey){
            tokens[line][index].type = _KEYWORD;
            tokens[line][index].tokens.TokenKeyWord = iskey;
            tf = 1;
        }
    }

    tokens[line][index].length = info.len;

    return tf;
}

inline static u8 verifyNumber(String word, u32 length){
    if(!(*word >= zero && *word <= nine))
        return NOTNUMBER;

    u8 hex = 0, bin = 0, f = 0, check = 0, charsv = 0;

    if(*word == zero && (word[1] == L'x' || word[1] == L'X'))
        hex = 1;

    if(*word == zero && (word[1] == L'b' || word[1] == L'B'))
        bin = 1;

    if(!hex && !bin && *word == zero)
        return _ERROR_INIT_WITH_ZERO;

    String nword = word;

    if(hex || bin)
        nword += 2;

    while(*nword){
        check = checkTokenValid(*nword, L"aAbBcCdDeEfF");
        charsv = (bin) ? !(*nword >= zero && *nword <= zero + 1) :
                         !(*nword >= zero && *nword <= nine);

        if(hex)
            if((!check && charsv))
                return _ERROR_FORMAT_IDENTIFIER;

        if(bin)
            if(charsv)
                return _ERROR_FORMAT_IDENTIFIER;

        if(*nword == L'.'){
            if(!f && !hex && !bin)
                f = 1;

            else
                return _ERROR_UNEXPECTED_EXPRESSION;
        }

        if(!hex && !bin && !f)
            if(!(*nword >= zero && *nword <= nine) && *nword != L'_')
                return _ERROR_FORMAT_IDENTIFIER;

        nword++;
    }

    if(hex)
        return _IDENTIFIER_CONST_HEX;

    if(bin)
        return _IDENTIFIER_CONST_BIN;
    
    if(f)
        return _IDENTIFIER_CONST_FLOAT;

    return _IDENTIFIER_CONST_DEC;
}

inline static u8 verifyIfaValidString
(String *source, Tokens **tokens, u64 line, u64 index)
{
    String src = *source;

    if(*src == L'\0')
        return _ERROR_STRING;

    u32 nChars = START_WORD, cChars = 0;

    String conststr = STRALLOC(START_WORD);
    if(conststr == NULL)
        return ALLOCWORD;

    while(*src != '"'){
        conststr[cChars++] = *src;

        if(!(nChars - cChars - 2)){
            nChars += nChars >> 1;
            String newstr = (String)realloc(conststr, nChars);
            if(newstr == NULL){
                free(conststr);
                return REALLOCWORD;
            }

            conststr = newstr;
        }

        src++;
        if(*src == L'\0'){
            free(conststr);
            return _ERROR_STRING;
        }
    }

    conststr[cChars] = L'\0';

    tokens[line][index].type = _IDENTIFIER_CONST_STRING;
    tokens[line][index].tokens.ConstValue = conststr;
    *source = src;

    return OK;
}

static lchar getScapeChar(String src){
    lchar c = getnptr(src, 3);
    
    if(c != L'\'')
        return c;

    c = getnptr(src, 2);

    switch(c){
        case L'0':
            c = L'\0';
            break;
        case L'n':
            c = L'\n';
            break;
        case L'b':
            c = L'\b';
            break;
        case L'r':
            c = L'\r';
            break;
        case L't':
            c = L'\t';
            break;
        case L'f':
            c = L'\f';
            break;
        case L'\\':
            c = L'\\';
            break;
    }

    return c;
}

static u8 Interruption
(String *source, Tokens **tokens, u64 *line, u64 *index)
{
    u8 returnfn = OK;
    String src = *source;
    lchar chr;

    if(*src == L' ')
        return SPACE;

    if(*src == L'\''){
        chr = getnptr(src, 1);

        if(!chr){
            errchar();
            return NOT_OK;
        }

        if(chr == L'\\'){
            chr = getnptr(src, 2);

            if(!chr){
                errchar();
                return NOT_OK;
            }
            
            tokens[*line][*index].type = _IDENTIFIER_CONST_CHAR;
            tokens[*line][*index].tokens.ConstChar = getScapeChar(src);
            
            *source = src + 3;
            return OK;
        }

        if(getnptr(src, 2) != L'\''){
            errchar();
            return NOT_OK;
        }

        tokens[*line][*index].type = _IDENTIFIER_CONST_CHAR;
        tokens[*line][*index].tokens.ConstChar = chr;
        *source = src + 2;
        return OK;
    }

    if(*src == '"'){
        src++;
        returnfn = verifyIfaValidString(&src, tokens, *line, *index);

        if(returnfn == _ERROR_STRING){
            tokens[*line][*index].type = __ERROR__;
            copyerror(_ERROR_STRING, tokens, *line, *index);
            return NOT_OK;
        }

        if(returnfn >= ALLOCWORD)
            return returnfn;

        *source = src;
        return OK;   
    }

    switch(*src){
        case L'+':
            src++;
            if(*src == L'+'){
                tokens[*line][*index].type = _OPERATOR_ADD_ADD;
                break;
            }

            if(*src == L'='){
                tokens[*line][*index].type = _OPERATOR_ADD_EQUAL;
                break;
            }
            
            src--;
            tokens[*line][*index].type = _OPERATOR_ADD;
            break;

        case L'-':
            src++;
            if(*src == L'-'){
                tokens[*line][*index].type = _OPERATOR_SUB_SUB;
                break;
            }

            if(*src == L'='){
                tokens[*line][*index].type = _OPERATOR_SUB_EQUAL;
                break;
            }

            if(*src == L'>'){
                tokens[*line][*index].type = _RESERVED_CHARACTER_ADDRESS_POINTER;
                break;
            }

            src--;
            tokens[*line][*index].type = _OPERATOR_SUB;
            break;

        case L'*':
            src++;
            if(*src == L'*'){
                src++;
                if(*src == L'='){
                    tokens[*line][*index].type = _OPERATOR_POW_EQUAL;
                    break;
                }

                src--;
                tokens[*line][*index].type = _OPERATOR_POW;
                break;
            }

            if(*src == L'='){
                tokens[*line][*index].type = _OPERATOR_MULT_EQUAL;
                break;
            }

            src--;
            tokens[*line][*index].type = _OPERATOR_MULT;
            break;

        case L'/':
            src++;
            if(*src == L'*'){
                while(1){
                    src++;
                    if(*src == L'*'){
                        src++;
                        if(*src == L'/')
                            break;
                    }

                    if(!*src){
                        returnfn = NOT_OK;
                        tokens[*line][*index].type = __ERROR__;
                        copyerror(_ERROR_COMMENT, tokens, *line, *index);
                        break;
                    }

                    if(*src == L'\n'){
                        tokens[*line][*index].type = ENDLINE;
                        (*line)++;
                        (*index) = 0;
                    }
                }

                break;
            }

            if(*src == L'/'){
                while(*src){
                    if(*src == L'\n'){
                        tokens[*line][*index].type = ENDLINE;
                        (*line)++;
                        (*index) = 0;
                        break;
                    }

                    src++;
                }

                break;
            }

            if(*src == L'='){
                tokens[*line][*index].type = _OPERATOR_DIV_EQUAL;
                break;
            }

            src--;
            tokens[*line][*index].type = _OPERATOR_DIV;
            break;

        case L'#':
            while(*src){
                if(*src == L'\n'){
                    tokens[*line][*index].type = ENDLINE;
                    (*line)++;
                    (*index) = 0;
                    break;
                }

                src++;
            }

            break;

        case L';':
            tokens[*line][*index].type = ENDLINE;
            (*line)++;
            (*index) = 0;

            break;

        case L'\n':
            tokens[*line][*index].type = ENDLINE;
            (*line)++;
            (*index) = 0;

            break;

        case L'%':
            src++;
            if(*src == L'='){
                tokens[*line][*index].type = _OPERATOR_REST_EQUAL;
                break;
            }

            src--;
            tokens[*line][*index].type = _OPERATOR_REST;
            break;

        case L'=':
            src++;
            if(*src == L'='){
                tokens[*line][*index].type = _RESERVED_CHARACTER_EQUAL_EQUAL;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_EQUAL;
            break;

        case L':':
            src++;
            if(*src == L':'){
                tokens[*line][*index].type = _RESERVED_CHARACTER_TTPOINTERS;
                break;
            }

            if(*src == L'='){
                tokens[*line][*index].type = _RESERVED_CHARACTER_EQUAL_DEFINE_TYPE;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_TPOINTERS;
            break;

        case L'.':
            src++;
            if(*src == L'.' && getnptr(src, 1) == L'.'){
                src++;
                tokens[*line][*index].type = _RESERVED_CHARACTER_TRANSFER;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_ACCESS_SCOPE;
            break;

        case L',':
            tokens[*line][*index].type = _RESERVED_CHARACTER_COMMA;
            break;

        case L'&':
            src++;
            if(*src == L'='){
                tokens[*line][*index].type = _RESERVED_CHARACTER_AND_EQUAL;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_AND;
            break;

        case L'|':
            src++;
            if(*src == L'='){
                tokens[*line][*index].type = _RESERVED_CHARACTER_OR_EQUAL;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_OR;
            break;

        case L'^':
            src++;
            if(*src == L'='){
                tokens[*line][*index].type = _RESERVED_CHARACTER_XOR_EQUAL;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_XOR;
            break;

        case L'!':
            src++;
            if(*src == L'='){
                tokens[*line][*index].type = _RESERVED_CHARACTER_DENIAL_EQUAL;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_DENIAL;
            break;

        case L'<':
            src++;
            if(*src == L'='){
                tokens[*line][*index].type = _RESERVED_CHARACTER_SMALLER_EQUAL;
                break;
            }

            if(*src == L'<'){
                if(getnptr(src, 1) == L'='){
                    src++;
                    tokens[*line][*index].type = _RESERVED_CHARACTER_MOV_BIT_LEFT_EQUAL;
                    break;
                }

                tokens[*line][*index].type = _RESERVED_CHARACTER_MOV_BIT_LEFT;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_SMALLER;
            break;

        case L'>':
            src++;
            if(*src == L'='){
                tokens[*line][*index].type = _RESERVED_CHARACTER_BIGGER_EQUAL;
                break;
            }

            if(*src == L'>'){
                if(getnptr(src, 1) == L'='){
                    src++;
                    tokens[*line][*index].type = _RESERVED_CHARACTER_MOV_BIT_RIGHT_EQUAL;
                    break;
                }

                tokens[*line][*index].type = _RESERVED_CHARACTER_MOV_BIT_RIGHT;
                break;
            }

            if(*src == L'/'){
                tokens[*line][*index].type = _RESERVED_CHARACTER_CLOSE_TAG;
                break;
            }

            src--;
            tokens[*line][*index].type = _RESERVED_CHARACTER_BIGGER;
            break;
            
        case L'(':
            tokens[*line][*index].type = _RESERVED_CHARACTER_OPEN_PARENTHESES;
            break;

        case L')':
            tokens[*line][*index].type = _RESERVED_CHARACTER_CLOSE_PARENTHESES;
            break;

        case L'[':
            tokens[*line][*index].type = _RESERVED_CHARACTER_OPEN_BRACKET;
            break;

        case L']':
            tokens[*line][*index].type = _RESERVED_CHARACTER_CLOSE_BRACKET;
            break;

        case L'{':
            tokens[*line][*index].type = _RESERVED_CHARACTER_OPEN_BLOCK;
            break;
        
        case L'}':
            tokens[*line][*index].type = _RESERVED_CHARACTER_CLOSE_BLOCK;
            break;

        default:
            tokens[*line][*index].type == __ERROR__;
            copyerror(_ERROR_INVALID_CHARACTERE, tokens, *line, *index);
            returnfn = NOT_OK;
    }

    *source = src;

    if(returnfn == NOT_OK)
        return NOT_OK;

    return returnfn;
}

static void reset(u8 *tf, u8 *output, u64 *cChars,
u64 *nChars, u64 *Tksline, u64 *index, String *word, Tokens **tokens)
{
    (*tf) = 0;
    (*cChars) = 0;
    (*nChars) = START_LINE;
    String newword = (String)realloc(*word, *nChars);
    if(newword == NULL)
        (*output) = REALLOCWORD;
    
    (*word) = newword;
    (*word)[0] = L'\0';

    if(!(*Tksline - *index - 1)){
        (*Tksline) += *Tksline >> 1;
        Tokens *newtokens = (Tokens*)realloc(tokens[*index], *Tksline);
        if(newtokens == NULL)
            (*output) = TKIREALLOC;

        tokens[*index] = newtokens;
    }
}

u8 TokenParser(Tokens **tokens, u64 *line, String src){
    u64 nlines = START_TOKENS, Tksline = START_LINE, index = 0, cChars = 0;
    u64 nChars = START_WORD, lastline = *line;
    u32 length = 0;
    u8 tf = 0, returnfn = 0, fpointer = 0, output = 0, getitt = 0;
    lchar nextchar = 1;

    String word = STRALLOC(START_WORD);
    if(word == NULL)
        output = ALLOCWORD;

    while(*src && !output){
        if(!(nlines - *line - 2)){
            nlines += nlines >> 1;
            
            Tokens **ntokens = (Tokens**)realloc(tokens, nlines);
            if(ntokens == NULL)
                return TKMREALLOC;

            tokens = ntokens;
        }

        nextchar = getnptr(src, 1);
        getitt = checkTokenValid(*src, INTERRUPTIONCHARS);

        if(!getitt && nextchar){
            word[cChars++] = *src;

            if(!(nChars - cChars - 2)){
                nChars = nChars >> 1;

                String newword = (String)realloc(word, nChars);
                if(newword == NULL)
                    output = REALLOCWORD;

                word = newword;
            }
        }

        else{
            if(!nextchar)
                if(*word && !getitt)
                    word[cChars++] = *src;

            word[cChars] = L'\0';

            length = strsize(word);

            if(!length)
                goto GETINTRR;

            if(*word >= zero && *word <= nine && *src == '.' && !fpointer){
                word[cChars++] = *src;
                fpointer = 1;

                goto TOKENFOUND;
            }

            else if(*src == '.' && fpointer){
                tokens[*line][index].type = __ERROR__;
                copyerror(_ERROR_FORMAT_IDENTIFIER, tokens, *line, index);
                
                break;
            }

            returnfn = verifyNumber(word, length);

            if(returnfn <= _ERROR_UNEXPECTED_EXPRESSION){
                tokens[*line][index].type = __ERROR__;
                copyerror(returnfn, tokens, *line, index);

                break;
            }

            fpointer = 0;

            if(returnfn != NOTNUMBER){
                tokens[*line][index].type = returnfn;

                if(returnfn == _IDENTIFIER_CONST_FLOAT){
                    tokens[*line][index].tokens.ConstValue = formatNumber(word, length);
                    tf = 1;

                    goto GETINTRR;
                }

                tokens[*line][index].tokens.Constint = formatNumber(word, length);
                tf = 1;

                goto GETINTRR;
            }

            tf = verifyKeyOrFn(word, tokens, *line, index, length);
            if(tf)
                goto GETINTRR;


            if(length > 0){
                tokens[*line][index].type = IDENTIFIERNAME;
                tokens[*line][index].tokens.IdentifierName = strfastcopy(word, length + 1);
                tf = 1;
            }

        GETINTRR:
            if((*src == L'\n' || *src == L';') && !index)
                goto TOKENFOUND;

            if(!nextchar && !getitt)
                goto TOKENFOUND;

            if(*src == L' ' || *src == L'\t')
                goto TOKENFOUND;

            u8 comment = ((*src == L'/' && (*(src + 1) == L'*' ||
                         *(src + 1) == L'/')) || *src == L'#') ? 1 : 0;

            if(tf && (!comment || *word))
                index++;

            returnfn = Interruption(&src, tokens, line, &index);
            if(tokens[*line][index].type == __ERROR__)
                break;

            if(*line != lastline){
                lastline = *line;
                reset(&tf, &output, &cChars, &nChars, &Tksline, &index, &word, tokens);
                goto TOKENFOUND;
            }

            if(returnfn >= ALLOCWORD && returnfn <= TKMREALLOC){
                output = returnfn;
                goto TOKENFOUND;
            }

            if(returnfn == OK){
                tf = 1;
                goto TOKENFOUND;
            }

        TOKENFOUND:
            if(tf){
                index++;
                reset(&tf, &output, &cChars, &nChars, &Tksline, &index, &word, tokens);
            }
        }

        if(*src)
            src++;

        if(output){
            tokens[*line][index].type = __ERROR__;
            copyerror(_ERROR_COMPILATION, tokens, *line, index);
        }
    }

    if(!output){
        if(tokens[*line][index].type != __ERROR__)
            tokens[*line][index].type = ENDLINE;
        (*line)++;
    }

    free(word);

    return output;
}

Tokens** allocTokens(){
    Tokens **tokens = (Tokens**)malloc(START_TOKENS * sizeof(Tokens*));
    if(tokens == NULL)
        return NULL;

    u64 i = 0;
    for(; i < START_TOKENS; i++){
        tokens[i] = (Tokens*)malloc(START_LINE * sizeof(Tokens));
        if(tokens[i] == NULL)
            return NULL;
    }

    return tokens;
}

void freeTokens(Tokens **tokens, u64 nlines, u64 i){
    for(; i < nlines; i++){
        u32 j = 0;
        while(tokens[i][j].type < ENDLINE){
            if(tokens[i][j].type == IDENTIFIERNAME && tokens[i][j].tokens.IdentifierName != NULL)
                free(tokens[i][j].tokens.IdentifierName);

            else if(tokens[i][j].type >= _IDENTIFIER_CONST_DEC && tokens[i][j].type <= _IDENTIFIER_CONST_BIN &&
                    tokens[i][j].tokens.Constint != NULL)
                free(tokens[i][j].tokens.Constint);

            else if((tokens[i][j].type == _IDENTIFIER_CONST_FLOAT ||
                    tokens[i][j].type == _IDENTIFIER_CONST_STRING) && tokens[i][j].tokens.ConstValue != NULL)
                free(tokens[i][j].tokens.ConstValue);

            j++;
        }

        free(tokens[i]);
    }

    free(tokens);
}

// int main(){
//     Tokens **tokens = (Tokens**)malloc(START_TOKENS * sizeof(Tokens*));
//     String src = L"i32 n = 35_000;\n\n\n\n\n\nconst object = 78;\n\nwrt(\"Hello, World\");\n\nstring\ni32\n\n\nu8";
//     u64 line = 0;

//     int i = 0, j = 0;
//     for(; i < START_TOKENS; i++)
//         tokens[i] = (Tokens*)malloc(START_LINE * sizeof(Tokens));

//     printf("out: %d\n\n", TokenParser(tokens, &line, src));
    
//     for(i = 0; i < line; i++){
//         j = 0;
//         while(tokens[i][j].type != ENDLINE && tokens[i][j].type != __ERROR__){
//             printf("[i][j]: [%d][%d]\n", i, j);
//             if(tokens[i][j].type == _KEYWORD)
//                 printf("KEYWORD: %d\n", tokens[i][j].tokens.TokenKeyWord);

//             else if(tokens[i][j].type == _INTERNAL_FN)
//                 printf("INTERNAL FN: %d\n", tokens[i][j].tokens.TokenFn);

//             else if(tokens[i][j].type == IDENTIFIERNAME){
//                 wprintf(L"IDENTIFIER NAME: %ls\n", tokens[i][j].tokens.IdentifierName);
//                 free(tokens[i][j].tokens.IdentifierName);
//             }

//             else if(tokens[i][j].type == _IDENTIFIER_CONST_BIN || tokens[i][j].type == _IDENTIFIER_CONST_HEX ||
//                 tokens[i][j].type == _IDENTIFIER_CONST_DEC){
//                     wprintf(L"CONST INTEGER: %ls\n", tokens[i][j].tokens.Constint);
//                     free(tokens[i][j].tokens.Constint);
//             }

//             else if(tokens[i][j].type == _IDENTIFIER_CONST_FLOAT){
//                 wprintf(L"CONST FLOAT: %ls\n", tokens[i][j].tokens.ConstValue);
//                 free(tokens[i][j].tokens.ConstValue);
//             }

//             else if(tokens[i][j].type == _IDENTIFIER_CONST_STRING){
//                 wprintf(L"CONST STRING: %ls\n", tokens[i][j].tokens.ConstValue);
//                 free(tokens[i][j].tokens.ConstValue);
//             }

//             else if(tokens[i][j].type == _IDENTIFIER_CONST_CHAR)
//                 wprintf(L"CONST CHAR: %lc\n", tokens[i][j].tokens.ConstChar);

//             else
//                 printf("TOKEN: %d\n", tokens[i][j].type);

//             j++;
//         }

//         if(tokens[i][j].type == __ERROR__)
//             wprintf(L"Line %d. %ls\n", i + 1, tokens[i][j].tokens.TokenError);

//         free(tokens[i]);
//     }

//     free(tokens);
// }

// gcc Token.c utils.c libString.c memory.c -o tkg.exe