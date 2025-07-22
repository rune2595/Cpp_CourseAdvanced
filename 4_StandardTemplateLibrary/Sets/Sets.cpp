//--------------------- File Information ---------------------
// File         : Sets.cpp
// Author       : Rune Dirk Willen
// Date         : 22-07-2025
// Description  : Basic C++ program looking into sets.

// Include necessary headers and namespaces
#include <iostream>
#include <set>
using namespace std;

class Person
{
private:
	string name;
	int age;
	
public:
	Person() : name(""), age(0)
	{
	}
	
	Person(string name, int age) : name(name), age(age)
	{
	}

	void print() const
	{
		cout << "Name: " << name << "\t, Age: " << age << endl;
	}

	bool operator<(const Person& other) const
	{
		if (name == other.name)
		{
			return age < other.age;
		}
		else
		{
			return name < other.name;
		}
	}
};


int main()
{
	// A simple set of integers
	set<int> ages;

	ages.insert(30);
	ages.insert(25);
	ages.insert(40);
	ages.insert(30); // Duplicate, will not be added

	for (auto it = ages.begin(); it != ages.end(); ++it)
	{
		cout << *it << endl; // Looks like a pointer dereference, but is actually an overloaded operator for iterators
	}

	cout << "--------------------------" << endl;

	// A set of Person objects
	set<Person> people;

	people.insert(Person("Alice", 24));
	people.insert(Person("Bob", 30));
	people.insert(Person("Charlie", 22));
	people.insert(Person("Alice", 24)); // Duplicate, will not be added
	people.insert(Person("Bob", 25)); // Different age, will be added

	for (auto it = people.begin(); it != people.end(); ++it)
	{
		it->print(); // Calls the print method of Person
	}


	return 0;
}