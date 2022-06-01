/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:16 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/07 13:49:36 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref) {
	//자식 클래스는 부모 클래스를 상속 받고 있기 때문에 참조가 가능하다
	std::cout << "ScavTrap " << getName() << " copy constructor called" << std::endl;
	*this = ref;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref) {
	std::cout << "ScavTrap " << getName() << "assignation operator called" << std::endl;
	return *this;
}

void	ScavTrap::attack(std::string const& target) {
	std::cout << "ScavTrap " << getName() << "attacked " << target << std::endl;

	std::cout << getAttackDamage() << "points of Damage occured" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now GATE KEEPER MODE" << std::endl;
}

void	ScavTrap::printST() {
	std::cout << "NAME : " << getName() << std::endl;
	std::cout << "HP : " << getHitPoint() << std::endl;
	std::cout << "EP : " << getEnergyPoint() << std::endl;
	std::cout << "AD : " << getAttackDamage() << std::endl;
}