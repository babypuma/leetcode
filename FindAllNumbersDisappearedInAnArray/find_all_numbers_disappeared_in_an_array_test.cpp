/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/14
 *
 * Source : https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 * Problem: Find All Numbers Disappeared in an Array
 *               
 */
#include <gtest/gtest.h>
#include "find_all_numbers_disappeared_in_an_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {4,3,2,7,8,2,3,1};
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  int b[] = {5,6};
  vector<int> dis = solution_.findDisappearedNumbers(nums);
  EXPECT_EQ(dis.size(), sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < dis.size(); ++i) {
    EXPECT_EQ(dis[i], b[i]);
  }
}

