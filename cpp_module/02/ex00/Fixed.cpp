/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:46:48 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/03 10:18:08 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "default Contructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref) {
	std::cout << "copy Constructor called" << std::endl;
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref) {
	std::cout << "assignation Operator called" << std::endl;
	fixedPoint = ref.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "member function getRawBits called" << std::endl;
	return fixedPoint;
}

void	Fixed::setRawBits(int const raw) {
	fixedPoint = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}