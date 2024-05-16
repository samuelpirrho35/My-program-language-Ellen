#ifndef TOKENS_H
#define TOKENS_H

#include "../includedefines/sizeDefined.h"
#include "../includedefines/defines.h"

typedef enum{
    _KEYWORD = 1,
    _KEYWORD_if,                               _KEYWORD_elif,
    _KEYWORD_else,                             _KEYWORD_while,
    _KEYWORD_for,                              _KEYWORD_switch,
    _KEYWORD_break,                            _KEYWORD_case,
    _KEYWORD_default,                          _KEYWORD_continue,                    
    _KEYWORD_fn,                               _KEYWORD_i32ernalOper,
    _KEYWORD_return,                           _KEYWORD_const,
    _KEYWORD_i32,                              _KEYWORD_i16,
    _KEYWORD_i8,                             _KEYWORD_i64,
    _KEYWORD_u32,                              _KEYWORD_u16,
    _KEYWORD_u8,                             _KEYWORD_u64,
    _KEYWORD_f32,                              _KEYWORD_f64,
    _KEYWORD_string,                              _KEYWORD_char,
    _KEYWORD_FILE,                             _KEYWORD_ArrayList,
    _KEYWORD_HashMap,                             _KEYWORD_and,
    _KEYWORD_or,                               _KEYWORD_in,
    _KEYWORD_endif,                            _KEYWORD_class,
    _KEYWORD_this,                             _KEYWORD_method,
    _KEYWORD_attribute,                        _KEYWORD_public,
    _KEYWORD_private,                          _KEYWORD_sys,
    _KEYWORD_try,                              _KEYWORD_catch,
    _KEYWORD_export,                           _KEYWORD_all,
    _KEYWORD_new,                              _KEYWORD_Resize,
    _INTERNAL_FN,                              __IDENTIFIER__,
    _IDENTIFIER_CONST_DEC,                     _IDENTIFIER_CONST_FLOAT,
    _IDENTIFIER_CONST_HEX,                     _IDENTIFIER_CONST_BIN,
    _IDENTIFIER_CONST_STRING,                  _IDENTIFIER_CONST_CHAR,
    _IDENTIFIER_CONST_LIST,                    _IDENTIFIER_CONST_HASHMAP,
    _IDENTIFIER_int,                           _IDENTIFIER_str,
    _IDENTIFIER_f32,                           _IDENTIFIER_list,
    _IDENTIFIER_array,                         _IDENTIFIER_pseudoObjects,
    _IDENTIFIER_class,                         _OPERATOR_ADD,
    _OPERATOR_SUB,                             _OPERATOR_DIV,
    _OPERATOR_MULT,                            _OPERATOR_REST,
    _OPERATOR_POW,                             _OPERATOR_ADD_ADD,
    _OPERATOR_SUB_SUB,                         _OPERATOR_ADD_EQUAL,
    _OPERATOR_SUB_EQUAL,                       _OPERATOR_DIV_EQUAL,
    _OPERATOR_MULT_EQUAL,                      _OPERATOR_POW_EQUAL,
    _OPERATOR_REST_EQUAL,                      _RESERVED_CHARACTER_EQUAL,
    _RESERVED_CHARACTER_EQUAL_EQUAL,           _RESERVED_CHARACTER_DENIAL,          
    _RESERVED_CHARACTER_SMALLER,               _RESERVED_CHARACTER_ADDRESS_POINTER,
    _RESERVED_CHARACTER_BIGGER,                _RESERVED_CHARACTER_SMALLER_EQUAL,
    _RESERVED_CHARACTER_BIGGER_EQUAL,          _RESERVED_CHARACTER_AND,
    _RESERVED_CHARACTER_OR,                    _RESERVED_CHARACTER_XOR,
    _RESERVED_CHARACTER_AND_EQUAL,             _RESERVED_CHARACTER_OR_EQUAL,
    _RESERVED_CHARACTER_MOV_BIT_LEFT,          _RESERVED_CHARACTER_MOV_BIT_RIGHT,
    _RESERVED_CHARACTER_MOV_BIT_LEFT_EQUAL,    _RESERVED_CHARACTER_MOV_BIT_RIGHT_EQUAL,
    _RESERVED_CHARACTER_OPEN_PARENTHESES,      _RESERVED_CHARACTER_CLOSE_PARENTHESES,
    _RESERVED_CHARACTER_OPEN_BLOCK,            _RESERVED_CHARACTER_CLOSE_BLOCK,
    _RESERVED_CHARACTER_OPEN_BRACKET,          _RESERVED_CHARACTER_CLOSE_BRACKET,
    _RESERVED_CHARACTER_COMMA,                 _RESERVED_CHARACTER_ACCESS_SCOPE,
    _RESERVED_CHARACTER_OPEN_CASE_AND_DEFAULT, _RESERVED_CHARACTER_SEMICOLON,
    _RESERVED_CHARACTER_BROKEN_LINE,           _RESERVED_CHARACTER_XOR_EQUAL,
    _RESERVED_CHARACTER_TPOINTERS,             _RESERVED_CHARACTER_TTPOINTERS,
    _RESERVED_CHARACTER_TRANSFER,              _RESERVED_CHARACTER_DENIAL_EQUAL,
    _RESERVED_CHARACTER_CLOSE_TAG,             
    ENDLINE,                                   IDENTIFIERNAME,
    __ERROR__
}TokenType;


