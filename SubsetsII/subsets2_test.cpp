#include <gtest/gtest.h>
#include <iostream>
#include "subsets2.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  vector<vector<int> > vec = solution_.subsetsWithDup(nums);
  EXPECT_EQ(vec.size(), 6);
  for (size_t i = 0; i < vec.size(); ++i) {
    for (size_t j = 0; j < vec[i].size(); ++j) {
      std::cout << vec[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

