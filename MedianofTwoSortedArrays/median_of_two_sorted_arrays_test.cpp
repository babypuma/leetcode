/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2020/12/05
 *
 * Source : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Problem:	Median of Two Sorted Arrays
 *               
 */
#include <gtest/gtest.h>
#include "median_of_two_sorted_arrays.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int A[] = {1, 3, 5, 7, 9};
  int B[] = {2, 4, 6, 8, 10};
  vector<int> v1(A, A + sizeof(A)/sizeof(A[0]));
  vector<int> v2(B, B + sizeof(B)/sizeof(B[0]));
  EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(v1, v2), 5.5);
}

TEST_F(SolutionTest, case4) {
  int A[] = {1, 3, 5};
  int B[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  vector<int> v1(A, A + sizeof(A)/sizeof(A[0]));
  vector<int> v2(B, B + sizeof(B)/sizeof(B[0]));
  EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(v1, v2), 8.0);
}

TEST_F(SolutionTest, case5) {
  int A[] = {1, 3, 5};
  int B[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
  vector<int> v1(A, A + sizeof(A)/sizeof(A[0]));
  vector<int> v2(B, B + sizeof(B)/sizeof(B[0]));
  EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(v1, v2), 9.0);
}

TEST_F(SolutionTest, case6) {
  int A[] = {1, 3, 5, 7, 9};
  int B[] = {2, 4, 6, 8, 10, 12};
  vector<int> v1(A, A + sizeof(A)/sizeof(A[0]));
  vector<int> v2(B, B + sizeof(B)/sizeof(B[0]));
  EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(v1, v2), 6.0);
}

TEST_F(SolutionTest, case8) {
  int A[] = {2, 2, 2, 2};
  int B[] = {2, 2, 2};
  vector<int> v1(A, A + sizeof(A)/sizeof(A[0]));
  vector<int> v2(B, B + sizeof(B)/sizeof(B[0]));
  EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(v1, v2), 2.0);
}

TEST_F(SolutionTest, case9) {
  int A[] = {3};
  int B[] = {1, 2};
  vector<int> v1(A, A + sizeof(A)/sizeof(A[0]));
  vector<int> v2(B, B + sizeof(B)/sizeof(B[0]));
  EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(v1, v2), 2.0);
}
