/*void print_BigintObject(BigintObject *int_Object){
    if(int_Object->sign == 1){
        printf("%c", '-');
    }

    uint64_t i;
    for(i = int_Object->sign; i < int_Object->extention; i++){
        printf("%d", int_Object->data[i]);
    }
}*/

/*static uint8_t verifySizei32(char *str_int){
    register uint8_t bigger_than_int = 0, sign = 0;
    int lengthi32_str = strsize(str_int);

    if(str_int[0] == '-'){
        sign = 1;
    }

    if((lengthi32_str - sign) > i32_SIZE_64){
        bigger_than_int = 1;
    }

    else if((lengthi32_str - sign) < i32_SIZE_64){
        bigger_than_int = -1;
    }

    if(bigger_than_int == 0){
        uint8_t stack_overFlow = 0;
        char int_max_in_str[20] = "18446744073709551615";

        int i;
        for(i = lengthi32_str - 1; i >= sign; i--){
            if(((int)str_int[i] - 48) > ((int)int_max_in_str[i - sign] - 48) && stack_overFlow == 0){
                stack_overFlow = 1;
            }

            if((((int)str_int[i] - 48) < ((int)int_max_in_str[i - sign] - 48)) && stack_overFlow == 1){
                stack_overFlow = 0;
            }
        }

        if(stack_overFlow == 1){
            bigger_than_int = 1;
        }
    }

    return bigger_than_int;
}*/

/*void print_List_Object_run_time(register ListTypeObject *list_Object){
    printf("[");
    register uint64_t i;
    for(i = 0; i < list_Object->extention; i++){
        if(list_Object[i].Type_Identifier_Object == IDENTIFIER_i32_OBJECT_DINAMIC){
            print_BigintObject(list_Object[i].types.int_Object_dinamic);
        }

        else if(list_Object[i].Type_Identifier_Object == IDENTIFIER_i32_OBJECT_STATIC){
            printf("%" PRId64, list_Object[i].types.int_Object_static->data);
        }

        if(i != list_Object->extention - 1){
            printf(", ");
        }
    }
    printf("]\n\n");
}*/

/*void print_List_Object_define(ListTypeObject **list_Object){
    register u64 size_List_String = START_SIZE_DATA_STRUCTURE_IN_String, counter = 0;
    char *list = (char*)malloc(size_List_String);
    strcpy(list, "[");

    if(list == NULL){
        return;
    }

    register u64 index;
    for(index = 0; index < (*list_Object)->extention; index++){
        if((*list_Object)[index].Type_Identifier_Object == IDENTIFIER_i32_OBJECT_STATIC){
            register int length_List_Object_index = strsize((*list_Object)[index].types.int_Object_static->_String_data);
            counter += length_List_Object_index;

            if(counter >= size_List_String){
                size_List_String *= 2;
                list = (char*)realloc(list, size_List_String);

                if(list == NULL){
                    return;
                }
            }

            strcat(list, (*list_Object)[index].types.int_Object_static->_String_data);

            if(index != (*list_Object)->extention - 1){
                strcat(list, ", ");
                counter += 2;
            }
            else{
                strcat(list, "]");
            }
        }

        else if((*list_Object)[index].Type_Identifier_Object == IDENTIFIER_i32_OBJECT_DINAMIC){

        }
    }

    wrt_Identifier_String_Object(list);
    free(list);
}*/

/*
BigintObject*
sum_i32Dinamic_and_i32Dinamic(BigintObject *i32Object_store,
BigintObject *i32Object)
{
    register u8 BiggerSizei32Object;
    register i64 LengthBiggeri32Object;
    u8 *NewDatai32Object;

    if(i32Object_store->extention >= i32Object->extention){
        BiggerSizei32Object = 1;
        LengthBiggeri32Object = i32Object_store->extention;
        NewDatai32Object = (u8*)malloc(LengthBiggeri32Object + 1);
        NewDatai32Object = i32Object_store->data;
    }

    else{
        BiggerSizei32Object = 2;
        LengthBiggeri32Object = i32Object->extention;
        NewDatai32Object = (u8*)malloc(LengthBiggeri32Object + 1);
        NewDatai32Object = i32Object->data;
    }

    register i64 i, y = ((BiggerSizei32Object == 1) ? i32Object->extention : i32Object_store->extention) - 1;
    register u8 upOne = 0;
    for(i = LengthBiggeri32Object - 1; i >= 0; i--){
        register u8 digit = NewDatai32Object[i];
        register u8 sum = 0;
        if(y >= 0){
            register u8 digit2 = (BiggerSizei32Object == 1) ? i32Object->data[y] : i32Object_store->data[y];
            sum = digit + digit2 + upOne;
            NewDatai32Object[i + 1] = sum % 10;
            upOne = sum / 10;
            y--;
        }

        else{
            sum = digit + upOne;
            NewDatai32Object[i + 1] = sum % 10;
            upOne = sum / 10;
        }
    }
    
    NewDatai32Object[0] = upOne;
    i32Object_store->data = NewDatai32Object;
    i32Object_store->extention = LengthBiggeri32Object + 1;

    return i32Object_store;
}
*/

/*i = 0;
while(i <= more_than_length_copy){
    if(NewDatai32Object[i] != 0 && !flag2){
        flag2 = 1;
    }

    if(flag2){
        NewDatai32Object[y++] = NewDatai32Object[i];
    }
    else{
        _zeros++;
    }
    i++;
}

NewDatai32Object = realloc(NewDatai32Object, more_than_length_copy - _zeros + 1);*/

/*BigintObject*
sum_i32Dinamic_and_i32Dinamic
(BigintObject *i32Object_store,
BigintObject *i32Object)
{
    register u8 BiggerSizei32Object;
    register i64 LengthBiggeri32Object;
    u8 *NewDatai32Object;

    if(i32Object_store->extention >= i32Object->extention){
        BiggerSizei32Object = 1;
        //NewDatai32Object = (u8*)malloc(i32Object_store->extention);
        NewDatai32Object = i32Object_store->data;
        LengthBiggeri32Object = i32Object_store->extention;
    }

    else{
        BiggerSizei32Object = 2;
        //NewDatai32Object = (u8*)malloc(i32Object->extention);
        NewDatai32Object = i32Object->data;
        LengthBiggeri32Object = i32Object->extention;
    }

    register i64 i, y = ((BiggerSizei32Object == 1) ? i32Object->extention : i32Object_store->extention) - 1;
    register u8 upOne = 0;
    for(i = LengthBiggeri32Object - 1; i != -1; i--){
        register u8 digit = NewDatai32Object[i];
        register u8 sum = 0;
        if(y >= 0){
            register u8 digit2 = (BiggerSizei32Object == 1) ? i32Object->data[y] : i32Object_store->data[y];
            sum = digit + digit2 + upOne;
            if(upOne){
                upOne = 0;
            }
            
            if(sum > 9){
                NewDatai32Object[i] = sum - 10;
                upOne = 1;
            }
            else{
                NewDatai32Object[i] = sum;
            }

            y--;
        }

        else{
            sum = digit + upOne;
            if(upOne){
                upOne = 0;
            }

            if(sum > 9){
                NewDatai32Object[i] = sum - 10;
                upOne = 1;
            }
            else{
                NewDatai32Object[i] = sum;
            }

            if(upOne == 0){
                break;
            }
        }
    }

    if(upOne){
        i32Object_store->data = expandDatai32DinamicObject(NewDatai32Object, upOne, LengthBiggeri32Object);
        i32Object_store->extention = LengthBiggeri32Object + 1;
    }
    else{
        i32Object_store->data = NewDatai32Object;
        i32Object_store->extention = LengthBiggeri32Object;
    }

    return i32Object_store;
}*/


/*BigintObject
sum_i32Dinamic_and_i32Dinamic
(BigintObject i32Object_store,
BigintObject i32Object)
{
    register u8 BiggerSizei32Object;
    register i64 LengthBiggeri32Object;
    u8 *NewDatai32Object;

    if(i32Object_store.extention >= i32Object.extention){
        BiggerSizei32Object = 1;
        NewDatai32Object = copyData(i32Object_store.data, NewDatai32Object, i32Object_store.extention);
        LengthBiggeri32Object = i32Object_store.extention;
    }

    else{
        BiggerSizei32Object = 2;
        NewDatai32Object = copyData(i32Object.data, NewDatai32Object, i32Object.extention);
        LengthBiggeri32Object = i32Object.extention;
    }

    register i64 i, y = ((BiggerSizei32Object == 1) ? i32Object.extention : i32Object_store.extention) - 1;
    register u8 upOne = 0;
    for(i = LengthBiggeri32Object - 1; i != -1; i--){
        register u8 digit = NewDatai32Object[i];
        register u8 sum = 0;
        if(y >= 0){
            register u8 digit2 = (BiggerSizei32Object == 1) ? i32Object.data[y] : i32Object_store.data[y];
            sum = digit + digit2 + upOne;
            if(upOne){
                upOne = 0;
            }
            
            if(sum > 9){
                NewDatai32Object[i] = sum - 10;
                upOne = 1;
            }
            else{
                NewDatai32Object[i] = sum;
            }

            y--;
        }

        else{
            sum = digit + upOne;
            if(upOne){
                upOne = 0;
            }

            if(sum > 9){
                NewDatai32Object[i] = sum - 10;
                upOne = 1;
            }
            else{
                NewDatai32Object[i] = sum;
            }

            if(upOne == 0){
                break;
            }
        }
    }

    if(upOne){
        i32Object_store.data = expandDatai32DinamicObject(NewDatai32Object, upOne, LengthBiggeri32Object);
        i32Object_store.extention = LengthBiggeri32Object + 1;
    }
    else{
        i32Object_store.data = NewDatai32Object;
        i32Object_store.extention = LengthBiggeri32Object;
    }

    return i32Object_store;
}*/

/*#ifndef OBJECTSSTRUCT_H
#define OBJECTSSTRUCT_H

#include "../includedefines/referenceTypes.h"
#include "../includedefines/sizeDefined.h"
#include "../includedefines/defines.h"
#include "../includeEnumerator/typeObjects.h"

//-----------OBJECTS---------------

typedef struct{
    u8 sign;
    i64 extention;
    u8 *data;
    String _String_Data;
}BigintObject;


typedef struct{
    i64 datai64;
    char _String_data[i32_SIZE_64 + 1];
}Identifier_i32_Static_Object;


typedef struct{
    String StringObject;
}StringTypeObject;


typedef struct{
    u8 sign;
    u64 extention;
    u8 *data_i32;
    u8 division;
    u8 *data_Float;
    String _String_Data;
}Bigf32Object;


typedef struct{
    f64 *data;
    String _String_Data;
}FloatTypeObject;


typedef struct{
    u64 extention;
    u64 capacity;
    u64 length_in_String;
    u8 modified_List;
    String list_String;
    reference_types Type_Identifier_Object;
    union{
        BigintObject *int_Object_dinamic;
        Identifier_i32_Static_Object *int_Object_static;
        StringTypeObject *StringObject;
        struct ListTypeObject *list_Object;
    }types;
}ListTypeObject;


typedef struct{
    reference_types Type_Identifier_Object;
    union{
        BigintObject *int_Object_dinamic;
        Identifier_i32_Static_Object *int_Object_static;
        StringTypeObject *StringObject;
        ListTypeObject *list_Object;
        Bigf32Object *f32_Object_dinamic;
        FloatTypeObject *f32_Object_static;
    }types;

}Objects;


typedef struct{
    i64 extention;
    i64 capacity;
    union{
        i64 *intStaticArray;
        String *strArray;
        f64 *f32StaticArray;
        BigintObject *intDinamicArray;
        Bigf32Object *f32DinamicArray;
        ListTypeObject *listArray;
        struct ArrayTypeObject *arrayArray;
    }type_Arrays;
}ArrayTypeObject;


typedef struct{
    reference_types *params;
    reference_types *args;
    Objects *objects;
    i32 paramsQtty;
    union{
        BigintObject *int_Object_dinamic;
        Identifier_i32_Static_Object *int_Object_static;
        StringTypeObject *StringObject;
        ListTypeObject *list_Object;
        Bigf32Object *f32_Object_dinamic;
        FloatTypeObject *f32_Object_static;
        ArrayTypeObject *array_Object;
    }_return;
}Identifier_Function_Object;

#endif //OBJECTSSTRUCT_H*/

/*void print_List_Object_define(ListTypeObject **list_Object){
    if((*list_Object)->modified_List){
        (*list_Object)->list_String = (String)malloc((*list_Object)->length_in_String);
        strcpy((*list_Object)->list_String, "\0");
        strcat((*list_Object)->list_String, "[");

        register u64 i;
        for(i = 0; i < (*list_Object)->extention; i++){
            if((*list_Object)[i].Type_Identifier_Object == IDENTIFIER_i32_OBJECT_STATIC){
                strcat((*list_Object)->list_String, (*list_Object)[i].types.int_Object_static->_String_data);
            }

            else if((*list_Object)[i].Type_Identifier_Object == IDENTIFIER_i32_OBJECT_DINAMIC){
                strcat((*list_Object)->list_String, (*list_Object)[i].types.int_Object_dinamic->_String_Data);
            }

            else if((*list_Object)[i].Type_Identifier_Object == StringTypeObject){
                strcat((*list_Object)->list_String, (*list_Object)[i].types.StringObject->StringObject);
            }

            if(i != (*list_Object)->extention - 1){
                strcat((*list_Object)->list_String, ", ");
            }
        }

        strcat((*list_Object)->list_String, "]");
        wrt_Identifier_String_Object((*list_Object)->list_String);
        (*list_Object)->modified_List = 0;
    }

    else{
        wrt_Identifier_String_Object((*list_Object)->list_String);
    }
}*/

