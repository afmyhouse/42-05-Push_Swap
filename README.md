# 42-05-Push_Swap
42  common-core : "push swap" project

## specification
- [`Push Swap Specification`](https://github.com/afmyhouse/42-05-Push_Swap/blob/b06/SPECIFICATION.md)
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

## The rules
- [ ] You have 2 stacks named a and b.
- [ ] At the beginning:
- [ ] The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
- [ ] The stack b is empty.
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
During the evaluation process, a binary will be provided in order to properly check your program.
It will work as follows:

```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l \
6\
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG \
OK \
$>\
```

### Bonus
- [ ] Write your own checker program.
- [ ] Using the push\swap output make a PROGRAMM THAT CHECKS IF THE LIST IS ORDERED

## Intro to sort algorithms
### What are sorting algorthms?
Sorting algorithims are code mechanics to grab a set of information randomly ordere and process till it orderred according to a specoific criteria for ecample "ascending", "descending", etc
### What types of sorting algorithims are there?
#### BUBBLE
Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the input list element by element, comparing the current element with the one after it, swapping their values if needed. These passes through the list are repeated until no swaps had to be performed during a pass, meaning that the list has become fully sorted. The algorithm, which is a comparison sort, is named for the way the larger elements "bubble" up to the top of the list.

This simple algorithm performs poorly in real world use and is used primarily as an educational tool. More efficient algorithms such as quicksort, timsort, or merge sort are used by the sorting libraries built into popular programming languages such as Python and Java. However, if parallel processing is allowed, bubble sort sorts in O(n) time, making it considerably faster than parallel implementations of _insertion sort_ or _selection sort_ which do not parallelize as effectively.

#### INSERTION
_**Insertion sort**_ is a simple sorting algorithm that builds the final sorted array (or list) one item at a time by comparisons. It is much less efficient on large lists than more advanced algorithms such as _**quick sort**_, _**heap sort**_, or _**merge sort**_. However, _**insertion sort**_ provides several advantages:

>**Simple implementation**: Jon Bentley shows a three-line C/C++ version that is five lines when optimized.[1]
>**Efficient for (quite) small data sets**, much like other quadratic (i.e., O(n^2)) sorting algorithms. More efficient in practice than most other simple quadratic algorithms such as _selection sort_ or _bubble sort_
>**Adaptive**, i.e., efficient for data sets that are already substantially sorted: the time complexity is O(kn) when each element in the input is no more than k places away from its sorted position
>**Stable**; i.e., does not change the relative order of elements with equal keys
>**In-place**; i.e., only requires a constant amount O(1) of additional memory space
>**Online**; i.e., can sort a list as it receives it

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



