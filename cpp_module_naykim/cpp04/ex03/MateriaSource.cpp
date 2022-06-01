#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (_materias[i] == 0) {
			_materias[i] = m;
			return ;
		}
	}
	std::cout << "no more space. FAIL to learn" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (type == this->_materias[i]->getType())
			return this->_materias[i]->clone();
	}
	return NULL;
}

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < INVEN_SIZE; i++)
		this->_materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& origin) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
		if (origin._materias[i])
			this->_materias[i] = origin._materias[i]->clone();
		else
			this->_materias[i] = 0;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (_materias[i])
			delete _materias[i];
		_materias[i] = 0;
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}
