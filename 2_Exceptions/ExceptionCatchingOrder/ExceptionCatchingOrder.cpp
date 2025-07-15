//--------------------- File Information ---------------------
// File         : ExceptionCatchingOrder.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program to demonstrate exception
//				  catching order.

// Include necessary headers and namespaces
#include <iostream>
#include <exception>
using namespace std;

// Function throwind artificial exceptions
void goesWrong()
{
	bool error1Occured = true;
	bool error2Occured = false;

	if (error1Occured)
	{
		cout << "Should throw a bad_alloc exception" << endl;
		throw bad_alloc(); // Throwing a bad_alloc exception
	}

	if (error2Occured)
	{
		cout << "Should throw a generic exception" << endl;
		throw exception(); // Throwing a generic exception
	}
}

int main()
{
	try
	{
		goesWrong();
	}
	catch (bad_alloc& e) // Catching specific exception first
	{
		cout << "Caught a bad_alloc exception: " << e.what() << endl;
	}
	catch (exception& e) // Catching parent class exception last
	{
		cout << "Caught a generic exception: " << e.what() << endl;
	}
	

	return 0;
}