/*
register i64 character = 0, index = 0;
    register i8 find = 0;
    i8 error = 0;
    register i64 counterCharacteres = 0, lenFontCode = strsize(code);
    String word = STRALLOC(INITSIZEWORDIDENTIFIER);
    String wordAux = STRALLOC(INITSIZEWORDIDENTIFIER);
    String identifier = STRALLOC(INITSIZEWORDIDENTIFIER);

    while(*code != '\0' && !error){
        if(*code != ' '){
            word[character] = *code;
            character++;
        }

        strcpy(wordAux, word);
        wordAux[character] = '\0';

        if(hashString(wordAux) == START_VARIABLE){
            code++;
            counterCharacteres++;
            if(*code == ':'){
                token[index].type = _KEYWORD_array;
                code++;
                counterCharacteres++;
            }

            else{
                token[index].type = _KEYWORD_variable;
            }

            printf("TOKEN encontrado: %d\n", token[index].type);
            token[index].value = NULL;

            character = 0;
            index++;

            if(!(checkTokenValid(*code, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"))){
                error = 1;
            }

            if(!error){
                while(*code != '\n' && *code != ' ' && *code != '='){
                    identifier[character] = *code;
                    character++;
                    code++;
                    counterCharacteres++;
                }
            }

            identifier[character] = '\0';
            verifyIdentifierDeclaration(identifier, &error);

            if(!error){
                token[index].type = _ANONYMOUS_IDENTIFIER;
                token[index].value = (String)malloc(character + 1);
                strcpy(token[index].value, identifier);
                printf("TOKEN LEXEMA: %s\n", token[index].value);
            }

            else{
                switch(error){
                    case 1:
                        token[index].type = _ERROR_INIT_IDENTIFIER;
                        token[index].value = (String)malloc(strsize("Identifier Initialization ERROR\0"));
                        strcpy(token[index].value, "Variable Initialization ERROR\0");
                        break;
                    case 2:
                        token[index].type = _ERROR_FORMAT_IDENTIFIER;
                        token[index].value = (String)malloc(strsize("Identifier Formatation ERROR\0"));
                        strcpy(token[index].value, "Identifier Formatation ERROR\0");
                        break;
                    case 3:
                        token[index].type = _ERROR_INVALID_NAME_IDENTIFIER;
                        token[index].value = (String)malloc(strsize("Identifier Name Is Invalid\0"));
                        strcpy(token[index].value, "Identifier Name Is Invalid\0");
                        break;
                }
                printf("ERROR: %s\n", token[index].value);
            }

            printf("TOKEN encontrado: %d\n", token[index].type);

            find = 1;
            code--;
            counterCharacteres--;
        }

        else if(keyWord_table(wordAux, "function") == FUNCTION){
            code++;
            counterCharacteres++;

            if(*code == ' '){
                token[index].type = _FUNCTION_IDENTIFIER;
                find = 1;
                printf("TOKEN encontrado: %d\n", token[index].type);
            }

            code--;
            counterCharacteres--;
        }

        else if((keyWord_table(wordAux, "int") == i32) || (keyWord_table(wordAux, "str") == STR) ||
        (keyWord_table(wordAux, "f32") == Float)){
            code++;
            counterCharacteres++;

            if(*code == ' '){
                switch(hashString(wordAux)){
                    case i32:
                        token[index].type = _IDENTIFIER_int;
                        break;
                    case STR:
                        token[index].type = _IDENTIFIER_str;
                        break;
                    case Float:
                        token[index].type = _IDENTIFIER_f32;
                        break;
                }

                token[index].value = NULL;

                printf("TOKEN encontrado: %d\n", token[index].type);
                find = 1;
            }

            else if(*code == '\0'){
                printf("null\n");
            }

            code--;
            counterCharacteres--;
        }

        else if(keyWord_table(wordAux, "return") == RETURN){
            code++;
            counterCharacteres++;

            if(*code == ' ' || *code == '('){
                token[index].type = _KEYWORD_return;
                printf("TOKEN encontrado: %d\n", token[index].type);
                find = 1;
            }

            else{

            }

            token[index].value = NULL;

            code--;
            counterCharacteres--;
        }

        else if((keyWord_table(wordAux, "if") == IF) ||
        (keyWord_table(wordAux, "elif") == ELIF) ||
        (keyWord_table(wordAux, "while") == WHILE) ||
        (keyWord_table(wordAux, "for") == FOR) ||
        (keyWord_table(wordAux, "switch") == SWITCH)){
            code++;
            counterCharacteres++;
            if(*code == ' '){
                while(*code == ' '){
                    code++;
                    counterCharacteres++;
                }
            }

            if(checkTokenValid(*code, "(")){
                switch(hashString(wordAux)){
                    case IF:
                        token[index].type = _KEYWORD_if;
                        break;
                    case ELIF:
                        token[index].type = _KEYWORD_elif;
                        break;
                    case WHILE:
                        token[index].type = _KEYWORD_while;
                        break;
                    case FOR:
                        token[index].type = _KEYWORD_for;
                        break;
                    case SWITCH:
                        token[index].type = _KEYWORD_switch;
                        break;
                }

                token[index].value = NULL;

                printf("TOKEN encontrado: %d\n", token[index].type);
                find = 1;
            }

            else{
                switch(hashString(wordAux)){
                    case IF:
                        token[index].type = _ERROR_IF;
                        break;
                    case ELIF:
                        token[index].type = _ERROR_ELIF;
                        break;
                    case WHILE:
                        token[index].type = _ERROR_WHILE;
                        break;
                    case FOR:
                        token[index].type = _ERROR_FOR;
                        break;
                    case SWITCH:
                        token[index].type = _ERROR_SWITCH;
                        break;
                }

                printf("TOKEN encontrado: %d\n", token[index].type);
                find = 1;
                error = 1;
            }

            token[index].value = NULL;

            code--;
            counterCharacteres--;
        }

        else if(keyWord_table(wordAux, "else") == ELSE){
            code++;
            counterCharacteres++;
            while(*code == ' '){
                code++;
                counterCharacteres++;
            }

            if(checkTokenValid(*code, "{")){
                token[index].type = _KEYWORD_else;
                printf("TOKEN encontrado: %d\n", token[index].type);
                find = 1;
            }

            else{
                error = 1;
                token[index].type = _ERROR_ELSE;
                find = 1;
            }

            token[index].value = NULL;

            code--;
            counterCharacteres--;
        }

        else if(keyWord_table(wordAux, "case") == CASE){
            code++;
            counterCharacteres++;

            if(checkTokenValid(*code, " ")){
                token[index].type = _KEYWORD_case;
                printf("TOKEN encontrado: %d\n", token[index].type);
                find = 1;
            }

            token[index].value = NULL;

            code--;
            counterCharacteres--;
        }

        else if(keyWord_table(wordAux, "default") == DEFAULT){
            code++;
            counterCharacteres++;
            if(*code == ' '){
                while(*code == ' '){
                    code++;
                    counterCharacteres++;
                }
            }

            if(checkTokenValid(*code, ":")){
                token[index].type = _KEYWORD_default;

                printf("TOKEN encontrado: %d\n", token[index].type);
                find = 1;
            }

            token[index].value = NULL;

            code--;
            counterCharacteres--;
        }

        else if((keyWord_table(wordAux, "break") == BREAK) ||
        (keyWord_table(wordAux, "continue") == CONTINUE)){
            code++;
            counterCharacteres++;
            if(*code == ' '){
                while(*code == ' '){
                    code++;
                    counterCharacteres++;
                }
            }

            if(checkTokenValid(*code, "\n")){
                if(hashString(wordAux) == BREAK){
                    token[index].type = _KEYWORD_break;
                }

                else{
                    token[index].type = _KEYWORD_continue;
                }

                printf("TOKEN encontrado: %d\n", token[index].type);
                find = 1;
            }

            token[index].value = NULL;

            code--;
            counterCharacteres--;
        }

        else if((keyWord_table(wordAux, "and") == AND) || (keyWord_table(wordAux, "or") == OR)){
            code++;
            counterCharacteres++;

            if(*code == ' ' || *code == '\0' || *code == '\n'){
                switch(hashString(wordAux)){
                    case AND:
                        token[index].type = _RESERVED_CHARACTER_AND;
                        break;
                    case OR:
                        token[index].type = _RESERVED_CHARACTER_OR;
                        break;
                }
                token[index].value = NULL;

                find = 1;
                printf("TOKEN encontrado: %d\n", token[index].type);
            }

            code--;
            counterCharacteres--;
        }

        else if(*code == '\n' || *code == '(' || *code == ')' || *code == '{' || *code == '}' || *code == '\t'){
            switch(*code){
                case '\n':
                    token[index].type = _RESERVED_CHARACTER_BROKEN_LINE;
                    printf("TOKEN encontrado: %d\n", token[index].type);
                    break;
                case '\t':
                    token[index].type = _RESERVED_CHARACTER_TAB;
                    printf("TOKEN encontrado: %d\n", token[index].type);
                    break;
                case '(':
                    token[index].type =_RESERVED_CHARACTER_OPEN_P;
                    printf("TOKEN encontrado: %d\n", token[index].type);
                    break;
                case ')':
                    token[index].type =_RESERVED_CHARACTER_CLOSE_P;
                    printf("TOKEN encontrado: %d\n", token[index].type);
                    break;
                case '{':
                    token[index].type =_RESERVED_CHARACTER_OPEN_BLOCK;
                    printf("TOKEN encontrado: %d\n", token[index].type);
                    break;
                case '}':
                    token[index].type =_RESERVED_CHARACTER_CLOSE_BLOCK;
                    printf("TOKEN encontrado: %d\n", token[index].type);
                    break;
            }
            token[index].value = NULL;

            find = 1;
        }

        else if(*code == '='){
            code++;
            counterCharacteres++;
            if(*code == '='){
                token[index].type = _RESERVED_CHARACTER_EQUAL_EQUAL;
            }

            else{
                code--;
                counterCharacteres--;
                token[index].type = _RESERVED_CHARACTER_EQUAL;
            }
            token[index].value = NULL;

            printf("TOKEN encontrado: %d\n", token[index].type);

            find = 1;
        }

        else if(*code == '!'){
            code++;
            counterCharacteres++;
            if(*code == '='){
                token[index].type = _RESERVED_CHARACTER_DIFFERENT;
            }

            else{
                code--;
                counterCharacteres--;
                token[index].type = _RESERVED_CHARACTER_DENIAL;
            }
            token[index].value = NULL;

            printf("TOKEN encontrado: %d\n", token[index].type);

            find = 1;
        }

        else if(*code == '*' || *code == '/' || *code == '+' || *code == '-'){
            switch(*code){
                case '*':
                    code++;
                    counterCharacteres++;

                    if(*code == '*'){
                        token[index].type = _OPERATOR_POW;
                    }

                    else if(*code == '='){
                        token[index].type = _OPERATOR_MULT_EQUAL;
                    }

                    else{
                        token[index].type = _OPERATOR_MULT;
                        code--;
                        counterCharacteres--;
                    }
                    find = 1;
                    break;

                case '/':
                    code++;
                    counterCharacteres++;
                    if(*code == '/'){
                        token[index].type = _RESERVED_CHARACTER_COMMENT;
                    }

                    else if(*code == '='){
                        token[index].type = _OPERATOR_DIV_EQUAL;
                    }

                    else{
                        token[index].type = _OPERATOR_DIV;
                        code--;
                        counterCharacteres--;
                    }
                    find = 1;
                    break;

                case '+':
                    code++;
                    counterCharacteres++;
                    if(*code == '+'){
                        token[index].type = _OPERATOR_ADD_ADD;
                    }

                    else if(*code == '='){
                        token[index].type = _OPERATOR_ADD_EQUAL;
                    }

                    else{
                        token[index].type = _OPERATOR_ADD;
                        code--;
                        counterCharacteres--;
                    }
                    find = 1;
                    break;

                case '-':
                    code++;
                    counterCharacteres++;
                    if(*code == '-'){
                        token[index].type = _OPERATOR_SUB_SUB;
                    }

                    else if(*code == '='){
                        token[index].type = _OPERATOR_SUB_EQUAL;
                    }

                    else{
                        token[index].type = _OPERATOR_SUB;
                        code--;
                        counterCharacteres--;
                    }
                    token[index].value = NULL;
                    find = 1;
                    break;
            }

            printf("TOKEN encontrado: %d\n", token[index].type);
        }

        //validação de Strings
        else if((int)*code == 39 || (int)*code == 34){
            i64 lenString = 10;
            String getString = (String)malloc(lenString);
            char typeStart_String = *code;

            token[index].type = _RESERVED_CHARACTER_START_String;
            token[index].value = NULL;
            printf("TOKEN encontrado: %d\n", token[index].type);

            index++;
            code++;
            counterCharacteres++;

            i64 counter = 0;
            while(*code != typeStart_String && *code != '\0'){
                getString[counter] = *code;

                if(counter == lenString - 1){
                    lenString *= 2;
                    getString = realloc(getString, lenString);
                }

                code++;
                counterCharacteres++;
                counter++;
            }

            getString[counter] = '\0';

            token[index].type = _IDENTIFIER_CONST_STR;
            token[index].value = (String)malloc(counter);
            strcpy(token[index].value, getString);

            printf("TOKEN encontrado: %d\n", token[index].type);
            printf("TOKEN LEXEMA: %s\n", token[index].value);

            index++;

            if(*code == '\0'){
                token[index].type = _ERROR_SYNTAX_STR_CONSTRUCT;
            }

            else if(*code == typeStart_String){
                token[index].type = _RESERVED_CHARACTER_FINISH_String;
            }

            printf("TOKEN encontrado: %d\n", token[index].type);

            free(getString);
            find = 1;
        }

        else if((int)*code >= 48 && (int)*code <= 57){
            i64 lenNum = 10;
            i8 flagFloat = 0;
            String getNum = (String)malloc(lenNum);

            i64 i = 0;
            while(*code != ' ' && *code != '\0' && *code != '\n'){
                if(!(((int)*code >= 48 && (int)*code <= 57) || *code == '.')){
                    token[index].type = _ERROR_FORMAT_IDENTIFIER;
                    token[index].value = (String)malloc(strsize("Identifier Formatation ERROR\0"));
                    strcpy(token[index].value, "Identifier Formatation ERROR\0");
                    error = 1;
                    break;
                }

                else{
                    if(*code == '.'){
                        flagFloat++;
                    }
                    
                    getNum[i] = *code;
                    code++;
                    counterCharacteres++;
                }
                
                if(i == lenNum - 1){
                    lenNum *= 2;
                    getNum = realloc(getNum, lenNum);
                }
                
                i++;
            }

            if(!error){
                getNum[i] = '\0';
                
                if(flagFloat > 1){
                    token[index].type = _ERROR_FORMAT_IDENTIFIER;
                    token[index].value = (String)malloc(strsize("Identifier Formatation ERROR\0"));
                    strcpy(token[index].value, "Identifier Formatation ERROR\0");
                    error = 1;
                }
                
                if(!error){
                    if(flagFloat == 1){
                        token[index].type = _IDENTIFIER_CONST_Float;
                        token[index].value = (String)malloc(strsize(getNum));
                        strcpy(token[index].value, getNum);
                    }
                    
                    else{
                        token[index].type = _IDENTIFIER_CONST_i32;
                        token[index].value = (String)malloc(strsize(getNum));
                        strcpy(token[index].value, getNum);
                    }
                    
                    printf("TOKEN ENCONTRADO: %d\n", token[index].type);
                    printf("TOKEN LEXEMA: %s\n", token[index].value);
                }
                
                else{
                    printf("TOKEN ENCONTRADO: %d\n", token[index].type);
                    printf("TOKEN LEXEMA: %s\n", token[index].value);
                }
            }
            
            else{
                printf("TOKEN ENCONTRADO: %d\n", token[index].type);
                printf("TOKEN LEXEMA: %s\n", token[index].value);
            }
            
            find = 1;

            free(getNum);
        }

        else if(*code == ' ' || (counterCharacteres == lenFontCode - 1)){
            word[character] = '\0';
            if(character > 0){
                token[index].value = (String)malloc(character + 1);
                strcpy(token[index].value, word);
                printf("TOKEN LEXEMA: %s\n", token[index].value);
                find = 1;
            }
            character = 0;
        }

        if(find){
            index++;
            word[character] = '\0';
            character = 0;
            find = 0;
        }

        code++;
        counterCharacteres++;
    }

    free(identifier);
*/

