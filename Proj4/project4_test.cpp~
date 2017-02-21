#include <iostream>
#include "factorial.h"
#include "/afs/umbc.edu/users/c/m/cmarron/pub/gtest-1.7.0/include/gtest/gtest.h"

using namespace std;

/* VALID INPUT TESTS FOR Factorial() GO HERE */
TEST(FactorialTest, HandlesValidInput) {
  EXPECT_EQ(1, Factorial(0));             // lower edge case
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6.00, Factorial(3));
  EXPECT_EQ(479001600, Factorial(12));
}

/* INVALID INPUT TESTS FOR Factorial() GO HERE */
TEST(FactorialTest, HandlesInvalidInput) {
  EXPECT_EQ(1, Factorial(0));             // lower edge case
  EXPECT_EQ(1, Factorial(-1));
  EXPECT_EQ(1, Factorial(-2));
  EXPECT_EQ(1, Factorial(-3));
  EXPECT_EQ(1, Factorial(-12));
}

int test_main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
