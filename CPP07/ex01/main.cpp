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
void	printElement(T& element) {
	std::cout << element << " ";
}

template<typename T>
void	doubleValue(T& element) {
	element *= 2;
}

template<typename T>
void	plus28(T& element) {
	element = element + 28;
	std::cout << element << " ";
}

int main() {

	int intArray[5] = {1, 2, 3, 4, 5};
	std::cout << "Original array: ";
	iter(intArray, 5, printElement);
	std::cout << std::endl << std::endl;;

	iter(intArray, 5, doubleValue);
	std::cout << "After double: ";
	iter(intArray, 5, printElement);
	std::cout << std::endl << std::endl;

	std::cout << "After +28: ";
	iter(intArray, 5, plus28);
	std::cout << std::endl << std::endl;

	return 0;
}
