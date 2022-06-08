#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <stdexcept>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int n) {
	//find는 첫번째로 일치하는 원소를 가리키는 반복자를 반환
	//find(여기서부터, 여기까지, 얘랑 일치하는거)
	typename T::iterator ret = find(container.begin(), container.end(), n);

	if (ret == container.end())
	//runtime_error : 예외로 던질 객체 유형을 정의하는 클래스
		throw std::runtime_error(std::to_string(n) + " is not in this container.");
	return ret;
}

#endif