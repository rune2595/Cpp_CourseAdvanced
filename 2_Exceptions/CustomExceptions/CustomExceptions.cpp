//--------------------- File Information ---------------------
// File         : CustomExceptions.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program to demonstrate custom
//				  exceptions.

// Include necessary headers and namespaces
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "My custom exception occurred!";
	}
};

class TestException
{
public:
	void goesWrong()
	{
		throw MyException();
	}
};


int main()
{
	
	TestException test;

	try
	{
		test.goesWrong();
	}
	catch (MyException& e)
	{
		cout << "Caught MyException: " << e.what() << endl;
	}

	return 0;
}