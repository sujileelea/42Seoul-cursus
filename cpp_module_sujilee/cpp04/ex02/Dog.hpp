/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:39:29 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:39:30 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog: public Animal {
public:
	void setType(const std::string type);
	void makeSound() const;

	Dog();
	Dog(std::string type);
	Dog(const Dog &origin);
	Dog& operator=(const Dog &origin);
	~Dog();
};

#endif