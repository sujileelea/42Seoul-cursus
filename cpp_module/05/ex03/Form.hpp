/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:03:33 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:40:10 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int execute);
		Form(const Form& original);
		virtual ~Form();

		Form&			operator=(const Form& original);
		std::string		getName() const;
		bool			getSign() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		bool			beSigned(const Bureaucrat& sign);
		virtual void	execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class ExecutetException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& o, const Form& original);


#endif