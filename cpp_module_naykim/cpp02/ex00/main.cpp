#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << "a.getRawBits: " << a.getRawBits() << std::endl;
	std::cout << "b.getRawBits: " << b.getRawBits() << std::endl;
	std::cout << "c.getRawBits: " << c.getRawBits() << std::endl;
	
	a.setRawBits(100);
	std::cout << std::endl << "after a.setRawBits(100)" << std::endl;
	std::cout << "a.getRawBits: " << a.getRawBits() << std::endl;
	std::cout << "b.getRawBits: " << b.getRawBits() << std::endl;
	std::cout << "c.getRawBits: " << c.getRawBits() << std::endl;

	return 0;
}