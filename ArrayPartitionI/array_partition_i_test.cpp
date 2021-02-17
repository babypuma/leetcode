/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/16
 *
 * Source : https://leetcode-cn.com/problems/array-partition-i/
 * Problem: Array Partition I
 *               
 */
#include <gtest/gtest.h>
#include "array_partition_i.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,4,3,2};
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.arrayPairSum(nums), 4);
}

