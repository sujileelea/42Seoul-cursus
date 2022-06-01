/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:03 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:43:56 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal("meta");
	const Animal *myDog = new Dog("myDog");
	const Animal *myCat = new Cat("myCat");
	const WrongAnimal *wrongAnimal = new WrongAnimal("wrongAnimal");
	const WrongAnimal *wrongcat = new WrongCat("wrongcat");

	std::cout << myCat->getType() << std::endl;
	std::cout << myDog->getType() << std::endl;
	myCat->makeSound();
	myDog->makeSound();
	meta->makeSound();
	
	delete meta;
	delete myCat;
	delete myDog;

	std::cout << "===================WRONG======================" << std::endl;
	std::cout << wrongAnimal->getType() << std::endl;
	std::cout << wrongcat->getType() << std::endl;
	wrongAnimal->makeSound();
	wrongcat->makeSound();

	delete wrongAnimal;
	delete wrongcat;

	return 0;
}