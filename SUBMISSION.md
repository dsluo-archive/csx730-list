# Submission Information

## Author Information

* __Full Name:__ David Luo
* __UGA Email:__ `davidluo@uga.edu`
* __Course:__ CSCI 4730

## Implementation Overview

This project implements a simple intrusive doubly linked list, along with a demo program to show off its features.
It is essentially the same as a regular doubly linked list, but the value is stored in an external struct rather than
the nodes themselves, instead using a macro to retrieve the original values.

## 6730 Requirements

I would like the grader to check for the following 6730 requirements:

* __[PRETTY]__
* __[DRIVER]__

## Reflecton

1. What do you think was the motivation behind assigning this project in this class?

   The motivation behind this project was probably to introduce students to what it's like to program in C, getting
   familiar with macros and the lack of true object-oriented programming.

2. What is the most important thing you learned in this project?

   I learned a lot about writing macros, and how in C, you're often using tricks in how memory is arranged to access
   data.

3. What do you wish you had spent more time on or done differently?

   I ended up rewriting the driver. Should have probably just written it right the first time.

4. What part of the project did you do your best work on?

   I feel like my driver was really well thought out and demonstrates a lot of edge cases.

5. What was the most enjoyable part of this project?

   It was really interesting working with a lower level language than I'm usually using.

6. What was the least enjoyable part of this project?

   Dealing with string manipulation in C is a lot more verbose than in something like Python. Also spent a lot of
   time figuring out how variable arguments worked. Only realized after a while that `va_start` only needed the
   last argument before the `...` and not necessarily a count. Also took a while to realize that where an argument
   count is not provided, you need have the last argument as `NULL` adn that's not taken care of for you.

7. How could your instructor change this project to make it better next time?

   I wish a `to_string` implementation was provided. Perhaps with it a `data_item` struct.
