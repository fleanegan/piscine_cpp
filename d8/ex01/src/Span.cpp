//
// Created by fleanegan on 08.06.22.
//

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "Span.hpp"

Span::Span(unsigned int maxCapacity) : \
        maxCapacity(maxCapacity), \
        currentIndex(0), \
		container(maxCapacity){

}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		container = other.container;
		maxCapacity = other.maxCapacity;
		currentIndex = other.currentIndex;
	}
	return *this;
}

Span::~Span() {

}

void Span::addNumber(int newNumber) {
	if (static_cast<int>(maxCapacity - currentIndex) <= 0)
		throw std::out_of_range("the Span is full!");
	container[currentIndex++] = newNumber;
}

int Span::shortestSpan()  {
	prepareSpanCalculation();
	return (container.at(1) - container.at(0));
}

int Span::longestSpan()  {
	prepareSpanCalculation();
	return (container.back() - container.front());
}

void Span::prepareSpanCalculation() {
	if (currentIndex <= 1)
		throw std::out_of_range("A Span requires at least two elements!");
	std::sort(container.begin(), container.begin() + currentIndex);
}
