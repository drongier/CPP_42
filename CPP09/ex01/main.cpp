#include "RPN.hpp"

int main(int ac, char **av) {
	try {	
		if (ac != 2) { 
			std::cerr << "Error : input" << std::endl;
			return (1);
		}

		RPN rpn;
		int result = rpn.calculate(av[1]);
		std::cout << result << std::endl;
		
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return (0);
}