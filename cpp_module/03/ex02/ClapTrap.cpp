/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:47:37 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/06 17:51:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(10) {
	std::cout << "ClapTrap default contructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(10) {
	std::cout << "ClapTrap  <" << _name << "> contructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) {
	std::cout << "ClapTrap <" << ref._name << "> copy contstructor called" << std::endl;
	*this = ref;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap <" << _name << "> desctructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref) {
	std::cout << "ClapTrap <" << ref._name << "> assignation operator called" << std::endl;
	_name = ref._name;
	_hitPoint = ref._hitPoint;
	_energyPoint = ref._energyPoint;
	_attackDamage = ref._attackDamage;
	return *this;
}

void	ClapTrap::setName(std::string name) {
		_name = name;
}

void	ClapTrap::setHitPoint(unsigned int amount) {
		_hitPoint = amount;
}

void	ClapTrap::setEnergyPoint(unsigned int amount) {
		_energyPoint = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
		_attackDamage = amount;
}





std::string	ClapTrap::getName() {
	return  _name;
}

unsigned int	ClapTrap::getHitPoint(void) {
	return _hitPoint;
}

unsigned int	ClapTrap::getEnergyPoint(void) {
	return _energyPoint;
}

unsigned int	ClapTrap::getAttackDamage(void) {
	return _attackDamage;
}




void	ClapTrap::attack(std::string const& target) {
	std::cout << "ClapTrap <" << _name << "> attacked " << target << std::endl;
	std::cout << _attackDamage << "poits of Damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap <" << _name << "> take damage of " << amount << "points" << std::endl;

	if (_hitPoint <= amount) {
		_hitPoint = 0;
		std::cout << "ClapTrap <" << _name << "> died" << std::endl;
	} 
	else {
		_hitPoint -= amount;
		std::cout << "ClapTrap <" << _name << ">'s HP : " << _hitPoint << std::endl;
 	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	_hitPoint += amount;
	std::cout << "Clap Trap <" << _name << "> was repaired by " << amount << " points" << std::endl;
	std::cout << "ClapTrap <" << _name << ">'s HP : " << _hitPoint << std::endl; 
}


void	ClapTrap::printStatus() const {
	std::cout << "NAME : " << _name << std::endl;
	std::cout << "HP : " << _hitPoint << std::endl;
	std::cout << "EP : " << _energyPoint << std::endl;
	std::cout << "AD : " << _attackDamage << std::endl;
}