/*if(((int)*sourceCode >= 65 && (int)*sourceCode <= 90) ||
                   ((int)*sourceCode >= 97 && (int)*sourceCode <= 122) || 
                   ((int)*sourceCode >= 48 && (int)*sourceCode <= 57) ||*/

/*if( keyWordIdentify(word, "continue") == CONTINUE ||
            keyWordIdentify(word, "and") == AND ||
            keyWordIdentify(word, "or") == OR ||
            keyWordIdentify(word, "return") == RETURN ||
            keyWordIdentify(word, "endif") == ENDIF ||
            keyWordIdentify(word, "in") ||
            keyWordIdentify(word, "break") == BREAK ||
            keyWordIdentify(word, "else") == ELSE ||
            keyWordIdentify(word, "if") == IF ||
            keyWordIdentify(word, "elif") == ELIF ||
            keyWordIdentify(word, "for") == FOR ||
            keyWordIdentify(word, "while") == WHILE ||
            keyWordIdentify(word, "switch") == SWITCH ||
            keyWordIdentify(word, "oper") == OPER ||
            keyWordIdentify(word, "case") == CASE || 
            keyWordIdentify(word, "default") == DEFAULT ||
            keyWordIdentify(word, "int") == i32 ||
            keyWordIdentify(word, "f32") == Float ||
            keyWordIdentify(word, "String") == String
        ){*/

/*if( (keyWordIdentify(identifierObject, "if") == IF) ||
        (keyWordIdentify(identifierObject, "elif") == ELIF) ||
        (keyWordIdentify(identifierObject, "while") == WHILE) ||
        (keyWordIdentify(identifierObject, "for") == FOR) ||
        (keyWordIdentify(identifierObject, "switch") == SWITCH) ||
        (keyWordIdentify(identifierObject, "else") == ELSE) ||
        (keyWordIdentify(identifierObject, "break") == BREAK) ||
        (keyWordIdentify(identifierObject, "default") == DEFAULT) ||
        (keyWordIdentify(identifierObject, "case") == CASE) ||
        (keyWordIdentify(identifierObject, "continue") == CONTINUE) ||
        (keyWordIdentify(identifierObject, "int") == i32) ||
        (keyWordIdentify(identifierObject, "f32") == Float) ||
        (keyWordIdentify(identifierObject, "String") == String) ||
        (keyWordIdentify(identifierObject, "and") == AND) ||
        (keyWordIdentify(identifierObject, "or") == OR) ||
        (keyWordIdentify(identifierObject, "endif") == ENDIF) ||
        (keyWordIdentify(identifierObject, "in") == IN) ||
        (keyWordIdentify(identifierObject, "return") == RETURN) ||
        (keyWordIdentify(identifierObject, "oper") == OPER)){
            (*error) = _ERROR_INVALID_NAME_IDENTIFIER;
            return;
    }*/

/*register i64 strEqualKey_word = codeString(key_word);
    register i64 lenStr = strsize(str), lenkeyWord = strsize(key_word);

    if(lenStr != lenkeyWord){
        return 0;
    }

    else{
        while(*str){
            if(*str != *key_word){
                return 0;
            }
            str++;
            key_word++;
        }
    }

    return strEqualKey_word;*/

/*void verifyIdentifierDeclaration(String identifierObject, i8 *error){
    if(keyWordIdentify(identifierObject, KeyWordTable, KEYWORDsQTTY)){
        (*error) = _ERROR_INVALID_NAME_IDENTIFIER;
        return;
    }

    if(!((identifierObject[0] >= 'A' && identifierObject[0] <= 'Z') ||
          (identifierObject[0] >= 'a' && identifierObject[0] <= 'z') ||
          identifierObject[0] == '_')){
        (*error) = _ERROR_FORMAT_IDENTIFIER;
        return;
    }

    identifierObject++;

    if(!*error){
        while(*identifierObject){
            if (!((((*identifierObject >= 'A' && *identifierObject <= 'Z') ||
                (*identifierObject >= 'a' && *identifierObject <= 'z')) ||
                (*identifierObject >= '0' && *identifierObject <= '9')) || (*identifierObject == '_'))){
                (*error) = _ERROR_FORMAT_IDENTIFIER;
                return;
            }

            identifierObject++;
        }
    }
}*/

/*void FlushInputBuffer(){
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD inputBuffer;
    DWORD events;
    COORD coord = {0, 0};

    SetConsoleScreenBufferSize(hInput, coord);

    while(PeekConsoleInput(hInput, &inputBuffer, 1, &events) && events > 0){
        ReadConsoleInput(hInput, &inputBuffer, 1, &events);
    }

    SetConsoleScreenBufferSize(hInput, coord);
}*/

/*while(1){
            if(!ReadConsoleW(hConsole, buffer, 1, &numberOfCharsRead, NULL)){
                wprintf(L"Erro ao ler a entrada do console\n");
                free(str);
                return NULL;
            }

            if(buffer[0] == L'\n' || buffer[0] == L'\r'){
                str[index] = L'\0';
                break;
            } 
            else{
                str[index] = buffer[0];
                index++;
                counter++;

                if(index == size - 2){
                    size += size / 2;
                    str = (String)realloc(str, size * sizeof(lchar));
                }

                buffer[0] = '\0';

                if(counter == 25){
                    break;
                }

                printf("%lld, ", counter);
            }
        }

        WindowsWrt(L"Enter 250...", L", ");
        
        counter = 0;
        FlushConsoleInputBuffer(hConsole);

        if(buffer[0] == L'\n' || buffer[0] == L'\r'){
            break;
        }*/

/*String format = *formatptr;
    i64 size = strsize(format), count = 0;
    String dstny = STRALLOC((size + 1));
    String dty = dstny;

    while(*format){
        if(*format != L' '){
            dstny[count++] = *format;
        }

        dstny[count] = L'\0';
        format++;

        if(*format == L' ' || *format == L'\0'){
            if(dstny[0] != L'\0'){
                while(*format == L' '){
                    format++;
                }

                *formatptr = format;
                return dstny;
            }
        }
    }*/


/*typedef struct{
    i8 sizeBits;
    union{
        i8 data8bits;
        i16 data16bits;
        i32 data32bits;
        i64 data64bits;
    //}Typei32;
    String _String_data;
}Identifier_i32_Static_Object;*/

/*String GetUTF(String path, i8 *Error){
    FILE *f = _wfopen(path, L"rb");
    i64 len = 1024, counter = 0;
    String rune = STRALLOC(len);

    if(f == NULL){
        (*Error) = ERROROPENFILE;
        return NULL;
    }

    u8 byte;
    while(fread(&byte, sizeof(u8), 1, f)){
        if(byte < 0x80){
            rune[counter] = byte;
        }

        else if((byte & 0xE0) == 0xC0){
            u16 lasti8 = byte;
            fread(&byte, sizeof(u8), 1, f);

            if((byte & 0xC0) == 0x80){
                lasti8 &= 0x1F;
                lasti8 <<= 6;
                byte &= 0x3F;
                rune[counter] = lasti8 | byte;
            }
            else{
                (*Error) = ERRORUTF2BYTES;
                printf("Error 2");
                (*Error) = ERRORALLOCNULL;
                return NULL;
            }
        }

        else if((byte & 0xF0) == 0xE0){
            u16 firsti8 = byte;
            fread(&byte, sizeof(u8), 1, f);
            u16 secondi8 = byte;

            fread(&byte, sizeof(u8), 1, f);
            u16 thirdi8 = byte;

            if((secondi8 & 0xC0) == 0x80 && (thirdi8 & 0xC0) == 0x80){
                firsti8 &= 0x0F;
                firsti8 <<= 12;
                secondi8 &= 0x3F;
                secondi8 <<= 6;
                thirdi8 &= 0x3F;
                rune[counter] = firsti8 | secondi8 | thirdi8;
            }
            else{
                (*Error) = ERRORUTF3BYTES;
                return NULL;
            }
        }

        else if((byte & 0xF8) == 0xF0){
            u16 firsti8 = byte, secondi8, thirdi8, fourthi8;

            fread(&byte, sizeof(u8), 1, f);
            secondi8 = byte;

            fread(&byte, sizeof(u8), 1, f);
            thirdi8 = byte;

            fread(&byte, sizeof(u8), 1, f);
            fourthi8 = byte;

            if((secondi8 & 0xC0) == 0x80 && (thirdi8 & 0xC0) == 0x80 && (fourthi8 & 0xC0) == 0x80){
                firsti8 &= 0x07;
                firsti8 <<= 18;
                secondi8 &= 0x3F;
                secondi8 <<= 12;
                thirdi8 &= 0x3F;
                thirdi8 <<= 6;
                fourthi8 &= 0x3F;
                rune[counter] = firsti8 | secondi8 | thirdi8 | fourthi8;
            }
            else{
                (*Error) = ERRORUTF4BYTES;
                return NULL;
            }
        }

        else{
            (*Error) = ERRORUTFINVALID;
            return NULL;
        }

        counter++;
        if(counter == len - 1){
            len += len / 2;
            rune = (String)realloc(rune, len * sizeof(lchar));
            if(rune == NULL){
                return NULL;
            }
        }
    }

    fclose(f);
    rune[counter] = L'\0';
    return rune;
}*/

/*String GetUTF(String path, i8 *Error){
    FILE *f = _wfopen(path, L"rb");
    i64 len = 1024, counter = 0;
    String rune = STRALLOC(len);

    if(f == NULL){
        (*Error) = ERROROPENFILE;
        return NULL;
    }

    u8 byte;
    while(fread(&byte, sizeof(u8), 1, f)){
        if(byte < 0x80){
            rune[counter] = byte;
        }

        else if((byte & 0xE0) == 0xC0){
            u16 lasti8 = byte;
            fread(&byte, sizeof(u8), 1, f);

            if((byte & 0xC0) == 0x80){
                lasti8 &= 0x1F;
                lasti8 <<= 6;
                byte &= 0x3F;
                rune[counter] = lasti8 | byte;
            }
            else{
                (*Error) = ERRORUTF2BYTES;
                printf("Error 2");
                (*Error) = ERRORALLOCNULL;
                return NULL;
            }
        }

        else if((byte & 0xF0) == 0xE0){
            u16 firsti8 = byte;
            u8 nexti8s[2];
            fread(nexti8s, sizeof(u8), 2, f);

            if((nexti8s[0] & 0xC0) == 0x80 && (nexti8s[1] & 0xC0) == 0x80){
                u16 secondi8 = nexti8s[0], thirdbyte = nexti8s[1];
                firsti8 &= 0x0F;
                firsti8 <<= 12;
                nexti8s[0] &= 0x3F;
                nexti8s[0] <<= 6;
                nexti8s[1] &= 0x3F;
                rune[counter] = firsti8 | nexti8s[0] | nexti8s[1];
            }
            else{
                (*Error) = ERRORUTF3BYTES;
                return NULL;
            }
        }

        else if((byte & 0xF8) == 0xF0){
            u16 firsti8 = byte;
            u16 nexti8s[3];

            fread(nexti8s, sizeof(u8), 3, f);

            if((nexti8s[0] & 0xC0) == 0x80 && (nexti8s[1] & 0xC0) == 0x80 && (nexti8s[2] & 0xC0) == 0x80){
                firsti8 &= 0x07;
                firsti8 <<= 18;
                nexti8s[0] &= 0x3F;
                nexti8s[0] <<= 12;
                nexti8s[1] &= 0x3F;
                nexti8s[1] <<= 6;
                nexti8s[2] &= 0x3F;
                rune[counter] = firsti8 | nexti8s[0] | nexti8s[1] | nexti8s[1];
            }
            else{
                (*Error) = ERRORUTF4BYTES;
                return NULL;
            }
        }

        else{
            (*Error) = ERRORUTFINVALID;
            return NULL;
        }

        counter++;
        if(counter == len - 1){
            len += len / 2;
            rune = (String)realloc(rune, len * sizeof(lchar));
            if(rune == NULL){
                return NULL;
            }
        }
    }

    fclose(f);
    rune[counter] = L'\0';
    return rune;
}*/

/*BigintObject* create_i32_Dinamic_Object(String parseToi32){
    u64 int_Length = strsize(parseToi32);
    BigintObject *int_Object = BIGINTALLOC(1);

    if(parseToi32[0] == L'-'){
        int_Object->sign = 1;
    }

    else{
        int_Object->sign = 0;
    }

    int_Object->extention = int_Length;
    int_Object->data = UINT8ALLOC(int_Object->extention);

    register i64 i;
    for(i = int_Object->sign; i < int_Object->extention; i++){
        int_Object->data[i] = (int)parseToi32[i] - 48;
    }

    return int_Object;
}*/

/*void free_BigintObject(BigintObject *int_Object){
    free(int_Object->data);
    free(int_Object);
}*/

/*//-------------Functions for String Object-----------------

StringTypeObject* create_String_Object(String data, u64 length_Data){
    StringTypeObject *StringObject = STROBJALLOC(1);
    StringObject->StringObject = strcopy(data);
    return StringObject;
}
*/

