//
// Created by fleanegan on 08.06.22.
//

#ifndef EX01_SPAN_HPP
#define EX01_SPAN_HPP

#include <vector>

class Span {
private:
	unsigned int maxCapacity;
	unsigned int currentIndex;
	std::vector<int> container;

	Span();
	void prepareSpanCalculation();
public:
	Span(unsigned int maxCapacity);
	Span(const Span &other);
	Span &operator=(const Span &);
	~Span();

	void addNumber(int);
	int shortestSpan();
	int longestSpan();
};

#endif //EX01_SPAN_HPP
