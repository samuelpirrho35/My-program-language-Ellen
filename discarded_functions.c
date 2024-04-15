/*void print_BigintObject(BigintObject *int_Object){
    if(int_Object->sign == 1){
        printf("%c", '-');
    }

    uint64_t i;
    for(i = int_Object->sign; i < int_Object->extention; i++){
        printf("%d", int_Object->data[i]);
    }
}*/

/*static uint8_t verifySizeInt(char *str_int){
    register uint8_t bigger_than_int = 0, sign = 0;
    int lengthInt_str = strsize(str_int);

    if(str_int[0] == '-'){
        sign = 1;
    }

    if((lengthInt_str - sign) > Int_SIZE_64){
        bigger_than_int = 1;
    }

    else if((lengthInt_str - sign) < Int_SIZE_64){
        bigger_than_int = -1;
    }

    if(bigger_than_int == 0){
        uint8_t stack_overFlow = 0;
        char int_max_in_str[20] = "18446744073709551615";

        int i;
        for(i = lengthInt_str - 1; i >= sign; i--){
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
        if(list_Object[i].Type_Identifier_Object == IDENTIFIER_Int_OBJECT_DINAMIC){
            print_BigintObject(list_Object[i].types.int_Object_dinamic);
        }

        else if(list_Object[i].Type_Identifier_Object == IDENTIFIER_Int_OBJECT_STATIC){
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
        if((*list_Object)[index].Type_Identifier_Object == IDENTIFIER_Int_OBJECT_STATIC){
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

        else if((*list_Object)[index].Type_Identifier_Object == IDENTIFIER_Int_OBJECT_DINAMIC){

        }
    }

    wrt_Identifier_String_Object(list);
    free(list);
}*/

/*
BigintObject*
sum_IntDinamic_and_IntDinamic(BigintObject *IntObject_store,
BigintObject *IntObject)
{
    register u8 BiggerSizeIntObject;
    register Long LengthBiggerIntObject;
    u8 *NewDataIntObject;

    if(IntObject_store->extention >= IntObject->extention){
        BiggerSizeIntObject = 1;
        LengthBiggerIntObject = IntObject_store->extention;
        NewDataIntObject = (u8*)malloc(LengthBiggerIntObject + 1);
        NewDataIntObject = IntObject_store->data;
    }

    else{
        BiggerSizeIntObject = 2;
        LengthBiggerIntObject = IntObject->extention;
        NewDataIntObject = (u8*)malloc(LengthBiggerIntObject + 1);
        NewDataIntObject = IntObject->data;
    }

    register Long i, y = ((BiggerSizeIntObject == 1) ? IntObject->extention : IntObject_store->extention) - 1;
    register u8 upOne = 0;
    for(i = LengthBiggerIntObject - 1; i >= 0; i--){
        register u8 digit = NewDataIntObject[i];
        register u8 sum = 0;
        if(y >= 0){
            register u8 digit2 = (BiggerSizeIntObject == 1) ? IntObject->data[y] : IntObject_store->data[y];
            sum = digit + digit2 + upOne;
            NewDataIntObject[i + 1] = sum % 10;
            upOne = sum / 10;
            y--;
        }

        else{
            sum = digit + upOne;
            NewDataIntObject[i + 1] = sum % 10;
            upOne = sum / 10;
        }
    }
    
    NewDataIntObject[0] = upOne;
    IntObject_store->data = NewDataIntObject;
    IntObject_store->extention = LengthBiggerIntObject + 1;

    return IntObject_store;
}
*/

/*i = 0;
while(i <= more_than_length_copy){
    if(NewDataIntObject[i] != 0 && !flag2){
        flag2 = 1;
    }

    if(flag2){
        NewDataIntObject[y++] = NewDataIntObject[i];
    }
    else{
        _zeros++;
    }
    i++;
}

NewDataIntObject = realloc(NewDataIntObject, more_than_length_copy - _zeros + 1);*/

