#include "csx730_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>

struct data_item {
    int value;
    struct list_node list1;
    struct list_node list2;
};

int main() {
    struct data_item item1 = { 1, { NULL, NULL }, { NULL, NULL } };
    struct data_item item2 = { 2, { NULL, NULL }, { NULL, NULL } };
    struct data_item item3 = { 3, { NULL, NULL }, { NULL, NULL } };
    struct data_item item4 = { 4, { NULL, NULL }, { NULL, NULL } };
    struct data_item item5 = { 5, { NULL, NULL }, { NULL, NULL } };

    list_init(&item1.list1);
    list_init(&item2.list1);
    list_init(&item3.list1);
    list_init(&item4.list1);
    list_init(&item5.list1);

    struct list_node * head = &item2.list1;
    list_append_all(head, &item4.list1, NULL);

    struct list_node * new_head_maybe = list_insert(head, &item3.list1, 1);

    if (new_head_maybe != head)
        printf("new head != head");

    head = new_head_maybe;

    list_append(head, &item5.list1);

    struct data_item * pointer = list_object(&item4.list1, struct data_item, list1);

    if (pointer != &item4)
        printf("list_object(item4.list1) != item4");

    struct list_node * headptr = head;
    list_foreach(headptr, node) {
        struct data_item * objptr = list_object(node, struct data_item, list1);
        printf("objptr->value = %d\n", objptr->value);
    }

    return 0;
} // main
