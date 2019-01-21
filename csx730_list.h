#ifndef CSX730_LIST_H
#define CSX730_LIST_H

/**
 * @file 
 * This header contains the definition for an intrusive, doubly linked list node in @c list_node
 * along with a collection of functions and macros that operate on lists involving such nodes.
 * Students should not alter any @c struct or function prototypes in this file. However, students
 * will need to alter the macros contained in this file. 
 *
 * <p>
 * If any @c struct or function prototypes are altered, then submissions involving this file
 * will very likely not be graded.
 */

/**
 * Represents a node in an intrusive, doubly linked list.
 */
struct list_node {
  struct list_node * prev;
  struct list_node * next;  
}; // list_node

/** 
 * The implementation-defined unsigned integer type of the result of @c sizeof. A @c size_t can 
 * store the maximum size of a theoretically possible object of any type (including array). We 
 * define it here so that @c <stddef.h> does not need to be included.
 *
 * <p>
 * The exact type provided here was chosen to match the @c gcc implementation on UGA's Nike server.
 * You should be able to verify using:
 * @code
 * $ echo | gcc -E -xc -include 'stddef.h' - | grep size_t
 * @endcode
 */
typedef long unsigned int size_t;

/**
 * Initializes the linked list. A single node in a linked list is properly initialized if the other
 * list functions are able to properly operate on that node.
 * @param head head of the list
 */
void list_init(struct list_node * head);

/**
 * Appends the specified node to the end of this list.
 * @param head head of the list
 * @param node node to add
 */
void list_append(struct list_node * head, struct list_node * node);

/**
 * Appends the specified nodes to the end of this list. The expected type of each variadic
 * argument is <tt>struct list_node *</tt>.
 * @param head head of the list
 * @param ... nodes to add
 */
void list_append_all(struct list_node * head, ...);

/**
 * Inserts the specified node at the specified position in this list.
 * @param head head of the list
 * @param node node to insert
 * @param index index at which the specified node is to be inserted
 */
void list_insert(struct list_node * head, struct list_node * node, size_t index);

/**
 * Returns a pointer to the node at the specified position in this list.
 * @param head head of the list
 * @param index index of the node to get
 */
struct list_node * list_get(struct list_node * head, size_t index);

/**
 * Removes the node at the specified position in this list. Shifts any subsequent elements to the
 * left (subtracts one from their indices). Returns a pointer to the node that was removed from the 
 * list.
 * @param head head of the list
 * @param index index of the node to remove
 */
struct list_node * list_remove(struct list_node * head, size_t index);

/**
 * Returns the number of nodes in this list. If @p head is a null pointer, then the size is @c 0.
 * @param head head of the list
 */
size_t list_size(struct list_node * head);

/**
 * Returns the index of the first occurrence of the specified node in this list, or @c -1 if this
 * list does not contain the node. 
 * @param head head of the list
 * @param node node to search for
 */
size_t index_of(struct list_node * head, struct list_node * node);

/**
 * Expands to a pointer to the structure that the given list node intrudes upon. The type of the
 * expansion is the expansion of <tt>type *</tt>. The overall expansion should be capable of
 * being used immediately (e.g, dereferenced or assigned to another variable).
 * @param node pointer to a @c list_node
 * @param type name of the @c struct type containing the node pointed to by @p node 
 * @param member name of the member in @p type that refers to the desired @c list_node
 */
#define list_object(node, type, member) 0

/**
 * Expands to the declaration for a @c for loop that iterates over the given list. Inside of
 * the @c for loop, a pointer named @p node is available that points to the current
 * @c list_node in the iteration. This can be used in conjuction with @c list_object to
 * easily iterate over all intruded upon objects in the list.
 *
 * <p>
 * Here is an example that illustrates the intended usage, assuming <tt>struct my_data_type</tt>
 * includes members @c x and @c list1:
 * @code
 * struct list_node * headptr = // some list head
 * list_foreach(headptr, node) {
 *   struct my_data_type * objptr = list_object(node, struct my_data_type, list1);
 *   printf("objptr->x = %d\n", objptr->x);
 * }
 * @endcode
 * 
 * @param head pointer to head of the list
 * @param node pointer name for use in the the @c for loop
 */
#define list_foreach(head, node) 0


// the following #endif is for the header guard
#endif

