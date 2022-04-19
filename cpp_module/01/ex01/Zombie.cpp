/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:17:47 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 13:21:16 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string str) : name(str) {}

void Zombie::announce(void) {
	std::cout << name << " BraiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string str) {
	name = str;
}

Zombie::~Zombie(void) {
	std::cout << name << " is destroyed" << std::endl;
}

