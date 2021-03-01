/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/01
 *
 * Source : https://leetcode-cn.com/problems/count-items-matching-a-rule/
 * Problem: Count Items Matching a Rule
 *               
 */
#include <gtest/gtest.h>
#include "count_items_matching_a_rule.h"

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
    string type;
    string color;
    string name;
  };
  TestData test_data[] = {
    {"phone","blue","pixel"},
    {"computer","silver","lenovo"},
    {"phone","gold","iphone"},
  };
  vector<vector<string> > items;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    items.push_back(vector<string>());
    items.back().push_back(test_data[i].type);
    items.back().push_back(test_data[i].color);
    items.back().push_back(test_data[i].name);
  }
  EXPECT_EQ(solution_.countMatches(items, "color", "silver"), 1);
}

