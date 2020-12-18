/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/19
 *
 * Source : https://leetcode-cn.com/problems/design-compressed-string-iterator/
 * Problem: Design Compressed String Iterator
 *               
 */
#include <gtest/gtest.h>
#include "design_compressed_string_iterator.h"

TEST(SolutionTest, StringIterator) {
  StringIterator iter("L1e2t1C1o1d1e1");
  EXPECT_TRUE(iter.next() == 'L');
  EXPECT_TRUE(iter.next() == 'e');
  EXPECT_TRUE(iter.next() == 'e');
  EXPECT_TRUE(iter.next() == 't');
  EXPECT_TRUE(iter.next() == 'C');
  EXPECT_TRUE(iter.next() == 'o');
  EXPECT_TRUE(iter.hasNext());
  EXPECT_TRUE(iter.next() == 'd');
  EXPECT_TRUE(iter.hasNext());
  EXPECT_TRUE(iter.next() == 'e');
  EXPECT_FALSE(iter.hasNext());
}

TEST(SolutionTest, StringIterator2) {
  StringIterator iter("x6");
  EXPECT_TRUE(iter.next() == 'x');
  EXPECT_TRUE(iter.next() == 'x');
  EXPECT_TRUE(iter.next() == 'x');
  EXPECT_TRUE(iter.next() == 'x');
  EXPECT_TRUE(iter.next() == 'x');
  EXPECT_TRUE(iter.hasNext());
  EXPECT_TRUE(iter.next() == 'x');
  EXPECT_FALSE(iter.hasNext());
  EXPECT_TRUE(iter.next() == ' ');
}

