#ifndef RUNTIMEVM_H
#define RUNTIMEVM_H

#include "../includedefines/inttypes.h"
#include "../System/System.h"

int program(data_c global[][50], data_c local[][50], __System__ *System);
STATUS COMMAND_START(data_c *line, __System__ *System);

#endif //RUNTIMEVM_H