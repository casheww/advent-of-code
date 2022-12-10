#include "../helper.h"

#define KNOT_COUNT 9

typedef struct {
    int x;
    int y;
} intVector2;

void move_head(intVector2 *h, char *line);
intVector2 subtract_vectors(intVector2 a, intVector2 b);
intVector2 add_vectors(intVector2 a, intVector2 b);
int compare_vectors(intVector2 a, intVector2 b);


int main() {
    int _, lineCount;
    char **lines = split(file_read("test.txt", &_), "\n", &lineCount);

    int moveCount = 0;

    for (int i = 0; i < lineCount; i++)
        moveCount += atoi(split(lines[i], " ", &_)[1]);

    intVector2 h = {0,0};
    intVector2 *tail_positions = (intVector2*) malloc(moveCount * sizeof(intVector2));
    int ti = 0;
    tail_positions[ti] = (intVector2) {0,0};
    intVector2 s = {0,0};

    int unique_positions = 1;

    for (int i = 0; i < lineCount; i++) {
        move_head(&h, lines[i]);
        s = subtract_vectors(h, tail_positions[ti]);

        for (int knot = 1; knot <= KNOT_COUNT; knot++) {

        }

        while ((ABS(s.x) > 1) || (ABS(s.y) > 1)) {
            intVector2 t = tail_positions[ti];
            printf("s:%d,%d\n", s.x, s.y);

            if (s.y == 0 && s.x != 0)
                t.x += SIGN(s.x);
            else if (s.x == 0 && s.y != 0)
                t.y += SIGN(s.y);
            else if (s.x != 0 && s.y != 0)
                t = add_vectors(t, (intVector2) {SIGN(s.x), SIGN(s.y)});

            int unique = 1;
            for (int j = 0; j < ti+1; j++) {
                //printf("%d,%d    %d,%d\n", tail_positions[j].x, tail_positions[j].y, t.x, t.y);
                if (compare_vectors(tail_positions[j], t)) {
                    unique = 0;
                    break;
                }
            }
            if (unique)
                {unique_positions++;printf("unique:%d,%d \t %d\n", t.x, t.y, unique_positions);}

            s = subtract_vectors(h, t);

            ti++;
            tail_positions[ti] = t;
        }
    }

    printf("%d\n", unique_positions);
}


void move_head(intVector2 *h, char *line) {
    int _;
    char **movement = split(line, " ", &_);
    printf("%s\n", line);
    char *dir = movement[0];
    int dist = atoi(movement[1]);

    switch (dir[0])
    {
    case 'U':
        h->y += dist;
        break;
    case 'D':
        h->y -= dist;
        break;
    case 'L':
        h->x -= dist;
        break;
    case 'R':
        h->x += dist;
        break;
    }
}

intVector2 subtract_vectors(intVector2 a, intVector2 b) {
    return (intVector2) {a.x - b.x, a.y - b.y};
}

intVector2 add_vectors(intVector2 a, intVector2 b) {
    return (intVector2) {a.x + b.x, a.y + b.y};
}

int compare_vectors(intVector2 a, intVector2 b) {
    return a.x == b.x && a.y == b.y;
}
