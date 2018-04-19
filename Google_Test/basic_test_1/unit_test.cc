

#include <limits.h>
#include "math.h"
#include "gtest/gtest.h"
namespace {

TEST(is_even, Negative) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  EXPECT_FALSE(is_even(-5));
  EXPECT_FALSE(is_even(5));
  EXPECT_TRUE(is_even(0));

}

TEST(is_even, Positive){
  EXPECT_TRUE(is_even(1000000));
  EXPECT_FALSE(is_even(1000001));
}

}

