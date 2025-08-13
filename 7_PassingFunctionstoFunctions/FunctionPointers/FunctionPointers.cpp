//--------------------- File Information ---------------------
// File         : FunctionPointers.cpp
// Author       : Rune Dirk Willen
// Date         : 13-08-2025
// Description  : Basic C++ program working with function 
//				  pointer.

// Include necessary headers and namespaces
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool match(string test, int length)
{
	return test.size() == length;
}

int countStrings(vector<string> words, int length, bool (*match)(string, int))
{
	int counter = 0;
	for(int i = 0; i < words.size(); i++)
	{
		if(match(words[i], length))
		{
			counter++;
		}
	}

	return counter;
}

int main()
{
	// Initialize a string
	vector<string> words = { "cat", "dog", "fish", "bat", "ant", "bee" };

	// Test the match function
	cout << match("cat", 3) << endl; // Should print 1 (true)

	// Use the match function with count_if to count words of size 3
	cout << count_if(words.begin(), words.end(), [](const string& str) { return str.size() == 3; }) << endl; // Should print 5
	//cout << *words.begin() << endl;


	// Use the countStrings function to count words of certain length
	cout << countStrings(words, 4, match) << endl;




	return 0;
}
