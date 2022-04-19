/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:39:14 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 14:36:10 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	private :
			std::string type;
	public :
			Weapon();
			Weapon(std::string type);
			const	std::string& getType() const;
			void	setType(std::string str);
			~Weapon();
};


#endif