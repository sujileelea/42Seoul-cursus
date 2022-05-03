/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:37:26 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/03 10:45:31 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "default Constructor called" << std::endl;
}

Fixed::Fixed(const int digit) {
	std::cout << "Int Contructor called" << std::endl;
	fixedPoint = digit << fracBits; //소수 비트 부분만큼 밀어준다.
}

Fixed::Fixed(const float digit) {
	std::cout << "Float Contructor called" << std::endl;
	fixedPoint = (int)(digit * (1 << fracBits)); //지수부에 소수 비트만큼 곱해준다
}

Fixed::Fixed(const Fixed& ref) {
	std::cout << "copy Contructor called" << std::endl;
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref) {
	std::cout << "assignation Operator called" << std::endl;
	fixedPoint = ref.fixedPoint;
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "member function getRawBits called" << std::endl;
	return  fixedPoint;
}

void	Fixed::setRawBits(int const raw) {
	fixedPoint = raw;
}

int		Fixed::toInt() const {
	return fixedPoint >> fracBits; //다시 소수비트만큼 당겨온다
}

float	Fixed::toFloat() const {
	return (float)fixedPoint / (1 << fracBits);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& outStream, const Fixed& fixed) {
	outStream << fixed.toFloat();
	return outStream; //outStream을 반환해야 그 후에도 계속 쓸 수 있다.

}