#include "../helper.h"
#include <ctype.h>

#define GROUP_SIZE 3
#define COMP1 0b01
#define COMP2 0b10

int main() {
    int _, lineCount;
    char **lines = split(file_read("input.txt", &_), "\n", &lineCount);

    int score1 = 0;
    int score2 = 0;
    int common_in_group[52] = {0};
    
    for (int i = 0; i < lineCount; i++) {
        int compartment_size = strlen(lines[i]) / 2;

        // part 1:
        int seen_in_bag[52] = {0};

        for (int j = 0; j < compartment_size; j++) {
            char c = lines[i][j];
            int n = islower(c) ? c-'a' : c-'A'+26;

            seen_in_bag[n] = COMP1;
            printf("%d,", n);
        }

        for (int j = compartment_size; j < (compartment_size*2); j++) {
            char c = lines[i][j];
            int n = islower(c) ? c-'a' : c-'A'+26;

            // part 2:
            seen_in_bag[n] |= COMP2;
            printf("%d", n);

            // part 1:
            if (seen_in_bag[n] == 0b11) {
                printf("!");
                score1 += n + 1;
                seen_in_bag[n] = COMP2;
            }
            printf(",");
        }
        printf("\n");


        // part 2:
        for (int j = 0; j < 52; j++) {
            common_in_group[j] = seen_in_bag[j] && (!(i%GROUP_SIZE) || common_in_group[j]);
            printf("%d->%d, ", seen_in_bag[j], common_in_group[j]);
        }
        printf("\n");

        if (i % GROUP_SIZE == GROUP_SIZE - 1) {
            printf("!!\n");
            for (int j = 0; j < 52; j++) {
                if (common_in_group[j]) {
                    score2 += j+1;
                    break;
                }
            }

            printf("\n\n");

            for (int j = 0; j < 52; j++)
                common_in_group[j] = 0;
        }   
    }

    printf("part 1: %d\npart 2: %d\n", score1, score2);
}
