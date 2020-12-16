/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * Problem:	Remove Duplicates from Sorted Array
 *               
 */
#include <gtest/gtest.h>
#include "remove_duplicates_from_sorted_array.h"

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
  int length = solution_.removeDuplicates(vec);

  int b[] = {1, 2, 3, 4, 5};
  ASSERT_EQ(length, (int)sizeof(b)/sizeof(int));
  for (int i = 0; i < length; i++) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

