/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:50:24 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/02 18:50:25 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

Base* generate() {
	int randomNum;
	Base* ret;

	randomNum = rand() % 3;
	if (randomNum == 0)
		ret = new A();
	else if (randomNum == 1)
		ret = new B();
	else
		ret = new C();
	return ret;
}

void identify(Base* p) {
	A* a;
	B* b;
	C* c;

	if ((a = dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	else if ((b = dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	else if ((c = dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception& e) {
		(void)e;
	}
	
	try {
		B& b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception& e) {
		(void)e;
	}

	try {
		C& c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception& e) {
		(void)e;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	Base* testptr;

	std::cout << "=================pointer" << std::endl;
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;

	std::cout << "=================reference" << std::endl;
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;

	return 0;
}