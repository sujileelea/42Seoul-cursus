/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:11:44 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:41:09 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

#define SHRUBBERY "@->--"

class ShrubberyCreationForm : public Form {
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& original);
		void					execute(Bureaucrat const& executor) const;
};

#endif