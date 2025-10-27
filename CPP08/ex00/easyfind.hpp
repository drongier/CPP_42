/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:43:21 by drongier          #+#    #+#             */
/*   Updated: 2025/10/27 17:43:22 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& a, int value) {
	typename T::iterator find_value = std::find(a.begin(), a.end(), value);
	if (find_value != a.end())
	    std::cout << "Found " << value << " at position " << std::distance(a.begin(), find_value) << '\n';
	else
		std::cout << "Value not found !" << std::endl;
	return find_value; 
}

#endif