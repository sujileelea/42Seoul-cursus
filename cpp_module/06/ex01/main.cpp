/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:10:46 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/14 12:10:51 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
    Data data = {"test"};

    std::cout << "data addr : " << &data<< std::endl;

    uintptr_t addr = serialize(&data);
    std::cout << "serialize addr : " << addr << std::endl;

    Data* temp = deserialize(addr);
    std::cout << "deserialize addr : " << temp << std::endl;

    return 0;
}