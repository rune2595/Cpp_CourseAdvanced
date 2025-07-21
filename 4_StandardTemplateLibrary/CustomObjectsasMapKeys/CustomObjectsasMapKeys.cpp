//--------------------- File Information ---------------------
// File         : CustomObjectsasMapKeys.cpp
// Author       : Rune Dirk Willen
// Date         : 21-07-2025
// Description  : Basic C++ program looking into custom 
//				  objects as map key.

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
		name = other.name;
		age = other.age;
	}

	Person(string name, int age) : name(name), age(age)
	{
	}

	void print() const
	{
		cout << "Key: " << name << " " << age << flush;
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
	map<Person, int> people;

	people[Person("Alice", 30)] = 0;
	people[Person("Bob", 54)] = 1;
	people[Person("Karen", 30)] = 2;
	people[Person("Alice", 45)] = 3;

	for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++)
	{
		cout << "Value: " << it->second << ", " << flush;
		it->first.print();
		cout << endl;
	}

	return 0;
}