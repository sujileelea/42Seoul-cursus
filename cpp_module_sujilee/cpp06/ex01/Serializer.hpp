/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:42:42 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/02 18:55:03 by sujilee          ###   ########.fr       */
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

	public:
		Serializer();								
		virtual ~Serializer();					
		Serializer(const Serializer& other);		
		Serializer& operator=(const Serializer& other);	

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif