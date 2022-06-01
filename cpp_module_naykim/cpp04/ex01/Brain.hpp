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

