/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:46:23 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/23 16:25:22 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T temp = a;

	a = b;
	b = temp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return a < b ? a : b;
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return a > b ? a : b;
}

#endif