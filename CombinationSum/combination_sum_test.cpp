#include <gtest/gtest.h>
#include "combination_sum.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, combinationSum) {
  int array[] = {2, 3, 6, 7};
  vector<int> cand;
  for (size_t i = 0; i < sizeof(array)/sizeof(array[0]); ++i) {
    cand.push_back(array[i]);
  }
  vector<vector<int> > vec_2_dim = solution_.combinationSum(cand, 7);
  EXPECT_EQ(vec_2_dim.size(), 2);
}
