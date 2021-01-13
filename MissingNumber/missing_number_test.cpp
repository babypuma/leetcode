/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/05/20
 * Update : 2021/01/13
 *
 * Source : https://leetcode-cn.com/problems/missing-number/
 * Problem: Missing Number
 *               
 */
#include <gtest/gtest.h>
#include "missing_number.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, combinationSum) {
  int array[] = {9,6,4,2,3,5,7,0,1};
  vector<int> cand;
  for (size_t i = 0; i < sizeof(array)/sizeof(array[0]); ++i) {
    cand.push_back(array[i]);
  }
  int miss_num = solution_.missingNumber(cand);
  EXPECT_EQ(miss_num, 8);
}
