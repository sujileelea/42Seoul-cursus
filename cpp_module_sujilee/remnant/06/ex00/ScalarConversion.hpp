/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:44:58 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/14 11:51:18 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#include <iostream>
#include <cmath>


class ScalarConversion {
	private:
			std::string _value;
			double		_double;
			bool		_nan;
			bool		_inf;
	public:
			ScalarConversion();
			ScalarConversion(std::string value);
			ScalarConversion(const ScalarConversion& original);
			~ScalarConversion();

			ScalarConversion&	operator=(const ScalarConversion& original);
			void	convertChar();
			void	convertInt();
			void	convertFloat();
			void	convertDouble();

			class ConversionException : public std::exception {
				private:
						std::string _message;
				public:
						ConversionException(std::string message);
						const char* what() const throw();
						~ConversionException() throw();
			};
			


};

#endif