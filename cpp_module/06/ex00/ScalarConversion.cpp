/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:44:56 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/14 11:54:51 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion() : _value(""), _double(0), _nan(false), _inf(false) {}

ScalarConversion::ScalarConversion(std::string value) : _value(value) {
	_double = atof(_value.c_str());
	_nan = isnan(_double);
	if (_value == "nan")
		_nan = true;
	_inf = isinf(_double);
	if (_value == "+inf" || value == "inf" || value == "-inf")
		_inf = true;
}

ScalarConversion::ScalarConversion(const ScalarConversion& original) : _value(original._value), _double(original._double), _nan(original._nan), _inf(original._inf) {}

ScalarConversion::~ScalarConversion(void) {}

ScalarConversion&	ScalarConversion::operator=(const ScalarConversion& original) {
	_value = original._value;
	_double = original._double;
	_nan = original._nan;
	_inf = original._inf;
	return *this;
}

void	ScalarConversion::convertChar(void) {
	try
	{
		std::cout << "char : ";
		if (_double < 0 || _double > 255 || _nan == true || _inf == true)
			throw ConversionException("impossible");

		char	temp = static_cast<char>(_double);
		if (temp < 32 || temp > 122)
			throw ConversionException("Non displayable");
		std::cout << temp << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	ScalarConversion::convertInt(void) {
	try
	{
		std::cout << "int : ";
		long	temp = static_cast<long>(_double);
		if (_nan == true || _inf == true || temp > INT_MAX || temp < INT_MIN)
			throw ConversionException("impossible");
		std::cout << temp << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	ScalarConversion::convertFloat(void) {
	try
	{
		std::cout << "float : ";
		if (_nan == true)
			throw ConversionException("nanf");
		else if (_inf == true && _double < 0)
			throw ConversionException("-inff");
		else if (_inf == true)
			throw ConversionException("+inff");

		float	temp = static_cast<float>(_double);
		if (temp - static_cast<int>(temp) == 0.0f)
			std::cout << temp << ".0f" << std::endl;
		else
			std::cout << temp << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	ScalarConversion::convertDouble(void) {
	try
	{
		std::cout << "double : ";
		if (_nan == true)
			throw ConversionException("nan");
		else if (_inf == true && _double < 0)
			throw ConversionException("-inf");
		else if (_inf == true)
			throw ConversionException("+inf");
		else if (_double - static_cast<int>(_double) == 0.0)
			std::cout << _double << ".0" << std::endl;
		else
			std::cout << _double << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

ScalarConversion::ConversionException::ConversionException(std::string message)
: _message(message) {}

const char* ScalarConversion::ConversionException::what() const throw()
{
	return _message.c_str();
}

ScalarConversion::ConversionException::~ConversionException() throw() {}