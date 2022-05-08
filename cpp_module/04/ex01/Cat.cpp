#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
	_brain = new Brain();
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	_brain = new Brain(*ref._brain);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& ref)
{
	Animal::operator=(ref);
	_brain = ref._brain;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << _type << " : Meow..." << std::endl;
}

void	Cat::addIdea(std::string idea)
{
	_brain->addIdea(idea);
}

const std::string&	Cat::getIdea(unsigned int idx) const
{
	return (_brain->getIdea(idx));
}
