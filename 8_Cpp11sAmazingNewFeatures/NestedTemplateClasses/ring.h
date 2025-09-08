#pragma once
#include <iostream>
using namespace std;


template<class T>
class ring
{
public:
	class iterator;
};

template<class T>
class ring<T>::iterator // Definition of the nested class (belongs to ring). This also uses the template parameter T from ring<T>.
{
public:
    void print()
    {
        cout << "Hello from ring::iterator: " << T() << endl;
    }
};

