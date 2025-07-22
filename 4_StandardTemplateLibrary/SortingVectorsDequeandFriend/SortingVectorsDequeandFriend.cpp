//--------------------- File Information ---------------------
// File         : SortingVectorsDequeandFriend.cpp
// Author       : Rune Dirk Willen
// Date         : 22-07-2025
// Description  : Basic C++ program looking into sorting
//				  vectors, deques, and using friend functions.

// Include necessary headers and namespaces
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

class Person1
{
private:
	string name;
	int age;

public:
	Person1() : name(""), age(0)
	{
	}

	Person1(string name, int age) : name(name), age(age)
	{
	}

	~Person1()
	{
		// Destructor
	}

	void printInfo() const
	{
		cout << "Name: " << name << "\t, Age: " << age << endl;
	}

	bool operator<(const Person1& other) const
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

class Person2
{
private:
	string name;
	int age;

public:
	Person2() : name(""), age(0)
	{
	}

	Person2(string name, int age) : name(name), age(age)
	{
	}

	~Person2()
	{
		// Destructor
	}

	void printInfo() const
	{
		cout << "Name: " << name << "\t, Age: " << age << endl;
	}

	friend bool compare(const Person2& person1, const Person2& person2);
};

bool compare(const Person2 &person1, const Person2 &person2)
{
	if (person1.name == person2.name)
	{
		return person1.age < person2.age;
	}
	else
	{
		return person1.name < person2.name;
	}
}


int main()
{
	// Sorting a vector of Person1 objects using the overloaded operator<
	
	vector<Person1> people1;
	people1.push_back(Person1("Charlie", 35));
	people1.push_back(Person1("Alice", 30));
	people1.push_back(Person1("Charlie", 14));
	people1.push_back(Person1("Diana", 28));
	people1.push_back(Person1("Bob", 25));

	cout << "Unsorted vector of Person1 objects:" << endl;
	for (int i = 0; i < people1.size(); i++)
	{
		people1[i].printInfo();
	}

	cout << endl;
	
	sort(people1.begin(), people1.end());

	cout << "Sorted vector of Person1 objects by age:" << endl;
	for (int i = 0; i < people1.size(); i++)
	{
		people1[i].printInfo();
	}

	cout << endl;
	cout << "---------------------------------------------------------" << endl;

	// Sorting a vector of Person2 objects using a friend function
	vector<Person2> people2;
	people2.push_back(Person2("Charlie", 35));
	people2.push_back(Person2("Alice", 30));
	people2.push_back(Person2("Charlie", 14));
	people2.push_back(Person2("Diana", 28));
	people2.push_back(Person2("Bob", 25));

	cout << "Unsorted vector of Person2 objects:" << endl;
	for (int i = 0; i < people2.size(); i++)
	{
		people2[i].printInfo();
	}

	cout << endl;

	sort(people2.begin(), people2.end(), compare);

	cout << "Sorted vector of Person2 objects:" << endl;
	for (int i = 0; i < people2.size(); i++)
	{
		people2[i].printInfo();
	}

	cout << endl;
	cout << "---------------------------------------------------------" << endl;

	// Working with a deque of Person1 objects

	deque<Person1> peopleDeque1;

	peopleDeque1.push_back(Person1("Charlie", 35));
	peopleDeque1.push_back(Person1("Alice", 30));
	peopleDeque1.push_back(Person1("Charlie", 14));
	peopleDeque1.push_back(Person1("Diana", 28));
	peopleDeque1.push_back(Person1("Bob", 25));

	cout << "Using a deque as a stack:" << endl;
	while (!peopleDeque1.empty())
	{
		Person1& person = peopleDeque1.back();
		person.printInfo();
		peopleDeque1.pop_back();
	}

	cout << endl;
	deque<Person1> peopleDeque2;

	peopleDeque2.push_back(Person1("Charlie", 35));
	peopleDeque2.push_back(Person1("Alice", 30));
	peopleDeque2.push_back(Person1("Charlie", 14));
	peopleDeque2.push_back(Person1("Diana", 28));
	peopleDeque2.push_back(Person1("Bob", 25));

	cout << "Using a deque as a queue:" << endl;
	while (!peopleDeque2.empty())
	{
		Person1& person = peopleDeque2.front();
		person.printInfo();
		peopleDeque2.pop_front();
	}

	return 0;
}