/*BigintObject*
sum_IntDinamic_and_IntDinamic
(BigintObject *IntObject_store,
BigintObject *IntObject)
{
    register u8 BiggerSizeIntObject;
    register Long LengthBiggerIntObject;
    u8 *NewDataIntObject;

    if(IntObject_store->extention >= IntObject->extention){
        BiggerSizeIntObject = 1;
        //NewDataIntObject = (u8*)malloc(IntObject_store->extention);
        NewDataIntObject = IntObject_store->data;
        LengthBiggerIntObject = IntObject_store->extention;
    }

    else{
        BiggerSizeIntObject = 2;
        //NewDataIntObject = (u8*)malloc(IntObject->extention);
        NewDataIntObject = IntObject->data;
        LengthBiggerIntObject = IntObject->extention;
    }

    register Long i, y = ((BiggerSizeIntObject == 1) ? IntObject->extention : IntObject_store->extention) - 1;
    register u8 upOne = 0;
    for(i = LengthBiggerIntObject - 1; i != -1; i--){
        register u8 digit = NewDataIntObject[i];
        register u8 sum = 0;
        if(y >= 0){
            register u8 digit2 = (BiggerSizeIntObject == 1) ? IntObject->data[y] : IntObject_store->data[y];
            sum = digit + digit2 + upOne;
            if(upOne){
                upOne = 0;
            }
            
            if(sum > 9){
                NewDataIntObject[i] = sum - 10;
                upOne = 1;
            }
            else{
                NewDataIntObject[i] = sum;
            }

            y--;
        }

        else{
            sum = digit + upOne;
            if(upOne){
                upOne = 0;
            }

            if(sum > 9){
                NewDataIntObject[i] = sum - 10;
                upOne = 1;
            }
            else{
                NewDataIntObject[i] = sum;
            }

            if(upOne == 0){
                break;
            }
        }
    }

    if(upOne){
        IntObject_store->data = expandDataIntDinamicObject(NewDataIntObject, upOne, LengthBiggerIntObject);
        IntObject_store->extention = LengthBiggerIntObject + 1;
    }
    else{
        IntObject_store->data = NewDataIntObject;
        IntObject_store->extention = LengthBiggerIntObject;
    }

    return IntObject_store;
}*/


/*BigintObject
sum_IntDinamic_and_IntDinamic
(BigintObject IntObject_store,
BigintObject IntObject)
{
    register u8 BiggerSizeIntObject;
    register Long LengthBiggerIntObject;
    u8 *NewDataIntObject;

    if(IntObject_store.extention >= IntObject.extention){
        BiggerSizeIntObject = 1;
        NewDataIntObject = copyData(IntObject_store.data, NewDataIntObject, IntObject_store.extention);
        LengthBiggerIntObject = IntObject_store.extention;
    }

    else{
        BiggerSizeIntObject = 2;
        NewDataIntObject = copyData(IntObject.data, NewDataIntObject, IntObject.extention);
        LengthBiggerIntObject = IntObject.extention;
    }

    register Long i, y = ((BiggerSizeIntObject == 1) ? IntObject.extention : IntObject_store.extention) - 1;
    register u8 upOne = 0;
    for(i = LengthBiggerIntObject - 1; i != -1; i--){
        register u8 digit = NewDataIntObject[i];
        register u8 sum = 0;
        if(y >= 0){
            register u8 digit2 = (BiggerSizeIntObject == 1) ? IntObject.data[y] : IntObject_store.data[y];
            sum = digit + digit2 + upOne;
            if(upOne){
                upOne = 0;
            }
            
            if(sum > 9){
                NewDataIntObject[i] = sum - 10;
                upOne = 1;
            }
            else{
                NewDataIntObject[i] = sum;
            }

            y--;
        }

        else{
            sum = digit + upOne;
            if(upOne){
                upOne = 0;
            }

            if(sum > 9){
                NewDataIntObject[i] = sum - 10;
                upOne = 1;
            }
            else{
                NewDataIntObject[i] = sum;
            }

            if(upOne == 0){
                break;
            }
        }
    }

    if(upOne){
        IntObject_store.data = expandDataIntDinamicObject(NewDataIntObject, upOne, LengthBiggerIntObject);
        IntObject_store.extention = LengthBiggerIntObject + 1;
    }
    else{
        IntObject_store.data = NewDataIntObject;
        IntObject_store.extention = LengthBiggerIntObject;
    }

    return IntObject_store;
}*/

