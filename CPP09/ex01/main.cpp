#include "RPN.hpp"

int main(int ac, char **av) {

    if (ac != 2)
        throw "Error : input";
    
    RPN rpn;

    int result = rpn.calculate(av[1]);

    std::cout << result << std::endl;

    return(0); 
}