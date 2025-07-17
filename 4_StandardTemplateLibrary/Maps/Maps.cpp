//--------------------- File Information ---------------------
// File         : Maps.cpp
// Author       : Rune Dirk Willen
// Date         : 17-07-2025
// Description  : Basic C++ program looking into maps.

// Include necessary headers and namespaces
#include <iostream>
#include <map>
using namespace std;

// Function prototypes (if needed) can be declared here
void displayMenu()	// Function to display the menu options
{
	cout << "1. Search database" << endl;
	cout << "2. Add record" << endl;
	cout << "3. Delete record" << endl;
	cout << "4. Update record" << endl;
	cout << "5. Exit" << endl;
}
int getUserInput() // Function to get user input
{
	int input = 0;	// Variable to store user input
	cin >> input;

	return input;	// Return the user input
}
int getAge() // Function to get user input
{
	cout << "Please enter age: " << flush;

	int input;	// Variable to store user input
	cin >> input;

	return input;	// Return the user input
}
string getName() // Function to get user input
{
	cout << "Please enter name: " << flush;

	string input;	// Variable to store user input
	cin >> input;

	return input;	// Return the user input
}
void endProgram()	// Function to end the program
{
	cout << "Thank you for using the program, bye!" << endl;	// Thank the user
}

int main()
{
	bool isRunning = true;								// Variable to control the program loop
	bool validIndex = false;						    // Variable to check if the index is valid for adding elements
	int selection1 = 0;									// Variable to store user selection
	string name;
	int age;
	map<string, int> database;						// Create a map to store string keys and int values
	database["Mike"] = 25;							// Add a record to the map
	database["Alice"] = 30;							// Add another record to the map
	database["Bob"] = 67;							// Add yet another record to the map

	while (isRunning)
	{
		cout << endl;
		displayMenu();									// Call the function to display the menu
		cout << endl;
		validIndex = false;								// Reset validIndex for the next iteration
		cout << "What do you want to do? " << flush;

		selection1 = getUserInput();					// Call the function to get user input

		switch (selection1)	// Switch statement to handle user selection
		{
			case 1:	// Case for searching the database
				name = getName();	// Call the function to get the name from user input

				if(database.find(name) != database.end())	// Check if the name exists in the map
				{
					cout << "Found " << name << " with age: " << database[name] << endl;	// Output the found record
				}
				else
				{
					cout << "No record found for " << name << endl;	// Output if no record is found
				}
				break;
			case 2:	// Case for adding a record
				name = getName();	// Call the function to get the name from user input
				age = getAge();	// Call the function to get the age from user input

				database.insert(make_pair(name, age));	// Insert the new record into the map
				cout << "Record added: " << name << " with age " << age << endl;

				break;
			case 3:	// Case for deleting a record
				name = getName();	// Call the function to get the name from user input
				
				if(database.find(name) != database.end())
				{
					database.erase(name);
					cout << "Record deleted: " << name << endl;
				}
				else
				{
					cout << "No record found for " << name << endl;
				}

				break;
			case 4:	// Case for updating a record
				name = getName();	// Call the function to get the name from user input
				age = getAge();	// Call the function to get the age from user input

				if(database.find(name) != database.end())	// Check if the name exists in the map
				{
					database[name] = age;	// Update the age for the existing record
					cout << "Record updated: " << name << " with new age " << database[name] << endl;	// Output the updated record
				}
				else
				{
					cout << "No record found for " << name << ", go to 'add record'." << endl;	// Output if no record is found
				}
				break;
			case 5:	// Case for exiting the program
				isRunning = false;	// Set isRunning to false to exit the loop
				break;
			default:	// Default case for invalid input
				cout << "Invalid selection, please try again." << endl;
				break;
		} // End of switch statement



	}

	endProgram();					// Call the function to end the program

	return 0;
}