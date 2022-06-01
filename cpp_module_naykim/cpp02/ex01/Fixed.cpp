#include "Fixed.hpp"

int Fixed::getRawBits() const {
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	fixedPointValue = raw;
}

int Fixed::toInt() const {
	return fixedPointValue >> fractionalBits;
}

float Fixed::toFloat() const {
	float retf = (float)fixedPointValue / (1 << fractionalBits);
	return retf;
}

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = i << fractionalBits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &origin) {
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed& Fixed::operator=(const Fixed &ref) {
	std::cout << "Assignation operator called" << std::endl;
	fixedPointValue = ref.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fixed &ref) {
	out << ref.toFloat();
	return out;
}
