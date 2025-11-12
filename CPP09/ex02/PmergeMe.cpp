/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:30 by drongier          #+#    #+#             */
/*   Updated: 2025/11/12 09:56:31 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <string>
#include <sys/time.h>

pmerge::pmerge() {}

pmerge::~pmerge() {}

void pmerge::addToDeque(int value) {
	_deque.push_back(value);
}

void pmerge::addToVector(int value) {
	_vector.push_back(value);
}

void pmerge::printNumber() const {
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void pmerge::display_time(struct timeval& ts1, struct timeval& ts2)
{
	size_t total_micros1 = ts1.tv_sec * MIL + ts1.tv_usec;
	size_t total_micros2 = ts2.tv_sec * MIL + ts2.tv_usec;
	size_t diff_micros = total_micros2 - total_micros1;
	size_t sec = diff_micros / MIL;
	size_t msec = (diff_micros % MIL) / 1000;
	size_t usec = (diff_micros % MIL) % 1000;
	std::cout << sec << " secs, " << msec << " ms and " << usec << " us." << std::endl;
}

bool isPositiveInteger(const std::string& str) {
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]))
			return false;
	}
	long val = std::strtol(str.c_str(), NULL, 10);
	if (val > INT_MAX || val < 0)
		return false;
	return true;
}

bool pmerge::parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq) {
	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);
		if (!isPositiveInteger(arg)) {
			std::cerr << "Error: invalid argument '" << arg << "' (must be a positive integer)" << std::endl;
			return false;
		}
		int value = std::atoi(arg.c_str());
		vec.push_back(value);
		deq.push_back(value);
	}
	return true;
}

void printVector(const std::vector<int>& vect) {
	for (size_t i = 0; i < vect.size(); ++i) {
		std::cout << vect[i] << ", ";
	}
	std::cout << std::endl;
}

void pmerge::printDeque(const std::deque<int>& vect) {
	if (vect.size() > 15) {
			for (size_t i = 0; i < 15; ++i) {
			std::cout << vect[i] << " ";
		}
		std::cout << "[...]" << std::endl;
	}
	else {
		for (size_t i = 0; i < vect.size(); ++i) {
			std::cout << vect[i] << " ";
		}
		std::cout << std::endl;
	}
}

void pmerge::printPairs(const std::vector<Pair>& pairs) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << "(" << pairs[i].a << ", " << pairs[i].b << ")";
	}
	std::cout << std::endl;
}

std::vector<int> pmerge::fordJohnson(const std::vector<int>& input) {
	if (input.size() <= 1)
		return input;

	std::vector<Pair> pairs = makePaire<std::vector<int>, std::vector<Pair> >(input);
	std::vector<int> winners = extractWinners<std::vector<Pair>, std::vector<int> >(pairs);
	std::vector<int> losers = extractLosers<std::vector<Pair>, std::vector<int> >(pairs);
	int unpaired = findUnpaired(pairs);

	std::vector<int> main_chain = fordJohnson(winners);

	std::vector<size_t> order = generateJacobsthalOrder<std::vector<size_t> >(losers.size());
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		int val = losers[idx];
		size_t pos = binaryInsertPosition(main_chain, val);
		main_chain.insert(main_chain.begin() + pos, val);
	}

	if (unpaired != -1) {
		size_t pos = binaryInsertPosition(main_chain, unpaired);
		main_chain.insert(main_chain.begin() + pos, unpaired);
	}
	return main_chain;
}

std::deque<int> pmerge::fordJohnsonDeque(const std::deque<int>& input) {
	if (input.size() <= 1)
		return input;

	std::deque<Pair> pairs = makePaire<std::deque<int>, std::deque<Pair> >(input);
	std::deque<int> winners = extractWinners<std::deque<Pair>, std::deque<int> >(pairs);
	std::deque<int> losers = extractLosers<std::deque<Pair>, std::deque<int> >(pairs);
	int unpaired = findUnpaired(pairs);

	std::deque<int> main_chain = fordJohnsonDeque(winners);

	std::deque<size_t> order = generateJacobsthalOrder<std::deque<size_t> >(losers.size());
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		int val = losers[idx];
		size_t pos = binaryInsertPosition(main_chain, val);
		main_chain.insert(main_chain.begin() + pos, val);
	}

	if (unpaired != -1) {
		size_t pos = binaryInsertPosition(main_chain, unpaired);
		main_chain.insert(main_chain.begin() + pos, unpaired);
	}
	return main_chain;
}
