#include "Form.hpp"

int main(void) {
	Form form_j("form_j", 5, 1);
	Form form_h("form_h", 140, 130);
	Bureaucrat b_1("b_1", 2);
	Bureaucrat b_2("b_2", 50);

	std::cout << "form_j: " << form_j;
	std::cout << "form_h: " << form_h;
	std::cout << "b_1: " << b_1;
	std::cout << "b_2: " << b_2 << std::endl;

	b_1.signForm(form_h);
	b_1.signForm(form_j);
	std::cout << std::endl;
	b_2.signForm(form_h);
	b_2.signForm(form_j);
	std::cout << std::endl;

	std::cout << "form_j: " << form_j;
	std::cout << "form_h: " << form_h;
	std::cout << std::endl;

	return 0;
}