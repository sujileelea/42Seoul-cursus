#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
	reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator rend() {
		return this->c.rend();
	}
	const_iterator cbegin() {
		return this->c.cbegin();
	}
	const_iterator cend() {
		return this->c.cend();
	}
	const_reverse_iterator crbegin() {
		return this->c.crbegin();
	}
	const_reverse_iterator crend() {
		return this->c.crend();
	}

	MutantStack() { }
	MutantStack(const MutantStack& copy) { *this = copy; }
	MutantStack& operator=(const MutantStack& m) {
		std::stack<T>::operator=(m);
		return *this;
	}
	~MutantStack() { }
};

#endif