/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:08:57 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/14 12:10:19 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

struct Data
{
	char test[10];
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif