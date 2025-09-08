//--------------------- File Information ---------------------
// File         : RangeBasedForLoops.cpp
// Author       : Rune Dirk Willen
// Date         : 18-08-2025
// Description  : Basic C++ program demonstrating range-based
//                for loops.

// Include necessary headers and namespaces
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	auto texts = { "Hello", "World", "from", "C++" };

	for (auto text : texts)
	{
		cout << text << " " << flush;
	}
	cout << endl;

	vector<int> numbers = { 1, 2, 3, 4, 5 };

	for (auto number : numbers)
	{
		cout << number << " " << flush;
	}
	cout << endl;

	string greeting = "Hello";
	for (auto character : greeting)
	{
		cout << character << flush;
	}
	cout << endl;

	return 0;
}

