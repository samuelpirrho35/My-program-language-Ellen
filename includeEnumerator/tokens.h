#ifndef TOKENS_H
#define TOKENS_H

#include "../includedefines/sizeDefined.h"
#include "../includedefines/defines.h"

typedef enum{
    _KEYWORD_if = 1,
    _KEYWORD_elif,
    _KEYWORD_else,
    _KEYWORD_while,
    _KEYWORD_for,
    _KEYWORD_switch,
    _KEYWORD_break,
    _KEYWORD_case,
    _KEYWORD_default,
    _KEYWORD_continue,
    _KEYWORD_dataStructure,
    _KEYWORD_variable,
    _KEYWORD_fn,
    _KEYWORD_InternalOper,
    _KEYWORD_return,
    _KEYWORD_const,
    _KEYWORD_int,
    _KEYWORD_short,
    _KEYWORD_byte,
    _KEYWORD_Long,
    _KEYWORD_float,
    _KEYWORD_double,
    _KEYWORD_str,
    _KEYWORD_char,
    _KEYWORD_FILE,
    _KEYWORD_ArrayList,
    _KEYWORD_Hash,
    _KEYWORD_and,
    _KEYWORD_or,
    _KEYWORD_in,
    _KEYWORD_endif,
    _KEYWORD_class,
    _KEYWORD_this,
    _KEYWORD_method,
    _KEYWORD_attribute,
    _KEYWORD_public,
    _KEYWORD_private,
    _KEYWORD_sys,
    _KEYWORD_try,
    _KEYWORD_catch,
    _KEYWORD_export,
    _KEYWORD_all,
    _KEYWORD_new,
    _KEYWORD_Resize,
    _INTERNAL_FN,
    __IDENTIFIER__,
    _IDENTIFIER_CONST_Int,
    _IDENTIFIER_CONST_Float,
    _IDENTIFIER_CONST_STR,
    _IDENTIFIER_CONST_CHAR,
    _IDENTIFIER_CONST_LIST,
    _IDENTIFIER_CONST_PSEUDOOBJECTS,
    _IDENTIFIER_int,
    _IDENTIFIER_str,
    _IDENTIFIER_float,
    _IDENTIFIER_list,
    _IDENTIFIER_array,
    _IDENTIFIER_pseudoObjects,
    _IDENTIFIER_class,
    _OPERATOR_ADD,
    _OPERATOR_SUB, 
    _OPERATOR_DIV,
    _OPERATOR_MULT,
    _OPERATOR_REST,
    _OPERATOR_POW,
    _OPERATOR_ADD_ADD,
    _OPERATOR_SUB_SUB,
    _OPERATOR_ADD_EQUAL,
    _OPERATOR_SUB_EQUAL,
    _OPERATOR_DIV_EQUAL,
    _OPERATOR_MULT_EQUAL,
    _OPERATOR_POW_EQUAL,
    _OPERATOR_REST_EQUAL,
    _RESERVED_CHARACTER_EQUAL,
    _RESERVED_CHARACTER_EQUAL_EQUAL,
    _RESERVED_CHARACTER_DENIAL,
    _RESERVED_CHARACTER_DIFFERENT,
    _RESERVED_CHARACTER_SMALLER,
    _RESERVED_CHARACTER_BIGGER,
    _RESERVED_CHARACTER_SMALLER_EQUAL,
    _RESERVED_CHARACTER_BIGGER_EQUAL,
    _RESERVED_CHARACTER_AND,
    _RESERVED_CHARACTER_OR,
    _RESERVED_CHARACTER_XOR,
    _RESERVED_CHARACTER_MOV_BIT_LEFT,
    _RESERVED_CHARACTER_MOV_BIT_RIGHT,
    _RESERVED_CHARACTER_OPEN_EXPRESS,
    _RESERVED_CHARACTER_CLOSE_EXPRESS,
    _RESERVED_CHARACTER_OPEN_BLOCK,
    _RESERVED_CHARACTER_CLOSE_BLOCK,
    _RESERVED_CHARACTER_OPEN_BRACKET,
    _RESERVED_CHARACTER_CLOSE_BRACKET,
    _RESERVED_CHARACTER_COMMA,
    _RESERVED_CHARACTER_ACCESS_SCOPE,
    _RESERVED_CHARACTER_OPEN_CASE_AND_DEFAULT,
    _RESERVED_CHARACTER_SEMICOLON,
    _RESERVED_CHARACTER_BROKEN_LINE,
    _RESERVED_CHARACTER_ADDRESS_POINTER,
    __ERROR__
}TokenType;


typedef enum{
    _ERROR_FORMAT_IDENTIFIER,
    _ERROR_INVALID_NAME_IDENTIFIER,
    _ERROR_INIT_IDENTIFIER,
    _ERROR_IDENTIFIER_NOT_INITIATED,
    _ERROR_SYNTAX_KEYWORD,
    _ERROR_String,
    _ERROR_INVALID_CHARACTERE,
    _ERROR_INVALID_SCAPE_CHARACTERE,
    _ERROR_INVALID_CONST_CHAR
}Errors;

typedef enum{
    IF              = 207,
    ELIF            = 416,
    ELSE            = 425,
    WHILE           = 537,
    FOR             = 327,
    BREAK           = 517,
    SWITCH          = 658,
    DEFAULT         = 741,
    CASE            = 412,
    CONTINUE        = 869,
    FN              = 212,
    CLASS           = 502,
    THIS            = 408,
    METHOD          = 609,
    ATTRIBUTE       = 948,
    PUBLIC          = 639,
    PRIVATE         = 763,
    _Int            = 331,
    _String         = 663,
    _CHAR           = 414,
    _Float          = 534,
    _Double         = 635,
    _Long           = 432,
    _Short          = 560,
    _Byte           = 436,
    _FILE           = 288,
    AND             = 307,
    OR              = 225,
    RETURN          = 672,
    IN              = 215,
    ENDIF           = 518,
    SYS             = 351,
    WRT             = 349,
    RD              = 214,
    GETByte         = 756,
    LENGTH          = 642,
    TYPE            = 418,
    READFILEBYTE    = 1168,
    READFILELINE    = 1156,
    READFILE        = 764,
    WRITEFILE       = 907,
    FILEOPEN        = 786,
    FILECLOSE       = 886,
    TRY             = 319,
    CATCH           = 483,
    CONST           = 551,
    IMPORT          = 667,
    EXPORT          = 674,
    ALL             = 313,
    NEW             = 330,
    ARRAYLIST       = 923,
    HASH            = 388,
    STRUCT          = 645,
    RESIZE          = 626
}ReservedWordsCodes;

String KeyWordTable[KEYWORDsQTTY] = {
    L"if", L"elif", L"else", L"for",
    L"while", L"int", L"Long", L"short",
    L"byte", L"float", L"String", L"char",
    L"double", L"Class", L"This", L"Method",
    L"Attribute", L"public", L"private", L"break",
    L"continue", L"and", L"or", L"endif",
    L"return", L"case", L"default", L"in",
    L"sys", L"Try", L"Catch", L"const",
    L"export", L"all", L"switch", L"fn",
    L"new", L"ArrayList", L"Hash", L"Resize",
    L"FILE"
};

String InternalOperTable[INTERNALOPERQTTY] = {
    L"wrt", L"rd", L"length", L"import",
    L"getbyte", L"Type", L"ReadFileByte", L"ReadFileLine",
    L"ReadFile", L"WriteFile", L"FileOpen", L"FileClose"
};

#endif