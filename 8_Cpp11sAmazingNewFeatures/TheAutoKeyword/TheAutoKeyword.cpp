//--------------------- File Information ---------------------
// File         : TheAutoKeyword.cpp
// Author       : Rune Dirk Willen
// Date         : 18-08-2025
// Description  : Basic C++ program working with decltype and
//				  typeID.

// Include necessary headers and namespaces
#include <iostream>
#include <typeinfo>
using namespace std;

template <class T, class S> // Function template to add two values of potentially different types
auto test(T value1, S value2) -> decltype(value1 + value2)
{
	return value1 + value2;
}

int getValue()
{
	return 42;
}

auto getAutoValue() -> decltype(getValue())
{
	return getValue();
}


int main()
{
	auto value = 10; // 'value' is of type int
	cout << typeid(value).name() << endl; // Output the type of 'value'

	auto text = "Hello, World!"; // 'text' is of type const char*
	cout << typeid(text).name() << endl; // Output the type of 'text'

	cout << test(10, 5.5) << " is of type '" << typeid(test(10, 5.5)).name() << "'" << endl; // Output the type of the result of test(10, 5.5)
	
	cout << getAutoValue() << " is of type '" << typeid(getAutoValue()).name() << "'" << endl; // Output the type of the result of getAutoValue()

	return 0;
}