/*String compressListToString(List *list){
    lchar *liststr = (String)malloc((list->lengthstr + 1) * sizeof(lchar)), *liststrcpy, *str = NULL;
    liststrcpy = liststr;

    setBuffer(&liststrcpy, L"[");

    for(unsigned long long index = 0; index < list->extention; index++){
        long long v;

        switch(list[index].ref_ty){
            case _long_:
                v = list[index].types.i64_ty;
                str = inttstr(v);
                break;
            case _int_:
                v = (long long)list[index].types.i32_ty;
                str = inttstr(v);
                break;
            case _short_:
                v = (long long)list[index].types.i16_ty;
                str = inttstr(v);
                break;
            case _byte_:
                v = (long long)list[index].types.i8_ty;
                str = inttstr(v);
                break;
            case _string_:
                str = (String)malloc((strsize(list[index].types.string_ty) + 3) * sizeof(lchar));
                str[0] = L'"';
                lchar *strcopy = str;
                strcopy++;
                setBuffer(&strcopy, list[index].types.string_ty);
                setBuffer(&strcopy, L"\"\0");
                break;
            default:
                printf("Unsupported type or invalid type\n");
                free(liststr);
                return NULL;
        }

        setBuffer(&liststrcpy, str);
        if(index != list->extention - 1){
            setBuffer(&liststrcpy, L", ");
        }
    }

    setBuffer(&liststrcpy, L"]\0");
    free(str);

    return liststr;
}*/

/*
typedef struct{
    i64TypeObject *i64Array;
}Arrayi64Object;


typedef struct{
    i32TypeObject *i32Array;
}Arrayi32Object;


typedef struct{
    i16TypeObject *i16Array;
}Arrayi16Object;


typedef struct{
    i8TypeObject *i8Array;
}Arrayi8Object;


typedef struct{
    CharTypeObject *CharArray;
}ArrayCharObject;


typedef struct{
    StringTypeObject *StringArray;
}ArrayStringObject;


typedef struct{
    FloatTypeObject *FloatArray;
}ArrayFloatObject;


typedef struct{
    DoubleTypeObject *f64Array;
}ArrayDoubleObject;


typedef struct{
    BigintObject *intDinamicArray;
}Arrayi32DinamicObject;


typedef struct{
    Bigf32Object *f32DinamicArray;
}ArrayBigf32Object;

typedef struct{
    i64 i64Object;
}i64TypeObject;


typedef struct{
    i32 i32Object;
}i32TypeObject;


typedef struct{
    i16 i16Object;
}i16TypeObject;


typedef struct{
    i8 i8Object;
}i8TypeObject;
*/

/*
void print_List_Object_define(ListTypeObject **list_Object){
    if((*list_Object)->modified_List){
        String list_String = STRALLOC((*list_Object)->length_in_String);
        String current_position = list_String;

        current_position += sprintf(current_position, "[");

        register u64 i;
        for(i = 0; i < (*list_Object)->extention; i++){
            switch((*list_Object)[i].Type_Identifier_Object){

                case __BIGINT__:
                    current_position += sprintf(current_position, "%s", (*list_Object)[i].types.int_Object_dinamic->_String_Data);
                    break;

                case __String__:
                    current_position += sprintf(current_position, "%s", (*list_Object)[i].types.StringObject->StringObject);
                    break;

                default:
                    if((*list_Object)[i].Type_Identifier_Object == __i64__ ||
                        (*list_Object)[i].Type_Identifier_Object == __i32__ ||
                        (*list_Object)[i].Type_Identifier_Object == __i16__ ||
                        (*list_Object)[i].Type_Identifier_Object == __i8__){
                        current_position += sprintf(current_position, "%s", (*list_Object)[i].types.int_Object_static->_String_data);
                    }
                    break;
            }

            if(i != (*list_Object)->extention - 1){
                current_position += sprintf(current_position, ", ");
            }
        }

        current_position += sprintf(current_position, "]");
        wrt_Identifier_String_Object(list_String);

        free(list_String);

        (*list_Object)->modified_List = 0;
    }
    
    else{
        wrt_Identifier_String_Object((*list_Object)->list_String);
    }
}
*/

/*
void increaseList_Object
(ListTypeObject **list_Object, packageReceived pkrv,
reference_types type_Object, size_ty Data_length)
{
    (*list_Object)->length_in_String += Data_length + 2;

    (*list_Object)->extention++;
    register size_ty _extention = (*list_Object)->extention;

    if((_extention) == (*list_Object)->capacity){
        (*list_Object)->capacity += (*list_Object)->capacity / 2;
        (*list_Object) = (ListTypeObject*)realloc((*list_Object), (*list_Object)->capacity * sizeof(ListTypeObject));
    }

    printf("Type    %d\n", type_Object);

    for(int i = 0; i < Data_length; i++){
        //printf("i8[%d]    %d\n", i, pkrv.bytePack[i]);
    }
    printf("end byte[]\n\n");

    switch(type_Object){
        case __i64__:
            printf("Type: i64\n");
            (*list_Object)[_extention - 1].Types.i32Types.i64Type.i64Object = compressToi32eger(pkrv.bytePack, Data_length);
            printf("n: %lld\n", (*list_Object)[_extention - 1].Types.i32Types.i64Type.i64Object);
            break;
        case __i32__:
            printf("Type: i32\n");
            (*list_Object)[_extention - 1].Types.i32Types.i32Type.i32Object = (i32)compressToi32eger(pkrv.bytePack, Data_length);
            printf("n: %lld\n", (*list_Object)[_extention - 1].Types.i32Types.i32Type.i32Object);
            break;
        case __i16__:
            printf("Type: i16\n");
            (*list_Object)[_extention - 1].Types.i32Types.i16Type.i16Object = (i16)compressToi32eger(pkrv.bytePack, Data_length);
            printf("n: %lld\n", (*list_Object)[_extention - 1].Types.i32Types.i16Type.i16Object);
            break;
        case __i8__:
            printf("Type: i8\n");
            (*list_Object)[_extention - 1].Types.i32Types.i8Type.i8Object = (i8)compressToi32eger(pkrv.bytePack, Data_length);
            printf("n: %lld\n", (*list_Object)[_extention - 1].Types.i32Types.i8Type.i8Object);
            break;
        case __String__:
            (*list_Object)[_extention - 1].Types.StringObject.StringObject = strcopy(pkrv.shortPack);
            break;
    }

    (*list_Object)[(*list_Object)->extention - 1].Type_Identifier_Object = type_Object;
}*/

/*


void assemblePackage(packageReceived *pkrv, size_ty size, u8 receivedi8s[]){
    if(pkrv->size_b != 0){
        free(pkrv->bytePack);
        pkrv->bytePack = (u8*)realloc(pkrv->bytePack, size);
    }

    else{
        pkrv->bytePack = INT8ALLOC(size);
    }

    pkrv->size_b = size;

    for(size_ty i = 0; i < size; i++){
        pkrv->bytePack[i] = receivedi8s[i];
    }
}
*/

/*ListTypeObject* newList(size_ty size){
    ListTypeObject *list_Object = LISTALLOC(1);
    list_Object->GN_Fields.extention = 0;
    list_Object->GN_Fields.capacity = START_DATA_STRUCTURE;
    list_Object->GN_Fields.lengthstr = INIT_LEN_DS_STR;
    list_Object->GN_Fields.modify_flag = NO_MODIFY;
    return list_Object;
}


char pushList
(ListTypeObject **list, reference_types ref_ty,
packageReceived pkrv, size_ty size)
{
    (*list)->GN_Fields.extention++;
    size_ty extention = (*list)->GN_Fields.extention, index = extention - 1;
    (*list)->GN_Fields.lengthstr += size + 2;

    if(extention == (*list)->GN_Fields.capacity - 1){
        (*list)->GN_Fields.capacity += (*list)->GN_Fields.capacity / 2;
        (*list) = (ListTypeObject*)realloc((*list), (*list)->GN_Fields.capacity * sizeof(ListTypeObject));
    }

    switch(ref_ty){
        case __i64__:
            (*list)[index].Types.primitiveTy.intTys.i64_ty = compressToi32eger(pkrv.package_ty.pack_bytes, size);
            break;

        case __i32__:
            (*list)[index].Types.primitiveTy.intTys.i32_ty = compressToi32eger(pkrv.package_ty.pack_bytes, size);
            break;

        case __i16__:
            (*list)[index].Types.primitiveTy.intTys.i16_ty = compressToi32eger(pkrv.package_ty.pack_bytes, size);
            break;
        
        case __i8__:
            (*list)[index].Types.primitiveTy.intTys.i8_ty = compressToi32eger(pkrv.package_ty.pack_bytes, size);
            break;

        case __String__:
            (*list)[index].Types.primitiveTy.string_ty = STRALLOC((size + 1));
            (*list)[index].Types.primitiveTy.string_ty = strcopy(pkrv.shortPack);
            break;
    }

    (*list)[index].object_ty = ref_ty;
    (*list)[index].GN_Fields.modify_flag = WITH_MODIFY;
    return 0;
}


void freeList(ListTypeObject **list){
    size_ty i = 0;
    for(; i < (*list)->GN_Fields.extention; i++){
        if((*list)[i].object_ty == __String__){
            free((*list)[i].Types.primitiveTy.string_ty);
        }
    }

    free(*list);
}


void printList(ListTypeObject **list){
    if((*list)->GN_Fields.modify_flag){
        (*list)->GN_Fields.dataStructurestr = compressListToString(*list);
        (*list)->GN_Fields.modify_flag = 0;
    }

    if((*list)->GN_Fields.dataStructurestr != NULL){
        WindowsWrt((*list)->GN_Fields.dataStructurestr, L"\n");
    }
    else{
        WindowsWrt(L"ERROR: ", L"Lista corrompida\n");
    }
}*/

/*
typedef struct{
    GNFieldsStructures GN_Fields;
    reference_types object_ty;
    union{
        PrimitiveTypes primitiveTy;
        BigintObject i32DinamicType;
        Bigf32Object FloatDinamicType;
        All_Arrays all_arrays;
        ArrayList *ArrayList;
        struct HashMap *HashObject;
        struct ListTypeObject *ListObject;
    }Types;
}ListTypeObject;
*/

/*
ListTypeObject* copyList(ListTypeObject *list){
    ListTypeObject *List = LISTALLOC(list->GN_Fields.capacity);
    List->GN_Fields.capacity = list->GN_Fields.capacity;
    List->GN_Fields.extention = list->GN_Fields.extention;
    List->GN_Fields.lengthstr = list->GN_Fields.lengthstr;
    for(size_ty i = 0; i < List->GN_Fields.extention; i++){
        switch(list[i].object_ty){
            case __i64__:
                List[i].Types.primitiveTy.intTys.i64_ty = list[i].Types.primitiveTy.intTys.i64_ty;
                break;
            case __i32__:
                List[i].Types.primitiveTy.intTys.i32_ty = list[i].Types.primitiveTy.intTys.i32_ty;
                break;
            case __i16__:
                List[i].Types.primitiveTy.intTys.i16_ty = list[i].Types.primitiveTy.intTys.i16_ty;
                break;
            case __i8__:
                List[i].Types.primitiveTy.intTys.i8_ty = list[i].Types.primitiveTy.intTys.i8_ty;
                break;
        }
        List[i].object_ty = list[i].object_ty;
    }
    return List;
}
*/

/*String compressListToString(ListTypeObject *list){
    lchar *liststr = (lchar*)malloc((list->GN_Fields.lengthstr + 1) * sizeof(lchar));
    lchar *liststrcpy, *str = NULL;
    liststrcpy = liststr;

    //ListTypeObject *listcpy = copyList(list);

    setBuffer(&liststrcpy, L"[");

    for(size_ty index = 0; index < list->GN_Fields.extention; index++){
        i64 v;

        printf("Type: %d\n", list[index].object_ty);
        switch(list[index].object_ty){
            case __i64__:
                printf("Caiu aqui: long\n");
                v = list[index].Types.primitiveTy.intTys.i64_ty;
                break;
            case __i32__:
                printf("Caiu aqui: int\n");
                v = (long long)list[index].Types.primitiveTy.intTys.i32_ty;
                break;
            case __i16__:
                printf("Caiu aqui: short\n");
                v = (long long)list[index].Types.primitiveTy.intTys.i16_ty;
                break;
            case __i8__:
                printf("Caiu aqui: byte\n");
                v = (long long)list[index].Types.primitiveTy.intTys.i8_ty;
                break;
            case __String__:
                str = STRALLOC((strsize(list->Types.primitiveTy.string_ty) + 3));
                str[0] = L'"';
                lchar *strcpy = str;
                strcpy++;
                setBuffer(&strcpy, list[index].Types.primitiveTy.string_ty);
                setBuffer(&strcpy, L"\"\0");
                break;
            default:
                printf("Unsupported type or invalid type\n");
                free(liststr);
                return NULL;
        }

        printf("v: %lld\n", v);

        str = inttstr(v);

        setBuffer(&liststrcpy, str);
        if(index != list->GN_Fields.extention - 1){
            setBuffer(&liststrcpy, L", ");
        }
    }

    setBuffer(&liststrcpy, L"]\0");
    free(str);

    //list->GN_Fields.modify_flag = 0;
    return liststr;
    //return L"Nossa, como eu amo programar e meu código não funciona";
}*/

