#include "test_utils.h"

TEST(swap, defaultArraySizeZero){
	Array<int> test;

	ASSERT_EQ(0, test.size());
}

TEST(swap, intConstructorSetsSize){
	Array<int> test(5);

	ASSERT_EQ(5, test.size());
}

TEST(array, canUseMemory){
	Array<int> test(5);

	test[0] = 5;
	ASSERT_EQ(5, test[0]);
}

TEST(array, accessingMemoryOutOfBoundThrowsErrorUpper){
	Array<int> test;

	ASSERT_ANY_THROW(test[0] = 7);
}

TEST(array, accessingMemoryOutOfBoundThrowsErrorLower){
	Array<int> test;

	ASSERT_ANY_THROW(test[-10] = 7);
}

TEST(array, deepCopy){
	Array<int> a(2);
	a[0] = 42;
	a[1] = 43;

	Array<int> b(a);
	b[0]++;
	b[1]++;
	ASSERT_EQ(42, a[0]);
	ASSERT_EQ(a[0] + 1, b[0]);
	ASSERT_EQ(43, a[1]);
	ASSERT_EQ(a[1] + 1, b[1]);
}

TEST(array, copyIntoSmallerObjectReallocates){
	Array<int> a(2);
	a[0] = 42;
	a[1] = 43;

	Array<int> b(1);
	b = a;
	ASSERT_EQ(a[0], b[0]);
	ASSERT_EQ(a[1], b[1]);
}

TEST(array, selfAssignment){
	Array<int> a(2);
	a[0] = 42;
	a[1] = 43;

	a = a;
	ASSERT_EQ(42, a[0]);
	ASSERT_EQ(43, a[1]);
}

//customClass