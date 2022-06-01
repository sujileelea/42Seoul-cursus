/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:03:33 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 09:35:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"


class Bureaucrat;


class Form {
	private:
			const std::string 	_name;
			bool				_isSigned;
			const int			_signGrade;
			const int			_executeGrade;
	public:
			Form();
			Form(std::string name, int signGrade, int executeGrade);
			Form(const Form& original);
			~Form();

			Form&	operator=(const Form& ref);
			std::string getName() const;
			bool		getSign() const;
			int			getSignGrade() const;
			int			getExecuteGrade() const;
			bool		beSigned(const Bureaucrat& sign);

			class GradeTooHighException : public std::exception {
					public:
							const char* what() const throw();
			};

			class GradeTooLowException : public std::exception {
					public:
							const char* what() const throw();
			};
			
};

std::ostream&  operator<<(std::ostream& out, const Form& original);




#endif