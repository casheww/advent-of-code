#include "../helper.h"

int main() {
    int _, pairCount;
    char **pairs = split(fileRead("input.txt", &_), "\n", &pairCount);

    int fully_containing_pairs = 0;

    for (int i = 0; i < pairCount; i++) {
        char **tasks = split(pairs[i], ",", &_);
        char **tasks0 = split(tasks[0], "-", &_);
        char **tasks1 = split(tasks[1], "-", &_);

        int min0 = atoi(tasks0[0]);
        int max0 = atoi(tasks0[1]);
        int min1 = atoi(tasks1[0]);
        int max1 = atoi(tasks1[1]);

        if (max0 - min0 > max1 - min1) {
            if (min0 <= min1 && max1 <= max0)
                fully_containing_pairs++;
        } else {
            if (min1 <= min0 && max0 <= max1)
                fully_containing_pairs++;
        }
    }

    printf("%d\n", fully_containing_pairs);
}
