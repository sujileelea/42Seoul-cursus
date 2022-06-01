/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:47:44 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 14:58:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	weapon = 0;
}

HumanB::HumanB(std::string name, Weapon weapon) : name(name) {
	this->weapon = &weapon;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack() {
	if (weapon == 0 || weapon->getType().length() == 0)
		std::cout << "all " << name << " has got is her courage" << std::endl;
	else
		std::cout << name << " attacks with her " << weapon->getType() << std::endl;
}

HumanB::~HumanB() {};