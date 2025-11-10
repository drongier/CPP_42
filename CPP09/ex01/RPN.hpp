#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept> 
#include <iostream>

class RPN {
	private: 
		std::stack<int> _stack;
		bool isOperation(char c);
		int performOperation(int a, int b, char op);

	public:
		RPN();
		int calculate(const std::string& expression);
};
