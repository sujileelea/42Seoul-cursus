#ifndef __CONVERSION_H__
#define __CONVERSION_H__

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class Conversion {
private:
	const char* _origin;
	int _type;
	char _inChar;
	int _inInt;
	float _inFloat;
	double _inDouble;

	static const int noType = -1;
	static const int charType = 0;
	static const int intType = 1;
	static const int floatType = 2;
	static const int doubleType = 3;

public:
	const char* getOrigin() const;
	int getType() const;
	char getChar() const;
	int getInt() const;
	float getFloat() const;
	double getDouble() const;

	void setAll();
	void setType();
	int checkTypeException();
	int checkTypeNumeric();

	void printChar() const;
	void printInt() const;
	void printFloat() const;
	void printDouble() const;
	void printAllType() const;
	
	int checkCharPossible(double n) const;
	int checkIntPossible(double n) const;
	std::string checkPlusZero(double n) const;

	Conversion();
	Conversion(const char* str);
	Conversion(const Conversion& copy);
	Conversion& operator=(const Conversion& origin);
	~Conversion();
};

#endif