/*int main(){
    List *list = newList(1);

    unsigned char *bytes;
    packageReceived pkrv;

    lchar *i_n = NULL;

    pkrv.pack_ty = PACK_BYTES;

    pkrv.package_ty.pack_bytes = (u8[]){0x00, 0x09, 0x02, 0x02};
    pushList(&list, __i64__, pkrv, 4);

    pkrv.package_ty.pack_bytes = (u8[]){0x00, 0x03, 0x05};
    pushList(&list, __i64__, pkrv, 3);

    pkrv.package_ty.pack_bytes = (u8[]){0x01, 0x03, 0x05};
    pushList(&list, __i8__, pkrv, 3);

    pkrv.package_ty.pack_bytes = (u8[]){0x00, 0x03, 0x05, 0x00};
    pushList(&list, __i16__, pkrv, 4);

    i64 limit = 1000000;
    for(i64 i = 0; i < limit; i++){
        if(i % 7 == 0){
            pkrv.pack_ty = PACK_DOUBLE_BYTES;
            i_n = inttstr(i);
            pkrv.package_ty.pack_doublebytes = i_n;
            pushList(&list, __String__, pkrv, strsize(i_n) + 1);
        }

        else{
            pkrv.pack_ty = PACK_BYTES;
            char size = 0;
            bytes = expandsToi8s(i, &size);
            pkrv.package_ty.pack_bytes = bytes;

            if(i <= 127 && i >= -128){
                pushList(&list, __i8__, pkrv, (unsigned long long)size);
            }

            else if(i <= 32767 && i >= -32768){
                pushList(&list, __i16__, pkrv, (unsigned long long)size);
            }

            else if(i % 2 == 0){
                pushList(&list, __i32__, pkrv, (unsigned long long)size);
            }

            else{
                pkrv.pack_ty = PACK_INTEGER;
                pkrv.package_ty.pack_integer = i;
                pushList(&list, __i64__, pkrv, (unsigned long long)size);
            }
        }
    }

    free(bytes);
    free(i_n);

    pkrv.pack_ty = PACK_BYTES;

    pkrv.package_ty.pack_bytes = (unsigned char[]){0x00, 0x03, 0x05, 0x00, 0x00, 0x00};
    pushList(&list, __i64__, pkrv, 6);
    pkrv.package_ty.pack_bytes[0] = 0x01;
    pushList(&list, __i64__, pkrv, 6);

    pkrv.package_ty.pack_bytes = (unsigned char[]){0x00, 0x03, 0x05, 0x00, 0x00};
    pushList(&list, __i32__, pkrv, 5);
    pkrv.package_ty.pack_bytes[0] = 0x01;
    pushList(&list, __i32__, pkrv, 5);

    pkrv.package_ty.pack_bytes = (unsigned char[]){0x00, 0x03, 0x05, 0x00};
    pushList(&list, __i16__, pkrv, 4);
    pkrv.package_ty.pack_bytes[0] = 0x01;
    pushList(&list, __i16__, pkrv, 4);

    pkrv.package_ty.pack_bytes = (unsigned char[]){0x00, 0x03, 0x05};
    pushList(&list, __i8__, pkrv, 3);
    pkrv.package_ty.pack_bytes[0] = 0x01;
    pushList(&list, __i8__, pkrv, 3);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    lchar hello_world[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x00};
    pkrv.package_ty.pack_doublebytes = hello_world;
    pushList(&list, __String__, pkrv, 14);

    lchar input[] = L"Todos esses momentos se perderão no tempo, como lágrimas na chuva...";
    pkrv.package_ty.pack_doublebytes = input;
    pushList(&list, __String__, pkrv, 69);

    lchar blade_runner[] = L"Blade Runner: Melhor filme de toda a história do cinema!";
    pkrv.package_ty.pack_doublebytes = blade_runner;
    pushList(&list, __String__, pkrv, 43);

    lchar *games[] = {
                        L"Dark Souls Remaster", L"Hollow Knight", L"Elden Ring",
                        L"Cyberpunk 2077", L"Dark Souls III", L"Batman: Arkham Knight",
                        L"Red Dead Redemption 2", L"Lies Of P", L"BloodBorne",
                        L"Sekiro", L"Dark Souls II"
                      };

    for(char y = 0; y < 11; y++){
        pkrv.package_ty.pack_doublebytes = games[y];
        pushList(&list, __String__, pkrv, strsize(games[y]) + 1);
    }

    lchar maxnum_long_long[] = L"9223372036854775807";
    i64 max_nLL = convert_StringToInteger(L"9223372036854775807");

    pkrv.pack_ty = PACK_BYTES;

    charsize_t len = 0;
    u8 *newData_c = expandsToi8s(max_nLL, &len);
    pkrv.package_ty.pack_bytes = newData_c;
    pushList(&list, __i64__, pkrv, (i64)len);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    free(newData_c);
    pkrv.package_ty.pack_doublebytes = maxnum_long_long;
    pushList(&list, __String__, pkrv, strsize(maxnum_long_long) + 1);

    lchar ellen[] = L"Ellen, morzinho di mi vida";
    pkrv.package_ty.pack_doublebytes = ellen;
    pushList(&list, __String__, pkrv, strsize(ellen) + 1);

    pkrv.pack_ty = PACK_BYTES;

    pkrv.package_ty.pack_bytes = (u8[]){0x00, 0x09, 0x02, 0x02, 0x03, 0x03, 0x07, 0x02, 0x00, 0x03, 0x06};
    pushList(&list, __i64__, pkrv, 11);

    pkrv.pack_ty = PACK_INTEGER;

    pkrv.package_ty.pack_integer = 9223372036854775807;
    pushList(&list, __i64__, pkrv, strsize(L"9223372036854775807") + 1);

    pkrv.package_ty.pack_integer = 25042006;
    pushList(&list, __i32__, pkrv, strsize(L"25042006") + 1);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    pkrv.package_ty.pack_doublebytes = L"Ton-618";
    pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doublebytes) + 1);

    pkrv.package_ty.pack_doublebytes = L"End List";
    pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doublebytes) + 1);

    printList(&list);
    freeList(list);
}
*/

/*
reference_types TypeReturn;
    union{
        PrimitiveTypes primitiveTys;
        BigintObject i32DinamicType;
        Bigf32Object FloatDinamicType;
        All_Arrays all_arrays;
        ArrayList *ArrayList;
        HashMap *HashObject;
        List *ListObject;
    }Return;
*/

/*void* initializeDataArray(void *data, size_ty init, size_ty end, reference_types ref_dataTy){
    switch(ref_dataTy){
        case __ARRAYi64__:{
            i64 *array = (i64*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYi32__:{
            i32 *array = (i32*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYi16__:{
            i16 *array = (i16*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYi8__:{
            i8 *array = (i8*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYCHAR__:{
            lchar *array = (lchar*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = '\0';
            }
            break;
        }
        case __ARRAYSTRING__:{
            lchar *array = (lchar*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = NULL;
            }
            break;
        }
        case __ARRAYf32__:{
            f32 *array = (f32*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0.0f;
            }
            break;
        }
        case __ARRAYf64__:{
            f64 *array = (f64*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0.0;
            }
            break;
        }
        case __ARRAYBIGINT__:{
            u8 *array = (u8*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYBIGFLOAT__:{
            u8 *array = (u8*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
    }
}*/

//u8 wrt(String _scope, String _index, Objects **matrObjects, String end){
    /*String copyScope = _scope;
    String copyIndex = _index;
    String finalString;
    String current_position;

    i64 size = 1024, sizeStr = 0, sizeRes = size;
    finalString = STRALLOC(size);

    while(*copyScope && *copyIndex){
        String scp;
        String ind;
        if(!(strgetnextstr(&scp, &_scope) && strgetnextstr(&ind, &_index))){
            i32 scpValue = convert_StringToInteger(scp);
            i32 indValue = convert_StringToInteger(ind);
            
            if(scpValue == NULL || indValue == NULL){
                return 2;
            }

            reference_types typeIndexObject = matrObjects[scpValue][indValue].Type_Identifier_Object;

            if(typeIndexObject == __i64__ ||
               typeIndexObject == __i32__ ||
               typeIndexObject == __i16__ ||
               typeIndexObject == __i8__)
            {
                sizeStr = strsize(matrObjects[scpValue][indValue].types.int_Object_static->_String_data);
                sizeRes -= sizeStr;
                if(sizeRes <= 1){
                    size = sizeStr + sizeStr / 2;
                    sizeRes = size;
                    finalString = (String)realloc(finalString, size);
                }

                if(finalString == NULL){
                    finalString = strfastcopy(matrObjects[scpValue][indValue].types.int_Object_static->_String_data, sizeStr);
                }
                else{
                    current_position = finalString;
                    if((setBuffer(&current_position, matrObjects[scpValue][indValue].types.int_Object_static->_String_data))){
                        return 1;
                    }
                }
            }

            else{
                String actString;

                switch(typeIndexObject){
                    case __BIGINT__:
                        sizeStr = strsize(matrObjects[scpValue][indValue].types.int_Object_dinamic->_String_Data);
                        actString = strfastcopy(matrObjects[scpValue][indValue].types.int_Object_dinamic->_String_Data, sizeStr);
                        break;

                    case __f32__:
                        sizeStr = strsize(matrObjects[scpValue][indValue].types.f32_Object_static->_String_Data);
                        actString = strfastcopy(matrObjects[scpValue][indValue].types.f32_Object_static->_String_Data, sizeStr);
                        break;

                    case __BIGFLOAT__:
                        sizeStr = strsize(matrObjects[scpValue][indValue].types.f32_Object_dinamic->_String_Data);
                        actString = strfastcopy(matrObjects[scpValue][indValue].types.f32_Object_dinamic->_String_Data, sizeStr);
                        break;

                    case __f64__:
                        sizeStr = strsize(matrObjects[scpValue][indValue].types.f64_Object->_String_Data);
                        actString = strfastcopy(matrObjects[scpValue][indValue].types.f64_Object->_String_Data, sizeStr);
                        break;

                    case __Char__:
                        sizeStr = 1;
                        actString = STRALLOC((sizeStr + 1));
                        actString[0] = matrObjects[scpValue][indValue].types.char_Object->CharObject;
                        actString[1] = L'\0';
                        break;

                    case __String__:
                        sizeStr = strsize(matrObjects[scpValue][indValue].types.StringObject->StringObject);
                        actString = strfastcopy(matrObjects[scpValue][indValue].types.StringObject->StringObject, sizeStr);
                        break;
                }

                sizeRes -= sizeStr;
                if(sizeRes <= 1){
                    size = sizeStr + sizeStr / 2;
                    sizeRes = size;
                    finalString = (String)realloc(finalString, size);
                }

                if(finalString == NULL){
                    finalString = strfastcopy(actString, sizeStr);
                }
                else{
                    //finalString = strfastmerger(finalString, actString, strsize(finalString), sizeStr);
                    if((setBuffer(&current_position, actString))){
                        free(actString);
                        return 1;
                    }
                }

                free(actString);
            }
        }
        free(scp);
        free(ind);
    }

    if(end == NULL){
        end = strfastcopy(L"\n\0", 2);
    }

#ifdef WINDOWS
    WindowsWrt(finalString, end);
#endif

    return 0;*/
//}

/*void getmemory(void *copy, u8 source[], size_ty size){
    i8 starti8 = 0x18;
    *((i32*)copy) = 0;

    int i = 0;
    for(; i < size; i++){
        *((i32*)copy) |= (source[i] << starti8);
        starti8 -= 0x08;
    }
}*/

/*
typedef struct Class{
    STATUS state__This__;
    STATUS state__Attributes__;
    STATUS state__Methods__;
    union{
        List *private__This__;
        List *public__This__;
    }__This__;
    union{
        List *private__Attributes__;
        List *public__Attributes__;
    }__Attributes__;
    union{
        ADDRESS *Address_private__Methods__;
        ADDRESS *Address_public__Methods__;
    }__Methods__;
    STATUS heritage;
    Class *__heritage__;
}Class;
*/

/*
u8 left_b = size - 1;

    memcopy(srccpy, src, 0, (size_ty)size);
for(charsize_t i = 0; i < size / 2; i++){
        u8 right_b = src[i];
        srccpy[i] = srccpy[left_b];
        srccpy[left_b--] = right_b;
    }*/

/*
u8* byteParser(void *any, reference_types ref_anyTy, size_ty qtty){
    u8 *bytes;
    u8 startdata = 0;
    size_ty i = 0;

    switch(ref_anyTy){
        case __i64__:
        case __i32__:
        case __i16__:
        case __i8__ :
        case __Char__:
            switch(ref_anyTy){
                case __i64__:
                    bytes = UINT8ALLOC(i64_size);
                    startdata = 0x38;
                    for(; i < i64_size; i++){
                        bytes[i] = (u8) (*((i64*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;
                
                case __i32__:
                    bytes = UINT8ALLOC(i32_size);
                    startdata = 0x18;
                    for(; i < i32_size; i++){
                        bytes[i] = (u8) (*((i32*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;
                
                case __i16__:
                case __Char__:
                    bytes = UINT8ALLOC(i16_size);
                    startdata = 0x10;
                    for(; i < i16_size; i++){
                        bytes[i] = (u8) (*((lchar*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;

                case __i8__:
                    bytes = UINT8ALLOC(i8_size);
                    bytes[0] = (*(i8*)any);
                    break;
            }
            break;
    }

    return bytes;
}
*/

/*
STATUS COMMAND_START(u8 *line, __System__ *System){
    u8 addr_i = 0x01, flagset = 0, count = 0;
    u8 *storages = UINT8ALLOC(OBJECTsQTTY);

    while(line[addr_i] != END_INSTRUCTION){
        while(line[++addr_i] != END_SET){
            if(count == OBJECTsQTTY)
                return -1;

            else if(line[addr_i] < STORAGE_LONG || line[addr_i] > STORAGE_FN)
                return -2;

            else
                storages[count++] = line[addr_i];
        }

        addr_i++;
        count = 0;

        while(line[++addr_i] != END_SET){
            if(count == OBJECTsQTTY)
                return -3;

            else if((line[addr_i] < LONG || line[addr_i] > STRUCT) && line[addr_i] != SEND){
                return -4;
            }

            else{
                i64 size_storage = 0;
                u8 *bytes;
                charsize_t size_Obj = 0;

                if(line[addr_i++] == SEND){
                    switch(line[addr_i++]){
                        case LONG:{
                            size_Obj = i64_size;
                            /*bytes = UINT8ALLOC(i64_size);
                            memcopy(bytes, line, addr_i, i64_size);
                            memcpyint(&size_storage, bytes, i64_size);
                            addr_i += i64_size - 1;
                            break;
                        }

                        case INT:{
                            size_Obj = i64_size;
                            bytes = UINT8ALLOC(i32_size);
                            memcopy(bytes, line, addr_i, i32_size);
                            memcpyint(&size_storage, bytes, i32_size);
                            addr_i += i32_size - 1;
                            break;
                        }

                        case SHORT:
                        case CHAR:{
                            size_Obj = i64_size;
                            bytes = UINT8ALLOC(i16_size);
                            memcopy(bytes, line, addr_i, i16_size);
                            memcpyint(&size_storage, bytes, i16_size);
                            addr_i += i16_size - 1;
                            break;
                        }

                        case BYTE:{
                            size_storage = line[addr_i];
                            break;
                        }
                        
                        default:
                            return -5;
                    }
                    if(line[addr_i - 1] == BYTE){
                        
                    }
                    else{
                        bytes = UINT8ALLOC(size_Obj);
                        memcopy(bytes, line, addr_i, size_Obj);
                        memcpyint(&size_storage, bytes, size_Obj);
                        addr_i += size_Obj - 1;
                    }
                }
            }
        }
        addr_i++;     
    }

    return 0;
}
*/

/*
typedef struct{
    size_ty extention;
    u8 *data;
}BigintObject;


typedef struct{
    size_ty extfData;
    u8 *data_f32;
}Bigf32Object;
*/

