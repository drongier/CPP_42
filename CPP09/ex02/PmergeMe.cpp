#include "PmergeMe.hpp"

pmerge::pmerge() {}

pmerge::~pmerge() {}

void pmerge::addToSeq(int value) {
	_sequence.push_back(value);
}

void pmerge::addToNumber(int value) {
	_numbers.push_back(value);
}

void pmerge::printNumber() const {
	for (size_t i = 0; i < _numbers.size(); i++)
		std::cout << _numbers[i] << " ";
	std::cout << std::endl;
}

std::vector<int>& pmerge::getNumbers() {
	return _numbers;
}

void pmerge::printPairs(const std::vector<Pair>& pairs) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << "(" << pairs[i].a << ", " << pairs[i].b << ")";
	}
	std::cout << std::endl;
}

std::vector<Pair> pmerge::makePaire(const std::vector<int>& input) {
	std::vector<Pair> pairs;

	for (size_t i = 0; i + 1 < input.size(); i += 2) {
		int x = input[i];
		int y = input[i + 1];
		Pair p;
		p.a = x;
		p.b = y;
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