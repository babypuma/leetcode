#include <gtest/gtest.h>
#include "permutations_ii.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, permuteUnique) {
  int array[] = {1, 1, 2};
  vector<int> cand;
  for (size_t i = 0; i < sizeof(array)/sizeof(array[0]); ++i) {
    cand.push_back(array[i]);
  }
  vector<vector<int> > vec_2_dim = solution_.permuteUnique(cand);
  EXPECT_EQ(vec_2_dim.size(), 3);
}
