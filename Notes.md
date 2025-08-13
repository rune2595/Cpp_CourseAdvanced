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

All sample code can be found in the repo. Files generally adopt the name of the tutorial, but some might cover multiple tutorials when it makes sense.

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

### 4.6 Custom Objects as Map Values<a name="4.6"></a>
[Go to top](#top)

This relates to objecs or classes that are sefl-defined as values in a map.

When defining a class constructor with input parameters, it loses the default constructor that creates the object without input. A map needs to initialize the objects without input and will therefore crash if no extra constructor is defined.

It is not smart to copy pointers when copying an object, otherwise, it still points to the old object.

### 4.7 Custom Objects as Map Keys<a name="4.7"></a>
[Go to top](#top)

When using custom objects as keys, methods need to be declared `const`. This is due to the iterator returning keys as `const`.

Maps naturally sort content by the keys. Ths is done using the less than operator `<`. However, custom objects do not work with this. An additional method should be defined to handle this.

The method should look like:
```c++
bool operatorOPERATORTOOVERLOAD(const OBJECT &OTHEROBJECT) const
{
    if(PARAMETER1 == OTHEROBJECT.PARAMETER1)
    {
        return PARAMETER2 < OTHEROBJECT.PARAMETER2;
    }
    else
    {
        return PARAMETER1 < OTHEROBJECT.PARAMETER2;
    }
}
```
The objects passed to the function as to be marked as a `const` reference `&`. The reference for efficiency to not create a copy, and `const` because we do not want the operator to change the other object. Also the whole method should be declared `const` as the operator should not change the original object either.

Like earlier, using the same key to define a new value in the map, overwrites the old value.

If the key consists of multiple parameters (fx. name and age), both need to be added to the additional method. If not, the `map` will consider only the added parameter as individual, i.e. two objects with same name but different ages will be considered identical. To simplify, a unique ID can be assigned and used as the "super parameter". Thereby, eliminating the need for additional conditions in the map sorting method. However, this might not always be possible.

### 4.8 Multimaps<a name="4.8"></a>
[Go to top](#top)

Multimaps enables storage for duplicate keys, and is also included in the `map` header file. Multimaps does not have an overloaded array subscript type operator, therefore, values can only be added using the `insert` method.

Iterating works the same way as for regular `map`s.

`.find()` can be used to find a value in the `multimap` just like in a `map`. However, to find all identical keys a range needs to be defined. This can be done for a `pair` of iterators as so
``` c++
pair<multimap<TYPE1, TYPE2>::iterator, multimap<TYPE1, TYPE2>::iterator> range = MULTIMAP.equal_range(KEY);
```
The loop is then defined as
``` c++
for(multimap<TYPE1, TYPE2>::iterator it = range.first; it != range.second; it++)
{
    // loop commands
}
```
In C++11 additional features allows for simplifications to the code above. `auto` automatically gets the type, i.e., the above can be simplified to
``` c++
auto range = MULTIMAP.equal_range(KEY);

for(auto it = range.first; it != range.second; it++)
{
    // loop commands
}
```

### 4.9 Sets<a name="4.9"></a>
[Go to top](#top)

A `set` only stores unique elements and orders them. Other contains method similar to a `map`. Trying to insert a duplicated value will fail and original value is kept.

Good at getting rid of duplicates. As elements are unique, the `.count()` method can be used as a `true`/`false` operator as it will either return 1 or 0.

Like for a `map` it is neccessary to overload the less than oprator to compare keys for ordering.

### 4.10 Stacks & Queues<a name="4.10"></a>
[Go to top](#top)

A `stack` is a "last in-first out" structure. Imagine a pile of planks; it is possible to add to the top, but not the bottom. Therefore, things also should be removed from the top before access to the bottom is obtained.

When storing local variables the memory stack is called, and it works just like a `stack` structure. To access the top of the `stack` simply use `.top()`.

A `queue` works like a queue in real life, i.e., first-come-first-serve. To access front of the `queue` simply use `.front()`. Can also look at the back of the `queue` by using `.back()`.

There is no way to iterate through a stack or a queue, as both already know which element to look at.

The method `.pop()` removes the next in line (top of stack, front of queue).

When accessing an element in a `stack` or a `queue`, use the reference operator `&` for efficiency. Otherwise, the program will create copies and destroy objects, which is very inefficient.

### 4.11 Sorting Vectors, Deque, & Friend<a name="4.11"></a>
[Go to top](#top)

Vectors can be sorted using the `std` method `sort()`. The method requires the start and end of the vector to be sorted (therfore, it is possible to sort part of a vector). `sort()` can also take function pointers as arguments. This is useful when sorting classes by others in a vector. A function comparing the sorting parameters can then be defined similar to the operator overload method used inside classes. However, a function prototype still needs to be added to the object for it to access private parameters using the keyword `friend`. `friend` basically says, "when you meet a function with this name, it can access our private members".

Generally, it is not efficient to sort a `vector`. Therefore, a `set` is preffered. However, if the sorting is done once at the end, then it is okay.

A `deque` is a double ended queue, which combines the functionalities of a `stack` and a `queue` into one type. Methods have similar names to a `queue`, but enables access to both ends for adding and removing.

### 4.12 STL Complex Data Types<a name="4.12"></a>
[Go to top](#top)

Nested STL types can be used to represent any datastructure imaginable. `vector`s of `map`s, etc.

Note that simplification if preffered as nested datatypes can become quite messy.

## Section 5: Operator Overloading<a name="5"></a>
[Go to top](#top)

### 5.1 Overloading the Assignment Operator<a name="5.1"></a>
[Go to top](#top)

Imaging having two objects defined as
``` c++
CLASS OBJECT1(INT1, INT2);

CLASS OBJECT2(INT3, INT4);
```
Overwriting the second object like
``` c++
OBJECT2 = OBJECTS1;
```
creates a shallow copy of `OBJECT1`. This is sometimes what you want, but other options exist, fx., a deep copy. Some objects might carry a unique ID, in that case, making a shallow copy will not be desired, as it simply has the same pointers as the source object (i.e., it points to the same memory). A deep copy will point to new memory.

An operator can basically be viewed as a function with to arguments (LHS and RHS). Similarly, a method will always have a minimum of one argument (even when the parenthesis are empty), as the implicit argument received by the method is the object on which it is called.

In case of the assignment operator `=`, it is a binary operator as it takes two arguments. A method can be implemented for a class to change the behavior of operators. The method `.operator=()` is equivalent to `=`.

Importantly,
``` c++
CLASS OBJECT2;

OBJECT2 = OBJECT1;
```
is different to
``` c++
CLASS OBJECT2 = OBJECT1;
```
In the first case the assignment operator is called, whereas, the second case utilizes the default copy constructor of the class.

A rule of thumb is if one of a copy constructor, a destructor, or an assignment operator is implemented, the other two should be implemented as well.

### 5.2 Printing - Overloading the Left Bit Shift<a name="5.2"></a>
[Go to top](#top)

Normally when printing private properties of a class, it is neccessary to create a method to access it. However, it would be nice to be able to simply write
``` c++
CLASS OBJECT(TYPE1, TYPE2);
cout << OBJECT << endl;
```
In the above code, the left bit shift operator `<<` has two arguments; `cout` and `OBJECT`. `cout` is an object of type `ostream` (output stream).

Operators can be either 'left-right' or 'right-left' associative. Fx. `+` has 'right-left' associativity, meaning operations to the right are done first (see example below).
``` c++
int value = 1 + 2 + 3 // will be calculated as 1 + (2 + 3)
```
`<<` has 'left-right' associativity, i.e.,
``` c++
cout << SOMETHING << endl; // is handled as (cout << SOMETHING) << endl;
```
The part in parenthesis returns an object which is a reference to an `ostream` type (in the case of `cout`).

As `cout` is not of type `CLASS`, it cannot be implemented as a method of the class. Therefore, a function has to be defined to create the overload, specifically a `friend` function. The syntax should be
``` c++
friend ostream &operator<<(ostream &OUT, const CLASS &OBJECT)
{
    OUT << OBJECT.TYPE1 << "optional string" << OBJECT.TYPE2;

    return OUT;
}
```

### 5.3 A Complex Number Class<a name="5.3"></a>
[Go to top](#top)

C++ already contains a class for complex numbers, however, a new one is created to enable operator overloading.

This is done utilizing the knowledge from above.

### 5.4 Overloading Plus<a name="5.4"></a>
[Go to top](#top)

This will extend on the complex number class created earlier.

Similar to the `<<`-operator, the method can be implemented as a member function or a free-standing function using either `friend` functions or "get" methods.

The addition-operator needs to return a new complex number, as the old numbers are simply `const` input. Input should be stated as references for efficiency.

Using complex numbers as an example, the implementation should be:
``` c++
Complex operator+(const Complex& c1, const Complex& c2)
{
	return Complex(c1.getReal()+c2.getReal(), c1.getImag()+c2.getImag()) ;
}
```
This assumes that getter functions have been implemented for the class. A similar approach can be used to add a real `double` to a complex number. Note that for this it is neccessary to implement two operators to handle objects on different sides of the operator.

Additional methods have been added for subtraction and multiplication.

### 5.5 Overloading Equality Test<a name="5.5"></a>
[Go to top](#top)

This shows how to overload both `==` and `!=`.

As opposed to the other operators, `==` needs to be defined within the class itself with a return type `bool`. Also, the operator only takes one explicit argument as the other in an implicit `this` argument.
``` c++
bool TYPE::operator==(const TYPE &other) const
{
    return (FEATURE1==other.FEATURE1) && (FEATURE2==other.FEATURE2);
}
```
The definition of `!=` can utilize the defined overloaded `==` operator in its test like:
``` c++
bool TYPE::operator!=(const TYPE &other) const
{
    return !(*this==other);
}
```

### 5.6 Overloading the Dereference Operator<a name="5.6"></a>
[Go to top](#top)

It is not only the "normal" operators that can be overloaded. More abstract operators such as the deference operator, `*`, can also be overloaded. The current section describes how and the principles can be translated to other operators as well.

Complex numbers will be used as an example, specifically, the dereference operator will be overloaded to give the complex conjugate.

Similar to the equality test operator, the implmentation should be defined within the class itself with return type `TYPE`, i.e. for the complex number class the return type is `Complex`. Otherwise, implementation is similar to previous cases.

Brackets can also be overloaded. However, a few operators cannot be overloaded (google when neccessary).


## Section 6: Template Classes & Functions<a name="6"></a>
[Go to top](#top)

### 6.1 Templates - An Important Note<a name="6.1"></a>
[Go to top](#top)

Importantly, it is not easy to separate the implementation from the actual class for template classes. Normally, prototypes (i.e., how the class works) are put in a header file, and the actual implmentation is put in a `.cpp` file. The compiler then only needs to look at the header to know the class is being used correctly. The `.cpp` file can separately be compiled into a `.o` file. However, this workflow does not apply to template classes.

Regarding templates, C++ needs to see both the implmentation and definition simultaneously to be able to compile. Therefore, it is likely better to define template classes all in the header file. There are ways to separate the implementation from the definition, but they are mostly workarounds. Fx., the implementation can be put in a file that is called something else than `.cpp` (could be `.tpp`) such that it is not compiled directly, then the implementation can be included in the header rather than including the header in the implementation.More ways exists, but all lead to various side effects that can affect the program adversely.

### 6.2 Template Classes<a name="6.2"></a>
[Go to top](#top)

Template classes allows for definition of classes using types of variables defined by the user. An example of this is the `vector` class, where the types are called in the variable definition.

Are not often useful in C++, but when they are the potential is ver high. The general syntax of a template class is (with a bit of examples that are not mandatory):
``` c++
template<class class1 , class class2>
class testClass
{
private:
    class1 obj1;

public:
    // below is optional
    Test(class1 obj)
    {
        this->obj = obj;
    }

    void print()
    {
        cout << obj << endl; // assuming stream insertion operator is implemented
    }
}
```
`testClass` can more or less do anything with `class1`, but is unable to use implemented methods as the type is technically unknown. Methods for interrogation exists to find out more about the input class and its methods, but it is generally bad practice.

### 6.3 Template Functions<a name="6.3"></a>
[Go to top](#top)

Importantly, template functions can be mixed with template classes. Also, when defining a template (both class and function), the `class` keyword can be changed to `typename` keyword, which is more general and covers primitive types such as `int`.

When using template functions, the type should be stated in `<>` after the functioname and before the input arguments. However, this is not neccessary, as C++ can infer the type from the argument.

__Exercise__

Create a code where the type input actually makes a difference.

Hint: Multiple classes can have same name with different overloaded operators.

### 6.4 Template Functions & Type Inference<a name="6.4"></a>
[Go to top](#top)

This is related to the exercise in section 6.3.

If two functions exists with the same name and only one is a template function, the nearest match will be used. Inserting the `<>` forces the use of the template function, as it indicates multiple types can be used. Example:
``` c++
template<class class1>
void print(class1 obj1)
{
    cout << "Template version: " << obj1 << endl;
}

void print(int value)
{
    cout << "Non-template version: " << value << endl;
}

int main()
{
    print("Hello");  // Uses template
    print(4);        // Uses non-template
    print<int>(4);   // Uses template
    print<>(4);      // Uses template

    return 0;
}
```
There are situations where the code will not compile without the type being stated in the diamond brackets. Removing the argument from the function definition creates this problem, as the type cannot be inferred.
``` c++
template<class class1>
void print()
{
    cout << "Template version: " << obj1 << endl;
}

int main()
{
    print();            // Will not work
    print<>();          // Will not work
    print<double>();    // Will initialize a double to default and print the value

    return 0;
}
```


## Section 7: Passing Functions to Functions<a name="7"></a>
[Go to top](#top)

### 7.1 Function Pointers<a name="7.1"></a>
[Go to top](#top)

A pointer to a function can be stated the same way as a pointer to a variable. Commonly used behind the scenes in C++. 

It is important to use brackets to ensure that the dereference operator is connected to the correct variable and the desired behaviour is reflected. However, `*` and `&` are not neccessary to point to functions. An example is shown below:
``` c++
// Simple function
void test()
{
    cout << "Hello" << endl;
}

int main()
{
    test(); // Simply call the function

    void (*pTest)(); // Instantiate a pointer. The brackets around '*pTest' indicates that it is actually a function pointer. Otherwise, the dereference operator could be related to the return object of the function rather than the fucntion itself.

    pTest = &test; // Point the pointer at the function using the address operator

    (*pTest)(); // Call the function through the pointer

    return 0;
}
```
As mentioned, not all operators are neccessary. Thereby, the code can be simplified to:
``` c++
// Simple function
void test()
{
    cout << "Hello" << endl;
}

int main()
{
    test(); // Simply call the function

    void (*pTest)() = test; // Initialize a pointer

    pTest(); // Call the function through the pointer

    return 0;
}
```
If the function that is called has arguments, the function pointer only needs the argument types as input.
``` c++
// Simple function
void test(int value)
{
    cout << "Hello: " << value << endl;
}

int main()
{
    test(7); // Simply call the function

    void (*pTest)(int) = test; // Initialize a pointer

    pTest(8); // Call the function through the pointer

    return 0;
}
```
I.e., there is no need to give the `int` (in this case) a value when initializing the pointer.

### 7.2 Using Function Pointers<a name="7.2"></a>
[Go to top](#top)

This module aims to implement a function using function pointers. The function implemented is similar to `count_if()`, which is part of `<algorithm>`.

### 7.3 Object Slicing & Polymorphism<a name="7.3"></a>
[Go to top](#top)

Adding the keyword `virtual` before methods belonging to a class, prompts `c++` to create a function pointer table, to ensure the correct function is used in a parent/child class situation.

Declaring a variable of the superclass as a subclass (see below), initializes the object using the copy constructor of the parent class, even when `virtual` functions are used.
``` c++
PARENT p1 = CHILD(); // In this case the parent copy constructor is used
```

Object slicing 
