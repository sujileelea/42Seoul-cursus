/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:25:45 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/08 14:34:09 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << _type << " :meow~~~~" << std::endl;
}
