#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span(void) {}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    else
        _numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (_numbers.size() <= 1)
        throw NoSpanException();
    else {
        std::vector<int> sorted = _numbers;
        std::sort(sorted.begin(), sorted.end());
        int miniSpan = sorted[1] - sorted[0];
        for (size_t i = 2; i < sorted.size(); i++) {
            int diffSpan = sorted[i] - sorted[i - 1];
            if (diffSpan < miniSpan) {
                miniSpan = diffSpan;
            }
        }
        return miniSpan;
    }
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1)
        throw NoSpanException();
    else {
        int minVal = *std::min_element(_numbers.begin(), _numbers.end());
        int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
        return (maxVal - minVal);
    }
}