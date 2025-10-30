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

// 1. main(argc, argv)
//    ↓
// 2. PmergeMe pmerge
//    ↓
// 3. pmerge.parseInput(argc, argv)
//    - Valider que tous les arguments sont des entiers positifs
//    - Stocker dans _vector ET _deque
//    ↓
// 4. pmerge.displayBefore()
//    - Afficher "Before: 3 5 9 7 4"
//    ↓
// 5. Trier avec vector
//    - start_time
//    - sortVector() → Ford-Johnson
//    - end_time
//    - Calculer durée
//    ↓
// 6. Trier avec deque
//    - start_time
//    - sortDeque() → Ford-Johnson
//    - end_time
//    - Calculer durée
//    ↓
// 7. pmerge.displayAfter()
//    - Afficher "After: 3 4 5 7 9"
//    ↓
// 8. Afficher les temps
//    - "Time to process ... with std::vector : X us"
//    - "Time to process ... with std::deque : Y us"

int	main(int ac, char **av) {
	
	pmerge pm;
	
	// 1) extract av[i] and save into vector numbers
	for (int i = 1; i < ac; i++) {
		//add parsing number
		int n = std::atoi(av[i]);
		pm.addToVector(n);
		pm.addToDeque(n);
	}
	std::cout << "Before : ";
	pm.printNumber();

	std::vector<int> numbers = pm.getNumbers();
	std::deque<int> deque = pm.getDeque();

	//VECTOR TEST TIME 
	clock_t start = clock();
	pm.fordJohnson(numbers);
	clock_t end = clock();
	// std::cout << "After : ";
	// pm.printVector(final_vector);
	double duration_us = ((double)(end - start) / CLOCKS_PER_SEC);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << numbers.size()
			<< " elements with std::vector : "
			<< duration_us << "sec" << std::endl;
	
	//DEQUE TEST TIME 
	clock_t startDeque = clock();
	pm.fordJohnsonDeque(deque);
	clock_t endDeque = clock();
	double duration_usDeque = ((double)(endDeque - startDeque) / CLOCKS_PER_SEC);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << deque.size()
			<< " elements with std::deque  : "
			<< duration_usDeque << "sec" << std::endl;
	
	return (0);
}
