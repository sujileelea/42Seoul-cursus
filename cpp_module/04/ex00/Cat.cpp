#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& ref)
{
	Animal::operator=(ref);
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << _type << " : Meow..." << std::endl;
}
