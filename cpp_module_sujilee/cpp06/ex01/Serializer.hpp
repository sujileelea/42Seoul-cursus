/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:42:42 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/02 17:32:29 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

struct Data
{
	std::string name;
	int intVal;
	double doubleVal;
};

class Serializer
{
	// ****************[canonical class form]****************
public:
	Serializer();								// default constructor
	virtual ~Serializer();					// destructor
	Serializer(const Serializer& other);			// copy constructor
	Serializer& operator=(const Serializer& other);	// (copy) assignment operator
	// ******************************************************
public:
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

#endif