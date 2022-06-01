/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:28:08 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 14:30:21 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

const std::string &Weapon::getType() const {
	const std::string &typeREF = type;

	return typeREF;
}

void	Weapon::setType(std::string str) {
	type = str;
}

Weapon::~Weapon() {}