/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:43 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 14:23:56 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
#define __SPAN_H__

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
	unsigned int _maxsize;
	std::vector<int> _spanVector;
public:
	unsigned int getMaxSize() const;
	unsigned int getCurrentSize() const;
	std::vector<int> getSpanVector() const;

	void addNumber(int number);
	void addByIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan() const;
	int longestSpan() const;
	
	class NoSpan: public std::exception {
	public:
		const char* what(void) const throw();
	};

	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& origin);
	~Span();
};

#endif