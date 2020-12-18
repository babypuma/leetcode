/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/17
 *
 * Source : https://leetcode-cn.com/problems/height-checker/
 * Problem: Height Checker
 *               
 */
#include <gtest/gtest.h>
#include "height_checker.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,1,4,2,1,3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.heightChecker(vec), 3);
}

TEST_F(SolutionTest, case2) {
  int a[] = {5,1,2,3,4};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.heightChecker(vec), 5);
}

TEST_F(SolutionTest, case3) {
  int a[] = {1,2,3,4,5};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.heightChecker(vec), 0);
}

