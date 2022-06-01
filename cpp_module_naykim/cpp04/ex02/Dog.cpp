#include "Dog.hpp"

void Dog::setType(const std::string type) {
	_type = "Dog_" + type;
}

void Dog::makeSound() const {
	std::cout <<  _type << " is making sound... BowWow BowWow BowWow..." << std::endl;
}

Dog::Dog(): Animal() {
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type): Animal(type) {
	_type = "Dog_" + type;
	std::cout << "Dog constructor with type \"" << type << "\" called" << std::endl;
}

Dog::Dog(const Dog &origin): Animal(origin) {
	*this = origin;
}

Dog& Dog::operator=(const Dog &origin) {
	if (this != &origin)
		Animal::operator=(origin);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog " << _type << " destructor called" << std::endl;
}
