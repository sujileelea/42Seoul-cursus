/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:04 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:14:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm: public Form {
private:
	std::string _target;
public:
	const std::string& getTarget() const;
	void setTarget(std::string& target);
	void execute(const Bureaucrat& executor) const;

	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& origin);
	~PresidentialPardonForm();
};

#endif