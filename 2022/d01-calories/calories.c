#include "../helper.h"

#define TOP_ELF_COUNT 3

void try_insert_elf(int test_elf, int *top_elves);

int main() {
    int _;
    char *input = file_read("input.txt", &_);
    
    int elf_count = 0;
    int top_elves[TOP_ELF_COUNT] = {0};
    int cals = 0;
    char **lines = split(input, "\n", &elf_count);

    for (int i = 0; i < elf_count; i++) {
        if (strlen(lines[i]) == 0){
            try_insert_elf(cals, top_elves);
            cals = 0;
        } else {
            cals += atoi(lines[i]);
        }
    }

    printf("%d\n", sum(top_elves, TOP_ELF_COUNT));
}

void try_insert_elf(int test_elf, int *top_elves) {
    for (int i = 0; i < TOP_ELF_COUNT; i++)
        if (test_elf > top_elves[i]) {
            for (int j = TOP_ELF_COUNT - 1; j > i; j--)
                top_elves[j] = top_elves[j-1];

            top_elves[i] = test_elf;
            break;
        }
}
