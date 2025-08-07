//--------------------- File Information ---------------------
// File         : templateFunctions.cpp
// Author       : Rune Dirk Willen
// Date         : 07-08-2025
// Description  : Basic C++ program working with template
// 		          functions.

// Include necessary headers and namespaces
#include <iostream>
using namespace std;

template<class class1>
void print(class1 obj1)
{
	cout << "The input is: " << obj1 << endl; // assuming stream insertion operator is implemented
}

int main()
{
	print(10); // Output: The input is: 10
	print("Hello"); // Output: The input is: Hello

	return 0;
}