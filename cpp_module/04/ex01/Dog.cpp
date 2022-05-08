#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
	_brain = new Brain();
}

Dog::Dog(const Dog& ref) : Animal(ref)
{
	_brain = new Brain(*ref._brain);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& ref)
{
	Animal::operator=(ref);
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << _type << " : Bow-wow!!!" << std::endl;
}

void	Dog::addIdea(std::string idea)
{
	_brain->addIdea(idea);
}

const std::string&	Dog::getIdea(unsigned int idx) const
{
	return (_brain->getIdea(idx));
}