/*
STATUS set_operation(u8 *line, u64 *addr_i, i64 *count, u8 *elements, i64 **forEach_loop1, i64 **forEach_loop2, u8 qttLoop){
    u8 *bytes;
    u8 lastLoop = 0;

    if(line[*addr_i] != INIT_SET)
        return -7;

    i64 actSize = OBJECTsQTTY;
    
    while(line[++(*addr_i)] != END_SET){
        if(*count == actSize){
            actSize += actSize >> 1;
            elements = (u8*)realloc(elements, actSize);
        }

        if(line[*addr_i] < STORAGE_LONG || line[*addr_i] > STORAGE_FN)
            return -2;

        else
            elements[(*count)++] = line[*addr_i];
    }

    if(!qttLoop)
        return 0;

    if(qttLoop == 2){
        (*forEach_loop1) = INT64ALLOC(*count);
        (*forEach_loop2) = INT64ALLOC(*count);
    }

    else
        (*forEach_loop1) = INT64ALLOC(*count);

    i64 countObjs = *count;

    (*addr_i)++;
    while(qttLoop){
        if(line[*addr_i] != INIT_SET)
            return -8;

        (*count) = 0;
        while(line[++(*addr_i)] != END_SET){
            if(*count == countObjs + 1)
                return -3;

            if((line[*addr_i] < LONG || line[*addr_i] > STRUCT) && line[*addr_i] != SEND)
                return -4;
            
            i64 value = 0;
            charsize_t size_Obj = 0;

            (*addr_i)++;
            switch(line[(*addr_i)++]){
                case LONG:
                    size_Obj = i64_size;
                    break;

                case INT:
                    size_Obj = i32_size;
                    break;

                case SHORT:
                case CHAR:
                    size_Obj = i16_size;
                    break;

                case BYTE:
                    value = line[*addr_i];
                    break;

                case STRING:

                
                default:
                    return -5;
            }

            if(size_Obj){
                if(line[*addr_i - 1] != BYTE){
                    bytes = (u8*)malloc(size_Obj);
                    memcopy(bytes, line, *addr_i, size_Obj);
                    memcpyint(&value, bytes, size_Obj);
                    (*addr_i) += size_Obj - 1;
                    free(bytes);
                }

                if(qttLoop == 1 && lastLoop == 2)
                    (*forEach_loop2)[(*count)++] = value;
                else
                    (*forEach_loop1)[(*count)++] = value;

                size_Obj = 0;
            }
        }
        lastLoop = qttLoop;
        qttLoop--;

        if(qttLoop == 1 && lastLoop == 2){
            (*addr_i)++;
        }
    }

    return 0;
}
*/

/*
STATUS set_operation(u8 *line, u64 *addr_i, i64 *count, u8 *elements, i64 **forEach_loop1, i64** forEach_loop2/*List **forEach_loop2, u8 qttLoop){
    u8 *bytes;
    u8 lastLoop = 0;

    if(line[*addr_i] != INIT_SET)
        return -7;

    i64 actSize = OBJECTsQTTY;
    
    while(line[++(*addr_i)] != END_SET){
        if(*count == actSize){
            actSize += actSize >> 1;
            elements = (u8*)realloc(elements, actSize);
        }

        if(line[*addr_i] < STORAGE_LONG || line[*addr_i] > STORAGE_FN)
            return -2;

        else
            elements[(*count)++] = line[*addr_i];
    }
    printf("passou de storages\n");

    if(!qttLoop)
        return 0;

    if(qttLoop == 2){
        (*forEach_loop1) = INT64ALLOC(*count);
        (*forEach_loop2) = INT64ALLOC(*count);//(List*)malloc(*count * sizeof(List));
    }

    else
        (*forEach_loop1) = INT64ALLOC(*count);

    i64 countObjs = *count, indexList = 0;

    (*addr_i)++;
    while(qttLoop){
        if(line[*addr_i] != INIT_SET)
            return -8;

        (*count) = 0;
        while(line[++(*addr_i)] != END_SET){
            if(*count == countObjs + 1)
                return -3;

            if((line[*addr_i] < LONG || line[*addr_i] > STRUCT) && line[*addr_i] != SEND)
                return -4;
            
            i64 value = 0;
            charsize_t size_Obj = 0;

            (*addr_i)++;
            switch(line[(*addr_i)++]){
                case LONG:
                    size_Obj = i64_size;
                    break;

                case INT:
                    size_Obj = i32_size;
                    break;

                case SHORT:
                case CHAR:
                    size_Obj = i16_size;
                    break;

                case BYTE:
                    size_Obj = 1;
                    value = line[*addr_i];
                    break;

                case STRING:
                    if(qttLoop == 1 && lastLoop == 0)
                        return -15;

                    
                
                default:
                    return -5;
            }

            if(size_Obj){
                if(line[*addr_i - 1] != BYTE){
                    bytes = (u8*)malloc(size_Obj);
                    memcopy(bytes, line, *addr_i, size_Obj);
                    memcpyint(&value, bytes, size_Obj);
                    (*addr_i) += size_Obj - 1;
                    free(bytes);
                }

                if(qttLoop == 1 && lastLoop == 2){
                    /*switch(line[*addr_i - 1]){
                        case LONG:
                            (*forEach_loop2)[indexList++].ref_ty = __i64__;

                    }
                    (*forEach_loop2)[(*count)++] = value;
                }
                    
                else
                    (*forEach_loop1)[(*count)++] = value;

                size_Obj = 0;
            }
        }
        lastLoop = qttLoop;
        qttLoop--;

        if(qttLoop == 1 && lastLoop == 2){
            (*addr_i)++;
        }
    }

    return 0;
}
*/

/*
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


void TokenGenerator(String sourceCode, Token *token, i64 *line){
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

        i64 identifyi32ernalOper = keyWordIdentify(word, internalOperTable, INTERNALOPERQTTY);
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
                token[*line][index].type = __ERROR__;
                token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_SYNTAX_KEYWORD]);
                (*line)++;
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
                            token[*line][index].type = _INTERNAL_FN;
                    }

                    token[*line][index].Identifiers.internaFn.fnCode = codeFnCall;
                }
                else{
                    switch(codeString(word)){
                        case CONTINUE:
                            token[*line][index].type = _KEYWORD_continue;
                            break;
                        case AND:
                            token[*line][index].type = _KEYWORD_and;
                            break;
                        case OR:
                            token[*line][index].type = _KEYWORD_or;
                            break;
                        case RETURN:
                            token[*line][index].type = _KEYWORD_return;
                            break;
                        case ENDIF:
                            token[*line][index].type = _KEYWORD_endif;
                            break;
                        case IN:
                            token[*line][index].type = _KEYWORD_in;
                            break;
                        case BREAK:
                            token[*line][index].type = _KEYWORD_break;
                            break;
                        case ELSE:
                            token[*line][index].type = _KEYWORD_else;
                            break;
                        case IF:
                            token[*line][index].type = _KEYWORD_if;
                            break;
                        case ELIF:
                            token[*line][index].type = _KEYWORD_elif;
                            break;
                        case FOR:
                            token[*line][index].type = _KEYWORD_for;
                            break;
                        case WHILE:
                            token[*line][index].type = _KEYWORD_while;
                            break;
                        case SWITCH:
                            token[*line][index].type = _KEYWORD_switch;
                            break;
                        case FN:
                            token[*line][index].type = _KEYWORD_fn;
                            break;
                        case CONST:
                            token[*line][index].type = _KEYWORD_const;
                            break;
                        case _i32:
                            token[*line][index].type = _KEYWORD_int;
                            break;
                        case _i64:
                            token[*line][index].type = _KEYWORD_i64;
                            break;
                        case _i16:
                            token[*line][index].type = _KEYWORD_short;
                            break;
                        case _i8:
                            token[*line][index].type = _KEYWORD_byte;
                            break;
                        case _Float:
                            token[*line][index].type = _KEYWORD_f32;
                            break;
                        case _Double:
                            token[*line][index].type = _KEYWORD_f64;
                            break;
                        case _String:
                            token[*line][index].type = _KEYWORD_str;
                            break;
                        case _CHAR:
                            token[*line][index].type = _KEYWORD_char;
                            break;
                        case CASE:
                            token[*line][index].type = _KEYWORD_case;
                            break;
                        case DEFAULT:
                            token[*line][index].type = _KEYWORD_default;
                            break;
                        case CLASS:
                            token[*line][index].type = _KEYWORD_class;
                            break;
                        case THIS:
                            token[*line][index].type = _KEYWORD_this;
                            break;
                        case METHOD:
                            token[*line][index].type = _KEYWORD_method;
                            break;
                        case ATTRIBUTE:
                            token[*line][index].type = _KEYWORD_attribute;
                            break;
                        case PUBLIC:
                            token[*line][index].type = _KEYWORD_public;
                            break;
                        case PRIVATE:
                            token[*line][index].type = _KEYWORD_private;
                            break;
                        case EXPORT:
                            token[*line][index].type = _KEYWORD_export;
                            break;
                        case TRY:
                            token[*line][index].type = _KEYWORD_try;
                            break;
                        case CATCH:
                            token[*line][index].type = _KEYWORD_catch;
                            break;
                        case ALL:
                            token[*line][index].type = _KEYWORD_all;
                            break;
                        case SYS:
                            token[*line][index].type = _KEYWORD_sys;
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
                        token[*line][index].type = __ERROR__;
                        token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_INIT_IDENTIFIER]);
                        (*line)++;
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
                                token[*line][index].type = __ERROR__;
                                token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_FORMAT_IDENTIFIER]);
                                (*line)++;
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
                                    token[*line][index].type = __ERROR__;
                                    token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_FORMAT_IDENTIFIER]);
                                    (*line)++;
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
                                    token[*line][index].type = __ERROR__;
                                    token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_FORMAT_IDENTIFIER]);
                                    (*line)++;
                                    free(word);
                                    free(auxWord);
                                    return;
                                }
                            }

                            auxWord++;
                        }

                        token[*line][index].type = (flagFloat) ? _IDENTIFIER_CONST_Float : _IDENTIFIER_CONST_i32;
                        token[*line][index].Identifiers.constData.addinfo = (flagHex) ? HEX : DEC;
                        token[*line][index].Identifiers.constData.data = strcopy(word);
                    }
                }

                else{
                    if(codeString(word) != _INTERNAL_FNCHARPOINTERNUMCODE){
                        if(*sourceCode == L'.'){
                            word[counterCharacteres - 1] = L'\0';
                            counterCharacteres--;
                        }

                        token[*line][index].type = __IDENTIFIER__;
                        token[*line][index].Identifiers.Data.nameIdentifier = strcopy(word);
                    }

                    else{
                        (*line)--;
                    }
                }

                tokenFound = flagTokenPointer;
            }

            if(*sourceCode == L'.' && flagAccessScope){
                if(tokenFound){
                    (*line)++;
                }
                token[*line][index].type = _RESERVED_CHARACTER_ACCESS_SCOPE;
            }

            else if(*sourceCode == L'"' || *sourceCode == L'\''){
                u8 flagChar = 0;

                if(tokenFound){
                    (*line)++;
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
                            token[*line][index].type = __ERROR__;
                            token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_STRING]);
                            (*line)++;
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

                    token[*line][index].type = _IDENTIFIER_CONST_STR;
                    token[*line][index].Identifiers.constData.data = strcopy(word);
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
                            token[*line][index].type = __ERROR__;
                            token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_INVALID_SCAPE_CHARACTERE]);
                            (*line)++;
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
                        token[*line][index].type = __ERROR__;
                        token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_INVALID_CONST_CHAR]);
                        (*line)++;
                        free(word);
                        return;
                    }

                    else{
                        word[flagChar] = '\0';
                        token[*line][index].type = _IDENTIFIER_CONST_CHAR;
                        token[*line][index].Identifiers.constData.data = strcopy(word);
                    }

                    tokenFound = 1;
                }
            }

            else if((*sourceCode != L' ' && *sourceCode != L'"' && *sourceCode != L'\'' && *sourceCode != L'.')){
                register i8 flag = 1;
                if(tokenFound){
                    (*line)++;
                }
                switch(*sourceCode){
                    case L'=':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _RESERVED_CHARACTER_EQUAL_EQUAL;
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _RESERVED_CHARACTER_EQUAL;
                        }
                        break;
                    
                    case L'+':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_ADD_EQUAL;
                        }
                        else if(*sourceCode == L'+'){
                            token[*line][index].type = _OPERATOR_ADD_ADD;
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _OPERATOR_ADD;
                        }
                        break;

                    case L'-':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_SUB_EQUAL;
                        }
                        else if(*sourceCode == L'-'){
                            token[*line][index].type = _OPERATOR_SUB_SUB;
                        }
                        else if(*sourceCode == L'>'){
                            token[*line][index].type = _RESERVED_CHARACTER_ADDRESS_POINTER;
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _OPERATOR_SUB;
                        }
                        break;

                    case L'/':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_DIV_EQUAL;
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
                            token[*line][index].type = _OPERATOR_DIV;
                        }
                        break;

                    case L'*':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_MULT_EQUAL;
                        }
                        else if(*sourceCode == L'*'){
                            sourceCode++;
                            if(*sourceCode == L'='){
                                token[*line][index].type = _OPERATOR_POW_EQUAL;
                            }
                            else{
                                sourceCode--;
                                token[*line][index].type = _OPERATOR_POW;
                            }
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _OPERATOR_MULT;
                        }
                        break;

                    case L'%':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_REST_EQUAL;
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _OPERATOR_REST;
                        }
                        break;

                    case L'(':
                        token[*line][index].type = _RESERVED_CHARACTER_OPEN_EXPRESS;
                        break;

                    case L')':
                        token[*line][index].type = _RESERVED_CHARACTER_CLOSE_EXPRESS;
                        break;

                    case L'{':
                        token[*line][index].type = _RESERVED_CHARACTER_OPEN_BLOCK;
                        break;
                    
                    case L'}':
                        token[*line][index].type = _RESERVED_CHARACTER_CLOSE_BLOCK;
                        break;

                    case L'[':
                        token[*line][index].type = _RESERVED_CHARACTER_OPEN_BRACKET;
                        break;

                    case L']':
                        token[*line][index].type = _RESERVED_CHARACTER_CLOSE_BRACKET;
                        break;

                    case L'<':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _RESERVED_CHARACTER_SMALLER_EQUAL;
                        }
                        else if(*sourceCode == L'<'){
                            token[*line][index].type = _RESERVED_CHARACTER_MOV_BIT_LEFT;
                        }
                        else{
                            token[*line][index].type = _RESERVED_CHARACTER_SMALLER;
                            sourceCode--;
                        }
                        break;

                    case L'>':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _RESERVED_CHARACTER_BIGGER_EQUAL;
                        }
                        else if(*sourceCode == L'>'){
                            token[*line][index].type = _RESERVED_CHARACTER_MOV_BIT_RIGHT;
                        }
                        else{
                            token[*line][index].type = _RESERVED_CHARACTER_BIGGER;
                            sourceCode--;
                        }
                        break;

                    case L'&':
                        token[*line][index].type = _RESERVED_CHARACTER_AND;
                        break;

                    case L'|':
                        token[*line][index].type = _RESERVED_CHARACTER_OR;
                        break;

                    case L'^':
                        token[*line][index].type = _RESERVED_CHARACTER_XOR;
                        break;

                    case L',':
                        token[*line][index].type = _RESERVED_CHARACTER_COMMA;
                        break;

                    case L';':
                        token[*line][index].type = _RESERVED_CHARACTER_SEMICOLON;
                        break;

                    case L':':
                        sourceCode++;
                        if(token[*line - 2].type == _KEYWORD_case ||
                           token[*line - 1].type == _KEYWORD_default){
                            token[*line][index].type = _RESERVED_CHARACTER_OPEN_CASE_AND_DEFAULT;
                            sourceCode--;
                        }
                        else if(*sourceCode == L':'){
                            token[*line][index].type = _KEYWORD_dataStructure;
                        }
                        else{
                            token[*line][index].type = _KEYWORD_variable;
                            sourceCode--;
                        }
                        break;

                    case L'\n':
                        token[*line][index].type = _RESERVED_CHARACTER_BROKEN_LINE;
                        break;

                    default:
                        if((nextCharacters != L'\0')||
                        nextCharacters == '\0' && checkTokenValid(*sourceCode, L"=+*-/%%(){}[]&$@#!|^,;:.<>?°~º´`¨/ª¹²³£¢¬§\"'\\ \n\t\r")){
                            token[*line][index].type = __ERROR__;
                            token[*line][index].Identifiers.error.dataError = strcopy(ErrorsTable[_ERROR_INVALID_CHARACTERE]);
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
            (*line)++;
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
    i64 line = 0, i = 0;

    TokenGenerator(str, tokens, &line);

    while(i < line){
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

*/

