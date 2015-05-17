#pragma once

#include <iostream>

class Complex {
private:
	double Re_;
	double Im_;
public:
	Complex(double Re = 0, double Im = 0) : Re_(Re), Im_(Im) {}
	Complex operator+(const Complex & z) const { return Complex(Re_+z.Re_, Im_+z.Im_); }
	Complex operator-(const Complex & z) const { return Complex(Re_-z.Re_, Im_-z.Im_); }
	Complex operator*(const Complex & z) const { return Complex(Re_*z.Re_-Im_*z.Im_, Re_*z.Im_+Im_*z.Re_); }
	Complex operator*(double a) const { return Complex(Re_*a, Im_*a); }
	Complex operator~() const { return Complex(Re_, -Im_); }
    double Re() const { return Re_; }
    double & Re() { return Re_; }
    double Im() const { return Im_; }
    double & Im() { return Im_; }
    friend Complex operator*(double a, const Complex & z) { return z * a; }
	friend std::ostream & operator<<(std::ostream & out, const Complex & z) {
    	out << "(" << z.Re_ << ", " << z.Im_ << ")";
	    return out;
    }
	friend std::istream & operator>>(std::istream & in, Complex & z) {
	    in >> z.Re_;
    	if (!in)
	    	return in;
    	in >> z.Im_;
	    return in;
    }
};
