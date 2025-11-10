#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept> 
#include <iostream>

class RPN {
	private: 
		std::stack<int> _stack;
	public:
		RPN();
		int calculate(const std::string& expression);
};
