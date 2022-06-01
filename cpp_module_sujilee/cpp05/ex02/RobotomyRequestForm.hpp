/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:11 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:14:12 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm: public Form {
private:
	std::string _target;
public:
	const std::string& getTarget() const;
	void setTarget(std::string& target);
	void execute(const Bureaucrat& executor) const;

	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);
	~RobotomyRequestForm();
};

#endif