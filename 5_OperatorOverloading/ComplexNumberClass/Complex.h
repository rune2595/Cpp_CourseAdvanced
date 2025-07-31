//--------------------- File Information ---------------------
// File         : Complex.h
// Author       : Rune Dirk Willen
// Date         : 31-07-2025
// Description  : Header file for complex number class.


#pragma once

using namespace std;

namespace rdw
{

class Complex
{
private:
	double real;  // Real part of the complex number
	double imag;  // Imaginary part of the complex number

public:
	Complex(); // Default constructor initializes to 0 + 0i

	Complex(double real, double imag); // Constructor with parameters to set real and imaginary parts

	~Complex(); // Destructor

	const Complex& operator=(const Complex& other); // Assignment operator to copy values from another Complex object

	Complex(const Complex& other); // Copy constructor

	double getReal() const // Getter for the real part
	{
		return real;
	}

	double getImag() const
	{
		return imag;
	}

	void display(); // Method to display the complex number in the format "a + bi"
};

// Implementation of free standing functions
ostream& operator<<(ostream& out, const Complex& c);
Complex operator+(const Complex& c1, const Complex& c2); // Addition operator for complex numbers
Complex operator+(const Complex& c1, double d); // Addition operator for complex number and double
Complex operator+(double d, const Complex& c1); // Addition operator for double and complex number
Complex operator-(const Complex& c1, const Complex& c2); // Subtraction operator for complex numbers
Complex operator-(const Complex& c1, double d); // Addition operator for complex number and double
Complex operator-(double d, const Complex& c1); // Addition operator for double and complex number
Complex operator*(const Complex& c1, const Complex& c2); // Multiplication operator for complex numbers
Complex operator*(const Complex& c1, double d); // Multiplication operator for complex number and double
Complex operator*(double d, const Complex& c1); // Multiplication operator for double and complex number

}
