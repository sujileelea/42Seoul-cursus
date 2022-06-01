#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {
private:
	int fixedPointValue;
	static const int fractionalBits = 8;
public:
	int getRawBits() const;
	void setRawBits(int const raw);

	Fixed();
	Fixed(const Fixed &origin);
	Fixed& operator=(const Fixed &ref);
	~Fixed();
};

#endif