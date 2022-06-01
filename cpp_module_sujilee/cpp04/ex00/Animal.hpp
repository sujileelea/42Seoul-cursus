/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:37:32 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:37:33 by sujilee          ###   ########.fr       */
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
	virtual void makeSound() const;

	Animal();
	Animal(std::string type);
	Animal(const Animal &origin);
	Animal& operator=(const Animal &origin);
	virtual ~Animal();
};

#endif