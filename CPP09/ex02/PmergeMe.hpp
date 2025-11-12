/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:49 by drongier          #+#    #+#             */
/*   Updated: 2025/11/12 12:14:08 by drongier         ###   ########.fr       */
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

struct Item {
	int val;
	size_t id;
	Item() : val(-1), id(0) {}
	Item(int v, size_t i) : val(v), id(i) {}
};

struct PairItem {
	Item a;
	Item b;
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
		void printDeque(const std::deque<int>& vect);
		std::vector<int> fordJohnson(const std::vector<int>& input);
		std::deque<int> fordJohnsonDeque(const std::deque<int>& input);
		bool parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq);
		void display_time(struct timeval& ts1, struct timeval& ts2);
};

template<typename PairItemContainer, typename ItemContainer>
ItemContainer extractWinnersItems(const PairItemContainer& pairs) {
	ItemContainer winners;
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].b.val != -1) {
			winners.push_back(pairs[i].a);
		}
	}
	return winners;
}

template<typename PairItemContainer, typename ItemContainer>
ItemContainer extractLosersItems(const PairItemContainer& pairs) {
	ItemContainer losers;
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].b.val != -1) {
			losers.push_back(pairs[i].b);
		}
	}
	return losers;
}

template<typename ItemContainer, typename PairItemContainer>
PairItemContainer makePaireItems(const ItemContainer& input) {
	PairItemContainer pairs;
	for (size_t i = 0; i + 1 < input.size(); i += 2) {
		Item x = input[i];
		Item y = input[i + 1];
		PairItem p;
		if (x.val > y.val) {
			p.a = x;
			p.b = y;
		} else {
			p.a = y;
			p.b = x;
		}
		pairs.push_back(p);
	}
	if (input.size() % 2 != 0) {
		PairItem p;
		p.a = input.back();
		p.b = Item(-1, 0);
		pairs.push_back(p);
	}
	return pairs;
}

template<typename PairItemContainer>
Item findUnpairedItem(const PairItemContainer& pairs) {
	if (pairs.empty())
		return Item(-1, 0);
	const PairItem& last = pairs.back();
	if (last.b.val == -1)
		return last.a;
	return Item(-1, 0);
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

template<typename ItemContainer>
size_t binaryInsertPositionItem(const ItemContainer& vec, const Item& item) {
	size_t left = 0;
	size_t right = vec.size();

	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (vec[mid].val < item.val)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

template<typename ItemContainer>
size_t findWinnerPosition(const ItemContainer& main_chain, size_t winner_id) {
	for (size_t i = 0; i < main_chain.size(); ++i) {
		if (main_chain[i].id == winner_id)
			return i;
	}
	return main_chain.size();
}

template<typename ItemContainer>
ItemContainer fordJohnsonItems(const ItemContainer& input) {
	if (input.size() <= 1)
		return input;

	typedef std::vector<PairItem> PairVec;
	PairVec pairs = makePaireItems<ItemContainer, PairVec>(input);
	
	ItemContainer winners = extractWinnersItems<PairVec, ItemContainer>(pairs);
	ItemContainer losers = extractLosersItems<PairVec, ItemContainer>(pairs);
	Item unpaired = findUnpairedItem<PairVec>(pairs);

	ItemContainer main_chain = fordJohnsonItems<ItemContainer>(winners);

	std::vector<size_t> order = generateJacobsthalOrder<std::vector<size_t> >(losers.size());
	
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		Item loser = losers[idx];
		Item winner = winners[idx];
		
		size_t winner_pos = findWinnerPosition<ItemContainer>(main_chain, winner.id);
		size_t left = 0;
		size_t right = winner_pos + 1;
		
		while (left < right) {
			size_t mid = left + (right - left) / 2;
			if (main_chain[mid].val < loser.val)
				left = mid + 1;
			else
				right = mid;
		}
		main_chain.insert(main_chain.begin() + left, loser);
	}

	if (unpaired.val != -1) {
		size_t pos = binaryInsertPositionItem<ItemContainer>(main_chain, unpaired);
		main_chain.insert(main_chain.begin() + pos, unpaired);
	}
	
	return main_chain;
}

#endif