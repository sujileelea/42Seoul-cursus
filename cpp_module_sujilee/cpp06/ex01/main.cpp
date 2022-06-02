/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:44:55 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/02 17:59:00 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Serializer serializer;
	Data data = {"sujilee", 29, 42.42};
	Data *reSerializedData;
	uintptr_t temp;

	
	temp = serializer.serialize(&data);
	// std::cout << *temp <<std::endl;

	//temp를 다시 Data*로 바꿈
	reSerializedData = serializer.deserialize(temp);
	std::cout << reSerializedData << std::endl;

	std::cout << "--------------------[Compare]-------------------" << std::endl;
	std::cout << "ptr :" << &data << "\t| " << "ptr :" << reSerializedData << std::endl;
	std::cout << "name :" << data.name << "\t\t| " << "name :" << reSerializedData->name << std::endl;
	std::cout << "intVal :" << data.intVal << "\t\t| " << "intVal :" << reSerializedData->intVal << std::endl;
	std::cout << "doubleVal :" << data.doubleVal << "\t| " << "doubleVal :" << reSerializedData->doubleVal << std::endl;

	return 0;
}