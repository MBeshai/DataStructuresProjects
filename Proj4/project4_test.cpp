#include <iostream>
#include "Driver.h"
#include "/afs/umbc.edu/users/c/m/cmarron/pub/gtest-1.7.0/include/gtest/gtest.h"

using namespace std;

/* VALID INPUT TESTS FOR Factorial() GO HERE */
TEST(runDriverTest, HandlesValidInput) {
  EXPECT_DOUBLE_EQ(31.54, runDriver("Sample1Store.txt", "Sample1Orders.txt"));             // lower edge case                                                                                                     
  EXPECT_DOUBLE_EQ(55.96, runDriver("Sample2Store.txt", "Sample2Orders.txt"));    //run driver test                                                                                                               
}

/* INVALID INPUT TESTS FOR Factorial() GO HERE */
TEST(runDiverTest, HandlesInvalidInput) {
  EXPECT_DOUBLE_EQ(-1, runDriver("Sample2131Store.txt", "Sample12312Orders.txt"));             // lower edge case                                                                                                 
  EXPECT_DOUBLE_EQ(-1, runDriver("Sample12312Pizza.txt", "Chick Fil a"));
}

int test_main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
