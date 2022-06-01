#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <stdexcept>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int n) {
	typename T::iterator ret = find(container.begin(), container.end(), n);

	if (ret == container.end())
		throw std::runtime_error(std::to_string(n) + " is not in this container.");
	return ret;
}

#endif