/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:43:06 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 14:54:51 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB {
	private :
			std::string name;
			Weapon *weapon;
	public :
			HumanB();
			HumanB(std::string name);
			HumanB(std::string name, Weapon weapon);
			void	setWeapon(Weapon &weapon);
			void	attack();
			~HumanB();
};

#endif