/*
inline static i8 verifyIfTokensIsAKeyOrFN(String word, String sourceCode, Token **token, u64 line, u64 index){
    printf("entrou em verifyIfTokensIsAKeyOrFN\n");
    u64 identifyinternalOper = keyWordIdentify(word, internalOperTable, INTERNALOPERQTTY);
    printf("Saiu de keyWordIdentify\n");
    u64 identifyKeyWord = 0;
    u8 tokenFound = 0;

    if(!identifyinternalOper){
        identifyKeyWord = keyWordIdentify(word, KeyWordTable, KEYWORDsQTTY);
        printf("Saiu de keyWordIdentify\n");
    }

    if(identifyinternalOper || identifyKeyWord){
        i8 flag = 0;
        sourceCode++;
        if(checkTokenValid(*sourceCode, ALLCHARACTERES)){
            sourceCode--;
            flag = 1;
        }

        if(*sourceCode == '\0' && !flag){
            token[line][index].type = __ERROR__;
            memcopy(token[line][index].Identifiers.error.dataError,
            ErrorsTable[_ERROR_SYNTAX_KEYWORD], 0, ErrosTableSizes[_ERROR_SYNTAX_KEYWORD]);
            free(word);
            return -1;
        }

        if(!flag){
            i64 codeFnKeyCall = codeString(word);
            if(identifyinternalOper){
                token[line][index].type = _INTERNAL_FN;
                token[line][index].Identifiers.internaFn.fnCode = codeFnKeyCall;
            }
                
            else{
                token[line][index].type = _KEYWORD;
                token[line][index].Identifiers.Key.keyword = codeFnKeyCall;
            }
            
            sourceCode--;
            tokenFound = 1;
        }
    }

    return tokenFound;
}


u8 TokenGenerator(String sourceCode, Token **token, u64 *line){
    printf("Entrou na fn TK\n");
    i8 ERROR = 0;
    u64 counterCharacteres = 0, limit = INITSIZEWORDIDENTIFIER;
    u8 tokenFound = 0, index = 0;
    String word = STRALLOC(limit);
    if(word == NULL)
        return 1;

    while(*sourceCode){
        if(!(checkTokenValid(*sourceCode, L"=+*-/%%(){}[]&$@#!|^,;:<>?\"'\\ \n\t\r\0"))){
            word[counterCharacteres] = *sourceCode;
            counterCharacteres++;

            if(counterCharacteres == limit - 2){
                limit += limit >> 1;
                String newWord = (String)realloc(word, limit * sizeof(lchar));
                if(newWord == NULL)
                    return 4;

                word = newWord;
            }
        }

        word[counterCharacteres] = L'\0';
        wprintf(L"---word: %ls\n\n", word);

        tokenFound = verifyIfTokensIsAKeyOrFN(word, sourceCode, token, *line, index);
        printf("saiu de verifyIfTokensIsAKeyOrFN\n");
        if(tokenFound == -1)
            return -1;

        if(tokenFound)
            goto TOKEN_IS_ONE;

        sourceCode++;
        lchar nextCharacters = *sourceCode;
        sourceCode--;

        if((checkTokenValid(*sourceCode, L"=+*-/%%(){}[]&$@#!|^,;:.<>?°~º´`¨/ª¹²³£¢¬§\"'\\ \n\t\r") ||
        nextCharacters == L'\0') && tokenFound == 0){
            i8 flagAccessScope = 0, flagTokenPointer = 1;
            if(word[0] != L'\0'){
                if(word[0] == L'0'){
                    sourceCode++;
                    if(((int)word[1] >= 48 && (int)word[1] <= 57) && (word[1] != 'x' && word[1] != 'X')
                    && codeString(word) != 48){
                        token[*line][index].type = __ERROR__;
                        memcopy(token[*line][index].Identifiers.error.dataError,
                        ErrorsTable[_ERROR_INIT_IDENTIFIER], 0, ErrosTableSizes[_ERROR_INIT_IDENTIFIER]);
                        free(word);
                        return 2;
                    }

                    sourceCode--;
                }

                if((int)word[0] >= 48 && (int)word[0] <= 57){
                    if(*sourceCode == '.'){
                        flagAccessScope = 1;
                        flagTokenPointer = 0;
                    }

                    if(!flagAccessScope){
                        u8 flagFloat = 0, flagHex = 0;
                        String auxWord;
                        auxWord = strcopy(word);

                        while(*auxWord){
                            if(!(checkTokenValid(*auxWord, L"0123456789aAbBcCdDeEfFxX."))){
                                token[*line][index].type = __ERROR__;
                                memcopy(token[*line][index].Identifiers.error.dataError,
                                ErrorsTable[_ERROR_FORMAT_IDENTIFIER], 0, ErrosTableSizes[_ERROR_FORMAT_IDENTIFIER]);
                                free(word);
                                free(auxWord);
                                return 3;
                            }

                            else if(*auxWord == L'x' || *auxWord == L'X'){
                                auxWord++;
                                if(!flagFloat && !flagHex && *auxWord != L'\0' && word[0] == L'0'){
                                    flagHex = 1;
                                    auxWord--;
                                }
                                else{
                                    token[*line][index].type = __ERROR__;
                                    memcopy(token[*line][index].Identifiers.error.dataError,
                                    ErrorsTable[_ERROR_FORMAT_IDENTIFIER], 0, ErrosTableSizes[_ERROR_FORMAT_IDENTIFIER]);
                                    free(word);
                                    free(auxWord);
                                    return 3;
                                }
                            }

                            else if(*auxWord == L'.'){
                                auxWord++;
                                if(!flagFloat && *auxWord != L'\0' && !flagHex){
                                    flagFloat = 1;
                                    auxWord--;
                                }

                                else{
                                    token[*line][index].type = __ERROR__;
                                    memcopy(token[*line][index].Identifiers.error.dataError,
                                    ErrorsTable[_ERROR_FORMAT_IDENTIFIER], 0, _ERROR_FORMAT_IDENTIFIER);
                                    free(word);
                                    free(auxWord);
                                    return 3;
                                }
                            }

                            auxWord++;
                        }

                        token[*line][index].type = (flagFloat) ? _IDENTIFIER_CONST_f64 : _IDENTIFIER_CONST_i64;
                        token[*line][index].Identifiers.constData.addinfo = (flagHex) ? HEX : DEC;
                        token[*line][index].Identifiers.constData.data = strcopy(word);
                    }
                }

                else{
                    if(codeString(word) != _INTERNAL_FNCHARPOINTERNUMCODE){
                        if(*sourceCode == L'.'){
                            word[counterCharacteres - 1] = L'\0';
                            counterCharacteres--;
                        }

                        token[*line][index].type = __IDENTIFIER__;
                        token[*line][index].Identifiers.Data.nameIdentifier = strcopy(word);
                    }

                    else{
                        (*line)--;
                    }
                }

                tokenFound = flagTokenPointer;
            }

            if(*sourceCode == L'.' && !flagAccessScope){
                if(tokenFound){
                    index++;
                }
                token[*line][index].type = _RESERVED_CHARACTER_ACCESS_SCOPE;
            }

            else if(*sourceCode == L'"' || *sourceCode == L'\''){
                u8 flagChar = 0;

                if(tokenFound){
                    (*line)++;
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
                            token[*line][index].type = __ERROR__;
                            memcopy(token[*line][index].Identifiers.error.dataError,
                            ErrorsTable[_ERROR_STRING], 0, ErrosTableSizes[_ERROR_STRING]);
                            free(word);
                            return 7;
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

                    token[*line][index].type = _IDENTIFIER_CONST_STRING;
                    token[*line][index].Identifiers.constData.data = strcopy(word);
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
                            token[*line][index].type = __ERROR__;
                            memcopy(token[*line][index].Identifiers.error.dataError,
                            ErrorsTable[_ERROR_INVALID_SCAPE_CHARACTERE], 0, ErrosTableSizes[_ERROR_INVALID_SCAPE_CHARACTERE]);
                            free(word);
                            return 8;
                        }
                    }

                    else if(checkTokenValid(*sourceCode, ALLCHARACTERES) ||
                       checkTokenValid(*sourceCode, TOKENSCHARACTERES)){
                        word[0] = *sourceCode;
                        flagChar = 1;
                    }
                    sourceCode++;

                    if(*sourceCode != L'\''){
                        token[*line][index].type = __ERROR__;
                        memcopy(token[*line][index].Identifiers.error.dataError,
                        ErrorsTable[_ERROR_INVALID_CONST_CHAR], 0, ErrosTableSizes[_ERROR_INVALID_CONST_CHAR]);
                        free(word);
                        return 9;
                    }

                    else{
                        word[flagChar] = '\0';
                        token[*line][index].type = _IDENTIFIER_CONST_CHAR;
                        token[*line][index].Identifiers.constData.data = strcopy(word);
                    }

                    tokenFound = 1;
                }
            }

            else if((*sourceCode != L' ' && *sourceCode != L'"' && *sourceCode != L'\'' && *sourceCode != L'.')){
                i8 flag = 1;
                if(tokenFound)
                    index++;
                
                switch(*sourceCode){
                    case L'=':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _RESERVED_CHARACTER_EQUAL_EQUAL;
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _RESERVED_CHARACTER_EQUAL;
                        }
                        break;
                    
                    case L'+':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_ADD_EQUAL;
                        }
                        else if(*sourceCode == L'+'){
                            token[*line][index].type = _OPERATOR_ADD_ADD;
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _OPERATOR_ADD;
                        }
                        break;

                    case L'-':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_SUB_EQUAL;
                        }
                        else if(*sourceCode == L'-'){
                            token[*line][index].type = _OPERATOR_SUB_SUB;
                        }
                        else if(*sourceCode == L'>'){
                            token[*line][index].type = _RESERVED_CHARACTER_ADDRESS_POINTER;
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _OPERATOR_SUB;
                        }
                        break;

                    case L'/':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_DIV_EQUAL;
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
                            token[*line][index].type = _OPERATOR_DIV;
                        }
                        break;

                    case L'*':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_MULT_EQUAL;
                        }
                        else if(*sourceCode == L'*'){
                            sourceCode++;
                            if(*sourceCode == L'='){
                                token[*line][index].type = _OPERATOR_POW_EQUAL;
                            }
                            else{
                                sourceCode--;
                                token[*line][index].type = _OPERATOR_POW;
                            }
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _OPERATOR_MULT;
                        }
                        break;

                    case L'%':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _OPERATOR_REST_EQUAL;
                        }
                        else{
                            sourceCode--;
                            token[*line][index].type = _OPERATOR_REST;
                        }
                        break;

                    case L'(':
                        token[*line][index].type = _RESERVED_CHARACTER_OPEN_EXPRESS;
                        break;

                    case L')':
                        token[*line][index].type = _RESERVED_CHARACTER_CLOSE_EXPRESS;
                        break;

                    case L'{':
                        token[*line][index].type = _RESERVED_CHARACTER_OPEN_BLOCK;
                        break;
                    
                    case L'}':
                        token[*line][index].type = _RESERVED_CHARACTER_CLOSE_BLOCK;
                        break;

                    case L'[':
                        token[*line][index].type = _RESERVED_CHARACTER_OPEN_BRACKET;
                        break;

                    case L']':
                        token[*line][index].type = _RESERVED_CHARACTER_CLOSE_BRACKET;
                        break;

                    case L'<':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _RESERVED_CHARACTER_SMALLER_EQUAL;
                        }
                        else if(*sourceCode == L'<'){
                            token[*line][index].type = _RESERVED_CHARACTER_MOV_BIT_LEFT;
                        }
                        else{
                            token[*line][index].type = _RESERVED_CHARACTER_SMALLER;
                            sourceCode--;
                        }
                        break;

                    case L'>':
                        sourceCode++;
                        if(*sourceCode == L'='){
                            token[*line][index].type = _RESERVED_CHARACTER_BIGGER_EQUAL;
                        }
                        else if(*sourceCode == L'>'){
                            token[*line][index].type = _RESERVED_CHARACTER_MOV_BIT_RIGHT;
                        }
                        else{
                            token[*line][index].type = _RESERVED_CHARACTER_BIGGER;
                            sourceCode--;
                        }
                        break;

                    case L'&':
                        token[*line][index].type = _RESERVED_CHARACTER_AND;
                        break;

                    case L'|':
                        token[*line][index].type = _RESERVED_CHARACTER_OR;
                        break;

                    case L'^':
                        token[*line][index].type = _RESERVED_CHARACTER_XOR;
                        break;

                    case L',':
                        token[*line][index].type = _RESERVED_CHARACTER_COMMA;
                        break;

                    case L';':
                        token[*line][index].type = _RESERVED_CHARACTER_SEMICOLON;
                        (*line)++;
                        break;

                    case L':':
                        sourceCode++;
                        if(token[*line][index - 2].type == _KEYWORD_case ||
                           token[*line][index - 1].type == _KEYWORD_default){
                            token[*line][index].type = _RESERVED_CHARACTER_OPEN_CASE_AND_DEFAULT;
                            sourceCode--;
                        }
                        else if(*sourceCode == L':')
                            token[*line][index].type = _KEYWORD_dataStructure;
                        
                        else{
                            token[*line][index].type = _KEYWORD_variable;
                            sourceCode--;
                        }
                        break;

                    case L'\n':
                        token[*line][index].type = _RESERVED_CHARACTER_BROKEN_LINE;
                        (*line)++;
                        break;

                    default:
                        if((nextCharacters != L'\0')||
                        nextCharacters == '\0' && checkTokenValid(*sourceCode, L"=+*-/%%(){}[]&$@#!|^,;:.<>?°~º´`¨/ª¹²³£¢¬§\"'\\ \n\t\r")){
                            token[*line][index].type = __ERROR__;
                            memcopy(token[*line][index].Identifiers.error.dataError,
                            ErrorsTable[_ERROR_INVALID_CHARACTERE], 0, ErrosTableSizes[_ERROR_INVALID_CHARACTERE]);
                            free(word);
                            return 5;
                        }
                        else
                            flag = 0;
                }

                tokenFound = flag;
            }

            else{
                if(*sourceCode != L'.' && flagAccessScope){
                    word[0] = '\0';
                    counterCharacteres = 0;
                    limit = INITSIZEWORDIDENTIFIER;
                }
            }
        }

    TOKEN_IS_ONE:

        if(tokenFound){
            printf("\n--------Token = 1\n");
            if(token[*line][index].type == _KEYWORD)
                printf("token found: %d---------\n\n", token[*line][index].Identifiers.Key.keyword);
            word[0] = L'\0';
            counterCharacteres = 0;
            limit = INITSIZEWORDIDENTIFIER;
            index++;
            tokenFound = 0;
        }

        sourceCode++;
    }

    if(word != NULL)
        free(word);
}

int main(){
    String str = L"i8 i16 i32 i64";
    Token **tokens = (Token**)malloc(sizeof(Token*) * START_TOKENS);
    i16 j = 0;
    u64 codelength = 0;

    for(; j < START_TOKENS; j++)
        tokens[j] = (Token*)malloc(sizeof(Token) * START_LINE);

    TokenGenerator(str, tokens, &codelength);

    j = 0;
    for(int y = 0; y < codelength; y++){
        while(1){
            if(tokens[y][j].type != ENDLINE)
                break;

            if(tokens[y][j].type != __ERROR__){
                wprintf(L"Error: %ls\n", tokens[y][j].Identifiers.error.dataError);
                break;
            }

            printf("TOKEN: %d\n", tokens[y][j].type);
        }
    }

    for(j = 0; j < START_TOKENS; j++)
        free(tokens[j]);
    
    free(tokens);

    return 0;
}
*/

