/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:24:39 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/08 14:32:59 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& original) : _type(original._type)
{
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& original)
{
	_type = original._type;
	return *this;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::setType(std::string type)
{
	_type = type;
}

void	Animal::makeSound() const
{
	std::cout << _type << "all animal has it's sound..." << std::endl;
}
