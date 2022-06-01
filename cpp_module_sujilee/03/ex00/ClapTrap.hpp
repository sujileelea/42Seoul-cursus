/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:32:03 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/20 16:25:10 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
			std::string		_name;
			unsigned int	_hitPoint;		//HP
			unsigned int	_energyPoint;	//EP
			unsigned int	_attackDamage;	//AD
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& original);
			ClapTrap&	operator=(const ClapTrap& original);
			~ClapTrap();


			void	setName(std::string name);
			void	setHitPoint(unsigned int amount);
			void	setEnergyPoint(unsigned int amount);
			void	setAttackDamage(unsigned int amount);

			std::string	getName();
			unsigned int	getHitPoint();
			unsigned int	getEnergyPoint();
			unsigned int	getAttackDamage();

			void	attack(std::string const& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
			void	printStatus() const;
			

};





#endif