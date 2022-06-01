/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:39:14 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/07 13:49:56 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

int main() {
	DiamondTrap	sujilee("sujilee");
	DiamondTrap	kchoi("kchoi");

	std::cout << std::endl;
	sujilee.whoAmI();
	kchoi.whoAmI();

	std::cout << std::endl;
	std::cout << std::endl;

	kchoi.printST();
	std::cout << std::endl;


	sujilee.attack(kchoi.getName());
	kchoi.takeDamage(sujilee.getAttackDamage());
	std::cout << std::endl;
	kchoi.printST();

	kchoi.beRepaired(10);
	std::cout << std::endl;
	kchoi.printST();


	sujilee.guardGate();
	kchoi.guardGate();
	std::cout << std::endl;
	sujilee.highFivesGuys();
	kchoi.highFivesGuys();

	return 0;
}