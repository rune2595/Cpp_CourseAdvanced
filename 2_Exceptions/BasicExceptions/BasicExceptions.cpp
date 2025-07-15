//--------------------- File Information ---------------------
// File         : BasicExceptions.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program to demonstrate exception
//                handling.

// Include necessary headers and namespaces
#include <iostream>
using namespace std;



// Function to demonstrate exception handling
void mightGoWrong()
{
	bool error1 = false; // Simulate an error condition
	bool error2 = true; // Simulate another condition

	if (error1)
	{
		throw "Something went wrong!"; // Throw an integer exception
	}

	if (error2)
	{
		throw string("Another error occurred!"); // Throw a string exception
	}

}
void usesMightGoWrong()
{
	mightGoWrong(); // Call the function that might throw an exception
}


// Main function
int main()
{
	try
	{
		usesMightGoWrong(); // Call the function that might throw an exception
	}
	catch (int e)
	{
		cout << "Error code: " << e << endl; // Catch the integer exception and print the error code
	}
	catch (char const* e)
	{
		cout << "Error message: " << e << endl; // Catch the string exception and print the error message
	}
	catch (string& e)
	{
		cout << "String error message: " << e << endl; // Catch the string exception and print the error message
	}

	cout << "Program continues after the exception." << endl; // Continue execution after handling the exception

	return 0;
}
