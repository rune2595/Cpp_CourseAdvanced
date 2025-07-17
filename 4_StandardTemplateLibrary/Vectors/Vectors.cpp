//--------------------- File Information ---------------------
// File         : Vectors.cpp
// Author       : Rune Dirk Willen
// Date         : 17-07-2025
// Description  : Basic C++ program looking into vectors.

// Include necessary headers and namespaces
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> strings; // Declare a vector of integers

	strings.push_back("one"); // Add elements to the vector
	strings.push_back("two");
	strings.push_back("three");
	strings.push_back("four");
	strings.push_back("five");
	strings.push_back("six");
	strings.push_back("seven");
	strings.push_back("eight");
	strings.push_back("nine");
	strings.push_back("ten");

	cout << "Print vector elements using a traditional for loop" << endl;
	cout << "--------------------------------------------------" << endl;
	for (int i = 0; i < strings.size(); i++)
	{
		cout << "Element " << i + 1 << " is\t: " << strings[i] << endl;
	}

	cout << endl << "Print vector elements using an iterator for loop" << endl;
	cout << "--------------------------------------------------------" << endl;

	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		cout << "Element " << (it - strings.begin()) + 1 << " is\t: " << *it << endl;

		if ((it - strings.begin()) % 2 == 1 && it + 1 < strings.end()) // Check if the index is odd
		{
			it += 1; // Skip the next element
		}
	}

    return 0;
}

