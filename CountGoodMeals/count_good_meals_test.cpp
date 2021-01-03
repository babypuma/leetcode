/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/03
 *
 * Source : https://leetcode-cn.com/problems/count-good-meals/
 * Problem: Count Good Meals
 *               
 */
#include <gtest/gtest.h>
#include "count_good_meals.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,1,1,3,3,3,7};
  vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.countPairs(vec), 15);
}

