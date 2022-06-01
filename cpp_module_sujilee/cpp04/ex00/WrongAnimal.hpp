/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:10 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:38:11 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string _type;
public:
	std::string getType() const;
	void setType(const std::string type);
	void makeSound() const;

	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &origin);
	WrongAnimal& operator=(const WrongAnimal &origin);
	~WrongAnimal();
};

#endif