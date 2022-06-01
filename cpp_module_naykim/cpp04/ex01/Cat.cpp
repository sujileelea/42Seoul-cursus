#include "Cat.hpp"

void Cat::setType(const std::string type) {
	_type = "Cat_" + type;
}

void Cat::makeSound() const {
	std::cout << _type << " is making sound... Meow Meow Meow..." << std::endl;
}

Brain* Cat::getBrain() const {
	return _brain;
}

void Cat::setBrain(Brain* const brain) {
	if (_brain)
		delete _brain;
	_brain = brain;
}

Cat::Cat(): Animal(), _brain(0) {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type): Animal(type), _brain(0) {
	_type = "Cat_" + type;
	_brain = new Brain();
	std::cout << "Cat constructor with type \"" << type << "\" called" << std::endl;
}

Cat::Cat(const Cat &origin): Animal(origin) {
	*this = origin;
}

Cat& Cat::operator=(const Cat &origin) {
	if (this != &origin) {
		Animal::operator=(origin);
		if (_brain)
			delete _brain;
		_brain = new Brain();
		*_brain = *origin.getBrain();
	}
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat " << _type << " destructor called" << std::endl;
}
