#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref) : _type(ref._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& ref)
{
	_type = ref._type;
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return _type;
}

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

void	WrongAnimal::makeSound(void) const
{
	if (_type == "")
		std::cout << "? : ???" << std::endl;
	else
		std::cout << _type << " : Crrrrr!!!" << std::endl;
}
