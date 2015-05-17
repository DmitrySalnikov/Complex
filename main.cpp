#include "Complex.h"
#include <iostream>

int main() {
    using std::endl;
	Complex a(3.0, 4.0);
	Complex c;
    std::cout << "Enter complex number: \n";
	while (std::cin >> c) 
		std::cout << c << endl
			<< ~c << endl
			<< a << endl
			<< a + c << endl
			<< a - c << endl
			<< a * c << endl
			<< 2 * c << endl
			<< "Enter next complex number: \n";
    
    return 0;
}
