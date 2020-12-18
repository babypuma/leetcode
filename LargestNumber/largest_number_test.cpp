/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/17
 *
 * Source : https://leetcode-cn.com/problems/largest-number/
 * Problem: Largest Number
 *               
 */
#include <gtest/gtest.h>
#include "largest_number.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {3,30,34,5,9};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_STREQ(solution_.largestNumber(vec).c_str(), "9534330");
}

TEST_F(SolutionTest, case2) {
  int a[] = {24, 242424};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_STREQ(solution_.largestNumber(vec).c_str(), "24242424");
}

TEST_F(SolutionTest, case3) {
  int a[] = {24, 242624};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_STREQ(solution_.largestNumber(vec).c_str(), "24262424");
}

TEST_F(SolutionTest, case4) {
  int a[] = {24, 242324};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_STREQ(solution_.largestNumber(vec).c_str(), "24242324");
}

TEST_F(SolutionTest, case5) {
  int a[] = {0, 0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_STREQ(solution_.largestNumber(vec).c_str(), "0");
}

TEST_F(SolutionTest, case6) {
  int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_STREQ(solution_.largestNumber(vec).c_str(), "0");
}

