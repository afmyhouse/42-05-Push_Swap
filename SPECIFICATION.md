# 42-05-Push_Swap : SPECIFICATION
42  common-core : "push swap" project
_Please refer to the original doc issued by 42 school. If any discrepancies are found between this document and the school edition, it is this last one whic prevails._


## Introduction
The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.
You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.
Your goal? Write a program in C called _**push_swap**_ which calculates and displays on the standard output the smallest program, made of "Push Swap" language instructions, that sorts the integers received as arguments.
Easy?
We’ll see...

## Objectives
Writing a -**sorting algorithm**_ is always a very important step in a developer’s journey. It is often the first encounter with the concept of complexity.
Sorting algorithms and their complexity are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts since you’ll have to face them at some point.
The learning objectives of this project are rigor, use of C, and use of basic algorithms.
Especially focusing on their complexity.
Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution can differ.

## Subject

### Mandatory Part
#### Mandatory task list
##### The rules
- [ ] You have 2 stacks named a and b.
- [ ] At the beginning:
>- [ ] The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
>- [ ] The stack b is empty.
- [ ] The goal is to sort in ascending order numbers into stack a.
- [ ] To do so you have the following operations at your disposal:\
**` sa  `** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.\
**` sb  `** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.\
**` ss  `** : **sa** and **sb** at the same time.\
**` pa  `** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.\
**` pb  `** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.\
**` ra  `** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.\
**` rb  `** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.\
**` rr  `** : ra and rb at the same time.\
**` rra `** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.\
**` rrb `** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.\
**` rrr `** : rra and rrb at the same time.\

#### Example
To illustrate the effect of some of these instructions, let’s sort a random list of integers.
In this example, we’ll consider that both stacks grow from the right.

|Init a and b |`sa` |`pb` |`pb` |`pb` |`ra` |`rb` |`rra`|`rrb`|`sa` |`pa` |`pa` |`pa` |
|-------------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| 2           | `1`   |     |     |     |     |     |     |     |     |     |     | `1`   |
| 1           | `2`   | 2   |     |     |     |     |     |     |     |     | `2`   | 2   |
| 3           | 3   | 3   | 3   |     |     |     |     |     |     | `3`   | 3   | 3   |
| 6           | 6   | 6   | 6   | 6 `3` | 5 3 | 5 2 | `6` 2 | 6 `3` | `5` 3 | 5   | 5   | 5   |
| 5           | 5   | 5   | 5 `2` | 5 2 | 8 2 | 8 1 | 5 1 | 5 2 | `6` 2 | 6 2 | 6   | 6   |
| 8           | 8   | 8 `1` | 8 1 | 8 1 | `6` 1 | 6 `3` | 8 3 | 8 1 | 8 1 | 8 1 | 8 1 | 8   |
| a b         | a b | a b | a b | a b | a b | a b | a b | a b | a b | a b | a b | a b |



Integers from a get sorted in 12 instructions. Can you do better?
### The "push_swap" program
|Program name           | push_swap|
|-----------------------|-------------------------------------------------------------|
|Turn in files          | Makefile, *.h, *.c|
|Makefile               | NAME, all, clean, fclean, re|
|Arguments              | stack a: A list of integers|
|External functions     |read, write, malloc, free, exit, ft_printf and any equivalent YOU coded|
|Libft authorized       | Yes|
|Description            | Sort stacks|

Your project must comply with the following rules:
- [ ] You have to turn in a Makefile which will compile your source files. It must not relink.
- [ ] Global variables are forbidden.
- [ ] You have to write a program named **push_swap** that takes as an argument, the _stack a_, formatted as a list of integers. The **first argument** should be at the **top of the stack** (be careful about the order).
- [ ] The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- [ ] Instructions must be separated by a ’\n’ and nothing else.
- [ ] The goal is to sort the stack with the lowest possible number of operations.
- [ ] During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated.
- [ ] If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
- [ ] If no parameters are specified, the program must not display anything and give the prompt back.
- [ ] In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

