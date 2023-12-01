#include "../helper.h"
#include "../linked_list.h"

typedef struct {
    int x;
    int y;
    int f_cost;
    node *parent;
} node;

int find_char(char **lines, int line_count, char c, int *x, int *y);
int find_best_unvisited(linked_list unvisited, int len, int end_x, int end_y);
float g(int x, int y, int end_x, int end_y);

int main() {
    int _, line_count;
    char **lines = split(file_read("test.txt", &_), "\n", &line_count);

    int total_nodes = line_count * strlen(lines[0]);

    linked_list visited = init_list();
    linked_list unvisited = init_list();

    int current_node_index = 0;

    int x, y;
    find_char(lines, line_count, 'S', &x, &y);
    list_append(&visited, &(node){x,y,0,NULL}, sizeof(node));

    int end_x, end_y;
    find_char(lines, line_count, 'E', &end_x, &end_y);

    while (x != end_x || y != end_y) {
        int best_unvisited = find_best_unvisited(unvisited, end_x, end_y);
        current_node_index++;
        visited[current_node_index] = unvisited[best_unvisited];
        unvisited[best_unvisited] = 0;
    }

}


int find_char(char **lines, int line_count, char c, int *x, int *y) {
    for (*x = 0; *x < line_count; (*x)++)
    for (*y = 0; *y < strlen(lines[0]); (*y)++)
        if (lines[*x][*y] == c)
            return 1;

    return 0;
}

int find_best_unvisited(linked_list unvisited, int len, int end_x, int end_y) {
    float min_cost = INFINITY;
    int best = -1;
    for (int i = 0; i < len; i++) {
        node u = unvisited[i];
        float cost = g(u.x, u.y, end_x, end_y);
        if (cost < min_cost) {
            min_cost = cost;
            best = i;
        }
    }
    return best;
}

float g(int x, int y, int end_x, int end_y) {
    int dx = end_x - x;
    int dy = end_y - y;
    return sqrt(dx*dx + dy*dy);
}
