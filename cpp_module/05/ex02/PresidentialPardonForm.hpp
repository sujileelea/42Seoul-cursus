/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:04:57 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:40:27 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& original);
		void					execute(Bureaucrat const& executor) const;
};

#endif