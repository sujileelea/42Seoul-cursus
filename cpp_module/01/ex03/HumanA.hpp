/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:34:14 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 14:42:49 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private :
			std::string name;
			Weapon &weapon;
	public : 
			HumanA(std::string name, Weapon &weapon);
			void	attack();
			~HumanA();
};


#endif