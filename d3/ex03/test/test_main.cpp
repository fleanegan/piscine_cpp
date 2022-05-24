#include <cstdio>
#include "gtest/gtest.h"
#include "test_utils.h"
#include "test_clap_trap.hpp"
#include "test_scav_trap.hpp"
#include "test_frag_trap.hpp"

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
