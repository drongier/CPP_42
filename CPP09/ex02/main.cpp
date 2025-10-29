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
#include <cstdlib> // pour std::atoi

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
	
	for (int i = 1; i < ac; i++) {
		int n = std::atoi(av[i]);
		pm.addToNumber(n);
	}

	std::cout << "Before : ";
	pm.printNumber();

	std::vector<int> numbers = pm.getNumbers();
	std::vector<Pair> mesPaires = pm.makePaire(numbers);

	std::cout << "1st pairs, sorted : ";
	pm.printPairs(mesPaires);
}
