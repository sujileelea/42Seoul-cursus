/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:25 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:38:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void WrongCat::setType(const std::string type) {
	_type = "WrongCat_" + type;
}

void WrongCat::makeSound() const {
	std::cout << _type << " is making sound... Meow Meow Meow..." << std::endl;
}

WrongCat::WrongCat(): WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type) {
	_type = "WrongCat_" + type;
	std::cout << "WrongCat constructor with type \"" << type << "\" called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &origin) {
	*this = origin;
}

WrongCat& WrongCat::operator=(const WrongCat &origin) {
	if (this != &origin)
		WrongAnimal::operator=(origin);
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat " << _type << " destructor called" << std::endl;
}
