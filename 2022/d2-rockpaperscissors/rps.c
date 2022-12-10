#include "../helper.h"

typedef enum { ROCK, PAPER, SCISSORS } shape;
typedef enum { LOSS = 0, DRAW = 3, WIN = 6 } result;

shape char_to_shape(char c);
result char_to_result(char c);

int main() {
    int _;
    char *input = file_read("input.txt", &_);

    int lineCount = 3;
    char **lines = split(input, "\n", &lineCount);

    int score1 = 0;
    int score2 = 0;

    for (int i = 0; i < lineCount; i++) {
        if (!strlen(lines[i])) continue;

        shape opp = char_to_shape(lines[i][0]);
        shape me = char_to_shape(lines[i][2]);

        score1 += me + 1;

        if (opp == me) 
            score1 += DRAW;
        else if ((me - opp) == 1 || me == ROCK && opp == SCISSORS)
            score1 += WIN;

        result desired_result = char_to_result(lines[i][2]);

        if (desired_result == WIN)
            me = (opp + 1) % 3;
        else if (desired_result == LOSS)
            me = (opp + 2) % 3;
        else
            me = opp;

        me++;

        score2 += me + desired_result;
    }

    printf("part 1: %d\npart 2: %d\n", score1, score2);
}


shape char_to_shape(char c) {
    switch (c)
    {
    case 'A':
    case 'X':
        return ROCK;
    case 'B':
    case 'Y':
        return PAPER;
    case 'C':  
    case 'Z':
        return SCISSORS;
    default:
        printf("invalid char\n");
        return -1;
    }
}

result char_to_result(char c) {
    switch (c) {
        case 'X':
            return LOSS;
        case 'Y':
            return DRAW;
        case 'Z':
            return WIN;
        default:
            printf("aaaaaaa\n");
            return -1;
    }
}
