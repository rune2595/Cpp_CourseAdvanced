//--------------------- File Information ---------------------
// File         : ObjectSlicing.cpp
// Author       : Rune Dirk Willen
// Date         : 14-08-2025
// Description  : Basic C++ program working with object
//                slicing.

// Include necessary headers and namespaces
#include <iostream>
using namespace std;

// Parent class definition
class Parent
{
private:
	int parentValue;

public:
    Parent() : parentValue(0)
    {
    }

    Parent(const Parent& other)
    {
        parentValue = other.parentValue;
        cout << "Parent copy constructor called." << endl;
	}

    virtual ~Parent()
    {
    }
    
    virtual void print()
    {
		cout << "Parent value: " << parentValue << endl;
    }
};

class Child : public Parent
{
private:
	int childValue;

public:
    Child() : childValue(1)
    {
    }

    void print()
    {
		cout << "Child value: " << childValue << endl;
    }
};



int main()
{
    Child c1;
	Parent& p1 = c1;        // Object slicing does not occur here
	p1.print();             // Calls Child's print method due to polymorphism via virtual function

	Parent p2 = Child();    // Object slicing occurs here as well
	p2.print();             // Calls Parent's print method, not Child's

    return 0;
}

