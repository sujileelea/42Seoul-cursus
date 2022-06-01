/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:05:59 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 17:08:02 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string>

class Karen {
	private :
			void debug(void);
			void info(void);
			void warning(void);
			void error(void);
	public :
			Karen();
			void	complain(std::string level);
			~Karen();
};	

#endif