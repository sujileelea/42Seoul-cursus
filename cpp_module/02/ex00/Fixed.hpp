/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:44:04 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/03 10:08:12 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
			int					fixedPoint; //고정 소수점
			static const int	fracBits = 8; //소수 비트 수
	public:
			Fixed(); //constructor
			Fixed(const Fixed& ref); //copy constructor
			Fixed& operator=(const Fixed& ref); //assignation operator
			int	getRawBits() const; //return the raw value of fixed point
			void setRawBits(int const raw); //sets the raw value of the fixed point
			~Fixed(); //destructor
};



#endif