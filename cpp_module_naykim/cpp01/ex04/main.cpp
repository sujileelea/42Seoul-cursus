#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	std::ifstream readFile;
	std::ofstream writeFile;
	std::string filename;
	std::string from;
	std::string to;
	std::string::size_type prev;
	std::string::size_type index;
	int ret = 0;

	if (ac != 4) {
		std::cout << "ERROR: you need 3 arguments - filename, from, to" << std::endl;
		return 1;
	}
	filename = av[1];
	from = av[2];
	to = av[3];
	readFile.open(filename);
	if (readFile.is_open()) {
		writeFile.open(filename + ".replace");
		if (writeFile.is_open()) {
			while (!readFile.eof())
			{
				std::string str;
				getline(readFile, str);
				if (!readFile.eof())
					str += "\n";
				prev = 0;
				while (prev < str.size() && (index = str.find(from, prev)) != std::string::npos) {
					writeFile << str.substr(prev, index - prev);
					writeFile << to;
					prev = std::min(index + from.size(), str.size());
				}
				writeFile << str.substr(prev);
			}
			writeFile.close();
		}
		else {
			std::cout << "FAIL to open writeFile: " << filename + ".replace" << std::endl;
			ret = 1;
		}
		readFile.close();
	}
	else {
		std::cout << "FAIL to open readFile: " << filename << std::endl;
		ret = 1;
	}
	return ret;
}
