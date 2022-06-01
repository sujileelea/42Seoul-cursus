/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:54 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 19:38:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::setType(const std::string type) {
	_type = "Dog_" + type;
}

void Dog::makeSound() const {
	std::cout << _type << " is making sound... BowWow BowWow BowWow..." << std::endl;
}

Brain* Dog::getBrain() const {
	return _brain;
}

void Dog::setBrain(Brain* const brain) {
	if (_brain)
		delete _brain;
	_brain = brain;
}

Dog::Dog(): Animal(), _brain(0) {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type): Animal(type), _brain(0) {
	_type = "Dog_" + type;
	_brain = new Brain();
	std::cout << "Dog constructor with type \"" << type << "\" called" << std::endl;
}

Dog::Dog(const Dog &origin): Animal(origin) {
	*this = origin;
}

Dog& Dog::operator=(const Dog &origin) {
	if (this != &origin) {
		Animal::operator=(origin);
		if (_brain)
			delete _brain;
		_brain = new Brain();
		*_brain = *origin.getBrain();
	}
	return (*this);
}

Dog::~Dog() {
	if (_brain)
		delete _brain;
	std::cout << "Dog " << _type << " destructor called" << std::endl;
}