#### Examples
```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```
During the evaluation process, a binary will be provided in order to properly check
your program.
It will work as follows:

```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l \
6\
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG \
OK \
$>\
```

### Bonus part
#### Bonus task list:
- [ ] The server acknowledges every message received by sending back a signal to the client.
- [ ] Unicode characters support! **UTF-8**

## Evaluation
The bonus part will only be assessed if the mandatory part is PERFECT.
Perfect means the mandatory part has been integrally done and works without malfunctioning.
If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.### Project instructions

## Project Specific Instructions
- [ ] Name your executable files _client_ and _server_
- [ ] You have to turn in a Makefile which will compile your source files. It must not relink.
- [ ] You can definitely use your libft.
- [ ] You have to handle errors thoroughly.
- [ ] In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
- [ ] Your program mustn’t have memory leaks.
- [ ] You can have one global variable per program (one for the client and one for the server), but you will have to justify their use.
- [ ] In order to complete the mandatory part, you are allowed to use the following functions:


## Allowed Functions (manual)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`read`](https://man7.org/linux/man-pages/man2/read.2.html)
- [`malloc`](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [`exit`](https://man7.org/linux/man-pages/man2/exit.2.html)
- [`ft_printf`](https://github.com/afmyhouse/42-01-ft_printf)


## Intro to sort algorithms
### What are sorting algorthms?
Sorting algorithims are code mechanics to grab a set of information randomly ordere and process till it orderred according to a specoific criteria for ecample "ascending", "descending", etc
### What types of sorting algorithims are there?
#### BUBBLE
Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the input list element by element, comparing the current element with the one after it, swapping their values if needed. These passes through the list are repeated until no swaps had to be performed during a pass, meaning that the list has become fully sorted. The algorithm, which is a comparison sort, is named for the way the larger elements "bubble" up to the top of the list.

This simple algorithm performs poorly in real world use and is used primarily as an educational tool. More efficient algorithms such as quicksort, timsort, or merge sort are used by the sorting libraries built into popular programming languages such as Python and Java. However, if parallel processing is allowed, bubble sort sorts in O(n) time, making it considerably faster than parallel implementations of _insertion sort_ or _selection sort_ which do not parallelize as effectively.

#### INSERTION
_**Insertion sort**_ is a simple sorting algorithm that builds the final sorted array (or list) one item at a time by comparisons. It is much less efficient on large lists than more advanced algorithms such as _**quick sort**_, _**heap sort**_, or _**merge sort**_. However, _**insertion sort**_ provides several advantages:

    Simple implementation: Jon Bentley shows a three-line C/C++ version that is five lines when optimized.[1]
    Efficient for (quite) small data sets, much like other quadratic (i.e., O(n2)) sorting algorithms
    More efficient in practice than most other simple quadratic algorithms such as _**selection sort**_ or _**bubble sort**_
    Adaptive, i.e., efficient for data sets that are already substantially sorted: the time complexity is O(kn) when each element in the input is no more than k places away from its sorted position
    Stable; i.e., does not change the relative order of elements with equal keys
    In-place; i.e., only requires a constant amount O(1) of additional memory space
    Online; i.e., can sort a list as it receives it

When people manually sort cards in a bridge hand, most use a method that is similar to insertion sort.[2]
- __Maskable__: signals which can be changed or ignored by the user (e.g., Ctrl+C)
- __None-Maskable__: Signals which cannot be changed or ignored by the user. These typically occurs when the user is signaled for non-recoverable hardware errors.

#### How to sort using push swap, internet resources

```
- [`Examine and Change Signal Action`](https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigactn.html)
- [Random Number sequences generator](https://numbergenerator.org/numberlistrandomizer#!numbers=100&lines=1&range=1-100)
- [`Insertion Algorithm`] (https://en.wikipedia.org/wiki/Insertion_sort)
- [`Jamie Orber Approach to Push Swap`] (https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

```



