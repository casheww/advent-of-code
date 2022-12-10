#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define ABS(a)   (a >= 0 ? a : -(a))
#define SIGN(a)  (a == 0 ? 0 : (a > 0 ? 1 : -1))


/* returns: number of characters in file */
int get_file_char_count(FILE *f);

/* returns: the entire contents of a file */
char* file_read(char fp[], int *char_count);

/* splits orig_str at any char from sep, 
 * returns: a pointer to an array of pointers to the resulting char arrays */
char** split(char *orig_str, char *sep, int *item_count);

char* substr(char *orig_str, int start, int end);

int sum(int *arr, int len);
