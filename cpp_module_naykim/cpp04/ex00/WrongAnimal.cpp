#include "WrongAnimal.hpp"

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(const std::string type) {
	_type = "WrongAnimal_" + type;
}

void WrongAnimal::makeSound() const {
	std::cout << _type << " is making sound... WrongAnimalWrongAnimalWrongAnimal..." << std::endl;
}

WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type("WrongAnimal_" + type) {
	std::cout << "WrongAnimal constructor with type \"" << type << "\" called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &origin) {
	*this = origin;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &origin) {
	if (this != &origin)
		this->_type = origin._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << _type << " destructor called" << std::endl;
}
