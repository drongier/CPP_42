#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <exception>
#include <iostream>

class Span {
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:

		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		
		void addNumber(int number);
		
		int shortestSpan() const;
		int longestSpan() const;

		template<typename Iterator>
		void addRange(Iterator begin, Iterator end);

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Container Full !";
				}
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough elements to calculate span";
				}
		};
		
};

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
        addNumber(*it);
    }
}

#endif