/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:13:15 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 16:54:22 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void) {
	Form target_sujilee("target_sujilee", 5, 1);
	Form target_kchoi("target_kchoi", 140, 130);
	Bureaucrat gosu("gosu", 2);
	Bureaucrat chobo("chobo", 120);

	std::cout << "target_sujilee: " << target_sujilee;
	std::cout << "target_kchoi: " << target_kchoi;
	std::cout << "gosu: " << gosu;
	std::cout << "chobo: " << chobo << std::endl;

	gosu.signForm(target_kchoi);
	// gosu.signForm(target_sujilee);
	std::cout << std::endl;
	chobo.signForm(target_kchoi);
	chobo.signForm(target_sujilee);
	std::cout << std::endl;

	std::cout << "target_sujilee: " << target_sujilee;
	std::cout << "target_kchoi: " << target_kchoi;
	std::cout << std::endl;

	return 0;
}