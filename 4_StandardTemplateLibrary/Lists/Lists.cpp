//--------------------- File Information ---------------------
// File         : Lists.cpp
// Author       : Rune Dirk Willen
// Date         : 17-07-2025
// Description  : Basic C++ program looking into lists.

// Include necessary headers and namespaces
#include <iostream>
#include <list>
using namespace std;

void displayMenu(int menu)	// Function to display the menu options
{
	switch (menu)	// Switch statement to handle different menu options
	{
	case 1:
		cout << "1. Define new list" << endl;
		cout << "2. Add element to list" << endl;
		cout << "3. Delete element from list" << endl;
		cout << "4. Change element in list" << endl;
		cout << "5. Exit" << endl;
		break;
	case 2:
		cout << "Do you want to define new list?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		break;
	}
}
int getUserInput() // Function to get user input
{
	int input = 0;
	cin >> input;

	return input;
}
void endProgram()	// Function to end the program
{
	cout << "Thank you for using the program, bye!" << endl;	// Thank the user
}
void displayList(list<int> List) // Function to display the current list
{
	cout << "( " << flush;
	for (list<int>::iterator it = List.begin(); it != List.end(); it++)
	{
		cout << *it << " " << flush;
	}
	cout << ")" << endl;
}


int main()
{
	bool isRunning = true;								// Variable to control the program loop
	bool validIndex = false;						    // Variable to check if the index is valid for adding elements

	list<int> List = { 1, 2, 3, 4, 5 };					// Create and initialize a list with values
	int listLength = List.size();						// Get the size of the list
	int selection1;
	int selection2;

	while (isRunning)
	{
		displayMenu(1);									// Call the function to display the menu
		validIndex = false;								// Reset validIndex for the next iteration
		cout << "What do you want to do? " << flush;

		selection1 = getUserInput();					// Call the function to get user input

		switch (selection1)
		{
		case 1:
			cout << "Current list is: " << flush;
			displayList(List);							// Display the current list
			displayMenu(2);								// Display the submenu for defining a new list
			selection2 = getUserInput();				// Get user input for defining a new list

			switch (selection2)
			{
			case 1:
				cout << "List length: " << flush;
				listLength = getUserInput();			// Get the length of the new list from user input

				List.clear();							// Clear the current list
				for (int i = 0; i < listLength; i++)	// Loop to add elements to the new list
				{
					int element;
					cout << "Enter element " << (i + 1) << ": ";
					cin >> element;						// Read each element from user input
					List.push_back(element);			// Add the element to the new list
				}
				cout << "New list defined: " << endl;	// Confirm that the new list has been defined
				displayList(List);						// Display the new list
				break;
			case 2:
				cout << "Keeping the current list." << endl;	// If user chooses not to define a new list
				break;
			}
			break;

		case 2:
			while (!validIndex)
			{
				cout << "Enter index: " << flush;
				int indexToAdd = getUserInput();			// Get the index where the user wants to add an element

				if (indexToAdd < 0 || indexToAdd > listLength)	// Check if the index is valid
				{
					cout << "Invalid index! Please enter a valid index between 1 and " << listLength << "." << endl;
				}
				else
				{
					validIndex = true;						// Set validIndex to true if the index is valid
					cout << "Enter element to add: ";
					int elementToAdd = getUserInput();		// Get the element to add to the list
					list<int>::iterator it = List.begin();	// Create an iterator for the list
					for (int i = 1; i < indexToAdd; i++)	// Loop to move the iterator to the specified index
					{
						it++;								// Increment the iterator
					}
					List.insert(it, elementToAdd);			// Insert the new element at the specified index
					listLength = List.size();				// Calculate the new size of the list
					cout << "Element added successfully!" << endl;
					displayList(List);						// Display the updated list
				}
			}
			break;
		case 3:
			while (!validIndex)
			{
				displayList(List);							// Display the current list
				cout << "Enter index to delete: " << flush;
				int indexToDelete = getUserInput();			// Get the index of the element to delete
				if (indexToDelete < 0 || indexToDelete >= listLength)	// Check if the index is valid
				{
					cout << "Invalid index! Please enter a valid index between 1 and " << listLength << "." << endl;
				}
				else
				{
					validIndex = true;						// Set validIndex to true if the index is valid
					list<int>::iterator it = List.begin();	// Create an iterator for the list
					for (int i = 1; i < indexToDelete; i++)	// Loop to move the iterator to the specified index
					{
						it++;								// Increment the iterator
					}
					List.erase(it);							// Erase the element at the specified index
					listLength = List.size();				// Calculate the new size of the list
					cout << "Element deleted successfully!" << endl;
					displayList(List);						// Display the updated list
				}
			}

			break;
		case 4:
			while (!validIndex)
			{
				displayList(List);							// Display the current list
				cout << "Enter index to change: " << flush;
				int indexToChange = getUserInput();			// Get the index of the element to change
				if (indexToChange < 0 || indexToChange >= listLength)	// Check if the index is valid
				{
					cout << "Invalid index! Please enter a valid index between 1 and " << listLength << "." << endl;
				}
				else
				{
					validIndex = true;						// Set validIndex to true if the index is valid
					list<int>::iterator it = List.begin();	// Create an iterator for the list
					for (int i = 1; i < indexToChange; i++)	// Loop to move the iterator to the specified index
					{
						it++;								// Increment the iterator
					}
					cout << "Enter new element: ";
					int newElement = getUserInput();		// Get the new element to change
					*it = newElement;						// Change the element at the specified index
					cout << "Element changed successfully!" << endl;
					displayList(List);						// Display the updated list
				}
			}
			break;
		case 5:
			cout << "Exiting..." << endl;
			isRunning = false;
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
	}

	endProgram();					// Call the function to end the program

	return 0;
}