/*#ifndef OBJECTSSTRUCT_H
#define OBJECTSSTRUCT_H

#include "../includedefines/inttypes.h"
#include "../includedefines/sizeDefined.h"
#include "../includedefines/defines.h"
#include "../includeEnumerator/typeObjects.h"

//-----------OBJECTS---------------

typedef struct{
    u8 sign;
    Long extention;
    u8 *data;
    String _String_Data;
}BigintObject;


typedef struct{
    Long dataLong;
    char _String_data[Int_SIZE_64 + 1];
}Identifier_Int_Static_Object;


typedef struct{
    String StringObject;
}StringTypeObject;


typedef struct{
    u8 sign;
    u64 extention;
    u8 *data_Int;
    u8 division;
    u8 *data_Float;
    String _String_Data;
}BigfloatObject;


typedef struct{
    double *data;
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
        Identifier_Int_Static_Object *int_Object_static;
        StringTypeObject *StringObject;
        struct ListTypeObject *list_Object;
    }types;
}ListTypeObject;


typedef struct{
    reference_types Type_Identifier_Object;
    union{
        BigintObject *int_Object_dinamic;
        Identifier_Int_Static_Object *int_Object_static;
        StringTypeObject *StringObject;
        ListTypeObject *list_Object;
        BigfloatObject *float_Object_dinamic;
        FloatTypeObject *float_Object_static;
    }types;

}Objects;


typedef struct{
    Long extention;
    Long capacity;
    union{
        Long *intStaticArray;
        String *strArray;
        double *floatStaticArray;
        BigintObject *intDinamicArray;
        BigfloatObject *floatDinamicArray;
        ListTypeObject *listArray;
        struct ArrayTypeObject *arrayArray;
    }type_Arrays;
}ArrayTypeObject;


typedef struct{
    reference_types *params;
    reference_types *args;
    Objects *objects;
    Int paramsQtty;
    union{
        BigintObject *int_Object_dinamic;
        Identifier_Int_Static_Object *int_Object_static;
        StringTypeObject *StringObject;
        ListTypeObject *list_Object;
        BigfloatObject *float_Object_dinamic;
        FloatTypeObject *float_Object_static;
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
            if((*list_Object)[i].Type_Identifier_Object == IDENTIFIER_Int_OBJECT_STATIC){
                strcat((*list_Object)->list_String, (*list_Object)[i].types.int_Object_static->_String_data);
            }

            else if((*list_Object)[i].Type_Identifier_Object == IDENTIFIER_Int_OBJECT_DINAMIC){
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
register Long character = 0, index = 0;
    register Byte find = 0;
    Byte error = 0;
    register Long counterCharacteres = 0, lenFontCode = strsize(code);
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

        else if((keyWord_table(wordAux, "int") == Int) || (keyWord_table(wordAux, "str") == STR) ||
        (keyWord_table(wordAux, "float") == Float)){
            code++;
            counterCharacteres++;

            if(*code == ' '){
                switch(hashString(wordAux)){
                    case Int:
                        token[index].type = _IDENTIFIER_int;
                        break;
                    case STR:
                        token[index].type = _IDENTIFIER_str;
                        break;
                    case Float:
                        token[index].type = _IDENTIFIER_float;
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
            Long lenString = 10;
            String getString = (String)malloc(lenString);
            char typeStart_String = *code;

            token[index].type = _RESERVED_CHARACTER_START_String;
            token[index].value = NULL;
            printf("TOKEN encontrado: %d\n", token[index].type);

            index++;
            code++;
            counterCharacteres++;

            Long counter = 0;
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
            Long lenNum = 10;
            Byte flagFloat = 0;
            String getNum = (String)malloc(lenNum);

            Long i = 0;
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
                        token[index].type = _IDENTIFIER_CONST_Int;
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
            keyWordIdentify(word, "int") == Int ||
            keyWordIdentify(word, "float") == Float ||
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
        (keyWordIdentify(identifierObject, "int") == Int) ||
        (keyWordIdentify(identifierObject, "float") == Float) ||
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

/*register Long strEqualKey_word = codeString(key_word);
    register Long lenStr = strsize(str), lenkeyWord = strsize(key_word);

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

/*void verifyIdentifierDeclaration(String identifierObject, Byte *error){
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
    Long size = strsize(format), count = 0;
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
    Byte sizeBits;
    union{
        Byte data8bits;
        Short data16bits;
        Int data32bits;
        Long data64bits;
    //}TypeInt;
    String _String_data;
}Identifier_Int_Static_Object;*/

