/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 14:08:58 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "easyfind.hpp"

template<typename T>
void displayIterator(T iter, T end) {
	if (iter != end)
 		std::cout << "*iterator: " << *iter << std::endl;
	else
		std::cout << "iterator reached the end of container" << std::endl;
}

void findNumber(std::vector<int> v, int n) {
	
	std::vector<int>::iterator iter;

	std::cout << "LET'S FIND " << n << " IN V" << std::endl;
	try {
		iter = easyfind(v, n);
		std::cout << "found " << n << " in vector" << std::endl;
	}
	catch (std::exception& e) {
		iter = v.end();
		std::cout << e.what() << std::endl;
	}
	displayIterator(iter, v.end());
	std::cout << std::endl;
}

int	main() {
	std::vector<int> v;
	// std::vector<int>::iterator testIter;

	for (int i = 1; i < 60; i+=2)
		v.push_back(i);
	std::cout << "=====MY VECTOR=====> " << std::endl;
	for (unsigned long i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	findNumber(v, 41);
	findNumber(v, 42);
	findNumber(v, 43);

	// testIter = v.end();
	// std::cout << *testIter << std::endl;

	return 0;
}