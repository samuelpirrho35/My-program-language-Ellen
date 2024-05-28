#include "compiler/functionsCompiler.h"
#include <stdio.h>

int main(){
    Tokens **tokens = allocTokens();
    u64 lines = 0;
    String src = L"name = \"Ellen\";age = 18;";

    if(TokenParser(tokens, &lines, src)){
        freeTokens(tokens, lines, 0);
        printf("ERROR: Fatal error during program compilation");
        return 0;
    }


    for(u64 i = 0; i < lines; i++){
        u32 j = 0;
        while(tokens[i][j].type != ENDLINE && tokens[i][j].type != __ERROR__){
            printf("[i][j]: [%d][%d]\n", i, j);
            if(tokens[i][j].type == _KEYWORD)
                printf("KEYWORD: %d\n", tokens[i][j].tokens.TokenKeyWord);

            else if(tokens[i][j].type == _INTERNAL_FN)
                printf("INTERNAL FN: %d\n", tokens[i][j].tokens.TokenFn);

            else if(tokens[i][j].type == IDENTIFIERNAME){
                wprintf(L"IDENTIFIER NAME: %ls\n", tokens[i][j].tokens.IdentifierName);
            }

            else if(tokens[i][j].type == _IDENTIFIER_CONST_BIN || tokens[i][j].type == _IDENTIFIER_CONST_HEX ||
                tokens[i][j].type == _IDENTIFIER_CONST_DEC){
                    wprintf(L"CONST INTEGER: %ls\n", tokens[i][j].tokens.Constint);
            }

            else if(tokens[i][j].type == _IDENTIFIER_CONST_FLOAT){
                wprintf(L"CONST FLOAT: %ls\n", tokens[i][j].tokens.ConstValue);
            }

            else if(tokens[i][j].type == _IDENTIFIER_CONST_STRING){
                wprintf(L"CONST STRING: %ls\n", tokens[i][j].tokens.ConstValue);
            }

            else if(tokens[i][j].type == _IDENTIFIER_CONST_CHAR)
                wprintf(L"CONST CHAR: %lc\n", tokens[i][j].tokens.ConstChar);

            else
                printf("TOKEN: %d\n", tokens[i][j].type);

            j++;
        }
    }

    freeTokens(tokens, lines, 0);

}

/*

                                        IDNAME
                                      ATTRIBUITION
                      IDNAME  CONSTINT  CONSTFLOT  CONSTSTR  {                                          [
                                                                IDNAME  CONSTINT  CONSTFLOT  CONSTSTR       IDNAME  CONSTINT  CONSTFLOT  CONSTSTR
                                                                                ,                                            ,
                                                                               ...                                          ...
                                                              }                                          ]
                                        ENDLINE

*/

// gcc compiler.c Token.c utils.c libString.c memory.c -o tkg.exe