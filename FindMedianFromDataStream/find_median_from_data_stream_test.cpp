/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/07
 *
 * Source : https://leetcode-cn.com/problems/find-median-from-data-stream/
 * Problem: Find Median from Data Stream
 *               
 */
#include <gtest/gtest.h>
#include "find_median_from_data_stream.h"

TEST(SolutionTest, MedianFinder) {
  int a[] = {1, 2, 3, 4, 5};
  MedianFinder mf;
  for (auto& i : a) {
    mf.addNum(i);
  }
  EXPECT_DOUBLE_EQ(mf.findMedian(), 3.0);
}

TEST(SolutionTest, MedianFinder2) {
  int a[] = {1, 2, 3, 4, 5, 6};
  MedianFinder mf;
  for (auto& i : a) {
    mf.addNum(i);
  }
  EXPECT_DOUBLE_EQ(mf.findMedian(), 3.5);
}

TEST(SolutionTest, MedianFinder3) {
  MedianFinder mf;
  mf.addNum(1);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 1.0);
  mf.addNum(2);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 1.5);
  mf.addNum(3);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 2.0);
  mf.addNum(4);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 2.5);
  mf.addNum(5);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 3.0);
  mf.addNum(6);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 3.5);
  mf.addNum(7);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 4.0);
  mf.addNum(8);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 4.5);
  mf.addNum(9);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 5.0);
  mf.addNum(10);
  EXPECT_DOUBLE_EQ(mf.findMedian(), 5.5);
}

