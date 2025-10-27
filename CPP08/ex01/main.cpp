#include "Span.hpp"

int main()
{

Span sp = Span(3);
sp.addNumber(1);
sp.addNumber(3);
sp.addNumber(10);

std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
std::cout << "longestSpan : " << sp.longestSpan() << std::endl;

std::vector<int> bigNumbers;
for (int i = 0; i < 1001; i++) {
    bigNumbers.push_back(i * 7 + (i % 13));
    std::cout << "["<< bigNumbers[i] << "]";
}

Span bigSpan(1001);
try {
    bigSpan.addRange(bigNumbers.begin(), bigNumbers.end());
    std::cout << std::endl << "shortestSpan : " << bigSpan.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << bigSpan.longestSpan() << std::endl;
} catch (const Span::SpanFullException& e) {
    std::cout << std::endl << "Erreur : " << e.what() << std::endl;
}
std::cout << std::endl;

return 0;

}