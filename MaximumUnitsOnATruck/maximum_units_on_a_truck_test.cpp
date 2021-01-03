/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/03
 *
 * Source : https://leetcode-cn.com/problems/maximum-units-on-a-truck/
 * Problem: Maximum Units on a Truck
 *               
 */
#include <gtest/gtest.h>
#include "maximum_units_on_a_truck.h"

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
    int box_num;
    int unit_num;
  };
  TestData test_data[] = {
    {5,10},
    {2,5},
    {4,7},
    {3,9},
  };

  vector<vector<int> > vec;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vec.push_back(vector<int>());
    vec.back().push_back(test_data[i].box_num);
    vec.back().push_back(test_data[i].unit_num);
  }
  EXPECT_EQ(solution_.maximumUnits(vec, 10), 91);
}

