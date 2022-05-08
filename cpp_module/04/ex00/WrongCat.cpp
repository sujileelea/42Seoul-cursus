#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	setType("WrongCat");
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& original) : WrongAnimal(original)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& original)
{
	WrongAnimal::operator=(original);
	return *this;
}

void	WrongCat::makeSound() const
{
	if (_type == "")
		std::cout << "? : ???" << std::endl;
	else
		std::cout << _type << " : Meow..." << std::endl;
}
