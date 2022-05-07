/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:09:53 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/07 13:32:29 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap : public FragTrap, public ScavTrap {
		private:
				std::string _name;
		public:
				DiamondTrap();
				DiamondTrap(std::string name);
				DiamondTrap(const DiamondTrap& ref);
				~DiamondTrap();

				DiamondTrap&  operator=(const DiamondTrap &ref);
				void		 attack(std::string const& target);
				void printStatus() const;
				void		whoAmI();

};


#endif
