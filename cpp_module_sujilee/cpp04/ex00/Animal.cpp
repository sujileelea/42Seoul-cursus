/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:37:28 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:37:29 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(const std::string type) {
	_type = "Animal_" + type;
}

void Animal::makeSound() const {
	std::cout << _type << " is making sound... animalanimalanimal..." << std::endl;
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
