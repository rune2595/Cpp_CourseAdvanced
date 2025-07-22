//--------------------- File Information ---------------------
// File         : Multimaps.cpp
// Author       : Rune Dirk Willen
// Date         : 22-07-2025
// Description  : Basic C++ program looking into multimaps.

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
	multimap<Person, int> people;

	people.insert(make_pair(Person("Bob", 43), 2));
	people.insert(make_pair(Person("Alice", 30), 0));
	people.insert(make_pair(Person("Kenneth", 18), 4));
	people.insert(make_pair(Person("Alice", 30), 6));

	// List all elements in the multimap
	for (multimap<Person, int>::iterator it = people.begin(); it != people.end(); it++)
	{
		cout << "Value: " << it->second << ", " << flush;
		it->first.print();
		cout << endl;
	}
	
	cout << endl;

	// Find all elements with the key "Alice" method 1
	pair<multimap<Person, int>::iterator, multimap<Person, int>::iterator> range = people.equal_range(Person("Alice", 30));

	for (multimap<Person, int>::iterator it = range.first; it != range.second; it++)
	{
		cout << "Value: " << it->second << ", " << flush;
		it->first.print();
		cout << endl;
	}

	cout << endl;

	// Find all elements with the key "Alice" method 2
	auto range2 = people.equal_range(Person("Alice", 30));

	for (auto it = range2.first; it != range2.second; it++)
	{
		cout << "Value: " << it->second << ", " << flush;
		it->first.print();
		cout << endl;
	}

	return 0;
}