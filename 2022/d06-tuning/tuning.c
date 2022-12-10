#include "../helper.h"

#define START_OF_PACKAGE_LEN  4
#define START_OF_MESSAGE_LEN 14

int find_unique_char_str(char *str, int len, int targetLen);
int has_duplicate_chars(char *str, int len);

int main() {
    int charCount;
    char *input = file_read("input.txt", &charCount);

    int sop_start = find_unique_char_str(input, charCount, 4);
    int som_start = find_unique_char_str(input, charCount, 14);

    printf("part 1: %d\npart 2: %d\n", sop_start, som_start);
}


int find_unique_char_str(char *str, int len, int targetLen) {
    char trial[targetLen];

    for (int i = 0; i < len - targetLen; i++) {
        for (int j = 0; j < targetLen; j++)
            trial[j] = str[i+j];

        if (!has_duplicate_chars(trial, targetLen))
            return i + targetLen;
    }

    return -1;      // no result
}

int has_duplicate_chars(char *str, int len) {
    for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++)
        if (i != j && str[i] == str[j])
            return 1;

    return 0;
}
