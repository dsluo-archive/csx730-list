#include "csx730_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/*
 * Helper macro to print the items in both lists.
 */
#define print_lists() \
    printf("odds: "); \
    list_pretty_print(odds_head, &to_string_odds); \
    printf("primes: "); \
    list_pretty_print(primes_head, &to_string_primes); \
    printf("\n"); \

struct data_item {
    int value;
    struct list_node odds;
    struct list_node primes;
};

/*
 * Helper function to get the string length of an integer.
 *
 * @param num The number to get the length of.
 */
size_t get_int_length(size_t num) {
    size_t length = 0;
    if (num == 0)
        length = 1;
    else {
        size_t temp = 1;
        while (temp <= num) {
            length++;
            temp *= 10;
        }
    }
    return length;
}

/*
 * Implementation of to_string for the odds list.
 *
 * @param node The node to convert to a string.
 */
char * to_string_odds(struct list_node * node) {
    struct data_item * item = list_object(node, struct data_item, odds);

    size_t length = get_int_length(item->value);
    
    char * buffer = (char *) calloc(6 + length + 1, sizeof(char));
    sprintf(buffer, "data(%d)", item->value);
    buffer[6+length] = '\0';

    return buffer;
}

/*
 * Implementation of to_string for the primes list.
 *
 * @param node The node to convert to a string.
 */
char * to_string_primes(struct list_node * node) {
    struct data_item * item = list_object(node, struct data_item, primes);

    size_t length = get_int_length(item->value);
    
    char * buffer = (char *) calloc(6 + length + 1, sizeof(char));
    sprintf(buffer, "data(%d)", item->value);
    buffer[6+length] = '\0';

    return buffer;
}

int main() {
    struct data_item item0 = { 0, { NULL, NULL }, { NULL, NULL } };
    struct data_item item1 = { 1, { NULL, NULL }, { NULL, NULL } };
    struct data_item item2 = { 2, { NULL, NULL }, { NULL, NULL } };
    struct data_item item3 = { 3, { NULL, NULL }, { NULL, NULL } };
    struct data_item item4 = { 4, { NULL, NULL }, { NULL, NULL } };
    struct data_item item5 = { 5, { NULL, NULL }, { NULL, NULL } };
    struct data_item item6 = { 6, { NULL, NULL }, { NULL, NULL } };
    struct data_item item7 = { 7, { NULL, NULL }, { NULL, NULL } };
    struct data_item item8 = { 8, { NULL, NULL }, { NULL, NULL } };
    struct data_item item9 = { 9, { NULL, NULL }, { NULL, NULL } };

    // list_init
    list_init(&item0.odds);
    list_init(&item1.odds);
    list_init(&item2.odds);
    list_init(&item3.odds);
    list_init(&item4.odds);
    list_init(&item5.odds);
    list_init(&item6.odds);
    list_init(&item7.odds);
    list_init(&item8.odds);
    list_init(&item9.odds);
                   
    list_init(&item0.primes);
    list_init(&item1.primes);
    list_init(&item2.primes);
    list_init(&item3.primes);
    list_init(&item4.primes);
    list_init(&item5.primes);
    list_init(&item6.primes);
    list_init(&item7.primes);
    list_init(&item8.primes);
    list_init(&item9.primes);
    
    // List init
    struct list_node * odds_head = &item1.odds;
    struct list_node * primes_head = &item2.primes;
    
    printf("List init\n");
    print_lists();
    
    // list_append
    list_append(odds_head, &item3.odds);
    list_append(primes_head, &item3.primes);
    
    printf("Append one\n");
    print_lists();

    // list_append_all
    list_append_all(odds_head, &item5.odds, &item9.odds, NULL);
    list_append_all(primes_head, &item7.primes, NULL);
    
    printf("Append more\n");
    print_lists();
    
    // list_insert
    odds_head = list_insert(odds_head, &item7.odds, 3);
    primes_head = list_insert(primes_head, &item5.primes, 2);

    printf("Insert item7 into odds index 3.\n");
    printf("Insert item5 into primes index 2.\n");
    print_lists();

    odds_head = list_insert(odds_head, &item0.odds, 0);
    primes_head = list_insert(primes_head, &item0.primes, 0);

    printf("Insert item0 into index 0.\n");
    print_lists();

    // list_get
    struct list_node * odd_node = list_get(odds_head, 2);
    printf("Item at odds[2]: ");
    char * odd_string = to_string_odds(odd_node);
    printf(odd_string);
    free(odd_string);

    printf("\n");

    struct list_node * prime_node = list_get(primes_head, 2);
    printf("Item at primes[2]: ");
    char * prime_string = to_string_primes(prime_node);
    printf(prime_string);
    free(prime_string);

    printf("\n");

    printf("\n");

    // list_remove
    odds_head = list_remove(odds_head, 0);
    primes_head = list_remove(primes_head, 0);
    
    printf("Remove item0\n");
    print_lists();

    // list_size
    printf("Size of odds: %lu\n", list_size(odds_head));
    printf("Size of primes: %lu\n", list_size(primes_head));

    printf("\n");

    // index_of
    printf("Index of item3:\n");
    printf("Odds: %lu\n", index_of(odds_head, &item3.odds));
    printf("Primes: %lu\n", index_of(primes_head, &item3.primes));

    printf("\n");

    printf("Index of item4:\n");
    printf("Odds: %lu\n", index_of(odds_head, &item0.odds));
    printf("Primes: %lu\n", index_of(primes_head, &item0.primes));
       
    printf("\n");

    // list_object & list_foreach

    printf("Values in odds:\n");
    list_foreach(odds_head, node) {
        struct data_item * item = list_object(node, struct data_item, odds);
        printf("%d\n", item->value);
    }

    printf("Values in primes:\n");
    list_foreach(primes_head, node) {
        struct data_item * item = list_object(node, struct data_item, primes);
        printf("%d\n", item->value);
    }

    printf("\n");

    return 0;
}
