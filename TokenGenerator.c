#include "includedefines/referenceTypes.h"
#include "includedefines/sizeDefined.h"
#include "includedefines/allocs.h"
#include "includeerror/errors.h"
#include "compiler/preObjects.h"
#include "includelib/libString.h"
#include "includelib/libIo.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>


void TokenGenerator(String sourceCode, Token *token, i64 *indexToken){
    i8 ERROR = 0;
    i64 counterCharacteres = 0, limit = INITSIZEWORDIDENTIFIER, tokenFound = 0, counter = 0;
    String word = STRALLOC(limit);

    while(*sourceCode){
        if(!(checkTokenValid(*sourceCode, L"=+*-/%%(){}[]&$@#!|^,;:<>?\"'\\ \n\t\r\0"))){
            word[counterCharacteres] = *sourceCode;
            counterCharacteres++;

            if(counterCharacteres == limit - 2){
                limit += limit / 2;
                String newWord = (String)realloc(word, limit * sizeof(lchar));
                word = newWord;
            }
        }

        word[counterCharacteres] = L'\0';

        i64 identifyi32ernalOper = keyWordIdentify(word, i32ernalOperTable, INTERNALOPERQTTY);
        i64 identifyKeyWord = 0;

        if(!identifyi32ernalOper){
            identifyKeyWord = keyWordIdentify(word, KeyWordTable, KEYWORDsQTTY);
        }

        if(identifyi32ernalOper || identifyKeyWord){
            register i8 flag = 0;
            sourceCode++;
            if(checkTokenValid(*sourceCode, ALLCHARACTERES)){
                sourceCode--;
                flag = 1;
            }

            if(*sourceCode == '\0' && !flag){
                token[*indexToken].type = __ERROR__;
                token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_SYNTAX_KEYWORD]);
                (*indexToken)++;
                free(word);
                return;
            }

            if(!flag){
                if(identifyi32ernalOper){
                    i64 codeFnCall = codeString(word);
                    switch(codeFnCall){
                        case WRT:
                        case RD:
                        case GETi8:
                        case IMPORT:
                        case LENGTH:
                        case TYPE:
                        case READFILEBYTE:
                        case READFILELINE:
                        case READFILE:
                        case WRITEFILE:
                        case FILEOPEN:
                        case FILECLOSE:
                            token[*indexToken].type = _INTERNAL_FN;
                    }

                    token[*indexToken].Identifiers.internaFn.fnCode = codeFnCall;
                }
                else{
                    switch(codeString(word)){
                        case CONTINUE:
                            token[*indexToken].type = _KEYWORD_continue;
                            break;
                        case AND:
                            token[*indexToken].type = _KEYWORD_and;
                            break;
                        case OR:
                            token[*indexToken].type = _KEYWORD_or;
                            break;
                        case RETURN:
                            token[*indexToken].type = _KEYWORD_return;
                            break;
                        case ENDIF:
                            token[*indexToken].type = _KEYWORD_endif;
                            break;
                        case IN:
                            token[*indexToken].type = _KEYWORD_in;
                            break;
                        case BREAK:
                            token[*indexToken].type = _KEYWORD_break;
                            break;
                        case ELSE:
                            token[*indexToken].type = _KEYWORD_else;
                            break;
                        case IF:
                            token[*indexToken].type = _KEYWORD_if;
                            break;
                        case ELIF:
                            token[*indexToken].type = _KEYWORD_elif;
                            break;
                        case FOR:
                            token[*indexToken].type = _KEYWORD_for;
                            break;
                        case WHILE:
                            token[*indexToken].type = _KEYWORD_while;
                            break;
                        case SWITCH:
                            token[*indexToken].type = _KEYWORD_switch;
                            break;
                        case FN:
                            token[*indexToken].type = _KEYWORD_fn;
                            break;
                        case CONST:
                            token[*indexToken].type = _KEYWORD_const;
                            break;
                        case _i32:
                            token[*indexToken].type = _KEYWORD_int;
                            break;
                        case _i64:
                            token[*indexToken].type = _KEYWORD_i64;
                            break;
                        case _i16:
                            token[*indexToken].type = _KEYWORD_short;
                            break;
                        case _i8:
                            token[*indexToken].type = _KEYWORD_byte;
                            break;
                        case _Float:
                            token[*indexToken].type = _KEYWORD_f32;
                            break;
                        case _Double:
                            token[*indexToken].type = _KEYWORD_f64;
                            break;
                        case _String:
                            token[*indexToken].type = _KEYWORD_str;
                            break;
                        case _CHAR:
                            token[*indexToken].type = _KEYWORD_char;
                            break;
                        case CASE:
                            token[*indexToken].type = _KEYWORD_case;
                            break;
                        case DEFAULT:
                            token[*indexToken].type = _KEYWORD_default;
                            break;
                        case CLASS:
                            token[*indexToken].type = _KEYWORD_class;
                            break;
                        case THIS:
                            token[*indexToken].type = _KEYWORD_this;
                            break;
                        case METHOD:
                            token[*indexToken].type = _KEYWORD_method;
                            break;
                        case ATTRIBUTE:
                            token[*indexToken].type = _KEYWORD_attribute;
                            break;
                        case PUBLIC:
                            token[*indexToken].type = _KEYWORD_public;
                            break;
                        case PRIVATE:
                            token[*indexToken].type = _KEYWORD_private;
                            break;
                        case EXPORT:
                            token[*indexToken].type = _KEYWORD_export;
                            break;
                        case TRY:
                            token[*indexToken].type = _KEYWORD_try;
                            break;
                        case CATCH:
                            token[*indexToken].type = _KEYWORD_catch;
                            break;
                        case ALL:
                            token[*indexToken].type = _KEYWORD_all;
                            break;
                        case SYS:
                            token[*indexToken].type = _KEYWORD_sys;
                            break;
                    }
                }

                sourceCode--;
                tokenFound = 1;
            }
        }

        sourceCode++;
        lchar nextCharacters = *sourceCode;
        sourceCode--;

        if((checkTokenValid(*sourceCode, L"=+*-/%%(){}[]&$@#!|^,;:.<>?°~º´`¨/ª¹²³£¢¬§\"'\\ \n\t\r") ||
        nextCharacters == L'\0') && tokenFound == 0){
            register i8 flagAccessScope = 1, flagTokenPointer = 1;
            if(word[0] != L'\0'){
                if(word[0] == L'0'){
                    sourceCode++;
                    if(((int)word[1] >= 48 && (int)word[1] <= 57) && (word[1] != 'x' && word[1] != 'X')
                    && codeString(word) != 48){
                        token[*indexToken].type = __ERROR__;
                        token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_INIT_IDENTIFIER]);
                        (*indexToken)++;
                        free(word);
                        return;
                    }

                    sourceCode--;
                }

                if((int)word[0] >= 48 && (int)word[0] <= 57){
                    if(*sourceCode == '.'){
                        flagAccessScope = 0;
                        flagTokenPointer = 0;
                    }

                    if(flagAccessScope){
                        u8 flagFloat = 0, flagHex = 0;
                        String auxWord;
                        auxWord = strcopy(word);

                        while(*auxWord){
                            if(!(checkTokenValid(*auxWord, L"0123456789aAbBcCdDeEfFxX."))){
                                token[*indexToken].type = __ERROR__;
                                token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_FORMAT_IDENTIFIER]);
                                (*indexToken)++;
                                free(word);
                                free(auxWord);
                                return;
                            }

                            else if(*auxWord == L'x' || *auxWord == L'X'){
                                auxWord++;
                                if(!flagFloat && !flagHex && *auxWord != L'\0' && word[0] == L'0'){
                                    flagHex = 1;
                                    auxWord--;
                                }
                                else{
                                    token[*indexToken].type = __ERROR__;
                                    token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_FORMAT_IDENTIFIER]);
                                    (*indexToken)++;
                                    free(word);
                                    free(auxWord);
                                    return;
                                }
                            }

                            else if(*auxWord == L'.'){
                                auxWord++;
                                if(!flagFloat && *auxWord != L'\0'){
                                    flagFloat = 1;
                                    auxWord--;
                                }
                                else{
                                    token[*indexToken].type = __ERROR__;
                                    token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_FORMAT_IDENTIFIER]);
                                    (*indexToken)++;
                                    free(word);
                                    free(auxWord);
                                    return;
                                }
                            }

                            auxWord++;
                        }

                        token[*indexToken].type = (flagFloat) ? _IDENTIFIER_CONST_Float : _IDENTIFIER_CONST_i32;
                        token[*indexToken].Identifiers.constData.addinfo = (flagHex) ? HEX : DEC;
                        token[*indexToken].Identifiers.constData.data = strcopy(word);
                    }
                }

                else{
                    if(codeString(word) != _INTERNAL_FNCHARPOINTERNUMCODE){
                        if(*sourceCode == L'.'){
                            word[counterCharacteres - 1] = L'\0';
                            counterCharacteres--;
                        }

                        token[*indexToken].type = __IDENTIFIER__;
                        token[*indexToken].Identifiers.Data.nameIdentifier = strcopy(word);
                    }

                    else{
                        (*indexToken)--;
                    }
                }

                tokenFound = flagTokenPointer;
            }

            if(*sourceCode == L'.' && flagAccessScope){
                if(tokenFound){
                    (*indexToken)++;
                }
                token[*indexToken].type = _RESERVED_CHARACTER_ACCESS_SCOPE;
            }

            else if(*sourceCode == L'"' || *sourceCode == L'\''){
                u8 flagChar = 0;

                if(tokenFound){
                    (*indexToken)++;
                }

                word[0] = L'\0';
                counterCharacteres = 0;
                limit = INITSIZEWORDIDENTIFIER;

                if(*sourceCode == L'"'){
                    sourceCode++;
                    while(1){
                        if(*sourceCode == L'"'){
                            break;
                        }
                        else if(*sourceCode == L'\0'){
                            token[*indexToken].type = __ERROR__;
                            token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_String]);
                            (*indexToken)++;
                            free(word);
                            return;
                        }
                        else{
                            word[counterCharacteres] = *sourceCode;
                            counterCharacteres++;

                            if(counterCharacteres == limit - 2){
                                limit += limit / 2;
                                String newWord = (String)realloc(word, limit * sizeof(lchar));
                                word = newWord;
                            }
                        }

                        sourceCode++;
                    }

                    word[counterCharacteres] = L'\0';

                    token[*indexToken].type = _IDENTIFIER_CONST_STR;
                    token[*indexToken].Identifiers.constData.data = strcopy(word);
                    tokenFound = 1;
                }

                else{
                    sourceCode++;
                    if(*sourceCode == '\\'){
                        word[0] = *sourceCode;
                        sourceCode++;
                        if(checkTokenValid(*sourceCode, L"nt0r'\"\\")){
                            word[1] = *sourceCode;
                            flagChar = 2;
                        }
                        else{
                            token[*indexToken].type = __ERROR__;
                            token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_INVALID_SCAPE_CHARACTERE]);
                            (*indexToken)++;
                            free(word);
                            return;
                        }
                    }

                    else if(checkTokenValid(*sourceCode, ALLCHARACTERES) ||
                       checkTokenValid(*sourceCode, TOKENSCHARACTERES)){
                        word[0] = *sourceCode;
                        flagChar = 1;
                    }
                    sourceCode++;

                    if(*sourceCode != L'\''){
                        token[*indexToken].type = __ERROR__;
                        token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_INVALID_CONST_CHAR]);
                        (*indexToken)++;
                        free(word);
                        return;
                    }

                    else{
                        word[flagChar] = '\0';
                        token[*indexToken].type = _IDENTIFIER_CONST_CHAR;
                        token[*indexToken].Identifiers.constData.data = strcopy(word);
                    }

                    tokenFound = 1;
                }
            }

            else if((*sourceCode != L' ' && *sourceCode != L'"' && *sourceCode != L'\'' && *sourceCode != L'.')){
                register i8 flag = 1;
                if(tokenFound){
                    (*indexToken)++;
                }
                switch(*sourceCode){
                    case L'=':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*indexToken].type = _RESERVED_CHARACTER_EQUAL_EQUAL;
                        }
                        else{
                            sourceCode--;
                            token[*indexToken].type = _RESERVED_CHARACTER_EQUAL;
                        }
                        break;
                    
                    case L'+':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*indexToken].type = _OPERATOR_ADD_EQUAL;
                        }
                        else if(*sourceCode == L'+'){
                            token[*indexToken].type = _OPERATOR_ADD_ADD;
                        }
                        else{
                            sourceCode--;
                            token[*indexToken].type = _OPERATOR_ADD;
                        }
                        break;

                    case L'-':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*indexToken].type = _OPERATOR_SUB_EQUAL;
                        }
                        else if(*sourceCode == L'-'){
                            token[*indexToken].type = _OPERATOR_SUB_SUB;
                        }
                        else if(*sourceCode == L'>'){
                            token[*indexToken].type = _RESERVED_CHARACTER_ADDRESS_POINTER;
                        }
                        else{
                            sourceCode--;
                            token[*indexToken].type = _OPERATOR_SUB;
                        }
                        break;

                    case L'/':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*indexToken].type = _OPERATOR_DIV_EQUAL;
                        }
                        else if(*sourceCode == L'/'){
                            while(1){
                                if(*sourceCode == L'\n' || nextCharacters == L'\0'){
                                    break;
                                }
                                else{
                                    sourceCode++;
                                }
                            }
                            flag = 0;
                        }
                        else if(*sourceCode == L'*'){
                            while(1){
                                if(*sourceCode == L'*'){
                                    sourceCode++;
                                    if(*sourceCode == L'/'){
                                        break;
                                    }
                                }
                                else{
                                    sourceCode++;
                                }
                                flag = 0;
                            }
                        }
                        else{
                            sourceCode--;
                            token[*indexToken].type = _OPERATOR_DIV;
                        }
                        break;

                    case L'*':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*indexToken].type = _OPERATOR_MULT_EQUAL;
                        }
                        else if(*sourceCode == L'*'){
                            sourceCode++;
                            if(*sourceCode == L'='){
                                token[*indexToken].type = _OPERATOR_POW_EQUAL;
                            }
                            else{
                                sourceCode--;
                                token[*indexToken].type = _OPERATOR_POW;
                            }
                        }
                        else{
                            sourceCode--;
                            token[*indexToken].type = _OPERATOR_MULT;
                        }
                        break;

                    case L'%':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*indexToken].type = _OPERATOR_REST_EQUAL;
                        }
                        else{
                            sourceCode--;
                            token[*indexToken].type = _OPERATOR_REST;
                        }
                        break;

                    case L'(':
                        token[*indexToken].type = _RESERVED_CHARACTER_OPEN_EXPRESS;
                        break;

                    case L')':
                        token[*indexToken].type = _RESERVED_CHARACTER_CLOSE_EXPRESS;
                        break;

                    case L'{':
                        token[*indexToken].type = _RESERVED_CHARACTER_OPEN_BLOCK;
                        break;
                    
                    case L'}':
                        token[*indexToken].type = _RESERVED_CHARACTER_CLOSE_BLOCK;
                        break;

                    case L'[':
                        token[*indexToken].type = _RESERVED_CHARACTER_OPEN_BRACKET;
                        break;

                    case L']':
                        token[*indexToken].type = _RESERVED_CHARACTER_CLOSE_BRACKET;
                        break;

                    case L'<':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*indexToken].type = _RESERVED_CHARACTER_SMALLER_EQUAL;
                        }
                        else if(*sourceCode == L'<'){
                            token[*indexToken].type = _RESERVED_CHARACTER_MOV_BIT_LEFT;
                        }
                        else{
                            token[*indexToken].type = _RESERVED_CHARACTER_SMALLER;
                            sourceCode--;
                        }
                        break;

                    case L'>':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*indexToken].type = _RESERVED_CHARACTER_BIGGER_EQUAL;
                        }
                        else if(*sourceCode == L'>'){
                            token[*indexToken].type = _RESERVED_CHARACTER_MOV_BIT_RIGHT;
                        }
                        else{
                            token[*indexToken].type = _RESERVED_CHARACTER_BIGGER;
                            sourceCode--;
                        }
                        break;

                    case L'&':
                        token[*indexToken].type = _RESERVED_CHARACTER_AND;
                        break;

                    case L'|':
                        token[*indexToken].type = _RESERVED_CHARACTER_OR;
                        break;

                    case L'^':
                        token[*indexToken].type = _RESERVED_CHARACTER_XOR;
                        break;

                    case L',':
                        token[*indexToken].type = _RESERVED_CHARACTER_COMMA;
                        break;

                    case L';':
                        token[*indexToken].type = _RESERVED_CHARACTER_SEMICOLON;
                        break;

                    case L':':
                        sourceCode++;
                        if(token[*indexToken - 2].type == _KEYWORD_case ||
                           token[*indexToken - 1].type == _KEYWORD_default){
                            token[*indexToken].type = _RESERVED_CHARACTER_OPEN_CASE_AND_DEFAULT;
                            sourceCode--;
                        }
                        else if(*sourceCode == L':'){
                            token[*indexToken].type = _KEYWORD_dataStructure;
                        }
                        else{
                            token[*indexToken].type = _KEYWORD_variable;
                            sourceCode--;
                        }
                        break;

                    case L'\n':
                        token[*indexToken].type = _RESERVED_CHARACTER_BROKEN_LINE;
                        break;

                    default:
                        if((nextCharacters != L'\0')||
                        nextCharacters == '\0' && checkTokenValid(*sourceCode, L"=+*-/%%(){}[]&$@#!|^,;:.<>?°~º´`¨/ª¹²³£¢¬§\"'\\ \n\t\r")){
                            token[*indexToken].type = __ERROR__;
                            token[*indexToken].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_INVALID_CHARACTERE]);
                            free(word);
                            return;
                        }
                        else{
                            flag = 0;
                        }
                }

                tokenFound = flag;
            }

            else{
                if(*sourceCode != L'.' && !flagAccessScope){
                    word[0] = '\0';
                    counterCharacteres = 0;
                    limit = INITSIZEWORDIDENTIFIER;
                }
            }
        }

        if(tokenFound){
            word[0] = L'\0';
            counterCharacteres = 0;
            limit = INITSIZEWORDIDENTIFIER;
            (*indexToken)++;
            tokenFound = 0;
        }

        sourceCode++;
    }

    if(word != NULL){
        free(word);
    }
}

