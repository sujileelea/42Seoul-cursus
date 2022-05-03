/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:51:45 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/03 09:51:55 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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