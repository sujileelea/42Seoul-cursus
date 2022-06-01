/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:58 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:38:59 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
private:
	Brain* _brain;
public:
	void setType(const std::string type);
	void makeSound() const;
	Brain* getBrain() const;
	void setBrain(Brain* const brain);

	Dog();
	Dog(std::string type);
	Dog(const Dog &origin);
	Dog& operator=(const Dog &origin);
	~Dog();
};

#endif