#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN.";
	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "address of str: " << &str << std::endl;
	std::cout << "     by strPTR: " << strPTR << std::endl;
	std::cout << "    by &strREF: " << &strREF << std::endl << std::endl;
	
	std::cout << "str          : " << str << std::endl;
	std::cout << "str using PTR: " << *strPTR << std::endl;
	std::cout << "str using REF: " << strREF << std::endl;

	return 0;
}