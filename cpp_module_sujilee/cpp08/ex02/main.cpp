/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:47 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 13:48:59 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "test basic and stack function==================" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "print mstack using iterator====================" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		*it += 100;
		++it;
	}
	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "print mstack using reverse_iterator============" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "print mstack using const_iterator==============" << std::endl;
	MutantStack<int>::const_iterator cit = mstack.cbegin();
	MutantStack<int>::const_iterator cite = mstack.cend();
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		// *cit -= 100;
		++cit;
	}
	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "test deep copy=================================" << std::endl;
	MutantStack<int> s(mstack);
	std::stack<int> ss(mstack);
	it = mstack.begin();
	ite = mstack.end();
	std::cout << "MutantStack mstack: " << std::endl;
	while (it != ite)
	{
		*it -= 100;
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "MutantStack s: " << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << "stack ss: " << std::endl;
	while (!ss.empty())
	{
		std::cout << ss.top() << std::endl;
		ss.pop();
	}

	return 0;
}
