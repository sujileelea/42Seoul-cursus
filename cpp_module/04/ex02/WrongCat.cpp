#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	setType("WrongCat");
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& ref)
{
	WrongAnimal::operator=(ref);
	return *this;
}

void	WrongCat::makeSound(void) const
{
	if (_type == "")
		std::cout << "? : ???" << std::endl;
	else
		std::cout << _type << " : Meow..." << std::endl;
}
