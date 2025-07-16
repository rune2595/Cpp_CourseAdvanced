//--------------------- File Information ---------------------
// File         : ParsingTextFiles.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program to demonstrate parsing
//                text files.

// Include necessary headers and namespaces
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string filename = "stats.txt"; // Name of the file to read
	ifstream inputFile; // Create an input file stream

	inputFile.open(filename); // Open the file

	if (!inputFile)
	{
		cout << "Error opening file: " << filename << endl;
		return 1; // Exit if the file cannot be opened
	}

	while (inputFile)
	{
		string line;
		getline(inputFile, line, ':');
		line.erase(remove(line.begin(), line.end(), '\n'), line.end());

		int population;
		inputFile >> population; // Read the population value

		inputFile >> ws; // Ignore any whitespace characters

		cout << line << " -- " << population << endl; // Output the line read from the file


	}


	inputFile.close();

	return 0;
}

