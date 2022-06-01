#ifndef __CURE_H__
#define __CURE_H__

#include "AMateria.hpp"

class Cure: public AMateria {
public:
	AMateria* clone() const;
	void use(ICharacter& target);
	
	Cure();
	Cure(std::string const & type);
	Cure(const Cure& copy);
	Cure& operator=(const Cure &origin);
	~Cure();
};

#endif