typedef enum{
    _ERROR_FORMAT_IDENTIFIER,
    _ERROR_INVALID_NAME_IDENTIFIER,
    _ERROR_INIT_WITH_ZERO,
    _ERROR_UNEXPECTED_EXPRESSION,
    _ERROR_IDENTIFIER_NOT_INITIATED,
    _ERROR_SYNTAX_KEYWORD,
    _ERROR_STRING,
    _ERROR_INVALID_CHARACTERE,
    _ERROR_INVALID_SCAPE_CHARACTERE,
    _ERROR_INVALID_CONST_CHAR,
    _ERROR_COMMENT
}Errors;

// typedef enum{
//     IF        = 425,  ELIF      = 958,  ELSE         = 986,  FOR      = 726,
//     WHILE     = 1275, _I32      = 427,  _I64         = 440,  _I16     = 429,
//     _I8       = 333,  U64       = 476,  _U32         = 463,  _U16     = 465,
//     _U8       = 369,  _F32      = 418,  _F64         = 431,  STRING   = 1604,
//     CHAR      = 940,  CLASS     = 1156, THIS        = 921,   METHOD   = 1445,
//     ATTRIBUTE = 2320, PUBLIC    = 1536, PRIVATE     = 1859,  BREAK    = 1209,
//     CONTINUE  = 2130, AND       = 680,  OR           = 467,  IMPORT   = 1603,
//     RETURN    = 1624, CASE      = 947,  DEFAULT      = 1778, IN       = 441,
//     NOT       = 754,  TRY       = 695,  CATCH        = 1110, CONST    = 1302,
//     EXPORT    = 1624, ALL       = 690,  SWITCH       = 1588, FN       = 432,
//     NEW       = 730,  ARRAYLIST = 2230, HASHMAP     = 1581,  RESIZE   = 1495,
//     _FILE     = 607,  KEY       = 725,  WRT          = 790,  RD       = 448,
//     LENGTH    = 1540, TYPE      = 965,  READFILELINE = 2803, READFILE = 1815,
//     WRITEFILE = 2197, FILECLOSE = 2134, FILEOPEN    = 1872,  PUSH     = 1052,
//     KEYS      = 1029, COPY      = 1020, VALUES      = 1571,  POP      = 752,
//     REMOVE    = 1579, CLEAR     = 1208, REVERSE     = 1862,  UPDATE   = 1546,
//     ITEMS     = 1288, STRTOLIST = 2509
// }ReservedWordsCodes;

typedef enum{
    IF        = 425,  ELIF      = 958,  ELSE    = 986,  FOR    = 726,
    WHILE     = 1275, _I32      = 427,  _I64    = 440,  _I16   = 429,
    _I8       = 333,  _U64      = 476,  _U32    = 463,  _U16   = 465,
    _U8       = 369,  _F32      = 418,  _F64    = 431,  STRING = 1604,
    CHAR      = 940,  CLASS     = 1156, THIS    = 921,  METHOD = 1445,
    ATTRIBUTE = 2320, PUBLIC    = 1536, PRIVATE = 1859, BREAK  = 1209,
    CONTINUE  = 2130, AND       = 680,  OR      = 467,  IMPORT = 1603,
    RETURN    = 1624, CASE      = 947,  DEFAULT = 1778, IN     = 441,
    NOT       = 754,  TRY       = 695,  CATCH   = 1110, CONST  = 1302,
    ALL       = 690,  SWITCH    = 1588, FN      = 432,  LIST   = 932,
    NEW       = 730,  ARRAYLIST = 2230, HASHMAP = 1581, RESIZE = 1495,
    _FILE     = 607,  KEY       = 725,  THREAD  = 1514, NIL    =  720
}ReservedWordsCodes;

typedef enum {
    WRT          = 790,  RD       = 448,  LENGTH    = 1540, TYPE      = 965,
    READFILELINE = 2803, READFILE = 1815, WRITEFILE = 2197, FILECLOSE = 2134,
    FILEOPEN     = 1872, PUSH     = 1052, KEYS      = 1029, COPY      = 1020,
    VALUES       = 1571, POP      = 752,  REMOVE    = 1579, CLEAR     = 1208,
    REVERSE      = 1862, UPDATE   = 1546, ITEMS     = 1288, STRTOLIST = 2509
} ReservedFunctionsCodes;

#endif