/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:23:59 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/23 16:25:16 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* arr, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void	increase(T& val)
{
	val++;
}

template <typename T>
void	decrease(T& val)
{
	val--;
}

template <typename T>
void	printVal(T& val)
{
	std::cout << val << std::endl;
}

#endif