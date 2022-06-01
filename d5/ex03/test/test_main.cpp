#include <cstdio>
#include "gtest/gtest.h"
#include "test_utils.h"
#include "testBureaucrat.hpp"
#include "testShrubberyCreationForm.hpp"
#include "testIntern.hpp"

GTEST_API_ int main(int argc, char **argv) {
	std::cout << "Running main() from " << __FILE__ << std::endl;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
