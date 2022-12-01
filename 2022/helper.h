#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b


/* returns: number of characters in file */
int getFileCharCount(FILE *f);

/* returns: the entire contents of a file */
char* fileRead(char fp[], int *charCount);

/* splits orig_str at any char from sep, 
 * returns: a pointer to an array of pointers to the resulting char arrays */
char** split(char *orig_str, char *sep, int *itemCount);

int sum(int *arr, int len);
