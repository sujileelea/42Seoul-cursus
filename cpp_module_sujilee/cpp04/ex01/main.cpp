/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:39:01 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 20:23:07 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

void test_normal(void) {
    const Animal* myCat = new Cat("myCat");
    const Animal* myDog = new Dog("myDog");

    std::cout << std::endl;
    myCat->makeSound();
    myDog->makeSound();
    std::cout << std::endl;
    std::cout << std::endl;
    delete myCat;
    delete myDog;
}

void test_array(void) {
    Animal* meta[B_COUNT / 20];
    Animal* ctmp = new Cat("tmp");
    Animal* dtmp = new Dog("tmp");

    for (int i = 0 ; i < B_COUNT / 20; ++i) {
        std::cout << i << std::endl;
        if (!(i % 2)) {
            meta[i] = new Cat(*(dynamic_cast<Cat *>(ctmp)));
        } else {
            meta[i] = new Dog(*(dynamic_cast<Dog *>(dtmp)));
        }
    }
    for (int i = 0 ; i < B_COUNT / 20; ++i) {
        std::cout << i << std::endl;
        delete meta[i];
    }
	std::cout << "=======delete instance========" << std::endl;
    delete ctmp;
    delete dtmp;
}


int main(void) {
    std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');
    test_normal();
    std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');
    test_array();
    std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');

    return 0;
}

