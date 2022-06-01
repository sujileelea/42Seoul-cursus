/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:10:57 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:36:57 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void b_call(const Bureaucrat& b, void (Bureaucrat::*f)(void)) {
	try {
		(*(const_cast<Bureaucrat*>(&b)).*f)();
		std::cout << b << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void b_make(const std::string& name, const int& grade) {
	try {
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(void) {
	Bureaucrat sujilee("sujilee", 1);
	Bureaucrat kchoi("kchoi", 150);

	std::cout << sujilee << kchoi << std::endl;

	std::cout << sujilee.getName() << " - increment from " << sujilee.getGrade() << std::endl;
	b_call(sujilee, &Bureaucrat::incrementGrade);
	std::cout << kchoi.getName() << " - decrement from " << kchoi.getGrade() << std::endl;
	b_call(kchoi, &Bureaucrat::decrementGrade);
	std::cout << std::endl;

	std::cout << sujilee.getName() << " - decrement from " << sujilee.getGrade() << std::endl;
	b_call(sujilee, &Bureaucrat::decrementGrade);
	std::cout << sujilee.getName() << " - decrement from " << sujilee.getGrade() << std::endl;
	b_call(sujilee, &Bureaucrat::decrementGrade);
	std::cout << std::endl;
	std::cout << kchoi.getName() << " - increment from " << kchoi.getGrade() << std::endl;
	b_call(kchoi, &Bureaucrat::incrementGrade);
	std::cout << kchoi.getName() << " - increment from " << kchoi.getGrade() << std::endl;
	b_call(kchoi, &Bureaucrat::incrementGrade);

	std::cout << "constructor with 0, 151 and error" << std::endl;
	b_make("too high", 0);
	b_make("too low", 151);
	std::cout << std::endl;
	return 0;
}