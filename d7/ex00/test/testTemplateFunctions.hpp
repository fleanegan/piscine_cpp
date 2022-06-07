#include "test_utils.h"

struct B{
	int id;
	int value;

	bool operator<(const B &rhs) const {
		return value < rhs.value;
	}

	bool operator>(const B &rhs) const {
		return rhs < *this;
	}

	bool operator<=(const B &rhs) const {
		return !(rhs < *this);
	}

	bool operator>=(const B &rhs) const {
		return !(*this < rhs);
	}
};

TEST(min, returnSecondOnEquality){
	B a;
	B b;
	a.value = 0;
	b.value = 0;
	a.id = 0;
	b.id = 1;

	B res = min<B>(a, b);

	ASSERT_EQ(res.id, b.id);
}

TEST(min, simpleTest){
	int res = min<int>(4, 6);

	ASSERT_EQ(res, 4);
}


TEST(max, returnSecondOnEquality){
	B a;
	B b;
	a.value = 0;
	b.value = 0;
	a.id = 0;
	b.id = 1;

	B res = max<B>(a, b);

	ASSERT_EQ(res.id, b.id);
}

TEST(max, simpleTest){
	int res = max<int>(4, 6);

	ASSERT_EQ(res, 6);
}

TEST(swap, simpleTest){
	int a = 0;
	int b = 1;
	swap<int>(a, b);

	ASSERT_EQ(a, 1);
	ASSERT_EQ(b, 0);
}