#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array {
private:
	int _size;
	T* _arr;

public:
	int size() const {
		return _size;
	}

	T* getArr() const {
		return _arr;
	}

	class OutOfBound: public std::exception {
	public:
		const char* what(void) const throw() {
			return "Out of bound.";
		}
	};

	Array(): _size(0), _arr(NULL) {
		std::cout << "Array default constructor called" << std::endl;
	}

	Array(const unsigned int& n): _size(n) {
		std::cout << "Array constructor with size called" << std::endl;
		if (_size > 0)
			_arr = new T[_size];
	}

	Array(const Array& copy) {
		std::cout << "Array copy constructor called" << std::endl;
		*this = copy;
	}

	Array& operator=(const Array& origin) {
		std::cout << "Array assignation operator called" << std::endl;
		if (this != &origin) {
			if (this->_size)
				delete[] this->_arr;
			this->_size = origin.size();
			//size만큼 메모리 할당
			this->_arr = new T[this->_size];
			//내용 넣어주기
			for (int i = 0; i < this->_size; i++)
				this->_arr[i] = origin.getArr()[i];
		}
		return *this;
	}

	T& operator[](const int& idx) const {
		//이 클래스의 private 변수인 배열의 인덱스에 접근할 수 있게 연산자 오버로딩.
		if (idx < 0 || idx >= _size)
			throw Array::OutOfBound();
		return _arr[idx];
	}

	~Array() {
		std::cout << "Array destructor called" << std::endl;
		if (this->_arr)
			delete[] this->_arr;
		this->_arr = NULL;
	}
};

//클래스 바깥에서 정의되었기 때문에 템플릿 선언을 해야겠다.
template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T> &ref) {
	for (int i = 0; i < ref.size(); i++)
		out << "arr[" << i << "]: " << ref.getArr()[i] << std::endl;
	return out;
}
//cout 시 << 연산자를 이렇게 쓸거야
#endif