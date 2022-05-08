#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

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
