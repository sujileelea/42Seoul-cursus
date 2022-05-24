/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:29:21 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/23 16:29:25 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::string str[3] = { "lee-sin", "ezreal", "janna"};

	iter(str, 3, printVal);
	std::cout << std::endl;

	int	arr[5] = { 0, 1, 2, 41, 42 };

	iter(arr, 5, increase);
	iter(arr, 5, printVal);
	std::cout << std::endl;
	iter(arr, 5, decrease);
	iter(arr, 5, printVal);

	return 0;
}