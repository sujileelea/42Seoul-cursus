/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:23:52 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/07 13:33:43 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
			FragTrap();
			FragTrap(std::string name);
			FragTrap(const FragTrap& ref);
			~FragTrap();

			FragTrap&  operator=(const FragTrap& ref);
			void		highFivesGuys(void);

};

#endif