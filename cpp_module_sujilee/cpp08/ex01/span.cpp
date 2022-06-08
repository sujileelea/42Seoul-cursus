/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:40 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 13:48:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

unsigned int Span::getMaxSize() const {
	return _maxsize;
}

unsigned int Span::getNowSize() const {
	return _store.size();
}

std::vector<int> Span::getStore() const {
	return _store;
}

void Span::addNumber(int number) {
	if (getNowSize() == getMaxSize())
		throw std::out_of_range("Storage is full");
	_store.push_back(number);
}

void Span::addByIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::vector<int> tmp(begin, end);
	
	if (getMaxSize() - getNowSize() < tmp.size()) {
		throw std::out_of_range("Not enough storage");
	}
	copy(tmp.begin(), tmp.end(), std::back_inserter(this->_store));
}

int Span::shortestSpan() const {
	std::vector<int> tmp = this->_store;
	int ret = -1;

	if (_store.size() <= 1)
		throw Span::NoSpan();
	sort(tmp.begin(), tmp.end());
	ret = *(tmp.begin() + 1) - *tmp.begin();
	for (std::vector<int>::iterator i = tmp.begin() + 1; i < tmp.end() - 1 && ret != 0; i++) {
		if (*(i + 1) - *i < ret)
			ret = *(i + 1) - *i;
	}
	return ret;
}

int Span::longestSpan() const {
	std::vector<int> tmp = this->_store;
	
	if (_store.size() <= 1)
		throw Span::NoSpan();
	sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}

const char* Span::NoSpan::what(void) const throw() {
	return "Not enough numbers(0 or 1).";
}

Span::Span(): _maxsize(0) {
	std::cout << "--[Span default constructor called]--" << std::endl;
}

Span::Span(unsigned int N): _maxsize(N) {
	std::cout << "--[Span constructor with N called]--" << std::endl;
}

Span::Span(const Span& copy) {
	std::cout << "--[Span copy constructor called]--" << std::endl;
	*this = copy;
}

Span& Span::operator=(const Span& origin) {
	std::cout << "--[Span assignation operator called]--" << std::endl;
	if (this != &origin) {
		this->_maxsize = origin.getMaxSize();
		this->_store.clear();
		copy(origin.getStore().begin(), origin.getStore().end(), this->_store.begin());
	}
	return *this;
}

Span::~Span() {
	std::cout << "--[Span destructor called]--" << std::endl;
}
