#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	Dog *dog = (Dog*)j;
	Cat *cat = (Cat*)i;

	dog->addIdea("Meong-meong!!!");
	cat->addIdea("Nya-ong...");
	std::cout << std::endl;

	Animal* animals[6];
	for (int k = 0; k < 6; k++)
	{
		if (k < 3)
		{
			animals[k] = new Dog(*dog);
			std::cout << ((Dog *)animals[k])->getIdea(0) << std::endl << std::endl;
		}
		else
		{
			animals[k] = new Cat(*cat);
			std::cout << ((Cat *)animals[k])->getIdea(0) << std::endl << std::endl;
		}
		delete animals[k];
	}
	delete j;
	delete i;

	return 0;
}
