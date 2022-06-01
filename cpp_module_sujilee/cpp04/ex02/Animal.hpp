/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:39:07 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:39:08 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <string>

class Animal {
protected:
	std::string _type;
public:
	std::string getType() const;
	void setType(const std::string type);
	virtual void makeSound() const = 0;

	Animal();
	Animal(std::string type);
	Animal(const Animal &origin);
	Animal& operator=(const Animal &origin);
	virtual ~Animal();
};

#endif