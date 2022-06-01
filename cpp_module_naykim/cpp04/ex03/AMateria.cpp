#include "AMateria.hpp"

std::string const &AMateria::getType() const {
	return _type;
}

AMateria::AMateria(): _type("") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type) {
	std::cout << "AMateria constructor with type \"" << type << "\" called" << std::endl;
}

AMateria::AMateria(const AMateria& copy) {
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& origin) {
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &origin)
		_type = origin.getType();
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria " << _type << " destructor called" << std::endl;
}