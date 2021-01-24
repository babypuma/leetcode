/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/24
 *
 * Source : https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/
 * Problem: Find Kth Largest XOR Coordinate Value
 *               
 */
#include <gtest/gtest.h>
#include "find_kth_largest_xor_coordinate_value.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  struct TestData {
    int k;
    int val;
  };
  TestData test_data[] = {
    {1, 7},
    {2, 5},
    {3, 4},
    {4, 0},
  };

  vector<vector<int> > matrix;
  matrix.push_back(vector<int>());
  matrix.back().push_back(5);
  matrix.back().push_back(2);
  matrix.push_back(vector<int>());
  matrix.back().push_back(1);
  matrix.back().push_back(6);

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vector<vector<int> > m(matrix);
    EXPECT_EQ(solution_.kthLargestValue(m, test_data[i].k), test_data[i].val);
  }
}

