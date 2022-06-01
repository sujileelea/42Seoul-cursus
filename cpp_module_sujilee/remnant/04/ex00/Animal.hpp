/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:22:40 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/08 14:23:49 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(const Animal& original);
		virtual ~Animal();

		Animal&			operator=(const Animal& original);
		std::string		getType() const;
		void			setType(std::string type);
		virtual void	makeSound() const;
};

#endif
