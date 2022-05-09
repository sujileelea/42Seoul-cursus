/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:23:15 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/08 14:32:15 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << _type << " : (WRONG CAT)" << std::endl;
}
