/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:47 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 14:54:48 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "==========test basic and stack function========" << std::endl;
	
	MutantStack<int> mStack;
	
	mStack.push(5);
	mStack.push(17);

	std::cout << "top: " << mStack.top() << std::endl;
	mStack.pop();
	std::cout << "current size: " << mStack.size() << std::endl;
	mStack.push(3);
	mStack.push(5);
	mStack.push(737);

	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "==========print mStack using iterator==========" << std::endl;
	MutantStack<int>::iterator it = mStack.begin();
	MutantStack<int>::iterator ite = mStack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		*it += 100;
		++it;
	}
	
	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "======print mStack using reverse_iterator=======" << std::endl;
	MutantStack<int>::reverse_iterator rit = mStack.rbegin();
	MutantStack<int>::reverse_iterator rite = mStack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "=======print mStack using const_iterator=======" << std::endl;
	MutantStack<int>::const_iterator cit = mStack.cbegin();
	MutantStack<int>::const_iterator cite = mStack.cend();
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		// *cit -= 100;
		++cit;
	}
	std::cout << std::endl << "===============================================" << std::endl;
	std::cout << "================test deep copy=================" << std::endl;
	MutantStack<int> s(mStack);
	std::stack<int> ss(mStack);
	it = mStack.begin();
	ite = mStack.end();
	std::cout << "MutantStack mStack: " << std::endl;
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
