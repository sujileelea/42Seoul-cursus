/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:13:41 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/07 13:38:58 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	_name = "default";
	setName(_name + "_clap_name");
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(), FragTrap()
{
	_name = name;
	setName(_name + "_clap_name");
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref) : ClapTrap(ref), _name(ref._name)
{
	*this = ref;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap <" << _name << "> destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& ref)
{
	_name = ref._name;
	ClapTrap::operator=(ref);
	return *this;
}

void	DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name : " << _name << std::endl
	<< "ClapTrap name : " << getName() << std::endl;
}