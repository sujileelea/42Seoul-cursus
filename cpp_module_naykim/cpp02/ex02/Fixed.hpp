#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixedPointValue;
	static const int fractionalBits = 8;
public:
	bool operator>(const Fixed &ref) const;
	bool operator<(const Fixed &ref) const;
	bool operator>=(const Fixed &ref) const;
	bool operator<=(const Fixed &ref) const;
	bool operator==(const Fixed &ref) const;
	bool operator!=(const Fixed &ref) const;

	Fixed operator+(const Fixed &ref);
	Fixed operator-(const Fixed &ref);
	Fixed operator*(const Fixed &ref);
	Fixed operator/(const Fixed &ref);

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed &ref1, Fixed &ref2);
	static Fixed& max(Fixed &ref1, Fixed &ref2);
	static const Fixed& min(const Fixed &ref1, const Fixed &ref2);
	static const Fixed& max(const Fixed &ref1, const Fixed &ref2);

	int getRawBits() const;
	void setRawBits(int const raw);
	int toInt() const;
	float toFloat() const;
	
	Fixed();
	explicit Fixed(const int i);
	explicit Fixed(const float f);
	Fixed& operator=(const Fixed &ref);
	Fixed(const Fixed &origin);
	~Fixed();
};

std::ostream& operator<<(std::ostream& out, const Fixed &ref);

#endif