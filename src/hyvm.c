#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;


