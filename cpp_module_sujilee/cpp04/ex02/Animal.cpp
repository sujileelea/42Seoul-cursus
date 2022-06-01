/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:39:05 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:39:06 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(const std::string type) {
	_type = "Animal_" + type;
}

Animal::Animal(): _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): _type("Animal_" + type) {
	std::cout << "Animal constructor with type \"" << type << "\" called" << std::endl;
}

Animal::Animal(const Animal &origin) {
	*this = origin;
}

Animal& Animal::operator=(const Animal &origin) {
	if (this != &origin)
		this->_type = origin.getType();
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal " << _type << " destructor called" << std::endl;
}
