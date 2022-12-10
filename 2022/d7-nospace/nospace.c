#include "../helper.h"
#include <limits.h>

/* you can avoid hashmaps and such for this puzzle - 
 * the order in which cd commands are executed is the same 
 * as the order in which subdirs appear in the ls commands
*/

#define P1_THRESHOLD        100000
#define TOTAL_SPACE       70000000
#define REQUIRED_SPACE    30000000

int calculate_dir_size(char **lines, int lineCount, int *i);
int below_threshold_sum;

int space_to_free = INT_MAX;        // only used for second pass
int smallest_suitable_dir_size = INT_MAX;

int main () {
    int _, lineCount;
    char **lines = split(file_read("input.txt", &_), "\n", &lineCount);

    int i = 0;
    int used_space = calculate_dir_size(lines, lineCount, &i);
    printf("part 1: %d\n", below_threshold_sum);

    i = 0;
    space_to_free = REQUIRED_SPACE - (TOTAL_SPACE - used_space);
    calculate_dir_size(lines, lineCount, &i);

    printf("part 2: %d\n", smallest_suitable_dir_size);
}


int calculate_dir_size(char **lines, int lineCount, int *i) {
    int size = 0;
    char *name = substr(lines[*i], 5, strlen(lines[*i]));

    (*i) += 2;      // skip cd {this dir} and ls commands

    for (; (*i) < lineCount; (*i)++) {
        if (!strcmp(substr(lines[*i], 0, 4), "$ cd")) {                     // check if command is cd
            if (!strcmp(substr(lines[*i], 5, strlen(lines[*i])), ".."))     // check if cd arg is ..
                break;
            else
                size += calculate_dir_size(lines, lineCount, i);
        }
        else {
            if (lines[*i][0] != 'd') {      // ignore mention of subdirs
                int _;
                size += atoi(split(lines[*i], " ", &_)[0]);
            }
        }
    }
    
    if (size <= P1_THRESHOLD) {
        below_threshold_sum += size;
        //printf("%s : %d\n", name, size);
    }

    if (size >= space_to_free && size < smallest_suitable_dir_size)
        smallest_suitable_dir_size = size;

    return size;
}
