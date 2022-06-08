/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 13:46:28 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "easyfind.hpp"

template<typename T>
void displayIterator(T it, T end) {
	if (it != end)
 		std::cout << "*iterator: " << *it << std::endl;
	else
		std::cout << "iterator reached the end of container" << std::endl;
}

void findNumber(std::vector<int> v, int n) {
	std::vector<int>::iterator it;

	std::cout << "LET'S FIND " << n << " IN V" << std::endl;
	try {
		it = easyfind(v, n);
		std::cout << "found " << n << " in vector" << std::endl;
	}
	catch (std::exception& e) {
		it = v.end();
		std::cout << e.what() << std::endl;
	}
	displayIterator(it, v.end());
	std::cout << std::endl;
}

int	main() {
	std::vector<int> v;

	for (int i = 1; i < 60; i+=2)
		v.push_back(i);
	std::cout << "=====v: " << std::endl;
	for (unsigned long i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	findNumber(v, 41);
	findNumber(v, 42);
	findNumber(v, 43);

	return 0;
}