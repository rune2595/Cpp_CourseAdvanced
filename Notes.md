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
- `.open()`, opens file
- `.is_open()`, checks if file is open
- `'objectFile' << "TEXT TO ADD" << endl;`, adds lines to file
- `.close()`, closes file

### 3.2 Reading Text Files<a name="3.2"></a>
[Go to top](#top)

Reading text files requires the same header as writing: `#include <fstream>`.

`ifstream` stands for "input file stream" and opens initializes an existing file. Methods for `ifstream`:
- `.open()`, opens file
- `.is_open()`, checks if file is open
- `.close()`, closes file
- `.eof()`, stand for 'end of file', can be used in a loop to read until end of file (can also just provide the `ifstream` object)

Function `getline()` exists in `fstream` (note that `#include <string>` is also needed) and is used to read lines in a text file. Can also use the extraction operator `>>`, however, this will only read the first word as spaces delimits the function.

Operators can be overloaded to get new behavior???

### 3.3 Parsing Text Files<a name="3.3"></a>
[Go to top](#top)

Reading complicated, formatted files can be tedious. Might consider using C-function that are able to do it, as C++ is not designed for this.

Single quotes are used to create a single character literal in C++, different to a string which uses double quotes.

Delimiters can be added to `getline()` as the third input option. However, this can lead to weird behavior.

To surpress non-printed newline characters in file, use `input.get();`. This will get the next character and discard it. In C++11 `input >> ws` will read white space, and will be a more robust solution than `input.get()`.

### 3.4 Structs & Padding<a name="3.4"></a>
[Go to top](#top)

`structs` are similar to `classes`, but the members are public by default. `structs` are typically used to write to files.

The objects of a `string` class contains pointers to an area of memory, or "stack". Saving a string to a binary file only saves the pointer address, i.e., if a different copy of the proggram is then used to read the file, it will read the address and whatever is stored on that device in that address. This is because `string` is a class rather than a type. Storing text in `char` arrays will read the desired text.

C++ pads `structs` to more efficiently transfer them to and from memory. If the data is to be written literally to a file the padding should be removed. This can be achieved by using a preprocessor directive, `#pragma`, with fx `pack(push, 1)` argument. The 1 tells the program to align the data on single byte boundaries, thereby, removing the padding. `#pragma pack(pop)` turns off the previous command.

### 3.5 Reading & Writing Binary Files<a name="3.5"></a>
[Go to top](#top)

The extension can be whatever, but a good binary file extension would be ".bin". If read in a text editor will just be a mad collection of data, therefore, an intepreter is needed.

An additional argument `ios::binary` is needed when using `.open()`, otherwise newline (and other) characters will be translated by C++. However, these are simply raw data and should NOT be interpreted as newline (or other) characters.

The "o" in `ofstream` is the same as adding `ios::out` as an argument in `.open()`. Same with "i" in `ifstream` and `ios::in`. Note that with argument `ios::binary` the arguments for open method should be separated by the 'or' operator '|'.

When writing a `struct`, it is the address of the data that should be used as input for `.write()` cast as a `char` pointer. Also, the amount of data should be input as an argument (`sizeof()`). A newer method for casting pointers exist (`reintepret_cast<TYPE TO CAST TO>(ADDRESS TO CAST)`).

A binary file can be read using `.read()`.

## Section 4: Standard Template Library<a name="4"></a>
[Go to top](#top)

### 4.1 Vectors<a name="4.1"></a>
[Go to top](#top)

A vector in C++ is a resizeable array. Need to `#inlcude <vector>`. When initiating a vector, the type within the vector should be stated in `<>` after calling it.

``` c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<TYPE> TYPEvector(SIZE)

    return 0;
}
```

A vector automatically handles memory for you unlike an array. An array is NOT resizeable. The vector is resizeable through the `.push_back()` method. The size can be found using `.size()` giving the actual length of the vector rather than the amount of memory!

Do not try to set elements that are off the end of a vector (i.e., `vector[10] = 1`, for a vector of length 5). This will give unexpected behavior.

Writing
```c++
vector<TYPE>::iterator it = vector.begin();
```
Will initialize an iterator. Calling the iterator as a pointer (i.e., `*it`) will give the first element. A similar method exists for end, however, this return that points just after the end of the vector. Together, these methods can be used to iterate through a vector. `it++` will increment the iterator. A `for` loop for a vector can then be written as
```c++
for(vector<TYPE>::iterator it = vector.begin(); it != vector.end(); it++)
{
    // LOOP COMMANDS
}
```

Note that in C++11 there is an even nicer way of iterating through vectors.

### 4.2 Vectors & Memory<a name="4.2"></a>
[Go to top](#top)

The `vector` class manages an array internally, therefore, if a vector is increased to a size larger than the current array, a new array will be created, the old values copied, and new values added. The method `.capacity()` gives the amount of elements the internal array can currently hold. The internal array capacity is doubled when bounds are exceeded. This behavior can be demonstrated by:

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> numbers(0); // Initialize vector of size 0

    cout << "Size: " << numbers.size() << endl;

    int capacity = numbers.capacity(); // Get current internal array capacity
    cout << "Capacity: " << capacity << endl;

    for(int i = 0; i < 10000; i++)
    {
        if(numbers.capacity() != capacity)
        {
            capacity = numbers.capacity();
            cout << "Capacity: " << capacity << endl;
        }

        numbers.push_back(i);
    }

    return 0;
}
```

This is because the method is trying to guess how big your new array should be based on its current size. Ensures that the insertion time remains as constant as it possibly can, since creating new arrays over and over is time consuming (i.e., if size only increased by one everytime, the loop above would be very slow as a new internal array is created at each step. Doubling the array size instead, reduces the amount of times a new array is created.).

`.clear()` deletes all the elements in the vector resulting in a size of 0, however, the capacity is unchanged.

`.resize()` resizes (duh) the vector to a specific size, without affecting existing elements.

`.reserve()` resizes the internal array (capacity) without changing the size of the vector.

### 4.3 Two-Dimensional Vectors<a name="4.3"></a>
[Go to top](#top)

To define multidimensional vectors, simply create a vector of vectors.
```c++
vector< vector<int> > = 2Dvec(ROWS, vector<int>(COLUMNS, CELL_VALUE));
```

Importantly, rows do not need to have the same size, behaving like cell arrays in matlab.

Exercise:

Create 2D vector containing the 12 times table.

### 4.4 Lists<a name="4.4"></a>
[Go to top](#top)

A vector is restricted to insert elements at the end. For a list, elements can be inserted anywhere. Lists are inherently different, as each element also contains pointers to the surrounding elements. This also means that regular indexing is not possible.

`#include <list>` is needed to work with lists.

`.push_back()` is the same as for a vector.

Iterators also work the same as for vector.

`.push_front()` adds element at the front instead of the back.

An iterator is needed to modify elements in the middle. `.insert()` needs the iterator and the value to insert as arguments, then pushes that element in front of the stated iterator.

`.erase()` erases the number at the iterator. Note that the syntax should be
```c++
list<TYPE> list;

// ADD ELEMENTS

list<TYPE>::iterator eraseIt = list.begin();
eraseIt++;
eraseIt = list.erase(eraseIt);
```
To erase the second element in the list. The important thing is reassigning `eraseIt` to have it point to the new element in that position, otherwise the iterator is invalidated.

### 4.5 Maps<a name="4.5"></a>
[Go to top](#top)

`maps` is like a lookup table, where elements can be retrieved by a key.

Similar to lists and vectors, it is possible to iterate through a `map` using the same syntax.

In basic `map`s keys are unique, i.e., assigning a value to an existing key overwrites the old value.

Accessing a value that is not in the `map`, adds it with value 0.

`.find(KEY)` returns an iterator that points at the right element, or to a point of the end of the `map` if not found. Can be used to check if a key is in the `map` before accessing it, thereby, not adding an unwanted key with value 0.

Map data comes in `pair`s, meaning that a key and a value are tied. A declared `pair` can be inserted into a `map` as follows:
```c++
map.insert(pair<KEYTYPE, VALUETYPE>(KEY, VALUE))
```
`make_pair()` can be used to create a `pair` corresponding to the `map` types.

