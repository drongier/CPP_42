/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:47:49 by drongier          #+#    #+#             */
/*   Updated: 2025/10/27 16:47:50 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template<typename T>
void	doubleValue(T const &element) {
	std::cout << element * 2 << " ";
}

template<typename T>
void	plus2(T const &element) {
	std::cout << element + 2 << " ";
}

int main() {

	int const intArray[5] = {1, 2, 3, 4, 5};
	iter(intArray, 5, plus2);
	std::cout << std::endl;
	iter(intArray, 5, doubleValue);
	std::cout << std::endl;
	return 0;
}
