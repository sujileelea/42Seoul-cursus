/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:55:16 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 14:58:46 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		Weapon club = Weapon("crude spiked club");

		HumanA kchoi("kchoi", club);
		kchoi.attack();
		club.setType("some other type of club");
		kchoi.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB suji("suji");
		suji.setWeapon(club);
		suji.attack();
		club.setType("");
		suji.attack();
	}
}