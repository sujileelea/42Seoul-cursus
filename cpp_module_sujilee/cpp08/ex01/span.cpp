/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:40 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 14:31:13 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

unsigned int Span::getMaxSize() const {
	return _maxsize;
}

unsigned int Span::getCurrentSize() const {
	return _spanVector.size();
}

std::vector<int> Span::getSpanVector() const {
	return _spanVector;
}

void Span::addNumber(int number) {
	if (getCurrentSize() == getMaxSize())
		throw std::out_of_range("spanVector is full");
	_spanVector.push_back(number);
}

void Span::addByIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::vector<int> tmp(begin, end);
	
	if (getMaxSize() - getCurrentSize() < tmp.size()) {
		throw std::out_of_range("Not enough storage");
	}
	//copy(원본 시작 반복자, 원본 끝 반복자, 복사받는 시작 반복자)
	copy(tmp.begin(), tmp.end(), std::back_inserter(this->_spanVector));
}

int Span::shortestSpan() const {
	std::vector<int> tmp = this->_spanVector;
	int ret = -1;

	if (_spanVector.size() <= 1)
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
	std::vector<int> tmp = this->_spanVector;
	
	if (_spanVector.size() <= 1)
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
		this->_spanVector.clear();
		copy(origin.getSpanVector().begin(), origin.getSpanVector().end(), this->_spanVector.begin());
	}
	return *this;
}

Span::~Span() {
	std::cout << "--[Span destructor called]--" << std::endl;
}
