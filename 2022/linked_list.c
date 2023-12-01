#include "linked_list.h"
#include <stdio.h>

linked_list init_list() {
    linked_list l = {NULL, NULL, 0};
    return l;
}

void list_append(linked_list *l, void *data, size_t data_size) {
    list_item *li = malloc(sizeof(list_item));
    li->data = malloc(data_size);
    li->next = NULL;

    for (int i = 0; i < data_size; i++)
        *(char*)(li->data + i) = *(char*)(data + i);

    if (l->count == 0) {
        l->first = li;
        l->last = li;
    } else {
        l->last->next = li;
        l->last = li;
    }

    l->count++;
}

void list_remove_at(linked_list *l, unsigned int at) {
    list_item *li = l->first;
    list_item *to_remove = NULL;

    if (at == 0) {
        l->first = li->next;
    } else {
        for (int i = 1; i < at; i++) {
            li = li->next;
        }

        to_remove = li->next;
        li->next = to_remove->next;
    }

    free(to_remove);
    return;

    if (li->next == NULL)
        l->last = li;
}

int compare_data(void *op0, void *op1, size_t size) {
    for (int i = 0; i < size; i++)
        if (*(char*)(op0 + i) != *(char*)(op1 + i))
            return 0;

    return 1;
}

int list_remove(linked_list *l, void *data, size_t data_size) {
    if (l->count == 0)
        return 0;

    list_item *li = l->first;

    int i = 0;

    while (!compare_data(li->data, data, data_size) && li != NULL) {
        li = li->next;
        i++;
    }

    if (li == NULL)
        return 0;

    list_remove_at(l, i);
    return 1;
}