/*String GetUTF(String path, Byte *Error){
    FILE *f = _wfopen(path, L"rb");
    Long len = 1024, counter = 0;
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
            u16 lastByte = byte;
            fread(&byte, sizeof(u8), 1, f);

            if((byte & 0xC0) == 0x80){
                lastByte &= 0x1F;
                lastByte <<= 6;
                byte &= 0x3F;
                rune[counter] = lastByte | byte;
            }
            else{
                (*Error) = ERRORUTF2BYTES;
                printf("Error 2");
                (*Error) = ERRORALLOCNULL;
                return NULL;
            }
        }

        else if((byte & 0xF0) == 0xE0){
            u16 firstByte = byte;
            fread(&byte, sizeof(u8), 1, f);
            u16 secondByte = byte;

            fread(&byte, sizeof(u8), 1, f);
            u16 thirdByte = byte;

            if((secondByte & 0xC0) == 0x80 && (thirdByte & 0xC0) == 0x80){
                firstByte &= 0x0F;
                firstByte <<= 12;
                secondByte &= 0x3F;
                secondByte <<= 6;
                thirdByte &= 0x3F;
                rune[counter] = firstByte | secondByte | thirdByte;
            }
            else{
                (*Error) = ERRORUTF3BYTES;
                return NULL;
            }
        }

        else if((byte & 0xF8) == 0xF0){
            u16 firstByte = byte, secondByte, thirdByte, fourthByte;

            fread(&byte, sizeof(u8), 1, f);
            secondByte = byte;

            fread(&byte, sizeof(u8), 1, f);
            thirdByte = byte;

            fread(&byte, sizeof(u8), 1, f);
            fourthByte = byte;

            if((secondByte & 0xC0) == 0x80 && (thirdByte & 0xC0) == 0x80 && (fourthByte & 0xC0) == 0x80){
                firstByte &= 0x07;
                firstByte <<= 18;
                secondByte &= 0x3F;
                secondByte <<= 12;
                thirdByte &= 0x3F;
                thirdByte <<= 6;
                fourthByte &= 0x3F;
                rune[counter] = firstByte | secondByte | thirdByte | fourthByte;
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

/*String GetUTF(String path, Byte *Error){
    FILE *f = _wfopen(path, L"rb");
    Long len = 1024, counter = 0;
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
            u16 lastByte = byte;
            fread(&byte, sizeof(u8), 1, f);

            if((byte & 0xC0) == 0x80){
                lastByte &= 0x1F;
                lastByte <<= 6;
                byte &= 0x3F;
                rune[counter] = lastByte | byte;
            }
            else{
                (*Error) = ERRORUTF2BYTES;
                printf("Error 2");
                (*Error) = ERRORALLOCNULL;
                return NULL;
            }
        }

        else if((byte & 0xF0) == 0xE0){
            u16 firstByte = byte;
            u8 nextBytes[2];
            fread(nextBytes, sizeof(u8), 2, f);

            if((nextBytes[0] & 0xC0) == 0x80 && (nextBytes[1] & 0xC0) == 0x80){
                u16 secondByte = nextBytes[0], thirdbyte = nextBytes[1];
                firstByte &= 0x0F;
                firstByte <<= 12;
                nextBytes[0] &= 0x3F;
                nextBytes[0] <<= 6;
                nextBytes[1] &= 0x3F;
                rune[counter] = firstByte | nextBytes[0] | nextBytes[1];
            }
            else{
                (*Error) = ERRORUTF3BYTES;
                return NULL;
            }
        }

        else if((byte & 0xF8) == 0xF0){
            u16 firstByte = byte;
            u16 nextBytes[3];

            fread(nextBytes, sizeof(u8), 3, f);

            if((nextBytes[0] & 0xC0) == 0x80 && (nextBytes[1] & 0xC0) == 0x80 && (nextBytes[2] & 0xC0) == 0x80){
                firstByte &= 0x07;
                firstByte <<= 18;
                nextBytes[0] &= 0x3F;
                nextBytes[0] <<= 12;
                nextBytes[1] &= 0x3F;
                nextBytes[1] <<= 6;
                nextBytes[2] &= 0x3F;
                rune[counter] = firstByte | nextBytes[0] | nextBytes[1] | nextBytes[1];
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

/*BigintObject* create_Int_Dinamic_Object(String parseToInt){
    u64 int_Length = strsize(parseToInt);
    BigintObject *int_Object = DIntALLOC(1);

    if(parseToInt[0] == L'-'){
        int_Object->sign = 1;
    }

    else{
        int_Object->sign = 0;
    }

    int_Object->extention = int_Length;
    int_Object->data = uByteALLOC(int_Object->extention);

    register Long i;
    for(i = int_Object->sign; i < int_Object->extention; i++){
        int_Object->data[i] = (int)parseToInt[i] - 48;
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
                v = list[index].types.long_ty;
                str = inttstr(v);
                break;
            case _int_:
                v = (long long)list[index].types.int_ty;
                str = inttstr(v);
                break;
            case _short_:
                v = (long long)list[index].types.short_ty;
                str = inttstr(v);
                break;
            case _byte_:
                v = (long long)list[index].types.byte_ty;
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
    LongTypeObject *LongArray;
}ArrayLongObject;


typedef struct{
    IntTypeObject *IntArray;
}ArrayIntObject;


typedef struct{
    ShortTypeObject *ShortArray;
}ArrayShortObject;


typedef struct{
    ByteTypeObject *ByteArray;
}ArrayByteObject;


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
    DoubleTypeObject *doubleArray;
}ArrayDoubleObject;


typedef struct{
    BigintObject *intDinamicArray;
}ArrayIntDinamicObject;


typedef struct{
    BigfloatObject *floatDinamicArray;
}ArrayBigfloatObject;

typedef struct{
    Long LongObject;
}LongTypeObject;


typedef struct{
    Int IntObject;
}IntTypeObject;


typedef struct{
    Short ShortObject;
}ShortTypeObject;


typedef struct{
    Byte ByteObject;
}ByteTypeObject;
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
                    if((*list_Object)[i].Type_Identifier_Object == __Long__ ||
                        (*list_Object)[i].Type_Identifier_Object == __Int__ ||
                        (*list_Object)[i].Type_Identifier_Object == __Short__ ||
                        (*list_Object)[i].Type_Identifier_Object == __Byte__){
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
        //printf("Byte[%d]    %d\n", i, pkrv.bytePack[i]);
    }
    printf("end byte[]\n\n");

    switch(type_Object){
        case __Long__:
            printf("Type: Long\n");
            (*list_Object)[_extention - 1].Types.IntTypes.LongType.LongObject = compressToInteger(pkrv.bytePack, Data_length);
            printf("n: %lld\n", (*list_Object)[_extention - 1].Types.IntTypes.LongType.LongObject);
            break;
        case __Int__:
            printf("Type: Int\n");
            (*list_Object)[_extention - 1].Types.IntTypes.IntType.IntObject = (Int)compressToInteger(pkrv.bytePack, Data_length);
            printf("n: %lld\n", (*list_Object)[_extention - 1].Types.IntTypes.IntType.IntObject);
            break;
        case __Short__:
            printf("Type: Short\n");
            (*list_Object)[_extention - 1].Types.IntTypes.ShortType.ShortObject = (Short)compressToInteger(pkrv.bytePack, Data_length);
            printf("n: %lld\n", (*list_Object)[_extention - 1].Types.IntTypes.ShortType.ShortObject);
            break;
        case __Byte__:
            printf("Type: Byte\n");
            (*list_Object)[_extention - 1].Types.IntTypes.ByteType.ByteObject = (Byte)compressToInteger(pkrv.bytePack, Data_length);
            printf("n: %lld\n", (*list_Object)[_extention - 1].Types.IntTypes.ByteType.ByteObject);
            break;
        case __String__:
            (*list_Object)[_extention - 1].Types.StringObject.StringObject = strcopy(pkrv.shortPack);
            break;
    }

    (*list_Object)[(*list_Object)->extention - 1].Type_Identifier_Object = type_Object;
}*/

