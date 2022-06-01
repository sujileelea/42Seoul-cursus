#include "Fixed.hpp"

int Fixed::getRawBits() const {
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	fixedPointValue = raw;
}

bool Fixed::operator>(Fixed const &ref) const {
	return this->getRawBits() > ref.getRawBits();
}

bool Fixed::operator<(const Fixed &ref) const {
	return this->getRawBits() < ref.getRawBits();
}

bool Fixed::operator>=(const Fixed &ref) const {
	return this->getRawBits() >= ref.getRawBits();
}

bool Fixed::operator<=(const Fixed &ref) const {
	return this->getRawBits() <= ref.getRawBits();
}

bool Fixed::operator==(const Fixed &ref) const {
	return this->getRawBits() == ref.getRawBits();
}

bool Fixed::operator!=(const Fixed &ref) const {
	return this->getRawBits() != ref.getRawBits();
}

Fixed Fixed::operator+(const Fixed &ref) {
	Fixed ret;
	
	ret.setRawBits(this->getRawBits() + ref.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(const Fixed &ref) {
	Fixed ret;
	
	ret.setRawBits(this->getRawBits() - ref.getRawBits());
	return (ret);
}

Fixed Fixed::operator*(const Fixed &ref) {
	Fixed ret;
	
	ret.setRawBits((this->getRawBits() * ref.getRawBits()) >> fractionalBits);
	return (ret);
}

Fixed Fixed::operator/(const Fixed &ref) {
	Fixed ret;
	
	ret.setRawBits((this->getRawBits() / ref.getRawBits()) << fractionalBits);
	return (ret);
}

Fixed& Fixed::operator++() {
	++this->fixedPointValue;
	return (*this);
}

Fixed& Fixed::operator--() {
	--this->fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed ret(*this);
	operator++();
	return (ret);
}

Fixed Fixed::operator--(int) {
	Fixed ret(*this);
	operator--();
	return (ret);
}

Fixed& Fixed::min(Fixed &ref1, Fixed &ref2) {
	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref2);
	return (ref1);
}

Fixed& Fixed::max(Fixed &ref1, Fixed &ref2) {
	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref1);
	return (ref2);
}

const Fixed& Fixed::min(Fixed const &ref1, Fixed const &ref2) {
	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref2);
	return (ref1);
}

const Fixed& Fixed::max(Fixed const &ref1, Fixed const &ref2) {
	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref1);
	return (ref2);
}

float Fixed::toFloat() const {
	float retf = (float)fixedPointValue / (1 << fractionalBits);
	return retf;
}

int Fixed::toInt() const {
	return fixedPointValue >> fractionalBits;
}

Fixed::Fixed() : fixedPointValue(0) { }

Fixed::Fixed(const int i) {
	fixedPointValue = i << fractionalBits;
}

Fixed::Fixed(const float f) {
	fixedPointValue = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &origin) {
	*this = origin;
}

Fixed& Fixed::operator=(const Fixed &ref) {
	setRawBits(ref.getRawBits());
	return *this;
}

Fixed::~Fixed() { }

std::ostream& operator<<(std::ostream& out, const Fixed &ref) {
	out << ref.toFloat();
	return out;
}
