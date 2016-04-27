#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ip = 0;

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

typedef enum {
    A, B, C, D, E, F,
    NUM_OF_REGISTERS
} Registers;

static int registers[NUM_OF_REGISTERS];

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

void eval(int instr) {
    switch (instr) {
        case HLT: {
            running = false;
            break
        }
        case PSH: {
            sp++;
            stack[sp] = program[++ip];
            break;
        }
        case POP: {
            int val_popped = stack[sp--];
            printf("popped %d\n", val_popped)
            break;
        }
        case ADD: {
            int a = stack[sp--];

            int b = stack[sp--];

            int result = b + a;
            sp++;
            stack[sp] = result;
            break;
        }
    }
}

int main() {
    while (running) {
      int x = fetch();
      if (x == HLT) running = false;
      ip++;
    }
}

