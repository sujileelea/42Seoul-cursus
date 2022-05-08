#include "Dog.hpp"

Dog::Dog()
{
	setType("Dog");
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& original) : Animal(original)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
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
