//--------------------- File Information ---------------------
// File         : OverloadingLeftBitShift.cpp
// Author       : Rune Dirk Willen
// Date         : 31-07-2025
// Description  : Basic C++ program working with a self-
//				  defined complex number class.

// Include necessary headers and namespaces
#include <iostream>
#include "Complex.h"
using namespace std;
using namespace rdw;

int main()
{
	
	// Initialize a complex number
	Complex num1(3.0, 4.0);
	num1.display(); // Display the complex number

	// Use copy constructor to create a new complex number
	Complex num2 = num1; // Copy constructor
	num2.display(); // Display the copied complex number
	
	// Use assignment operator to assign a new value to num2
	num2 = Complex(5.0, 6.0);
	num2.display(); // Display the newly assigned complex number

	// Initialize another complex number
	Complex num3;
	num3.display(); // Display the default complex number (0 + 0i)
	
	cout << num1 << endl; // Display num1 using overloaded << operator


	// Demonstrate the overloaded addition operator
	cout << num1 + num2 << endl; // Display the result of num1 + num2
	cout << num1 + 5.8 << endl; // Display the result of num1 + 5.0

	// Demonstrate the overloaded subtraction operator
	cout << num1 - num2 << endl; // Display the result of num1 - num2
	cout << num1 - 5.8 << endl; // Display the result of num1 - 5.8
	cout << 5.8 - num1 << endl; // Display the result of 5.8 - num1

	// Demonstrate the overloaded multiplication operator
	cout << num1 * num2 << endl; // Display the result of num1 * num2
	cout << num1 * 5.8 << endl; // Display the result of num1 * 5.8
	cout << 5.8 * num1 << endl; // Display the result of 5.8 * num1

	return 0;
}

