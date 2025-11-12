/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:30 by drongier          #+#    #+#             */
/*   Updated: 2025/11/12 12:05:37 by drongier         ###   ########.fr       */
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

std::vector<int> pmerge::fordJohnson(const std::vector<int>& input) {
	if (input.size() <= 1)
		return input;

	std::vector<Item> items;
	items.reserve(input.size());
	for (size_t i = 0; i < input.size(); ++i)
		items.push_back(Item(input[i], i));

	std::vector<Item> sorted_items = fordJohnsonItems<std::vector<Item> >(items);

	std::vector<int> result;
	result.reserve(sorted_items.size());
	for (size_t i = 0; i < sorted_items.size(); ++i)
		result.push_back(sorted_items[i].val);
	
	return result;
}

std::deque<int> pmerge::fordJohnsonDeque(const std::deque<int>& input) {
	if (input.size() <= 1)
		return input;

	std::deque<Item> items;
	for (size_t i = 0; i < input.size(); ++i)
		items.push_back(Item(input[i], i));

	std::deque<Item> sorted_items = fordJohnsonItems<std::deque<Item> >(items);

	std::deque<int> result;
	for (size_t i = 0; i < sorted_items.size(); ++i)
		result.push_back(sorted_items[i].val);
	
	return result;
}
