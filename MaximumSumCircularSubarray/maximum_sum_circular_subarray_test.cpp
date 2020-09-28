/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/26
 *
 * Source : https://leetcode-cn.com/problems/maximum-sum-circular-subarray/
 * Problem:	Maximum Sum Circular Subarray
 *
 */
#include <gtest/gtest.h>
#include "maximum_sum_circular_subarray.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, maxSubarraySumCircular) {
  int a[] = {5,-3,5};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxSubarraySumCircular(vec), 10);
}

TEST_F(SolutionTest, maxSubarraySumCircular2) {
  int a[] = {1,-2,3,-2};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxSubarraySumCircular(vec), 3);
}

TEST_F(SolutionTest, maxSubarraySumCircular3) {
  int a[] = {-2};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxSubarraySumCircular(vec), -2);
}

TEST_F(SolutionTest, maxSubarraySumCircular4) {
  int a[] = {8,-1,-3,8,-6,-9,2,4};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxSubarraySumCircular(vec), 18);
}

TEST_F(SolutionTest, maxSubarraySumCircular5) {
  int a[] = {2,-2,2,7,8,0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxSubarraySumCircular(vec), 19);
}

