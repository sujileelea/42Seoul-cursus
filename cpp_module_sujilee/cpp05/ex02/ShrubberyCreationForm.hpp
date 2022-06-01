/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:17 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:14:18 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm: public Form {
private:
	std::string _target;
public:
	std::string getTarget() const;
	void setTarget(std::string& target);
	void execute(const Bureaucrat& executor) const;

	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& origin);
	~ShrubberyCreationForm();
};

#endif