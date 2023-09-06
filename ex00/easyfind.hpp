#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
typename T::iterator easyfind(T& arr, int n)
{
	typename T::iterator it = arr.begin();

	for (;it != arr.end(); it++)
		if (*it == n)
			return it;
	std::cerr << n << " Not found in arr" << std::endl;
	return it;
}

#endif