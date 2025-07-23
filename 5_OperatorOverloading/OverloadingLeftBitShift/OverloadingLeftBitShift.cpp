//--------------------- File Information ---------------------
// File         : OverloadingLeftBitShift.cpp
// Author       : Rune Dirk Willen
// Date         : 23-07-2025
// Description  : Basic C++ program looking into overloading
//                the left bit shift operator for printing.

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

    ~Person()
    {
    }

    void printInfo()
    {
		cout << "Using printInfo method: " << flush;
        cout << id << ": " << name << endl;
    }

    const Person& operator=(const Person& other)
    {
        id = other.id;
        name = other.name;

        return *this; // Return the current object by reference
    }

    Person(const Person& other)
    {
        id = other.id;
        name = other.name;
    }

    friend ostream& operator<<(ostream& out, const Person& person)
    {
		cout << "Using overloaded operator<<: " << flush;
		out << person.id << ": " << person.name;
		return out; // Return the output stream to allow chaining
    }


};

int main()
{
	Person person1(1, "Alice");
	Person person2(2, "Bob");
	person1.printInfo();
	person2.printInfo();

    cout << endl;

	cout << person1 << " " << person2 << endl; // Using the overloaded operator<< to print


    return 0;
}

