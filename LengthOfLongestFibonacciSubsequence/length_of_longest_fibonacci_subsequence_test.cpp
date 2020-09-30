/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/30
 *
 * Source : https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/
 * Problem:	Length of Longest Fibonacci Subsequence
 *
 */
#include <gtest/gtest.h>
#include "length_of_longest_fibonacci_subsequence.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, lenLongestFibSubseq) {
  int a[] = {1,2,3,4,5,6,7,8};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.lenLongestFibSubseq(vec), 5);
}

