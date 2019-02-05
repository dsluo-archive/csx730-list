#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "csx730_list.h"

void list_init(struct list_node * head) {
    head->prev = NULL;
    head->next = NULL;
}

void list_append(struct list_node * head, struct list_node * node) {
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = node;
    node->prev = head;
}

void list_append_all(struct list_node * head, ...) {
    va_list args;
    va_start(args, head);
   
    for (struct list_node * node = va_arg(args, struct list_node *);
                node != NULL;
                node = va_arg(args, struct list_node *)) {
        list_append(head, node);
    }
    va_end(args);
}

struct list_node * list_insert(struct list_node * head, struct list_node * node, size_t index) {
    struct list_node * insert_before;    
    struct list_node * insert_after;

    insert_before = list_get(head, index);
    if (insert_before != NULL)
        insert_after = insert_before->prev;
    else {
        insert_after = list_get(head, index - 1);
        insert_before = insert_after->next; 
    }

    if (insert_after != NULL) {
        insert_after->next = node;
        node->prev = insert_after;
    }
    if (insert_before != NULL) {
        insert_before->prev = node;
        node->next = insert_before;
    }

    return index == 0 ? node : head;    
}

struct list_node * list_get(struct list_node * head, size_t index) {
    for (size_t i = 0; i < index; i++) {
        if (head != NULL && head->next != NULL)
            head = head->next;
        else
            head = NULL;
    }
    return head;
}

struct list_node * list_remove(struct list_node * head, size_t index) {
    struct list_node * new_head = index == 0 ? head->next : head;
    struct list_node * remove_this = list_get(head, index);
    
    if (remove_this != NULL) {
        if (remove_this->prev != NULL) {
            remove_this->prev->next = remove_this->next;
        }
        if (remove_this->next != NULL) {
            remove_this->next->prev = remove_this->prev;
        }

        remove_this->next = NULL;
        remove_this->prev = NULL;

    }

    return new_head;
}

size_t list_size(struct list_node * head) {
    size_t size = 0;
    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

size_t index_of(struct list_node * head, struct list_node * node) {
    size_t index = 0;
    while (head != NULL && node != head) {
        index++;
        head = head->next;
    }
    if (head == NULL) {
        index = -1;
    }
    return index;
}

void list_pretty_print(struct list_node * head, char * (* to_string)(struct list_node *)) {
    list_foreach(head, node) {
        if (node->prev == NULL) {
            printf("{ ");
        }

        char * string = to_string(node);
        printf(string);
        free(string);

        if (node->next == NULL) {
            printf(" }\n");
        } else {
            printf(", ");
        }
    }
}
