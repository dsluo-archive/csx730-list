# csx730-list

![Railway stations intrude on the towns the link.](https://i.imgur.com/MdPMTcO.png)

**DUE MON 2019-02-04 (Feb 4) @ 11:55 PM**

This repository contains the skeleton code for the `csx730-list` project
assigned to the students in the Spring 2019 CSCI 4730/6730 class
at the University of Georgia.

## Academic Honesty

You agree to the Academic Honesty policy as outlined in the course syllabus. 
In accordance with this notice, I must caution you **not** to fork this repository
on GitHub if you have an account. Doing so will more than likely make your copy of
the project publicly visible. Please follow the instructions contained in the 
[How to Get the Skeleton Code](#how-to-get-the-skeleton-code) section below in
order to do your development on Nike. Furthermore, you must adhere to the copyright
notice and licensing information at the bottom of this document.

## Intrusive Linked List

In a regular, non-intrusive linked list implementation, the nodes of the linked list contain the 
list items:

```c
struct list_node {
  struct some_type data;
  struct list_node * next;
};
```

The implementation of a singly linked list provided above is one that students are usually most
familiar with from their Data Structures course. It has many pros and cons, which we will not list
here. One major disadvantage of this popular implementation is that it makes it more difficult for
items to be involved in multiple lists concurrently unless we decide to make list nodes carry pointers
to their items instead of the items themeselves--i.e., using something like `struct some_type *` 
instead of `struct some_type` in the example presented above. 

This might not seem like a big deal, but it increases the overall complexity of memory allocation for 
all lists involved. In most scenarios, the list implementation will require dynamic memory 
allocation to add more nodes. In fact, it is a pretty safe bet to assume that is how you implemented
your own linked list when asked to do so for a project in a previous class.

In an operating system kernel, we would like to provide a linked list implementation that minimizes 
and/or eliminates dynamic memory allocation for list manageent. This is where **intrusive linked lists** 
come into play. Here is a structure for a node in an intrusive, singly linked list:

```c
struct list_node {
  struct list_node * next;
};
```

The node structure itself is slightly simpler than the one presented earlier--it lacks a data member and
is therefore independent of a data member type without the need for a pointer. Why is it called
"instrusive"? Well, that comes from how it's used. Here is a structure for some items that are involved 
in two intrusive linked lists called `list1` and `list2`:

```c
struct data_item {
  unsigned int x;
  struct list_node list1;
  struct list_node list2;
};
```

The structure above illustrates why this kind of list implementation is called intrusive. It looks
like an item contains the lists and not the other way around! That is, the lists intrude on the
structures of their items.

In this project, you are tasked with implementing an __intrusive, doubly linked list__! The
structure for list nodes is provided. Other project details are provided below.

## How to Get the Skeleton Code

On Nike, execute the following terminal command in order to download the project
files into sub-directory within your present working directory:

```
$ git clone https://github.com/cs1730/csx730-list.git
```

This should create a directory called `csx730-list` in your present working directory that contains
the project files. For this project, the only files that are included with the project download
are listed near the top of the page [here](https://github.com/cs1730/csx730-list).

Here is a table that briely outlines each file in the skeleton code:

| File                   | Description                                                      |
|------------------------|------------------------------------------------------------------|
| `Doxyfile`             | Configuration file for `doxygen`.                                |
| `Makefile`             | Configuration file for `make`.                                   |
| `README.md`            | This project description.                                        |
| `SUBMISSION.md`        | Student submission information.                                  |
| `csx730_list.c`        | Where you will put most of your list implementation.             |
| `csx730_list.h`        | List function prototypes and macros.                             |
| `csx730_list_driver.c` | Where the `main` method lives for the  __[DRIVER]__ requirement. |

If any updates to the project files are announced by your instructor, you can
merge those changes into your copy by changing into your project directory
on Nike and issuing the following terminal command:

```
$ git pull
```

If you have any problems with any of these procedures, then please contact
your instructor via Piazza. 

## Project Requirements

This assignment is worth 100 points. The lowest possible grade is 0, and the 
highest possible grade is 110 (if you are enrolled in CSCI 4730).

### Functional Requirements

A functional requirement is *added* to your point total if satisfied.
There will be no partial credit for any of the requirements that simply 
require the presence of a function related a particular functionality. 
The actual functionality is tested using test cases.

1. __(80 points) Implement `csx730_list.h` functions in `csx730_list.c`.__
   Each of the functions whose prototype appears in `csx730_list.h` must
   be implemented correctly in `csx730_list.c`. Here is a list of the
   functions:

   * (10 points) `void list_init(struct list_node *);`
   * (10 points) `void list_append(struct list_node *, struct list_node *);`
   * (10 points) `void list_append_all(struct list_node * head, ...);`
   * (10 points) `void list_insert(struct list_node *, struct list_node *, size_t);`
   * (10 points) `struct list_node * list_get(struct list_node *, size_t);`
   * (10 points) `struct list_node * list_remove(struct list_node *, size_t);`
   * (10 points) `size_t list_size(struct list_node *);`
   * (10 points) `size_t index_of(struct list_node *, struct list_node *);`

   The documentation for each function is provided directly in
   `csx730_list.h`. You may generate an HTML version of the corresponding
   documentation using the `doc` target provided by the project's `Makefile`.
   Students should not modify the prototypes for these functions in any way--doing
   so will cause the tester used by the grader to fail. 

1. __(20 points) Implement `csx730_list.h` macros in `csx730_list.h`.__
   Each of the macros partially defined in `csx730_list.h` must be
   implemented correctly directly in `csx730_list.h`. Here is a list of the
   macros:

   * `list_object(node, type, member)`
   * `list_foreach(head, node)`

   The documentation for each macro is provided directly in `csx730_list.h`.
   You may generate an HTML version of the corresponding documentation using
   the `doc` target provided by the project's `Makefile`. Students will
   need to modify `csx730_list.h` to properly implement the macros. Currently,
   each macro expands to `0`. 

### 6730 Requirements

For the purposes of grading, a 6730 requirement is treated as a non-functional requirement
for students enrolled in CSCI 6730 and a functional requirement for students enrolled in
CSCI 4730. This effectively provides an extra credit opportunity to the undergraduate
students and a non-compliance penalty for the graduate students.

1. __(5 points) [PRETTY] Implement pretty printing for your list implementation.__ Add the
   following prototype to `csx730_list.h` (and implement it in `csx730_list.c`): 

   ```c
   /**
    * Prints the list to a line in standard output with the help of @p to_string. Assume
    * @p to_string returns a new string representation of the structure a node intrudes upon,
    * formatted similarly to <tt>data(7, 2.0)</tt>. Then, the output that this function produces
    * to standard output might look like the following for a list containing three nodes:
    * <tt>{ data(7, 2.0), data(3, 2.2), data(9, 1.4) }</tt>. You should assume that the memory
    * for the string returned by @p to_string was obtained with @c malloc(3) and should be freed
    * with @c free(3). You may assume that all nodes in the list intrude on the same type of
    * structure. 
    * @param head head of the list
    * @param to_string function that returns a string representaton of a node's enclosing structure
    */
   void list_pretty_print(struct list_node * head, char * (* to_string)(struct list_node *));
   ```

1. __(5 points) [DRIVER] Provide code in `csx730_list_driver.c` that demos your implementation.__
   Provide a commented, functional demo in the `main` function that illustrates each list
   function and macro. This demo should clearly show that each function works correctly. In order
   to recieve points for this requirement, you must include at least one structure that is involved
   with two or more lists. Furthermore, some of the data structures involed in the lists should
   be dynamically allocated. Output to standard output is expected. 

### Non-Functional Requirements

A non-functional requirement is *subtracted* from your point total if not satisfied. In order to
emphasize the importance of these requirements, non-compliance results in the full point amount
being subtracted from your point total. That is, they are all or nothing.

1. __(100 points) Build Compliance:__ Your project must compile on Nike
   using the provided `Makefile` and `gcc` (GCC) 8.2.0. Your code must compile,
   assemble, and link with no errors or warnings. The required compiler
   flags for this project are already included in the provided `Makefile`.

   The grader will compile and test your code using `all` and `test` targets in
   the provided `Makefile`. The `test` target will not work until the test driver
   is provided during grading. If your code compiles, assembles, and links
   with no errors or warnings usign the `all` target, then it will very likely
   do the same with the `test` target.

1. __(100 points) Libraries:__ You are allowed to use any of the C standard library
   functions. A reference is provided [here](https://en.cppreference.com/w/c).
   No other libraries are permitted.

1. __(100 points) `SUBMISSION.md`:__ Your project must include a properly formatted 
   `SUBMISSION.md` file that includes, at a minimum, the following information:

   * __Author Information:__ You need to include your full name, UGA email, and
     which course you are enrolled in (e.g., CSCI 4730 or CSCI 6730).

   * __Implementation Overview:__ You need to include a few sentences that provide an overview
     of your implementation.
     
   * __6730 Requirements:__ You need to include a list of the 6730 requirements that you
     would like the grader to check. These requirements will only be checked if you
     include them in this list. 
     
   * __Reflecton:__ You need to provide answers to the following questions:

     1. What do you think was the motivation behind assigning this project in this class?
     1. What is the most important thing you learned in this project?
     1. What do you wish you had spent more time on or done differently?
     1. What part of the project did you do your best work on?
     1. What was the most enjoyable part of this project?
     1. What was the least enjoyable part of this project?
     1. How could your instructor change this project to make it better next time?

   A properly formatted sample `SUBMISSION.md` file is provided that may be modified to
   help fulfill this non-functional requirement.

1. __(25 points) Memory Leaks:__ Your submission should not result in any memory leaks.
   The grader will check this using `valgrind(1)`.

1. __(25 points) Code Documentation:__ Any new functions or macros must be properly documented
   using Javadoc-style comments. An example of such comments can be seen in the souce code
   provided with the project. Please also use inline documentation, as needed, to explain
   ambiguous or tricky parts of your code.

## Submission Instructions

You will still be submitting your project via Nike. Make sure your project files
are on <code>nike.cs.uga.edu</code>. Change into the parent directory of your
project directory. If you've followed the instructions provided in earlier in this
document, then the name of your project directory is likely `csx730-list`.
While in your project parent directory, execute the following command: 

```
$ submit csx730-list csx730
```

If you have any problems submitting your project then please make a private Piazza
post to "Instructors" as soon as possible. 

<hr/>

[![License: CC BY-NC-ND 4.0](https://img.shields.io/badge/License-CC%20BY--NC--ND%204.0-lightgrey.svg)](http://creativecommons.org/licenses/by-nc-nd/4.0/)

<small>
Copyright &copy; Michael E. Cotterell and the University of Georgia.
This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a> to students and the public.
The content and opinions expressed on this page do not necessarily reflect the views of nor are they endorsed by the University of Georgia or the University System of Georgia.
</small>
