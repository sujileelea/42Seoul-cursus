/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:57:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/20 16:26:00 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public :
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap& original);
			~ScavTrap();
			ScavTrap& operator=(const ScavTrap& original);

			void attack(std::string const& target);
			void guardGate();

};


#endif