/*
typedef struct{
    String nameIdentifier;
    String codeName;
}IdentifierData;


typedef struct{
    String data;
    u8 addinfo;
}IdentifierConst;


typedef struct{
    u16 fnCode;
}IdentifierinternalFn;


typedef struct{
    lchar dataError[60];
}ERROR_;


typedef struct{
    u16 keyword;
}KeyWordType;


typedef struct{
    u16 type;
    union{
        KeyWordType Key;
        IdentifierData Data;
        IdentifierConst constData;
        IdentifierinternalFn internaFn;
        ERROR_ error;
        u8 EndLine;
    }Identifiers;
}Token;
*/

// String KeyWordTable[KEYWORDsQTTY] = {
//     L"i8",          L"u8",          L"f32",         L"if",
//     L"i32",         L"i16",         L"f64",         L"fn",
//     L"i64",         L"in",          L"u32",         L"u16",
//     L"or",          L"u64",         L"FILE",        L"and",
//     L"all",         L"Try",         L"key",         L"for",
//     L"new",         L"not",         L"This",        L"List",
//     L"char",        L"case",        L"elif",        L"else",
//     L"Catch",       L"Class",       L"break",       L"while",
//     L"const",       L"Method",      L"Resize",      L"public",
//     L"HashMap",     L"switch",      L"import",      L"string",
//     L"result",      L"default",     L"private",     L"continue",
//     L"ArrayList",   L"Attribute"
// };

// String internalOperTable[INTERNALOPERQTTY] = {
//     L"rd",           L"pop",          L"wrt",          L"Type",
//     L"copy",         L"keys",         L"push",         L"clear",
//     L"items",        L"length",       L"update",       L"values",
//     L"remove",       L"ReadFile",     L"reverse",      L"FileOpen",
//     L"FileClose",    L"WriteFile",    L"strtolist",    L"ReadFileLine",
// };

/*int main(){
    Array_i8Ty *arrBty = (Array_i8Ty*)newArray(10, sizeof(Array_i8Ty), __ARRAYi8__);
    int i = 0;

    for(i = 0; i < arrBty->GN_Fields.capacity; i++){
        arrBty->data[i] = i + 1;
        printf("%d -> ", arrBty->data[i]);
    }
    printf("end\n");

    Array_f32Ty *arrflt = (Array_f32Ty*)newArray(10, sizeof(Array_f32Ty), __ARRAYf32__);

    for(i = 0; i < arrflt->GN_Fields.capacity; i++){
        arrflt->data[i] = i * 0.3445;
        arrflt->GN_Fields.extention++;
        printf("%f -> ", arrflt->data[i]);
    }
    printf("end\n");

    resizeArray(15, sizeof(Array_f32Ty), (GenericArray*)arrflt, __ARRAYf32__);
    for(i = 0; i < arrflt->GN_Fields.capacity; i++){
        printf("%f -> ", arrflt->data[i]);
    }

    printf("\n");


    Array_stringTy *arrStr = (Array_stringTy*)newArray(7, sizeof(Array_stringTy), __ARRAYSTRING__);
    for(i = 0; i < arrStr->GN_Fields.capacity; i++){
        printf("string[%d]: ", i);
        if(arrStr->data[i] == NULL){
            printf("string null\n");
        }
        else{
            WindowsWrt(arrStr->data[i], L"\n");
        }
    }


    free(arrBty);
    free(arrBty->data);
    free(arrflt);
    free(arrflt->data);
}
*/

// int mainn(){
//     List *list = newList(START_DATA_STRUCTURE);

//     unsigned char *bytes;
//     packageReceived pkrv;

//     lchar *i_n = NULL;

//     pkrv.pack_ty = PACK_BYTES;

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x09, 0x02, 0x02, ENDBYTE};
//     pushList(&list, __i64__, pkrv, 4);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, ENDBYTE};
//     pushList(&list, __i64__, pkrv, 3);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0F, 0x03, 0x05, ENDBYTE};
//     pushList(&list, __i8__, pkrv, 3);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, 0x00, ENDBYTE};
//     pushList(&list, __i16__, pkrv, 4);

//     i64 limit = 1000000;
//     for(i64 i = 0; i < limit; i++){
//         if(i % 7 == 0){
//             pkrv.pack_ty = PACK_DOUBLE_BYTES;
//             i_n = inttstr(i);
//             pkrv.package_ty.pack_doublebytes = i_n;
//             pushList(&list, __String__, pkrv, strsize(i_n) + 1);
//         }

//         else{
//             pkrv.pack_ty = PACK_BYTES;
//             char size = 0;
//             bytes = expandsToi8s(i, &size);
//             pkrv.package_ty.pack_bytes = bytes;

//             if(i <= 127 && i >= -128){
//                 pushList(&list, __i8__, pkrv, (unsigned long long)size);
//             }

//             else if(i <= 32767 && i >= -32768){
//                 pushList(&list, __i16__, pkrv, (unsigned long long)size);
//             }

//             else if(i % 2 == 0){
//                 pushList(&list, __i32__, pkrv, (unsigned long long)size);
//             }

//             else{
//                 pkrv.pack_ty = PACK_INTEGER;
//                 pkrv.package_ty.pack_integer = i;
//                 pushList(&list, __i64__, pkrv, (unsigned long long)size);
//             }
//         }
//     }

//     free(bytes);
//     free(i_n);

//     pkrv.pack_ty = PACK_BYTES;

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, 0x00, 0x00, 0x00, ENDBYTE};
//     pushList(&list, __i64__, pkrv, 6);
//     pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X0F;
//     pushList(&list, __i64__, pkrv, 6);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, 0x00, 0x00, ENDBYTE};
//     pushList(&list, __i32__, pkrv, 5);
//     pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X0F;
//     pushList(&list, __i32__, pkrv, 5);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, 0x00, ENDBYTE};
//     pushList(&list, __i16__, pkrv, 4);
//     pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X0F;
//     pushList(&list, __i16__, pkrv, 4);

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x03, 0x05, ENDBYTE};
//     pushList(&list, __i8__, pkrv, 3);
//     pkrv.package_ty.pack_bytes[0] = STARTBYTE_0X0F;
//     pushList(&list, __i8__, pkrv, 3);

//     pkrv.pack_ty = PACK_DOUBLE_BYTES;

//     lchar hello_world[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x00};
//     pkrv.package_ty.pack_doublebytes = hello_world;
//     pushList(&list, __String__, pkrv, 14);

//     lchar input[] = L"Todos esses momentos se perderão no tempo, como lágrimas na chuva...";
//     pkrv.package_ty.pack_doublebytes = input;
//     pushList(&list, __String__, pkrv, 69);

//     lchar blade_runner[] = L"Blade Runner: Melhor filme de toda a história do cinema!";
//     pkrv.package_ty.pack_doublebytes = blade_runner;
//     pushList(&list, __String__, pkrv, 43);

//     lchar *games[] = {
//                         L"Dark Souls Remaster", L"Hollow Knight", L"Elden Ring",
//                         L"Cyberpunk 2077", L"Dark Souls III", L"Batman: Arkham Knight",
//                         L"Red Dead Redemption 2", L"Lies Of P", L"BloodBorne",
//                         L"Sekiro", L"Dark Souls II"
//                       };

//     for(char y = 0; y < 11; y++){
//         pkrv.package_ty.pack_doublebytes = games[y];
//         pushList(&list, __String__, pkrv, strsize(games[y]) + 1);
//     }

//     lchar maxnum_long_long[] = L"9223372036854775807";
//     i64 max_nLL = convert_StringToInteger(L"9223372036854775807");

//     pkrv.pack_ty = PACK_BYTES;

//     charsize_t len = 0;
//     u8 *newData_c = expandsToi8s(max_nLL, &len);
//     pkrv.package_ty.pack_bytes = newData_c;
//     pushList(&list, __i64__, pkrv, (i64)len);

//     pkrv.pack_ty = PACK_DOUBLE_BYTES;

//     free(newData_c);
//     pkrv.package_ty.pack_doublebytes = maxnum_long_long;
//     pushList(&list, __String__, pkrv, strsize(maxnum_long_long) + 1);

//     lchar ellen[] = L"Ellen, morzinho di mi vida";
//     pkrv.package_ty.pack_doublebytes = ellen;
//     pushList(&list, __String__, pkrv, strsize(ellen) + 1);

//     pkrv.pack_ty = PACK_BYTES;

//     pkrv.package_ty.pack_bytes = (u8[]){STARTBYTE_0X0E, 0x09, 0x02, 0x02, 0x03, 0x03, 0x07, 0x02, 0x00, 0x03, 0x06, ENDBYTE};
//     pushList(&list, __i64__, pkrv, 11);

//     pkrv.pack_ty = PACK_INTEGER;

//     pkrv.package_ty.pack_integer = 9223372036854775807;
//     pushList(&list, __i64__, pkrv, strsize(L"9223372036854775807") + 1);

//     pkrv.package_ty.pack_integer = 25042006;
//     pushList(&list, __i32__, pkrv, strsize(L"25042006") + 1);

//     pkrv.pack_ty = PACK_DOUBLE_BYTES;

//     pkrv.package_ty.pack_doublebytes = L"Ton-618";
//     pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doublebytes) + 1);

//     pkrv.package_ty.pack_doublebytes = L"I Love You Ellen";
//     pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doublebytes) + 1);

//     pkrv.package_ty.pack_doublebytes = L"End List";
//     pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doublebytes) + 1);

//     printList(&list, MODE_PRINT_LIST, 0, list->GN_Fields.extention);
//     freeList(&list);
// }

// #define KeyWordTable  (String[KEYWORDsQTTY]){                                                           \
//                                     L"i8", L"u8", L"f32", L"if", L"i32", L"i16", L"f64", L"fn",         \
//                                     L"i64", L"in", L"u32", L"u16", L"or", L"u64", L"FILE", L"and",      \
//                                     L"all", L"Try", L"key", L"for", L"new", L"not", L"This", L"List",   \
//                                     L"char", L"case", L"elif", L"else", L"Catch", L"Class", L"break",   \
//                                     L"while", L"const", L"Method", L"Resize", L"thread", L"public", L"HashMap",    \
//                                     L"switch", L"import", L"string", L"return", L"default", L"private", \
//                                     L"continue", L"ArrayList", L"Attribute"                             \
//                                }

// #define internalOperTable (String[INTERNALOPERQTTY]){                                                        \
//                                         L"rd", L"pop", L"wrt", L"Type", L"copy", L"keys", L"push", L"clear", \
//                                         L"items", L"length", L"update", L"values", L"remove", L"ReadFile",   \
//                                         L"reverse", L"FileOpen", L"FileClose", L"WriteFile", L"strtolist",   \
//                                         L"ReadFileLine"                                                      \
//                                    }


// if(returnfn >= COMMENT){
//     if(lastline != *line){
//         if(*word)
//             index++;

//         tokens[lastline][index].type = ENDLINE;
//         index = 0;
//         lastline = *line;
//         tf = 0;
//     }

//     goto TOKENFOUND;
// }