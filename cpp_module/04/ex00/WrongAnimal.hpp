/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:23:11 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/08 14:24:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& original);
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& original);
		std::string		getType() const;
		void			setType(std::string type);
		void			makeSound() const;
};

#endif
