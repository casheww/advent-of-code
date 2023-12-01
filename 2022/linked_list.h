#include <stdlib.h>

typedef struct list_item list_item;

struct list_item {
    void *data;
    list_item *next;
};

typedef struct {
    list_item *first;
    list_item *last;
    size_t count;
} linked_list;


linked_list init_list();
void list_append(linked_list *l, void *data, size_t data_size);
void list_remove_at(linked_list *l, unsigned int at);
int list_remove(linked_list *l, void *data, size_t data_size);
