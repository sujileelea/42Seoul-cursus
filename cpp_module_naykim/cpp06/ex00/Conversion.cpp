#include "Conversion.hpp"

const char* Conversion::getOrigin() const {
	return _origin;
}

int Conversion::getType() const {
	return _type;
}

char Conversion::getChar() const {
	return _inChar;
}

int Conversion::getInt() const {
	return _inInt;
}

float Conversion::getFloat() const {
	return _inFloat;
}

double Conversion::getDouble() const {
	return _inDouble;
}

void Conversion::setAll() {
	setType();
	_inChar = _origin[0];
	_inInt = atoi(_origin);
	_inFloat = atof(_origin);
	_inDouble = atof(_origin);
}

void Conversion::setType() {
	_type = checkTypeException();
	if (_type != Conversion::noType)
		return;
	if ((_origin[0] >= '0' && _origin[0] <= '9') || _origin[0] == '-' || _origin[0] == '.') {
		_type = checkTypeNumeric();
		if (_type != Conversion::noType)
			return;
	}
	if (_origin[1])
		return;
	_type = Conversion::charType;
}

int Conversion::checkTypeException() {
	std::string doubleSpecial[4] = { "inf", "+inf", "-inf", "nan" };
	std::string floatSpecial[4] = { "inff", "+inff", "-inff", "nanf" };

	for (int i = 0; i < 4; i++) {
		if (doubleSpecial[i] == _origin)
			return Conversion::doubleType;
		if (floatSpecial[i] == _origin)
			return Conversion::floatType;
	}
	return Conversion::noType;
}

int Conversion::checkTypeNumeric() {
	int i = 0;
	int dot = 0;

	if (_origin[0] == '-' && _origin[1])
		i++;
	if (_origin[i] == '.' && (_origin[i + 1] == 'f' || _origin[i + 1] == 0))
		return Conversion::noType;
	while ((_origin[i] >= '0' && _origin[i] <= '9') || _origin[i] == '.') {
		if (_origin[i] == '.')
			++dot;
		if (dot > 1)
			return Conversion::noType;
		i++;
	}
	if (!_origin[i]) {
		if (dot == 1)
			return Conversion::doubleType;
		return Conversion::intType;
	}
	else if (_origin[i] == 'f' && !_origin[i + 1] && dot == 1)
		return Conversion::floatType;
	return Conversion::noType;
}

void Conversion::printChar() const {
	std::cout << "char: ";
	switch (_type) {
	case Conversion::charType:
		std::cout << "\'" << _inChar << "\'" << std::endl;
		break;
	case Conversion::intType:
		if (checkCharImpossible(_inInt))
			std::cout << "\'" << static_cast<char>(_inInt) << "\'" << std::endl;
		break;
	case Conversion::floatType:
		if (checkCharImpossible(_inFloat))
			std::cout << "\'" << static_cast<char>(_inFloat) << "\'" << std::endl;
		break;
	case Conversion::doubleType:
		if (checkCharImpossible(_inDouble))
			std::cout << "\'" << static_cast<char>(_inDouble) << "\'" << std::endl;
		break;
	}
}

void Conversion::printInt() const {

	std::cout << "int: ";
	switch (_type) {
	case Conversion::charType:
		std::cout << static_cast<int>(_inChar) << std::endl;
		break;
	case Conversion::intType:
		std::cout << _inInt << std::endl;
		break;
	case Conversion::floatType:
		if (checkIntImpossible(_inFloat))
			std::cout << static_cast<int>(_inFloat) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		break;
	case Conversion::doubleType:
		if (checkIntImpossible(_inDouble))
			std::cout << static_cast<int>(_inDouble) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		break;
	}
}

void Conversion::printFloat() const {
	std::cout << "float: ";
	switch (_type) {
	case Conversion::charType:
		std::cout << static_cast<float>(_inChar) << std::endl;
		break;
	case Conversion::intType:
		std::cout << static_cast<float>(_inInt) << ".0f" << std::endl;
		break;
	case Conversion::floatType:
		std::cout << _inFloat << checkPlusZero(_inFloat) << "f" << std::endl;
		break;
	case Conversion::doubleType:
		std::cout << static_cast<float>(_inDouble) << checkPlusZero(_inDouble) << "f" << std::endl;
		break;
	}
}

void Conversion::printDouble() const {
	std::cout << "double: ";
	switch (_type) {
	case Conversion::charType:
		std::cout << static_cast<double>(_inChar) << std::endl;
		break;
	case Conversion::intType:
		std::cout << static_cast<double>(_inInt) << ".0" << std::endl;
		break;
	case Conversion::floatType:
		std::cout << static_cast<double>(_inFloat) << checkPlusZero(_inFloat) << std::endl;
		break;
	case Conversion::doubleType:
		std::cout << _inDouble << checkPlusZero(_inFloat) << std::endl;
		break;
	}
}

void Conversion::printAllType() const {
	if (_type == Conversion::noType) {
		std::cout << "It has No type" << std::endl;
		return;
	}
	printChar();
	printInt();
	printFloat();
	printDouble();
}

int Conversion::checkCharImpossible(double n) const {
	if (n - static_cast<int>(n) != 0 || !checkIntImpossible(n))
		std::cout << "impossible" << std::endl;
	else if (n < 32 || n > 127)
		std::cout << "Non displayable" << std::endl;
	else
		return 1;
	return 0;
}

int Conversion::checkIntImpossible(double n) const {
	if (n <= std::numeric_limits<int>::max() && n >= std::numeric_limits<int>::min()
	&& n != std::numeric_limits<double>::infinity() && n != -std::numeric_limits<double>::infinity()
	&& n != std::numeric_limits<double>::quiet_NaN())
		return 1;
	return 0;
}

std::string Conversion::checkPlusZero(double n) const {
	if (n - static_cast<int>(n) == 0 && checkIntImpossible(n))
		return ".0";
	return "";
}

Conversion::Conversion(): _origin(""), _type(Conversion::noType) {
	_inChar = 0;
	_inInt = 0;
	_inFloat = 0;
	_inDouble = 0;
}

Conversion::Conversion(const char* str): _origin(str), _type(Conversion::noType) {
	setAll();
}

Conversion::Conversion(const Conversion& copy) {
	*this = copy;
}

Conversion& Conversion::operator=(const Conversion& origin) {
	if (this != &origin) {
		this->_origin = origin.getOrigin();
		this->_type = origin.getType();
		this->_inChar = origin.getChar();
		this->_inInt = origin.getInt();
		this->_inFloat = origin.getFloat();
		this->_inDouble = origin.getDouble();
	}
	return (*this);
}

Conversion::~Conversion() { }