/*


void assemblePackage(packageReceived *pkrv, size_ty size, u8 receivedBytes[]){
    if(pkrv->size_b != 0){
        free(pkrv->bytePack);
        pkrv->bytePack = (u8*)realloc(pkrv->bytePack, size);
    }

    else{
        pkrv->bytePack = ByteALLOC(size);
    }

    pkrv->size_b = size;

    for(size_ty i = 0; i < size; i++){
        pkrv->bytePack[i] = receivedBytes[i];
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
        case __Long__:
            (*list)[index].Types.primitiveTy.intTys.long_ty = compressToInteger(pkrv.package_ty.pack_bytes, size);
            break;

        case __Int__:
            (*list)[index].Types.primitiveTy.intTys.int_ty = compressToInteger(pkrv.package_ty.pack_bytes, size);
            break;

        case __Short__:
            (*list)[index].Types.primitiveTy.intTys.short_ty = compressToInteger(pkrv.package_ty.pack_bytes, size);
            break;
        
        case __Byte__:
            (*list)[index].Types.primitiveTy.intTys.byte_ty = compressToInteger(pkrv.package_ty.pack_bytes, size);
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
        BigintObject IntDinamicType;
        BigfloatObject FloatDinamicType;
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
            case __Long__:
                List[i].Types.primitiveTy.intTys.long_ty = list[i].Types.primitiveTy.intTys.long_ty;
                break;
            case __Int__:
                List[i].Types.primitiveTy.intTys.int_ty = list[i].Types.primitiveTy.intTys.int_ty;
                break;
            case __Short__:
                List[i].Types.primitiveTy.intTys.short_ty = list[i].Types.primitiveTy.intTys.short_ty;
                break;
            case __Byte__:
                List[i].Types.primitiveTy.intTys.byte_ty = list[i].Types.primitiveTy.intTys.byte_ty;
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
        Long v;

        printf("Type: %d\n", list[index].object_ty);
        switch(list[index].object_ty){
            case __Long__:
                printf("Caiu aqui: long\n");
                v = list[index].Types.primitiveTy.intTys.long_ty;
                break;
            case __Int__:
                printf("Caiu aqui: int\n");
                v = (long long)list[index].Types.primitiveTy.intTys.int_ty;
                break;
            case __Short__:
                printf("Caiu aqui: short\n");
                v = (long long)list[index].Types.primitiveTy.intTys.short_ty;
                break;
            case __Byte__:
                printf("Caiu aqui: byte\n");
                v = (long long)list[index].Types.primitiveTy.intTys.byte_ty;
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

    pkrv.package_ty.pack_bytes = (data_c[]){0x00, 0x09, 0x02, 0x02};
    pushList(&list, __Long__, pkrv, 4);

    pkrv.package_ty.pack_bytes = (data_c[]){0x00, 0x03, 0x05};
    pushList(&list, __Long__, pkrv, 3);

    pkrv.package_ty.pack_bytes = (data_c[]){0x01, 0x03, 0x05};
    pushList(&list, __Byte__, pkrv, 3);

    pkrv.package_ty.pack_bytes = (data_c[]){0x00, 0x03, 0x05, 0x00};
    pushList(&list, __Short__, pkrv, 4);

    Long limit = 1000000;
    for(Long i = 0; i < limit; i++){
        if(i % 7 == 0){
            pkrv.pack_ty = PACK_DOUBLE_BYTES;
            i_n = inttstr(i);
            pkrv.package_ty.pack_doubleBytes = i_n;
            pushList(&list, __String__, pkrv, strsize(i_n) + 1);
        }

        else{
            pkrv.pack_ty = PACK_BYTES;
            char size = 0;
            bytes = expandsToBytes(i, &size);
            pkrv.package_ty.pack_bytes = bytes;

            if(i <= 127 && i >= -128){
                pushList(&list, __Byte__, pkrv, (unsigned long long)size);
            }

            else if(i <= 32767 && i >= -32768){
                pushList(&list, __Short__, pkrv, (unsigned long long)size);
            }

            else if(i % 2 == 0){
                pushList(&list, __Int__, pkrv, (unsigned long long)size);
            }

            else{
                pkrv.pack_ty = PACK_INTEGER;
                pkrv.package_ty.pack_integer = i;
                pushList(&list, __Long__, pkrv, (unsigned long long)size);
            }
        }
    }

    free(bytes);
    free(i_n);

    pkrv.pack_ty = PACK_BYTES;

    pkrv.package_ty.pack_bytes = (unsigned char[]){0x00, 0x03, 0x05, 0x00, 0x00, 0x00};
    pushList(&list, __Long__, pkrv, 6);
    pkrv.package_ty.pack_bytes[0] = 0x01;
    pushList(&list, __Long__, pkrv, 6);

    pkrv.package_ty.pack_bytes = (unsigned char[]){0x00, 0x03, 0x05, 0x00, 0x00};
    pushList(&list, __Int__, pkrv, 5);
    pkrv.package_ty.pack_bytes[0] = 0x01;
    pushList(&list, __Int__, pkrv, 5);

    pkrv.package_ty.pack_bytes = (unsigned char[]){0x00, 0x03, 0x05, 0x00};
    pushList(&list, __Short__, pkrv, 4);
    pkrv.package_ty.pack_bytes[0] = 0x01;
    pushList(&list, __Short__, pkrv, 4);

    pkrv.package_ty.pack_bytes = (unsigned char[]){0x00, 0x03, 0x05};
    pushList(&list, __Byte__, pkrv, 3);
    pkrv.package_ty.pack_bytes[0] = 0x01;
    pushList(&list, __Byte__, pkrv, 3);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    lchar hello_world[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x00};
    pkrv.package_ty.pack_doubleBytes = hello_world;
    pushList(&list, __String__, pkrv, 14);

    lchar input[] = L"Todos esses momentos se perderão no tempo, como lágrimas na chuva...";
    pkrv.package_ty.pack_doubleBytes = input;
    pushList(&list, __String__, pkrv, 69);

    lchar blade_runner[] = L"Blade Runner: Melhor filme de toda a história do cinema!";
    pkrv.package_ty.pack_doubleBytes = blade_runner;
    pushList(&list, __String__, pkrv, 43);

    lchar *games[] = {
                        L"Dark Souls Remaster", L"Hollow Knight", L"Elden Ring",
                        L"Cyberpunk 2077", L"Dark Souls III", L"Batman: Arkham Knight",
                        L"Red Dead Redemption 2", L"Lies Of P", L"BloodBorne",
                        L"Sekiro", L"Dark Souls II"
                      };

    for(char y = 0; y < 11; y++){
        pkrv.package_ty.pack_doubleBytes = games[y];
        pushList(&list, __String__, pkrv, strsize(games[y]) + 1);
    }

    lchar maxnum_long_long[] = L"9223372036854775807";
    Long max_nLL = convert_StringToInteger(L"9223372036854775807");

    pkrv.pack_ty = PACK_BYTES;

    charsize_t len = 0;
    data_c *newData_c = expandsToBytes(max_nLL, &len);
    pkrv.package_ty.pack_bytes = newData_c;
    pushList(&list, __Long__, pkrv, (Long)len);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    free(newData_c);
    pkrv.package_ty.pack_doubleBytes = maxnum_long_long;
    pushList(&list, __String__, pkrv, strsize(maxnum_long_long) + 1);

    lchar ellen[] = L"Ellen, morzinho di mi vida";
    pkrv.package_ty.pack_doubleBytes = ellen;
    pushList(&list, __String__, pkrv, strsize(ellen) + 1);

    pkrv.pack_ty = PACK_BYTES;

    pkrv.package_ty.pack_bytes = (data_c[]){0x00, 0x09, 0x02, 0x02, 0x03, 0x03, 0x07, 0x02, 0x00, 0x03, 0x06};
    pushList(&list, __Long__, pkrv, 11);

    pkrv.pack_ty = PACK_INTEGER;

    pkrv.package_ty.pack_integer = 9223372036854775807;
    pushList(&list, __Long__, pkrv, strsize(L"9223372036854775807") + 1);

    pkrv.package_ty.pack_integer = 25042006;
    pushList(&list, __Int__, pkrv, strsize(L"25042006") + 1);

    pkrv.pack_ty = PACK_DOUBLE_BYTES;

    pkrv.package_ty.pack_doubleBytes = L"Ton-618";
    pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doubleBytes) + 1);

    pkrv.package_ty.pack_doubleBytes = L"End List";
    pushList(&list, __String__, pkrv, strsize(pkrv.package_ty.pack_doubleBytes) + 1);

    printList(&list);
    freeList(list);
}
*/

