#include "../includedefines/defines.h"

#define ERROROPENFILE    1
#define ERRORUTF2BYTES   2
#define ERRORUTF3BYTES   3
#define ERRORUTF4BYTES   4
#define ERRORUTFINVALID  100

#define ERRORALLOCNULL  -100

String ErrorsTable[50] = {
    L"ERROR: The identifier format is invalid\n",
    L"ERROR: Identifier declaration is invalid\n",
    L"ERROR: Identifier name starting with 0 is invalid\n",
    L"",
    L"ERROR: Invalid syntax\n",
    L"ERROR: Unclosed String quotes\n",
    L"ERROR: Invalid charactere\n",
    L"ERROR: Invalid scape charactere\n",
    L"ERROR: Const char Is Invalid\n"
};