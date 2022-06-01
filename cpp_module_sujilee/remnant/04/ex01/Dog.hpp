/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:25:05 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/08 14:26:29 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(const Dog& original);
		~Dog();

		Dog&				operator=(const Dog& original);
		void				makeSound() const;
		void				addIdea(std::string idea);
		const std::string&	getIdea(unsigned int idx) const;
};

#endif
