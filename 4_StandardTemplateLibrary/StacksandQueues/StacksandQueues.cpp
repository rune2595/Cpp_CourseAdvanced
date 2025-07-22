//--------------------- File Information ---------------------
// File         : StacksandQueues.cpp
// Author       : Rune Dirk Willen
// Date         : 22-07-2025
// Description  : Basic C++ program looking into stacks and
//				  queues.

// Include necessary headers and namespaces
#include <iostream>
#include <stack>
#include <queue>
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

	~Person()
	{
		// Destructor
	}

	void printInfo() const
	{
		cout << "Name: " << name << "\t, Age: " << age << endl;
	}
};


int main()
{
	// Working with stacks
	stack<Person> personStack;

	personStack.push(Person("John", 30));
	personStack.push(Person("Mark", 48));
	personStack.push(Person("Alice", 25));

	while (!personStack.empty())
	{
		Person& person = personStack.top();
		person.printInfo();
		personStack.pop();
	}


	// Working with queues
	queue<Person> personQueue;

	personQueue.push(Person("John", 30));
	personQueue.push(Person("Mark", 48));
	personQueue.push(Person("Alice", 25));

	while (!personQueue.empty())
	{
		Person& person = personQueue.front();
		person.printInfo();
		personQueue.pop();
	}

	return 0;
}

