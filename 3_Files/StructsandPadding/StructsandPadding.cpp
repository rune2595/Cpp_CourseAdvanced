//--------------------- File Information ---------------------
// File         : StructsandPadding.cpp
// Author       : Rune Dirk Willen
// Date         : 15-07-2025
// Description  : Basic C++ program looking into structs and 
//                their padding.

// Include necessary headers and namespaces
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Person1
{
    char name[50];  // 50 bytes for name
    int age;        // 4 bytes for age
	double weight;  // 8 bytes for weight
};

#pragma pack(push, 1) // Disable padding for the following structs
struct Person2
{
    char name[50];  // 50 bytes for name
    int age;        // 4 bytes for age
    double weight;  // 8 bytes for weight
};
#pragma pack(pop) // Restore previous packing alignment

int main()
{
	Person1 person1;
    Person2 person2;

    cout << "Person 1 features\tSize of feature" << endl;
	cout << "=======================================" << endl;
	cout << "Name \t\t\t" << sizeof(person1.name) << " bytes" << endl;
	cout << "Age \t\t\t" << sizeof(person1.age) << " bytes" << endl;
	cout << "Weight \t\t\t" << sizeof(person1.weight) << " bytes" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Expected size:\t\t" << sizeof(person1.name)+sizeof(person1.age)+sizeof(person1.weight) << " bytes" << endl;
	cout << "Actual size:\t\t" << sizeof(person1) << " bytes" << endl;
	cout << endl;
	cout << "Person 2 features\tSize of feature" << endl;
	cout << "=======================================" << endl;
	cout << "Name \t\t\t" << sizeof(person2.name) << " bytes" << endl;
	cout << "Age \t\t\t" << sizeof(person2.age) << " bytes" << endl;
	cout << "Weight \t\t\t" << sizeof(person2.weight) << " bytes" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Expected size:\t\t" << sizeof(person2.name) + sizeof(person2.age) + sizeof(person2.weight) << " bytes" << endl;
	cout << "Actual size:\t\t" << sizeof(person2) << " bytes" << endl;
   
    return 0;
}

