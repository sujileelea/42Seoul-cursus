/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:11:00 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/30 17:36:03 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main()
{
	//const char *을 인자로 한 string 객체 생성자 자동 호출
	Zombie zombieKing("sujilee");
	//스택에 저장됐다가 main()의 return을 만나면 소멸자 호출
	zombieKing.announce();

	Zombie *zombieKnight = newZombie("kchoi");	
	//힙에 할당됐다가
	zombieKnight->announce();
	//여기서 해제되고 소멸자 호출
	delete zombieKnight;

	//함수 내에서 지역변수(스택)로 객체를 생성했다가 함수 반환 후 객체 소멸자 호출
	randomChump("Faker");
	
	return (0);
	
}