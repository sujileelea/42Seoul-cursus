#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

void test_normal(void) {
	const Animal* i = new Cat("i");
	const Animal* j = new Dog("j");
	const Animal* k = new Dog("k");

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;
	*(const_cast<Animal*>(k)) = *(const_cast<Animal*>(j));
	k->makeSound();
	std::cout << std::endl;

	delete k;
	delete j;
	delete i;
}

void test_array(void) {
	Animal* meta[B_COUNT / 20];
	Dog*	collie;

	for (int i = 0 ; i < B_COUNT / 20; ++i) {
		if (!(i % 2)) {
			meta[i] = new Cat(std::to_string(i / 2 + 1));
		} else {
			meta[i] = new Dog(std::to_string(i / 2 + 1));
		}
	}
	collie = new Dog((*dynamic_cast<Dog *>(meta[1])));
	collie->getBrain()->setIdeas("hello", 0);
	std::cout << (*collie->getBrain()).getIdeas(0) << std::endl;
	for (int i = 0 ; i < B_COUNT / 20; ++i)
		delete meta[i];
	delete collie;
}


int main(void) {
	std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');
	test_normal();
	std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');
	test_array();
	std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');

	return 0;
}