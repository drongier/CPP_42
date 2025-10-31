/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:44:51 by drongier          #+#    #+#             */
/*   Updated: 2025/10/31 13:15:10 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sys/time.h>


int	main(int ac, char **av) {
	
	pmerge pm;
	
	std::vector<int> vector;
	std::deque<int> deque;
	struct timeval ts1;
	struct timeval ts2;
	
	if (!pm.parseInput(ac, av, vector, deque)) {
		return 1;
	}
	std::cout << "Before : ";
	pm.printDeque(deque);
	
	//DEQUE TEST TIME 
	gettimeofday(&ts1, NULL);
	std::deque<int> final_deque = pm.fordJohnsonDeque(deque);
	gettimeofday(&ts2, NULL);
	std::cout << "After : ";
	pm.printDeque(final_deque);
	std::cout << "Time to process a range of " << deque.size()
			<< " elements with std::deque  : ";
	pm.display_time(ts1, ts2);
	
	//VECTOR TEST TIME 
	gettimeofday(&ts1, NULL);
	std::vector<int> final_vector = pm.fordJohnson(vector);
	gettimeofday(&ts2, NULL);
	std::cout << "Time to process a range of " << vector.size()
	<< " elements with std::vector : ";
	pm.display_time(ts1, ts2);
	
	return (0);
}
