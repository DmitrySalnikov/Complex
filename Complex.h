#pragma once

#include <iostream>

class Complex {
private:
	double Re_;
	double Im_;
public:
	Complex(double Re = 0, double Im = 0) : Re_(Re), Im_(Im) {}
	Complex & operator+=(const Complex & z) { Re_ += z.Re_; Im_ += z.Im_; return *this; }
	Complex & operator-=(const Complex & z) { Re_ -= z.Re_; Im_ -= z.Im_; return *this; }
	Complex & operator*=(const Complex & z) { 
        double re_ = Re_; 
        Re_ = Re_*z.Re_-Im_*z.Im_; 
        Im_ = re_*z.Im_+Im_*z.Re_; 
        return *this; 
    }
	Complex operator~() const { return Complex(Re_, -Im_); }
    double Re() const { return Re_; }
    double & Re() { return Re_; }
    double Im() const { return Im_; }
    double & Im() { return Im_; }
	friend Complex operator+(Complex const & a, Complex const & z) { 
        Complex t = a;
        return t += z; 
    }
	friend Complex operator-(Complex const & a, Complex const & z) { 
        Complex t = a;
        return t -= z; 
    }
    friend Complex operator*(Complex const & a, Complex const & z) { 
        Complex t = a;
        return t *= z; 
    }
	friend std::ostream & operator<<(std::ostream & out, Complex const & z) {
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