int main(){
    String str = L"int:: array = [35, 0x3F]";
    register i64 sourceSize = strsize(str);

    Token *tokens = (Token*)malloc(sizeof(Token) * 1024);
    i64 indexToken = 0, i = 0;

    TokenGenerator(str, tokens, &indexToken);

    while(i < indexToken){
        printf("token: %d\n", tokens[i].type);
        if(tokens[i].type == __IDENTIFIER__){
            WindowsWrt(L"name: ", tokens[i].Identifiers.Data.nameIdentifier);
            printf("\n");
        }
        else if(tokens[i].type == __ERROR__){
            WindowsWrt(tokens[i].Identifiers.error.dataError, L"\n");
        }

        else if(tokens[i].type == _IDENTIFIER_CONST_i32 || tokens[i].type == _IDENTIFIER_CONST_Float ||
                tokens[i].type == _IDENTIFIER_CONST_STR || tokens[i].type == _IDENTIFIER_CONST_CHAR){
            WindowsWrt(L"value: ", tokens[i].Identifiers.constData.data);
            printf("\n");
        }

        else if(tokens[i].type == _INTERNAL_FN){
            printf("i32ernal fn: %d\n", tokens[i].Identifiers.internaFn.fnCode);
            printf("\n");
        }

        i++;
    }

    free(tokens);

    return 0;
}
