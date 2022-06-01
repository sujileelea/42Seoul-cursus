/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:39:13 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:39:14 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"

class Cat: public Animal {
public:
	void setType(const std::string type);
	void makeSound() const;

	Cat();
	Cat(std::string type);
	Cat(const Cat &origin);
	Cat& operator=(const Cat &origin);
	~Cat();
};

#endif