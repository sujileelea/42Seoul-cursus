/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:32:03 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/07 13:44:26 by sujilee          ###   ########.fr       */
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
			ClapTrap();	//디폴트 생성자?
			ClapTrap(std::string name); //기본 생성자?
			ClapTrap(const ClapTrap& ref);  //복사 생성자
			ClapTrap&	operator=(const ClapTrap& ref); //대입 연산자
			~ClapTrap(); //소멸자


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