/*
reference_types TypeReturn;
    union{
        PrimitiveTypes primitiveTys;
        BigintObject IntDinamicType;
        BigfloatObject FloatDinamicType;
        All_Arrays all_arrays;
        ArrayList *ArrayList;
        HashMap *HashObject;
        List *ListObject;
    }Return;
*/

/*void* initializeDataArray(void *data, size_ty init, size_ty end, reference_types ref_dataTy){
    switch(ref_dataTy){
        case __ARRAYLONG__:{
            Long *array = (Long*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYINT__:{
            Int *array = (Int*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYSHORT__:{
            Short *array = (Short*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYBYTE__:{
            Byte *array = (Byte*)data;
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
        case __ARRAYFLOAT__:{
            float *array = (float*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0.0f;
            }
            break;
        }
        case __ARRAYDOUBLE__:{
            double *array = (double*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0.0;
            }
            break;
        }
        case __ARRAYBIGINT__:{
            data_c *array = (data_c*)data;
            for(size_ty i = init; i < end; i++){
                array[i] = 0;
            }
            break;
        }
        case __ARRAYBIGFLOAT__:{
            data_c *array = (data_c*)data;
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

    Long size = 1024, sizeStr = 0, sizeRes = size;
    finalString = STRALLOC(size);

    while(*copyScope && *copyIndex){
        String scp;
        String ind;
        if(!(strgetnextstr(&scp, &_scope) && strgetnextstr(&ind, &_index))){
            Int scpValue = convert_StringToInteger(scp);
            Int indValue = convert_StringToInteger(ind);
            
            if(scpValue == NULL || indValue == NULL){
                return 2;
            }

            reference_types typeIndexObject = matrObjects[scpValue][indValue].Type_Identifier_Object;

            if(typeIndexObject == __Long__ ||
               typeIndexObject == __Int__ ||
               typeIndexObject == __Short__ ||
               typeIndexObject == __Byte__)
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

                    case __Float__:
                        sizeStr = strsize(matrObjects[scpValue][indValue].types.float_Object_static->_String_Data);
                        actString = strfastcopy(matrObjects[scpValue][indValue].types.float_Object_static->_String_Data, sizeStr);
                        break;

                    case __BIGFLOAT__:
                        sizeStr = strsize(matrObjects[scpValue][indValue].types.float_Object_dinamic->_String_Data);
                        actString = strfastcopy(matrObjects[scpValue][indValue].types.float_Object_dinamic->_String_Data, sizeStr);
                        break;

                    case __Double__:
                        sizeStr = strsize(matrObjects[scpValue][indValue].types.double_Object->_String_Data);
                        actString = strfastcopy(matrObjects[scpValue][indValue].types.double_Object->_String_Data, sizeStr);
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

/*void getmemory(void *copy, data_c source[], size_ty size){
    Byte startByte = 0x18;
    *((Int*)copy) = 0;

    int i = 0;
    for(; i < size; i++){
        *((Int*)copy) |= (source[i] << startByte);
        startByte -= 0x08;
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
data_c* byteParser(void *any, reference_types ref_anyTy, size_ty qtty){
    data_c *bytes;
    u8 startdata = 0;
    size_ty i = 0;

    switch(ref_anyTy){
        case __Long__:
        case __Int__:
        case __Short__:
        case __Byte__ :
        case __Char__:
            switch(ref_anyTy){
                case __Long__:
                    bytes = uByteALLOC(long_size);
                    startdata = 0x38;
                    for(; i < long_size; i++){
                        bytes[i] = (data_c) (*((Long*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;
                
                case __Int__:
                    bytes = uByteALLOC(int_size);
                    startdata = 0x18;
                    for(; i < int_size; i++){
                        bytes[i] = (data_c) (*((Int*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;
                
                case __Short__:
                case __Char__:
                    bytes = uByteALLOC(char_size);
                    startdata = 0x10;
                    for(; i < short_size; i++){
                        bytes[i] = (data_c) (*((lchar*)any) >> startdata);
                        startdata -= 0x08;
                    }
                    break;

                case __Byte__:
                    bytes = uByteALLOC(byte_size);
                    bytes[0] = (*(Byte*)any);
                    break;
            }
            break;
    }

    return bytes;
}
*/

