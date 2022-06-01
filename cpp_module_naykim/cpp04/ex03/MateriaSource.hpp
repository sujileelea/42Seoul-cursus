#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
private:
	AMateria* _materias[INVEN_SIZE];
public:
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const &type);

	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& origin);
	~MateriaSource();
};

#endif
