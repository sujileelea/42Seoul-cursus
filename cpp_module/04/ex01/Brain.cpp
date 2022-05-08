#include "Brain.hpp"

Brain::Brain() : _ideaIdx(0)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& original)
{
	for (int i = 0; i < original._ideaIdx; i++)
		_ideas[i] = original._ideas[i];
	_ideaIdx = original._ideaIdx;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& original)
{
	for (int i = 0; i < original._ideaIdx; i++)
		_ideas[i] = original._ideas[i];
	_ideaIdx = original._ideaIdx;
	return *this;
}

void	Brain::addIdea(std::string idea)
{
	if (_ideaIdx == 99)
		_ideaIdx = 0;
	_ideas[_ideaIdx] = idea;
	_ideaIdx++;
}

const std::string&	Brain::getIdea(unsigned int idx) const
{
	return _ideas[idx];
}
