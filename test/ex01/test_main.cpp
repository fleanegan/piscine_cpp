#include <cstdio>
#include "gtest/gtest.h"
#include "test_utils.h"
#include "test_phone_book.h"
#include "test_contact.h"

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
