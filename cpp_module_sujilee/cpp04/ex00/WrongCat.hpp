/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:22 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:38:23 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
	void setType(const std::string type);
	void makeSound() const;

	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &origin);
	WrongCat& operator=(const WrongCat &origin);
	~WrongCat();
};

#endif