//--------------------- File Information ---------------------
// File         : CustomObjectsasMapValues.cpp
// Author       : Rune Dirk Willen
// Date         : 21-07-2025
// Description  : Basic C++ program looking into custom 
//				  objects as map values.

// Include necessary headers and namespaces
#include <iostream>
#include <map>
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

	Person(const Person& other)
	{
		cout << "Copy constructor called" << endl;
		name = other.name;
		age = other.age;
	}

	Person(string name, int age) : name(name), age(age)
	{
	}

	void print()
	{
		cout << name << ": " << age << endl;
	}
};


int main()
{
	map<int, Person> people;

	people[1] = Person("Alice", 30);
	people[2] = Person("Bob", 25);
	people[3] = Person("Charlie", 35);

	people.insert(make_pair(4, Person("Diana", 28)));
	people.insert(make_pair(5, Person("Eve", 22)));

	for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
	{
		cout << "Key: " << it->first << ": " << flush;
		it->second.print();
	}

	return 0;
}