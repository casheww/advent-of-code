#include "linked_list.h"
#include <stdio.h>

void print_list(linked_list l);

int main() {
    linked_list l = init_list();

    int numbers[] = {1,6,43,-1,125,7,83};
    print_list(l);

    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++) {
        list_append(&l, &numbers[i], sizeof(int));
    }

    print_list(l);

    int to_remove[] = {43,-1,7};
    for (int i = 0; i < sizeof(to_remove)/sizeof(int); i++) {
        list_remove(&l, to_remove+i, sizeof(int));
        print_list(l);
    }    
}

void print_list(linked_list l) {
    list_item *li = l.first;

    while (li != NULL) {
        printf("%d, ", *(int*)li->data);
        li = li->next;
    }

    printf("\n");
}
