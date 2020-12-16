/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/remove-element/
 * Problem:	Remove Element
 *               
 */
#include <gtest/gtest.h>
#include "remove_element.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1, 2, 2, 3, 4, 5};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  int length = solution_.removeElement(vec, 2);

  int b[] = {1, 3, 4, 5};
  ASSERT_EQ((int)sizeof(b)/sizeof(int), length);
  for (size_t i = 0; i < length; i++) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

TEST_F(SolutionTest, case2) {
  int a[] = {1, 2, 2, 3, 4, 5};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  int length = solution_.removeElement(vec, 5);

  int b[] = {1, 2, 2, 3, 4};
  ASSERT_EQ((int)sizeof(b)/sizeof(int), length);
  for (size_t i = 0; i < length; i++) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

