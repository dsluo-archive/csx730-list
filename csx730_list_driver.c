#include "csx730_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>

struct data_item {
    int value;
    struct list_node list;
};

int main() {
    struct data_item item1 = { 1, { NULL, NULL } };
    struct data_item item2 = { 2, { NULL, NULL } };
    struct data_item item3 = { 3, { NULL, NULL } };
    struct data_item item4 = { 4, { NULL, NULL } };

    list_init(&item1.list);
    list_init(&item2.list);
    list_init(&item3.list);
    list_init(&item4.list);

    struct list_node * head = &item2.list;
    list_append_all(head, &item4.list, NULL);
    
    struct list_node * new_head_maybe = list_insert(head, &item3.list, 1);

    if (new_head_maybe != head)
        printf("new head != head");
    
    head = new_head_maybe;

    list_append(head, &item4.list);

    struct data_item * pointer = list_object(&item4.list, struct data_item, list);

    if (pointer != &item4)
        printf("list_object(item4.list) != item4");
 
    return 0;
} // main
