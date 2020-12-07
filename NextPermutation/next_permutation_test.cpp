/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/06
 * Update : 2020/12/07
 *
 * Source : https://leetcode-cn.com/problems/next-permutation/
 * Problem:	Next Permutation
 *
 */
#include <gtest/gtest.h>
#include "next_permutation.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case4) {
  int a[] = {1, 2, 3};
  vector<int> vec(a, a + sizeof(a)/sizeof(int));

  int b[] = {1, 3, 2};
  solution_.nextPermutation(vec);
  for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

TEST_F(SolutionTest, case5) {
  int a[] = {3, 2, 1};
  vector<int> vec(a, a + sizeof(a)/sizeof(int));

  int b[] = {1, 2, 3};
  solution_.nextPermutation(vec);
  for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

TEST_F(SolutionTest, case6) {
  int a[] = {1, 1, 5};
  vector<int> vec(a, a + sizeof(a)/sizeof(int));

  int b[] = {1, 5, 1};
  solution_.nextPermutation(vec);
  for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

TEST_F(SolutionTest, case7) {
  int a[] = {4, 2, 0, 2, 3, 2, 0};
  vector<int> vec(a, a + sizeof(a)/sizeof(int));

  int b[] = {4, 2, 0, 3, 0, 2, 2};
  solution_.nextPermutation(vec);
  for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

TEST_F(SolutionTest, case8) {
  int a[] = {2, 1, 2, 2, 2, 2, 2, 1};
  vector<int> vec(a, a + sizeof(a)/sizeof(int));

  int b[] = {2, 2, 1, 1, 2, 2, 2, 2};
  solution_.nextPermutation(vec);
  for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

