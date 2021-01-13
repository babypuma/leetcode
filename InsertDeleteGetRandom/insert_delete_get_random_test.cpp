/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/13
 *
 * Source : https://leetcode-cn.com/problems/insert-delete-getrandom-o1/
 * Problem: Insert Delete GetRandom O(1)
 *               
 */
#include <gtest/gtest.h>
#include "insert_delete_get_random.h"

TEST(SolutionTest, RandomizedSet) {
  RandomizedSet rset;
  EXPECT_TRUE(rset.insert(1));
  EXPECT_FALSE(rset.remove(2));
  EXPECT_TRUE(rset.insert(2));
  EXPECT_TRUE(rset.getRandom() == 1 || rset.getRandom() == 2);
  EXPECT_TRUE(rset.remove(1));
  EXPECT_FALSE(rset.insert(2));
  EXPECT_TRUE(rset.getRandom() == 2);
}

