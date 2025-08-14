//--------------------- File Information ---------------------
// File         : AbstractClasses.cpp
// Author       : Rune Dirk Willen
// Date         : 14-08-2025
// Description  : Basic C++ program working with abstract
//				  classes.

// Include necessary headers and namespaces
#include <iostream>
using namespace std;

class Machine
{
private:

public:
	virtual void identify() = 0; // Pure virtual function
	virtual void noise() = 0; // Pure virtual function
};

class Car : public Machine
{
private:
	

public:
	virtual void noise()
	{
		cout << "Vroom vroom!" << endl;
	}
};

class Volvo : public Car
{
private:
	string model;

public:
	Volvo(string model) : model(model)
	{
	}

	~Volvo()
	{
	}

	virtual void identify()
	{
		cout << "I am a Volvo " << model << endl;
	}

};

class Airplane : public Machine
{
private:

public:
	virtual void noise()
	{
		cout << "Whoosh!" << endl;
	}
};

class Boeing : public Airplane
{
private:
	string model;

public:
	Boeing(string model) : model(model)
	{
	}

	~Boeing()
	{
	}

	virtual void identify()
	{
		cout << "I am a Boeing " << model << endl;
	}
};

void runMachine(Machine& m)
{
	m.identify();
	m.noise();
}


int main()
{
	// Create and test Volvo class
	Volvo v("XC90");
	v.identify();
	v.noise();

	// Create and test Boeing class
	Boeing b("747");
	b.identify();
	b.noise();

	cout << "-----------------------------" << endl;

	// Create array of Machine pointers
	Machine* machines[2];
	machines[0] = &v; // Assign Volvo object to first element
	machines[1] = &b; // Assign Boeing object to second element

	// Loop through array and call identify and noise methods
	for (int i = 0; i < sizeof(machines) / sizeof(machines[0]); i++)
	{
		machines[i]->identify();
		machines[i]->noise();
	}

	cout << "-----------------------------" << endl;
	// Run the runMachine function with a Car and an Airplane through loop

	for (int i = 0; i < sizeof(machines) / sizeof(machines[0]); i++)
	{
		runMachine(*machines[i]);
	}

	return 0;
}

