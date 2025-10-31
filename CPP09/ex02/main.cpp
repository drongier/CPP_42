/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:44:51 by drongier          #+#    #+#             */
/*   Updated: 2025/10/29 16:29:08 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>


int	main(int ac, char **av) {
	
	pmerge pm;
	
	std::vector<int> vector;
	std::deque<int> deque;
	
	if (!pm.parseInput(ac, av, vector, deque)) {
		return 1;
	}
	std::cout << "Before : ";
	pm.printVector(vector);

	//VECTOR TEST TIME 
	clock_t start = clock();
	std::vector<int> final_vector = pm.fordJohnson(vector);
	clock_t end = clock();
	std::cout << "After : ";
	pm.printVector(final_vector);
	double duration_us = ((double)(end - start) / CLOCKS_PER_SEC);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vector.size()
			<< " elements with std::vector : "
			<< duration_us << "sec" << std::endl;
	
	//DEQUE TEST TIME 
	clock_t startDeque = clock();
	std::deque<int> final_deque = pm.fordJohnsonDeque(deque);
	clock_t endDeque = clock();
	double duration_usDeque = ((double)(endDeque - startDeque) / CLOCKS_PER_SEC);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << deque.size()
			<< " elements with std::deque  : "
			<< duration_usDeque << "sec" << std::endl;
	
	return (0);
}
