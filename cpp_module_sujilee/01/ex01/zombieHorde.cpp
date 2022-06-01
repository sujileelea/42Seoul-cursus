/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:16:41 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 14:21:22 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *zombies = new Zombie[N];
	std::string	temp;

	for (int i = 0; i < N; i++) {
		temp = name;
		temp += i + '1';
		zombies[i].setName(temp);
	}
	return zombies;
}