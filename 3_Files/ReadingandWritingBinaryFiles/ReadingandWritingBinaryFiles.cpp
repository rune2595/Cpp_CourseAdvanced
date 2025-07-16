//--------------------- File Information ---------------------
// File         : ReadingandWritingBinaryFiles.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program looking into binary files.

// Include necessary headers and namespaces
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#pragma pack(push, 1) // Disable padding for the following structs
struct Person
{
	char name[50];  // 50 bytes for name
	int age;        // 4 bytes for age
	double height;  // 8 bytes for height
};
#pragma pack(pop) // Restore previous packing alignment

int main()
{
	// ------ Create a binary file and write a struct to it ------
	
	Person someone = { "John Doe", 30, 186 };

	ofstream outFile;
	string filename = "person.bin";
	
	outFile.open(filename, ios::binary); // Open file in binary mode

	if (!outFile.is_open())
	{
		cout << "Could not create file: " + filename << endl;
		return 1; // Exit with error code
	}

	outFile.write(reinterpret_cast<char*>(&someone), sizeof(Person)); // Write the Person struct to the binary file
	outFile.close(); // Close the file after writing


	// ------ Read the binary file and display the struct content ------
	
	Person someoneElse;

	ifstream inFile;

	inFile.open(filename, ios::binary); // Open file in binary mode

	if (!inFile.is_open())
	{
		cout << "Could not read file: " + filename << endl;
		return 2; // Exit with error code
	}

	inFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person)); // Read the Person struct from the binary file

	inFile.close(); // Close the file after reading

	cout << "Name: " << someoneElse.name << ", Age: " << someoneElse.age << ", Height: " << someoneElse.height << " cm" << endl; // Display the content of the struct

	return 0;
}

