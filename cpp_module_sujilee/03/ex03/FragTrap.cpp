/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:50:34 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/07 12:59:52 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout <<  "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref) {
	std::cout << "FragTrap " << getName() << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << getName() << " destructor called" << std::endl;
}

FragTrap&  FragTrap::operator=(const FragTrap& ref) {
	std::cout << "FragTrap " << getName() << " assignation operator called" << std::endl;
	return *this;
}

void		FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " : HIGHFIVES, GUYS!" << std::endl; 
}