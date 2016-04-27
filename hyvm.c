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

int main() {
    while (running) {
      int x = fetch();
      if (x == HLT) running = false;
      ip++;
    }
}

