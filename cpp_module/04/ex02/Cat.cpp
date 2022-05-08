#include "Cat.hpp"

Cat::Cat()
{
	setType("Cat");
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& original) : Animal(original)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& original)
{
	Animal::operator=(original);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << _type << " : Meow..." << std::endl;
}
