/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:36 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 14:50:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

#define COUNT 10000

int main(){
	Span basicSpan = Span(5);
	Span iterSpan = Span(COUNT + 5);
	Span wrongSpan = Span(3);

	std::cout << std::endl << "=======================================" << std::endl;
	std::cout << "[Basic test]" << std::endl;
	try {
		basicSpan.addNumber(5);
		basicSpan.addNumber(3);
		basicSpan.addNumber(17);
		basicSpan.addNumber(9);
		basicSpan.addNumber(11);
		for (unsigned long i = 0; i < basicSpan.getSpanVector().size(); i++) {
			std::cout << basicSpan.getSpanVector()[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "shortestspan: " << basicSpan.shortestSpan() << std::endl;
		std::cout << "longestspan: " << basicSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=======================================" << std::endl;



	std::cout << "[addByIterator test]" << std::endl;
	try {
		iterSpan.addNumber(1);
		iterSpan.addNumber(2);
		iterSpan.addNumber(3);
		std::cout << "before addByIterator iterSpan's size: " << iterSpan.getCurrentSize() << std::endl;

		std::vector<int> modelVector;
		
		srand((unsigned int)time(NULL));
		for (int i = 0; i < COUNT; i++)
			modelVector.push_back(rand() % (COUNT * 100));
		
		iterSpan.addByIterator(modelVector.begin(), modelVector.end());
		std::cout << "modelVector size: " << modelVector.size() << std::endl;
		std::cout << "after addByIterator iterSpan size: " << iterSpan.getCurrentSize() << std::endl;
		std::cout << "shortestspan: " << iterSpan.shortestSpan() << std::endl;
		std::cout << "longestspan: " << iterSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=======================================" << std::endl;
	std::cout << "[error test]" << std::endl;
	try {
		std::cout << "test addNumber() when Span is full" << std::endl;
		std::cout << "current size : " << basicSpan.getCurrentSize() << std::endl;
		basicSpan.addNumber(42);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "test shortestSpan() when wrongSpan is empty" << std::endl;
		std::cout << "shortestspan possible? : " << wrongSpan.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}