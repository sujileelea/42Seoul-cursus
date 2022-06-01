/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:55:39 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/14 12:50:27 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
			int		fixedPoint; //고정 소수점
			static const int	fracBits = 0; //소수 비트 수 
	public:
			Fixed(); //constructor
			Fixed(const int digit); //int -> fixed point
			Fixed(const float digit); //float -> fixed point
			Fixed(const Fixed& ref); //copy constructor
			Fixed& operator=(const Fixed& ref); //assignation operator
			int		getRawBits() const; //returns the raw value of the fixed point
			void	setRawBits(int const raw); //sets the raw value of the fixed point
			int		toInt() const; //fixed point -> int
			float	toFloat() const; //fixed point -> float
			~Fixed(); //destructor
	
};

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixed);

#endif

