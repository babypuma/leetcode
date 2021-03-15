/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/15
 *
 * Source : https://leetcode-cn.com/problems/maximum-score-of-a-good-subarray/
 * Problem: Maximum Score of a Good Subarray
 *               
 */
#include <gtest/gtest.h>
#include "maximum_score_of_a_good_subarray.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,4,3,7,4,5};
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maximumScore(nums, 3), 15);
}

TEST_F(SolutionTest, case2) {
  int a[] = {6569,9667,3148,7698,1622,2194,793,9041,1670,1872};
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maximumScore(nums, 5), 9732);
}

