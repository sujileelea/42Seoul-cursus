/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:53:00 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/03 10:53:03 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixedPoint; // 고정 소수점
		static const int	fracBits = 8; // 소수 비트 수
	public:
		Fixed(void); // constructor
		Fixed(const int digit); // int -> fixed point
		Fixed(const float digit); // float -> fixed point
		Fixed(const Fixed& ref); // copy constructor
		~Fixed(); // destructor

		Fixed&	operator=(const Fixed& ref); // assignation operator
		Fixed	operator+(const Fixed fixed) const;
		Fixed	operator-(const Fixed fixed) const;
		Fixed	operator*(const Fixed fixed) const;
		Fixed	operator/(const Fixed fixed) const;

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		bool	operator>(const Fixed fixed) const;
		bool	operator<(const Fixed fixed) const;
		bool	operator>=(const Fixed fixed) const;
		bool	operator<=(const Fixed fixed) const;
		bool	operator==(const Fixed fixed) const;
		bool	operator!=(const Fixed fixed) const;

		static Fixed& 		min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& point2);

		int		getRawBits(void) const; // returns the raw value of the fixed point
		void	setRawBits(int const raw); // sets the raw value of the fixed point
		float	toFloat(void) const; // fixed point -> float
		int		toInt(void) const; // fixed point -> int

};

std::ostream&	operator<<(std::ostream& outStream, const Fixed& fixed);

#endif