/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:06:05 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/10 13:12:48 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>

class Bureaucrat {
	private:
			const std::string	_name;
			int					_grade;
	public:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(const Bureaucrat& original);
			~Bureaucrat();

			Bureaucrat& operator=(const Bureaucrat& original);
			std::string getName() const;
			int			getGrade() const;
			void		upGrade(int grade);
			void		downGrade(int grade);
			
			class GradeTooHighException : public std::exception {
				public:
						const char* what() const throw();
			};
			class GradeTooLowException : public std::exception {
				public:
						const char* what() const throw();
			};

};


std::ostream&	operator<<(std::ostream&, const Bureaucrat& original);

#endif