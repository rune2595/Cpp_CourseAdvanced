//--------------------- File Information ---------------------
// File         : WritingTextFiles.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program to demonstrate writing
//                text files.

// Include necessary headers and namespaces
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outFile; // Create an output file stream object

	string fileName = "example.txt"; // Specify the file name

	outFile.open(fileName); // Open the file for writing

	if (outFile.is_open()) // Check if the file is successfully opened
	{
		outFile << "Hello, World!" << endl; // Write to the file
		outFile << "This is a text file created using C++." << endl;
		outFile << "Writing text files is easy!" << endl;
		
		outFile.close(); // Close the file
		cout << "File written successfully: " << fileName << endl;
	}
	else
	{
		cout << "Error opening file: " << fileName << endl; // Error handling
	}

	// Writing text file using a loop

	ofstream loopFile; // Create another output file stream object

	string loopFileName = "loop_example.txt"; // Specify the file name

	loopFile.open(loopFileName); // Open the file for writing

	string loopChar[4] = { "first", "second", "third", "fourth"}; // Initialize a string array

	if (loopFile.is_open()) // Check if the file is open
	{
		for (int i = 1; i < 5; i++)
		{
			loopFile << i << ". Added the " << loopChar[i-1] << " line to the file." << endl; // Write lines using a loop
		}
		loopFile.close();
		cout << "Loop file written successfully: " << loopFileName << endl;
	}
	else
	{
		cout << "Error opening file: " << loopFileName << endl; // Error handling
	}

	return 0;
}

