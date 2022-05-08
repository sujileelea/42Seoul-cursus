#include "Dog.hpp"

Dog::Dog(void)
{
	setType("Dog");
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& ref) : Animal(ref)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
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
