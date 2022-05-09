/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:24:55 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/08 14:33:18 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
	_brain = new Brain();
}

Cat::Cat(const Cat& original) : Animal(original)
{
	_brain = new Brain(*original._brain);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& original)
{
	Animal::operator=(original);
	_brain = original._brain;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << _type << " : meow~~~~" << std::endl;
}

void	Cat::addIdea(std::string idea)
{
	_brain->addIdea(idea);
}

const std::string&	Cat::getIdea(unsigned int idx) const
{
	return (_brain->getIdea(idx));
}
