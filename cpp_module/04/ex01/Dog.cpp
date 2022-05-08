#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
	_brain = new Brain();
}

Dog::Dog(const Dog& original) : Animal(original)
{
	_brain = new Brain(*original._brain);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& original)
{
	Animal::operator=(original);
	return *this;
}

void	Dog::makeSound() const
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
