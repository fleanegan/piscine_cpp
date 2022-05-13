#include <cstdio>
#include "gtest/gtest.h"
#include "test_utils.h"
#include "test_fixed.h"

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
