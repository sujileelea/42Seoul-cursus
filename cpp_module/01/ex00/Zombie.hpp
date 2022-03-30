/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:09:09 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/30 17:49:07 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMEBIE_H
# define ZOMBIE_H

#include <iostream>
#include <cstring>
#include <cstdlib>

class Zombie {
	private:
			std::string name;
	public:
			Zombie(std::string str);
			void	announce(void);
			~Zombie(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif