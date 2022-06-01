#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	std::cout << std::endl << "==========make MateriaSource src" << std::endl;
	IMateriaSource* src = new MateriaSource();

	std::cout << std::endl << "==========src learn ice, cure" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl << "==========make Character me" << std::endl;
	ICharacter* me = new Character("me");

	std::cout << std::endl << "==========make AMateria * tmp" << std::endl;
	AMateria* tmp;
	
	std::cout << std::endl << "==========src create ice, cure and me equip them" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << std::endl << "==========make Character bob" << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << std::endl << "==========me use ice, cure passing bob" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "==========delete bob" << std::endl;
	delete bob;
	std::cout << "==========delete me" << std::endl;
	delete me;
	std::cout << "==========delete src" << std::endl;
	delete src;

	return 0;
}