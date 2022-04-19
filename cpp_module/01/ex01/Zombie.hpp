/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:12:54 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 13:26:31 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private :
			std::string name;
	public :
			Zombie();
			Zombie(std::string name);
			void	announce();
			void	setName(std::string str);
			~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif