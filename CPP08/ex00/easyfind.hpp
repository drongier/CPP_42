#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& a, int value) {
	typename T::iterator find_value = std::find(a.begin(), a.end(), value);
	if (find_value != a.end())
	    std::cout << "Found " << value << " at position " << (find_value - a.begin()) << '\n';
	else
		std::cout << "Value not found !" << std::endl;
	return find_value; 
}

#endif