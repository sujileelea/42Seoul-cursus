/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:24:52 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/08 14:26:17 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
		int			_ideaIdx;
	public:
		Brain(void);
		Brain(const Brain& ref);
		~Brain(void);

		Brain&				operator=(const Brain& ref);
		void				addIdea(std::string idea);
		const std::string&	getIdea(unsigned int idx) const;
};

#endif
