#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

void test_normal(void) {
	// Animal animal("tmp");
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

int main(void) {
	std::cout << std::setfill('=') << std::setw(50) << "\n" << std::setfill(' ');
	test_normal();
	std::cout << std::setfill('=') << std::setw(50) << "\n" << std::setfill(' ');
	return 0;
}