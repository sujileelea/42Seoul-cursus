#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* cat2 = new WrongCat();

	std::cout << meta2->getType() << " " << std::endl;
	std::cout << cat2->getType() << " " << std::endl;
	meta2->makeSound();
	cat2->makeSound();

	delete meta2;
	delete cat2;

	return 0;
}
