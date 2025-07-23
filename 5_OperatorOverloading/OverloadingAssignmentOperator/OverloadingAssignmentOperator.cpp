//--------------------- File Information ---------------------
// File         : OverloadingAssignmentOperator.cpp
// Author       : Rune Dirk Willen
// Date         : 22-07-2025
// Description  : Basic C++ program looking into overloading
//                the assignment operator.

// Include necessary headers and namespaces
#include <iostream>
using namespace std;

// Define a class
class Person
{
private:
    int id;
    string name;

public:
    Person() : id(0), name("")
    {
    }

    Person(int id, string name) : id(id), name(name)
    {
    }

    void printInfo()
    {
        cout << id << ": " << name << endl;
    }
};



int main()
{
    Person person1(1, "Bob");
    person1.printInfo();
    
    
    
    return 0;
}

