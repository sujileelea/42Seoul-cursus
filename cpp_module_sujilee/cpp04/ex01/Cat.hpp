/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:51 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:38:52 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
private:
	Brain* _brain;
public:
	void setType(const std::string type);
	void makeSound() const;
	Brain* getBrain() const;
	void setBrain(Brain* const brain);

	Cat();
	Cat(std::string type);
	Cat(const Cat &origin);
	Cat& operator=(const Cat &origin);
	~Cat();
};

#endif