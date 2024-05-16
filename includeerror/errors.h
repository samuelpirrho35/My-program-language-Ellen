#include "../includedefines/defines.h"

#define ERROROPENFILE    1
#define ERRORUTF2BYTES   2
#define ERRORUTF3BYTES   3
#define ERRORUTF4BYTES   4
#define ERRORUTFINVALID  100

#define ERRORALLOCNULL  -100

String ErrorsTable[60] = {
    L"ERROR: The identifier format is invalid\n",
    L"ERROR: Identifier declaration is invalid\n",
    L"ERROR: Identifier name starting with 0\n",
    L"ERROR: Unexpected expression\n",
    L"ERROR: Quick statement not started\n",
    L"ERROR: Invalid syntax\n",
    L"ERROR: Unclosed String quotes\n",
    L"ERROR: Invalid charactere\n",
    L"ERROR: Invalid scape charactere\n",
    L"ERROR: Const char is invalid\n",
    L"ERROR: comment not finished\n",
};

u8 ErrosTableSizes[] = {
    41, 42, 40, 30,
    36, 23, 31, 27,
    33, 30, 29
};