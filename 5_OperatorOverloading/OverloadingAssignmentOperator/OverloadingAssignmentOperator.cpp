//--------------------- File Information ---------------------
// File         : OverloadingAssignmentOperator.cpp
// Author       : Rune Dirk Willen
// Date         : 23-07-2025
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
    
    ~Person()
    {
		cout << "Destructor called for " << name << endl;
	}

    void printInfo()
    {
        cout << id << ": " << name << endl;
    }

    const Person& operator=(const Person& other)
    {
        cout << "Assignment operator called" << endl;
        id = other.id;
        name = other.name;

		return *this; // Return the current object by reference
    }

    Person(const Person& other)
    {
        cout << "Copy constructor called" << endl;
		id = other.id;
		name = other.name;
    }
};

int main()
{
    Person person1(1, "Bob");
	cout << "Person 1 info: " << endl;
    person1.printInfo();

	cout << endl;

	Person person2(2, "Alice");
    cout << "Person 2 info: " << endl;
	person2.printInfo();
	person2 = person1; // Assignment operator is called here
	cout << "Person 2 info after assignment: " << endl;
	person2.printInfo(); // Should print Bob's info
    
	cout << endl;

	Person person3; // Default constructor
	person3 = person2 = person1; // Chained assignment
	cout << "Person 3 info after chained assignment: " << endl;
	person3.printInfo(); // Should print Bob's info

    cout << endl;

	Person person4 = person1; // Copy constructor is called here
	cout << "Person 4 info after copy: " << endl;
	person4.printInfo(); // Should print Bob's info

	cout << endl;

	Person person5; // Default constructor
	person5.operator=(person4); // Assignment operator is called here
	cout << "Person 5 info after assignment: " << endl;
	person5.printInfo(); // Should print Bob's info

    return 0;
}

