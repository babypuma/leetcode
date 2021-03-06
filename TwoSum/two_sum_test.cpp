/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/08/31
 * Update : 2020/11/18
 *
 * Source : https://leetcode-cn.com/problems/two-sum/
 * Problem:	Two Sum
 *               
 */
#include <gtest/gtest.h>
#include "two_sum.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, hashTable) {
  vector<int> result;

  vector<int> v;
  v.push_back(2);
  v.push_back(7);
  v.push_back(11);
  v.push_back(15);
  result = solution_.twoSum(v, 9);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 1);

  v.clear();
  v.push_back(-3);
  v.push_back(4);
  v.push_back(3);
  v.push_back(15);
  result = solution_.twoSum(v, 0);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 2);

  int a[] = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
  vector<int> vec(a, a + sizeof(a) / sizeof(int));
  result = solution_.twoSum(vec, 542);
  EXPECT_EQ(result[0], 28);
  EXPECT_EQ(result[1], 45);
}

