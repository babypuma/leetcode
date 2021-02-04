/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/04
 *
 * Source : https://leetcode-cn.com/problems/maximum-average-subarray-i/
 * Problem: Maximum Average Subarray I
 *               
 */
#include <gtest/gtest.h>
#include "maximum_average_subarray_i.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,12,-5,-6,50,3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_DOUBLE_EQ(solution_.findMaxAverage(vec, 4), 12.75);
}

TEST_F(SolutionTest, case2) {
  int a[] = {8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,-79,-4418,-4348,-5891};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_DOUBLE_EQ(solution_.findMaxAverage(vec, 93), -594.58065);
}

