#include "../helper.h"

int main () {
    int _, height;
    char **trees = split(file_read("input.txt", &_), "\n", &height);

    int width = strlen(trees[0]);
    int visible_trees = width * 2 + height * 2 - 4;

    for (int i = 1; i < width - 1; i++)
    for (int j = 1; j < height - 1; j++) {
        int t = trees[j][i] - '0';

        int visibility_from_edges = 4;

        for (int x = i-1; x >= 0; x--)
            if (t <= trees[j][x] - '0') {
                visibility_from_edges--;
                break;
            }
        for (int x = i+1; x < width; x++)
            if (t <= trees[j][x] - '0') {
                visibility_from_edges--;
                break;
            }
        for (int y = j-1; y >= 0; y--)
            if (t <= trees[y][i] - '0') {
                visibility_from_edges--;
                break;
            }
        for (int y = j+1; y < height; y++)
            if (t <= trees[y][i] - '0') {
                visibility_from_edges--;
                break;
            }

        if (visibility_from_edges)
            visible_trees++;
    }

    printf("part 1: %d\n", visible_trees);
}
