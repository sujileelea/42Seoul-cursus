/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:45 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/30 18:38:46 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <iostream>
#include <string>

#define B_COUNT 100

class Brain {
private:
	std::string ideas[B_COUNT];
public:
	std::string getIdeas(const int i) const;
	void setIdeas(std::string str, const int i);

	Brain();
	Brain(const Brain &origin);
	Brain& operator=(const Brain &origin);
	~Brain();
};

#endif

