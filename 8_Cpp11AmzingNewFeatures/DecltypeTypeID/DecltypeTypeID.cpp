//--------------------- File Information ---------------------
// File         : DecltypeTypeID
// Author       : Rune Dirk Willen
// Date         : 18-08-2025
// Description  : Basic C++ program working with decltype and
//				  typeID.

// Include necessary headers and namespaces
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    string value;

	cout << typeid(value).name() << endl; // Output the type of 'value'

	decltype(value) newValue = "Hello, World!"; // Use decltype to declare newValue with the same type as value

	cout << typeid(newValue).name() << endl; // Output the type of 'newValue'

    return 0;
}


