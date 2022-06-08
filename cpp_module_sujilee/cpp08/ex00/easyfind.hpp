/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:46:31 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/08 13:46:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <stdexcept>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int n) {
	//find�� ù��°�� ��ġ�ϴ� ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ
	//find(���⼭����, �������, ��� ��ġ�ϴ°�)
	typename T::iterator ret = find(container.begin(), container.end(), n);

	if (ret == container.end())
	//runtime_error : ���ܷ� ���� ��ü ������ �����ϴ� Ŭ����
		throw std::runtime_error(std::to_string(n) + " is not in this container.");
	return ret;
}

#endif