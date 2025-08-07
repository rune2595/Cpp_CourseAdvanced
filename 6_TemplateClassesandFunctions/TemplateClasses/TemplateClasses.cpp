//--------------------- File Information ---------------------
// File         : TemplateClasses.cpp
// Author       : Rune Dirk Willen
// Date         : 07-08-2025
// Description  : Basic C++ program working with template
// 		          classes.

// Include necessary headers and namespaces
#include <iostream>
using namespace std;

template<class class1, class class2>
class testClass
{
private:
    class1 obj1;
    class2 obj2;

public:
    // below is optional
    testClass(class1 obj1, class2 obj2)
    {
        this->obj1 = obj1;
        this->obj2 = obj2;
    }

    void print()
    {
        cout << "The first input is: " << obj1 << " and the second input is: " << obj2 << endl; // assuming stream insertion operator is implemented
    }
};


int main()
{
    
	testClass<int, string> obj1(10, "Hello");

	obj1.print(); // Output: The first input is: 10 and the second input is: Hello

    return 0;
}

