#ifndef __ICE_H__
#define __ICE_H__

#include "AMateria.hpp"

class Ice: public AMateria {
public:
	AMateria* clone() const;
	void use(ICharacter& target);
	
	Ice();
	Ice(std::string const & type);
	Ice(const Ice& copy);
	Ice& operator=(const Ice &origin);
	~Ice();
};

#endif