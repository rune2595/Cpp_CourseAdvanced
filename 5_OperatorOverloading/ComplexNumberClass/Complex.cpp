//--------------------- File Information ---------------------
// File         : Complex.cpp
// Author       : Rune Dirk Willen
// Date         : 31-07-2025
// Description  : Implementation of the Complex class.

#include <iostream>
#include "Complex.h"

using namespace std;

namespace rdw
{

// Implementation of free standing functions
ostream& operator<<(ostream& out, const Complex& c)
{
	out << c.getReal() << " + " << c.getImag() << "i";
	return out;
}

Complex operator+(const Complex& c1, const Complex& c2)
{
	return Complex(c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag());
}

Complex operator+(const Complex& c1, double d)
{
	return Complex(c1.getReal() + d, c1.getImag());
}

Complex operator+(double d, const Complex& c1)
{
	return Complex(c1.getReal() + d, c1.getImag());
}

Complex operator-(const Complex& c1, const Complex& c2)
{
	return Complex(c1.getReal() - c2.getReal(), c1.getImag() - c2.getImag());
}

Complex operator-(const Complex& c1, double d)
{
	return Complex(c1.getReal() - d, c1.getImag());
}

Complex operator-(double d, const Complex& c1)
{
	return Complex(d - c1.getReal(), -c1.getImag());
}

Complex operator*(const Complex& c1, const Complex& c2)
{
	return Complex(c1.getReal() * c2.getReal() - c1.getImag() * c2.getImag(), c1.getReal() * c2.getImag() + c1.getImag() * c2.getImag());
}

Complex operator*(const Complex& c1, double d)
{
	return Complex(c1.getReal() * d, c1.getImag() * d);
}

Complex operator*(double d, const Complex& c1)
{
	return Complex(c1.getReal() * d, c1.getImag() * d);
}


// Implementation of the Complex class methods
Complex::Complex() : real(0), imag(0)
{
}

Complex::Complex(double real, double imag) : real(real), imag(imag)
{
}

Complex::~Complex()
{
}

const Complex& Complex::operator=(const Complex& other)
{

	if (this != &other) // Check for self-assignment
	{
		real = other.real;
		imag = other.imag;
	}

	return *this;
}

Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) // Copy constructor
{
}

void Complex::display()
{
	cout << real << " + " << imag << "i" << endl;
}

}

