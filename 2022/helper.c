#include "helper.h"

int get_file_char_count(FILE *f) {
    fpos_t pos;
    fgetpos(f, &pos);       // cache orig stream position
    rewind(f);
    int count = 0;

    while (fgetc(f) != EOF) {
        count++;
    }

    fsetpos(f, &pos);       // reset orig stream position
    return count;
}

char* file_read(char fp[], int *char_count) {
    FILE *f = fopen(fp, "r");
    if (f == NULL) {
        printf("ERROR CREATING FILE STREAM. Did you create the file?\n");
        return NULL;
    }

    *char_count = get_file_char_count(f);
    char *str = (char*) malloc((*char_count + 1) * sizeof(char));
    str[*char_count] = '\0';

    for (int i = 0; i < *char_count; i++) {
        str[i] = (char) fgetc(f);
    }

    fclose(f);
    return str;
}

char** split(char *orig_str, char *sep, int *item_count) {
    char *str = (char*) malloc((strlen(orig_str) + 1) * sizeof(char));
    strcpy(str, orig_str);
    
    *item_count = 1;

    // calc number of elements there will be after splitting
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(sep); j++)
            if (str[i] == sep[j])
                (*item_count)++;
    }

    char **strs = (char**) malloc((*item_count) * sizeof(char*));
    char *token;

    for (int i = 0; i < *item_count; i++) {
        char *t = strsep(&str, sep);
        int token_length = t == NULL ? 1 : strlen(t) + 1;
        token = (char*) malloc(token_length * sizeof(char));

        strcpy(token, t);
        strs[i] = token;
    }

    free(str);
    return strs;
}

char* substr(char *orig_str, int start, int end) {
    int len = ABS(end - start);
    char *str = (char*) malloc((len + 1) * sizeof(char));
    str[len] = '\0';

    for (int i = 0; i < len; i++)
        str[i] = orig_str[start + i];

    return str;
}

int sum(int *arr, int len) {
    int s = 0;
    for (int i = 0; i < len; i++)
        s += arr[i];
    return s;
}
