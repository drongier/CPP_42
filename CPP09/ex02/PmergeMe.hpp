#include <vector>
#include <deque>
#include <iostream>

struct Pair {
	int a;
	int b;
};

class pmerge {
	private: 
		std::vector<int> _numbers;
		std::vector<int> _sequence;
	public:
		pmerge();
		~pmerge();
		void addToSeq(int value);
		void addToNumber(int value);
		void printNumber() const;
		std::vector<int>& getNumbers();
		void printPairs(const std::vector<Pair>& pairs);

		std::vector<Pair> makePaire(const std::vector<int>& input);
};