#include "Brain.hpp"

Brain::Brain(void) : _num(0)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& ref)
{
	for (int i = 0; i < ref._num; i++)
		_ideas[i] = ref._ideas[i];
	_num = ref._num;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& ref)
{
	for (int i = 0; i < ref._num; i++)
		_ideas[i] = ref._ideas[i];
	_num = ref._num;
	return *this;
}

void	Brain::addIdea(std::string idea)
{
	if (_num == 99)
		_num = 0;
	_ideas[_num] = idea;
	_num++;
}

const std::string&	Brain::getIdea(unsigned int idx) const
{
	return _ideas[idx];
}
