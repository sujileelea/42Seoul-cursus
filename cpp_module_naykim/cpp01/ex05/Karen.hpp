#ifndef __KAREN_H__
#define __KAREN_H__

#include <iostream>
#include <string>

class Karen {
private:
	void debug();
	void info();
	void warning();
	void error();
public:
	Karen();
	void complain(std::string level);
	~Karen();
};

#endif