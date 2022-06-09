#include "test_utils.h"

TEST(mutantStack, canStillUseStackFunctions) {
	MutantStack<int> m;
	MutantStack<int> m1;
	ASSERT_TRUE(m.empty());
	m.push(3);
	ASSERT_FALSE(m.empty());
	m.push(4);
	m.emplace(5);
	ASSERT_EQ(3, m.size());
	ASSERT_EQ(5, m.top());
	m.swap(m1);
	ASSERT_TRUE(m.empty());
	ASSERT_FALSE(m1.empty());
	ASSERT_EQ(5, m1.top());
	m1.pop();
	ASSERT_EQ(2, m1.size());
}

TEST(mutantStack, canIterate) {
	MutantStack<int> m;
	m.push(1);
	m.push(2);
	m.push(3);
	m.push(4);
	for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it){
		std::cout << *it << std::endl;
	}
}