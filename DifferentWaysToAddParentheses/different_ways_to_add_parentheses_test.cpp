
#include <gtest/gtest.h>
#include "different_ways_to_add_parentheses.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {2,0};
  vector<int> b = solution_.diffWaysToCompute("2-1-1");
  EXPECT_EQ(b.size(), sizeof(a)/sizeof(a[0]));
  for (size_t i = 0; i < b.size(); ++i) {
    EXPECT_EQ(b[i], a[i]);
  }
}

TEST_F(SolutionTest, case2) {
  int a[] = {-34, -10, -14, -10, 10};
  vector<int> b = solution_.diffWaysToCompute("2*3-4*5");
  EXPECT_EQ(b.size(), sizeof(a)/sizeof(a[0]));
  for (size_t i = 0; i < b.size(); ++i) {
    EXPECT_EQ(b[i], a[i]);
  }
}

