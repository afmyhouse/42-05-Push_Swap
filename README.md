# 42-05-Push_Swap
42  common-core : "push swap" project

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
You must create a communication program in the form of a client and a server.
- [ ] The server must be started first. After its launch, it has to print its PID.
- [ ] The client takes two parameters: the server PID, the string to send (./client PID_NUMBER "string to send")
- [ ] The client must send the string passed as a parameter to the server.
- [ ] Once the string has been received, the server must print it.
- [ ] The server has to display the string pretty quickly. 
        _Quickly means that if you think it takes too long, then it is probably too long._
        _1 second for displaying 100 characters is way too much!_
- [ ] Your server should be able to receive strings from several clients in a row without needing to restart.
- [ ] The communication between your client and your server has to be done only using UNIX signals.
        _You can only use these two signals: SIGUSR1 and SIGUSR2._
        _Linux system does NOT queue signals when you already have pending signals of this type! Bonus time?_

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

#### How to handle signals

```

## Resources
- [Examine and Change Signal Action](https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigactn.html)
- [Insertion Algorithm] (https://en.wikipedia.org/wiki/Insertion_sort)




