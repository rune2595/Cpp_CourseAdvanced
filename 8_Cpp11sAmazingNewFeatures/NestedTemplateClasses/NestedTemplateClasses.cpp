//--------------------- File Information ---------------------
// File         : NestedTemplateClasses.cpp
// Author       : Rune Dirk Willen
// Date         : 08-09-2025
// Description  : Basic C++ program demonstrating nested
//				  template classes.

// Include necessary headers and namespaces
#include <iostream>
#include <typeinfo>
#include <string>
#include "ring.h"
using namespace std;

int main()
{
	
	ring<int>::iterator it; // The iterator needs to be aware of the type it is iterating over

	it.print();





	//ring<string> myRing(5); // Create a ring of strings with size 5

	//myRing.add("one");
	//myRing.add("two");
	//myRing.add("three");
	//myRing.add("four");
	//myRing.add("five");
	//myRing.add("six"); // This will overwrite "one"
	//myRing.add("seven"); // This will overwrite "two"


	//for (int i = 0; i < myRing.size(); i++)
	//{
	//	cout << myRing.get(i) << endl; // Print each element in the ring
	//}

	return 0;
}