/*
STATUS COMMAND_START(data_c *line, __System__ *System){
    u8 addr_i = 0x01, flagset = 0, count = 0;
    u8 *storages = uByteALLOC(OBJECTsQTTY);

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
                Long size_storage = 0;
                data_c *bytes;
                charsize_t size_Obj = 0;

                if(line[addr_i++] == SEND){
                    switch(line[addr_i++]){
                        case LONG:{
                            size_Obj = long_size;
                            /*bytes = uByteALLOC(long_size);
                            memcopy(bytes, line, addr_i, long_size);
                            memcpyint(&size_storage, bytes, long_size);
                            addr_i += long_size - 1;
                            break;
                        }

                        case INT:{
                            size_Obj = long_size;
                            bytes = uByteALLOC(int_size);
                            memcopy(bytes, line, addr_i, int_size);
                            memcpyint(&size_storage, bytes, int_size);
                            addr_i += int_size - 1;
                            break;
                        }

                        case SHORT:
                        case CHAR:{
                            size_Obj = long_size;
                            bytes = uByteALLOC(char_size);
                            memcopy(bytes, line, addr_i, char_size);
                            memcpyint(&size_storage, bytes, char_size);
                            addr_i += char_size - 1;
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
                        bytes = uByteALLOC(size_Obj);
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