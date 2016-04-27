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
    }
}

int main() {
    while (running) {
      int x = fetch();
      if (x == HLT) running = false;
      ip++;
    }
}

