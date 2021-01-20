/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/20
 *
 * Source : https://leetcode-cn.com/problems/evaluate-division/
 * Problem: valuate Division
 *               
 */
#include <gtest/gtest.h>
#include "evaluate_division.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

struct StringPair {
  string s1;
  string s2;
};

TEST_F(SolutionTest, case1) {
  StringPair a[] = {
    {"a", "b"},
    {"b", "c"},
  };
  vector<vector<string> > equations;
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    equations.push_back(vector<string>());
    equations.back().push_back(a[i].s1);
    equations.back().push_back(a[i].s2);
  }

  vector<double> values;
  values.push_back(2.0);
  values.push_back(3.0);

  StringPair b[] = {
    {"a", "c"},
    {"b", "a"},
    {"a", "e"},
    {"a", "a"},
    {"x", "x"},
  };
  vector<vector<string> > queries;
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    queries.push_back(vector<string>());
    queries.back().push_back(b[i].s1);
    queries.back().push_back(b[i].s2);
  }

  vector<double> vec = solution_.calcEquation(equations, values, queries);
  double c[] = {6.00000,0.50000,-1.00000,1.00000,-1.00000};
  ASSERT_EQ(vec.size(), sizeof(c)/sizeof(c[0]));
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    EXPECT_DOUBLE_EQ(c[i], vec[i]);
  }
}

