#include "test_utils.h"

TEST(span, addNumberOnNoCapacityThrows){
	Span a(0);

	ASSERT_ANY_THROW(a.addNumber(3));
}

TEST(span, addNumberWhileHavindFreeCapacityDoesNotThrow){
	Span a(1);

	ASSERT_NO_THROW(a.addNumber(3));
}

TEST(span, longestSpanWithUnsortedList){
	Span a(2);
	a.addNumber(1);
	a.addNumber(5);

	ASSERT_EQ(4, a.longestSpan());
}

TEST(span, shortestSpan){
	Span a(3);
	a.addNumber(1);
	a.addNumber(5);
	a.addNumber(2);

	ASSERT_EQ(1, a.shortestSpan());
}

TEST(span, calculationOfSpanOnEmptyListThrows){
	Span a(0);

	ASSERT_ANY_THROW(a.shortestSpan());
	ASSERT_ANY_THROW(a.longestSpan());
}

TEST(span, calculationOfSpanOnOneElementListThrows){
	Span a(1);
	a.addNumber(3);

	ASSERT_ANY_THROW(a.shortestSpan());
	ASSERT_ANY_THROW(a.longestSpan());
}

TEST(span, deepAssignment){
	Span a(3);
	a.addNumber(1);
	a.addNumber(2);
	Span b = a;
	b.addNumber(3);

	ASSERT_NE(b.longestSpan(), a.longestSpan());
}
