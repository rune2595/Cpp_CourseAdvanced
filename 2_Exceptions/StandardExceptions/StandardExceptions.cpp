//--------------------- File Information ---------------------
// File         : StandardExceptions.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program to demonstrate exception
//                handling.

// Include necessary headers and namespaces
#include <iostream>
using namespace std;

class CanGoWrong
{
public:
	CanGoWrong()
	{
		char* pMemory = new char[999999999999]; // Allocate a large amount of memory
		delete [] pMemory; // Delete the allocated memory
	}
};


int main()
{
	
	try
	{
		CanGoWrong wrong; // Create an instance of CanGoWrong
	}
	catch (bad_alloc& e)
	{
		cout << "Memory allocation failed: " << e.what() << endl;
	}
	




	return 0;
}
