#include "../helper.h"

#define CRT_WIDTH  40
#define CRT_HEIGHT  6

int main() {
    int _, line_count;
    char **lines = split(file_read("input.txt", &_), "\n", &line_count);

    int i=0, cycle=1, wait=0;
    int X=1, buffer=0;

    int part1_strength_sum = 0;
    int test_cycles[6] = {20, 60, 100, 140, 180, 220};

    for (; i < line_count || wait; cycle++) {
        for (int j = 0; j < 6; j++) {
            if (cycle == test_cycles[j]) {
                part1_strength_sum += test_cycles[j] * X;
            }
        }

        int crt_x = (cycle-1) % CRT_WIDTH;
        if (!crt_x)
            printf("\n");
        printf(ABS(crt_x - X) <= 1 ? "#" : ".");

        if (wait) {
            wait = 0;
            X += buffer;
        } else {
            if (strcmp(lines[i], "noop")) {
                char **instr = split(lines[i], " ", &_);
                wait = 1;
                buffer = atoi(instr[1]);
            }

            i++;
        }
    }

    printf("\n%d\n", part1_strength_sum);

}
