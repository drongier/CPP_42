/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:49 by drongier          #+#    #+#             */
/*   Updated: 2025/11/12 09:56:50 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <climits>
#include <algorithm>


#define MIL 1000000

struct Pair {
	int a;
	int b;
};

class pmerge {
	private: 
		std::vector<int> 	_vector;
		std::deque<int> 	_deque;
	public:
		pmerge();
		~pmerge();

		void addToVector(int value);
		void addToDeque(int value);
		void printNumber() const;
		void printPairs(const std::vector<Pair>& pairs);
		void printDeque(const std::deque<int>& vect);
		std::vector<int> fordJohnson(const std::vector<int>& input);
		std::deque<int> fordJohnsonDeque(const std::deque<int>& input);
		bool parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq);
		void display_time(struct timeval& ts1, struct timeval& ts2);
};

template<typename PairContainer, typename IntContainer>
IntContainer extractWinners(const PairContainer& pairs) {
	IntContainer winners;
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].b != -1) {
			winners.push_back(pairs[i].a);
		}
	}
	return winners;
}

template<typename PairContainer, typename IntContainer>
IntContainer extractLosers(const PairContainer& pairs) {
	IntContainer losers;
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].b != -1) {
			losers.push_back(pairs[i].b);
		}
	}
	return losers;
}

template<typename Container>
int findUnpaired(const Container& pairs) {
	if (pairs.empty())
		return -1;
	const Pair& last = pairs.back();
	if (last.b == -1)
		return last.a;
	return -1;
}

template<typename IntContainer, typename PairContainer>
PairContainer makePaire(const IntContainer& input) {
	PairContainer pairs;
	for (size_t i = 0; i + 1 < input.size(); i += 2) {
		int x = input[i];
		int y = input[i + 1];
		Pair p;
		if (x > y) {
			p.a = x;
			p.b = y;
		} else {
			p.a = y;
			p.b = x;
		}
		pairs.push_back(p);
	}
	if (input.size() % 2 != 0) {
		Pair p;
		p.a = input.back();
		p.b = -1;
		pairs.push_back(p);
	}
	return pairs;
}

template<typename Container>
Container generateJacobsthalOrder(size_t n) {
	Container jacobsthal;
	size_t j0 = 0, j1 = 1;

	while (true) {
		size_t next = j1 + 2 * j0;
		if (next >= n)
			break;
		jacobsthal.push_back(next);
		j0 = j1;
		j1 = next;
	}

	Container order;
	if (n == 0)
		return order;
	order.push_back(0);

	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		size_t current = jacobsthal[i];
		size_t previous = (i == 0) ? 0 : jacobsthal[i-1];
		
		if (current < n) {
			order.push_back(current);
		}
		
		for (size_t j = current - 1; j > previous; --j) {
			if (j < n) {
				order.push_back(j);
			}
		}
	}
	
	for (size_t i = 0; i < n; ++i) {
		if (std::find(order.begin(), order.end(), i) == order.end()) {
			order.push_back(i);
		}
	}

	return order;
}

template<typename Container>
size_t binaryInsertPosition(const Container& vec, int value) {
	size_t left = 0;
	size_t right = vec.size();

	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

#endif