/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/11
 *
 * Source : https://leetcode-cn.com/problems/search-in-a-sorted-array-of-unknown-size/
 * Problem: Search in a Sorted Array of Unknown Size
 *               
 */
#include <gtest/gtest.h>
#include "search_in_a_sorted_array_of_unknown_size.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {-1,0,3,5,9,12};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  ArrayReader reader(vec);
  EXPECT_EQ(solution_.search(vec, 9), 4);
}

