#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal("meta");
	const Animal *j = new Dog("j");
	const Animal *i = new Cat("i");
	const WrongAnimal *wrong = new WrongAnimal("wrong");
	const WrongAnimal *wrongcat = new WrongCat("wrongcat");

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;

	std::cout << "=========================================" << std::endl;
	std::cout << wrong->getType() << std::endl;
	std::cout << wrongcat->getType() << std::endl;
	wrong->makeSound();
	wrongcat->makeSound();

	delete wrong;
	delete wrongcat;

	return 0;
}