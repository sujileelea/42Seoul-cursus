/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:39:32 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 19:03:03 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

int main() {

	const Animal* myCat = new Cat("myCat");
	const Animal* myDog = new Dog("myDog");

	std::cout << std::endl;
	myCat->makeSound();
	myDog->makeSound();
	std::cout << std::endl;

	delete myCat;
	delete myDog;

	return (0);
}