#include "../helper.h"

int main () {
    int _, height;
    char **trees = split(file_read("input.txt", &_), "\n", &height);

    int width = strlen(trees[0]);
    int visible_trees = width * 2 + height * 2 - 4;

    int highest_scenic_score = -1;

    for (int i = 1; i < width - 1; i++)
    for (int j = 1; j < height - 1; j++) {
        int t = trees[j][i] - '0';

        int visibility_from_edges = 4;  // part 1
        int viewing_dists[4] = {0};     // part 2

        for (int x = i-1; x >= 0; x--) {
            if (t <= trees[j][x] - '0') {
                visibility_from_edges--;
                viewing_dists[0] = i - x;
                break;
            } else {
                viewing_dists[0] = i - x;
            }
        }
        for (int x = i+1; x < width; x++){
            if (t <= trees[j][x] - '0') {
                visibility_from_edges--;
                viewing_dists[1] = x - i;
                break;
            } else {
                viewing_dists[1] = x - i;
            }
        }
        for (int y = j-1; y >= 0; y--) {
            if (t <= trees[y][i] - '0') {
                visibility_from_edges--;
                viewing_dists[2] = j - y;
                break;
            } else {
                viewing_dists[2] = j - y;
            }
        }
        for (int y = j+1; y < height; y++) {
            if (t <= trees[y][i] - '0') {
                visibility_from_edges--;
                viewing_dists[3] = y - j;
                break;
            } else {
                viewing_dists[3] = y - j;
            }
        }

        // part 1
        if (visibility_from_edges)
            visible_trees++;

        // part 2
        for (int a = 0; a < 4;a++){
            printf("%d,", viewing_dists[a]);
        }
        printf("\n");
        int scenic_score = viewing_dists[0] * viewing_dists[1] * viewing_dists[2] * viewing_dists[3];
        if (scenic_score > highest_scenic_score)
            highest_scenic_score = scenic_score;
    }

    printf("part 1: %d\npart 2: %d\n", visible_trees, highest_scenic_score);
}
