#include <vector>
#include <deque>
#include <iostream>

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
		void printVector(const std::vector<int>& vect);
		std::vector<int> fordJohnson(const std::vector<int>& input);
		std::deque<int> fordJohnsonDeque(const std::deque<int>& input);
		bool parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq);
};