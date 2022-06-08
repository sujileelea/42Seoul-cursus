#include "span.hpp"
#include <ctime>

#define COUNT 10000

int main(){
	Span sp = Span(5);
	Span sp1 = Span(COUNT + 5);
	Span sp2 = Span(3);

	std::cout << std::endl << "=======================================" << std::endl;
	std::cout << "[Basic test]" << std::endl;
	try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		for (unsigned long i = 0; i < sp.getStore().size(); i++) {
			std::cout << sp.getStore()[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "shortestspan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestspan: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=======================================" << std::endl;
	std::cout << "[addByIterator test]" << std::endl;
	try {
		sp1.addNumber(1);
		sp1.addNumber(2);
		sp1.addNumber(3);
		std::cout << "before addByIterator sp1 size: " << sp1.getNowSize() << std::endl;
		std::vector<int> newv;
		srand((unsigned int)time(NULL));
		for (int i = 0; i < COUNT; i++)
			newv.push_back(rand() % (COUNT * 100));
		sp1.addByIterator(newv.begin(), newv.end());
		std::cout << "newv size: " << newv.size() << std::endl;
		std::cout << "after addByIterator sp1 size: " << sp1.getNowSize() << std::endl;
		std::cout << "shortestspan: " << sp1.shortestSpan() << std::endl;
		std::cout << "longestspan: " << sp1.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=======================================" << std::endl;
	std::cout << "[error test]" << std::endl;
	try {
		std::cout << "test addNumber() when sp is full" << std::endl;
		sp.addNumber(42);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "test shortestSpan() when sp2 is empty" << std::endl;
		std::cout << "shortestspan: " << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}