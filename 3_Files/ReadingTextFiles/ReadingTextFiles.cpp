//--------------------- File Information ---------------------
// File         : ReadingTextFiles.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program to demonstrate reading
//                text files.

// Include necessary headers and namespaces
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileName[] = { "example.txt", "test", "loop_example.txt"};	// Declare a string to hold the file name
	string file;														// Declare a string to hold the current file name
	string line;														// Declare a string to hold each line of the file
	ifstream inFile;													// Declare an input file stream
	int numberOfFiles = sizeof(fileName) / sizeof(string);				// Calculate the number of files

	for (int i = 0; i < numberOfFiles; i++)
	{
		file = fileName[i];												// Assign the current file name to a variable
		inFile.open(file);												// Open current file for reading

		if (inFile.is_open())											// Check if the file is open
		{
			cout << "Reading file " << i+1 << " of " << numberOfFiles << ": " << file << endl;
			cout << "----------------------------------------" << endl;

			while (inFile)
			{
				getline(inFile, line);									// Read a line from the file
				cout << line << endl;									// Output the line to the console
			}

			inFile.close();												// Close the file after reading
		}
		else															// Error handling
		{
			cout << "Error opening file " << i+1 << " of " << numberOfFiles << ": " << file << endl;
			cout << endl;
			continue;
		}
	}

	return 0;
}

