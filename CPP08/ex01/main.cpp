#include "Span.hpp"

int main()
{

Span sp = Span(3);
sp.addNumber(1);
sp.addNumber(3);
sp.addNumber(10);

std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

std::vector<int> bigNumbers;
for (int i = 0; i < 100; i++) {
    bigNumbers.push_back(i);
    std::cout << bigNumbers[i];
}

Span bigSpan(100);
bigSpan.addRange(bigNumbers.begin(), bigNumbers.end());

std::cout << "shortestSpan : " << bigSpan.shortestSpan() << std::endl;
std::cout << "longestSpan : " << bigSpan.longestSpan() << std::endl;

return 0;

}