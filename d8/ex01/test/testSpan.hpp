#include "test_utils.h"

TEST(span, addNumberOnNoCapacityThrows) {
	Span a(0);

	ASSERT_ANY_THROW(a.addNumber(3));
}

TEST(span, addNumberWhileHavindFreeCapacityDoesNotThrow) {
	Span a(1);

	ASSERT_NO_THROW(a.addNumber(3));
}

TEST(span, longestSpanWithUnsortedList) {
	Span a(2);
	a.addNumber(1);
	a.addNumber(5);

	ASSERT_EQ(4, a.longestSpan());
}

TEST(span, shortestSpan) {
	Span a(3);
	a.addNumber(1);
	a.addNumber(5);
	a.addNumber(2);

	ASSERT_EQ(1, a.shortestSpan());
}

TEST(span, shortestSpanWithTrickyNumbers) {
	Span a(3);
	a.addNumber(1);
	a.addNumber(3);
	a.addNumber(4);

	ASSERT_EQ(1, a.shortestSpan());
}

TEST(span, calculationOfSpanOnEmptyListThrows) {
	Span a(0);

	ASSERT_ANY_THROW(a.shortestSpan());
	ASSERT_ANY_THROW(a.longestSpan());
}

TEST(span, calculationOfSpanOnOneElementListThrows) {
	Span a(1);
	a.addNumber(3);

	ASSERT_ANY_THROW(a.shortestSpan());
	ASSERT_ANY_THROW(a.longestSpan());
}

TEST(span, deepAssignment) {
	Span a(3);
	a.addNumber(1);
	a.addNumber(2);
	Span b = a;
	b.addNumber(3);

	ASSERT_NE(b.longestSpan(), a.longestSpan());
}

TEST(span, addingRangeTooBigThrows) {
	Span a(1);
	std::vector<int> tooBig{0, 1, 2};

	ASSERT_ANY_THROW(a.addRange(tooBig.begin(), tooBig.end()));
}

TEST(span, manyNumbers) {
	int elementCount = 2000;
	std::srand(unsigned(std::time(NULL)));
	std::vector<int> input(elementCount);
	std::generate(input.begin(), input.end(), std::rand);
	Span a(elementCount + 1);
	a.addNumber(235);
	a.addRange(input.begin(), input.end());

	std::cout << a.shortestSpan() << " is the shortest span" << std::endl;
	std::cout << a.longestSpan() << " is the longest span" << std::endl;
}