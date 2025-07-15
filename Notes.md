# C++ Advanced Course

Author: __*rune2595*__

The current file contains notes on the course "Learn Advanced C++ Programming" by John Purcell available on udemy.com.
</br>
____

## Table of Contents <a name="top"></a>

1. [Introduction](#1)<br>
2. [Exceptions](#2)<br>
    2.1 [Exceptions Basics](#2.1)<br>
    2.2 [Standard Exceptions](#2.2)<br>
    2.3 [Custom Exceptions](#2.3)<br>
    2.4 [Exception Catching Order](#2.4)<br>
3. [Files](#3)<br>
    3.1 [Writing Text Files](#3.1)<br>
    3.2 [Reading Text Files](#3.2)<br>
    3.3 [Parsing Text Files](#3.3)<br>
    3.4 [Structs & Padding](#3.4)<br>
    3.5 [Reading & Writing Binary Files](#3.5)<br>
4. [Standard Template Library](#4)<br>
    4.1 [Vectors](#4.1)<br>
    4.2 [Vectors & Memory](#4.2)<br>
    4.3 [Two-Dimensional Vectors](#4.3)<br>
    4.4 [Lists](#4.4)<br>
    4.5 [Maps](#4.5)<br>
    4.6 [Custom Objects as Map Values](#4.6)<br>
    4.7 [Custom Objects as Map Keys](#4.7)<br>
    4.8 [Multimaps](#4.8)<br>
    4.9 [Sets](#4.9)<br>
    4.10 [Stacks & Queues](#4.10)<br>
    4.11 [Sorting Vectors, Deque, & Friend](#4.11)<br>
    4.12 [STL Complex Data Types](#4.12)<br>
5. [Operator Overloading](#5)<br>
    5.1 [Overloading the Assignment Operator](#5.1)<br>
    5.2 [Printing - Overloading Left Bit Shift](#5.2)<br>
    5.3 [A Complex Number Class](#5.3)<br>
    5.4 [Overloading Plus](#5.4)<br>
    5.5 [Overloading Equality Test](#5.5)<br>
    5.6 [Overloading the Dereference Operator](#5.6)<br>
6. [Template Classes & Functions](#6)<br>
    6.1 [Templates - An Important Note](#6.1)<br>
    6.2 [Template Classes](#6.2)<br>
    6.3 [Template Functions](#6.3)<br>
    6.4 [Template Functions & Type Inference](#6.4)<br>
7. [Passing Functions to Functions](#7)<br>
    7.1 [Function Pointers](#7.1)<br>
    7.2 [Using Function Pointers](#7.2)<br>
    7.3 [Object Slicing & Polymorphism](#7.3)<br>
    7.4 [Abstract Classes & Pure Virtual Functions](#7.4)<br>
    7.5 [Functors](#7.5)<br>
8. [C++ 11's Amazing New Features](#8)<br>
    8.1 [Decltype, Typeid, & Name Mangling](#8.1)<br>
    
Add more on the go...

## Section 1: Introduction<a name="1"></a>
[Go to top](#top)

Source code for all the projects can be found at this GitHub [wiki](https://github.com/caveofprogramming/advanced-cplusplus/wiki).

All sample code can be found in the repo.


__Bold text__
*Italic text*
`Inline code`
```c++
// Example code block
#include <iostream>

// Code here!

```


## Section 2: Exceptions<a name="2"></a>
[Go to top](#top)

The current section describes exception handling for error messages.

### 2.1 Exceptions Basics<a name="2.1"></a>
[Go to top](#top)

Exceptions are used for error handling.

Errors are called through `throw`, which need a corresponding `catch` in the main code. Multiple catch blocks are needed to handle different types of errors (`int`, `char`, `string`, etc.).

As soon as an exception is thrown, the program jumps to the first catch block that matches the type of the exception. Subsequent catch blocks are not executed.

`throw` creates an object without the need for keyword `new`. `string` objects are caught using a reference. Normally references go out of scope at the end of a function and is not recommended practice, but with exceptions it is different. The compiler will both instantiate and clean up the object.

`throw` throws exceptions all the way out of the call stack until it is caught, i.e., if there is no `catch`, the exception will be thrown out of main too.

### 2.2 Standard Exceptions<a name="2.2"></a>
[Go to top](#top)

Exceptions can be thrown from within classes. 

C++ has a standard exception class called `std::exception`. This acts as a parent class for many other exceptions, fx. `bad_alloc`. `std::exception` contains a method, `.what()`, giving a string explaining the error.

### 2.3 Custom Exceptions<a name="2.3"></a>
[Go to top](#top)

Custom exception classes can be derived from the standard exception class available in C++.

It a good custom to name exception related to the error that occurs.

The standard `.what()` contains a `const throw()`. This means that the method cannot throw an exception. Compiler then might be able to optimize, but is likely bad coding. Better to modify and insert it somewhere else.

### 2.4 Exception Catching Order<a name="2.4"></a>
[Go to top](#top)

Exceptions can have "child/parent"-relationships. It is therefore, important to get the detection order correct. Due to polymorphism (subclasses are also of type of parent class), subclasses can mistakenly be caught as their parent class. This can be solved be trying to catch subclasses before parent classes.

## Section 3: Files<a name="3"></a>
[Go to top](#top)

The current section describes basic file handling in C++.

### 3.1 Writing Text Files<a name="3.1"></a>
[Go to top](#top)

It is important to note that header files are likely different depending on compiler. In the course `#include <fstream>` is used, this also works in visual studio.

`ofstream` stands for "output file stream" and initiates a file stream (part of `fstream`). Methods for `ofstream`:
- `.open`, opens file
- `.is_open`, checks if file is open
- `'objectFile' << "TEXT TO ADD" << endl;`, adds lines to file

