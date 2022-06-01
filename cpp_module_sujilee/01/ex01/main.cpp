/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:24:05 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 13:25:20 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void) {
	int		num = 7;
	Zombie *zombies = zombieHorde(num, "zombie");

	for (int i = 0; i < num; i++) {
		zombies[i].announce();
	}
	delete[] zombies;

	return (0);
}