/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/25
 *
 * Source : https://leetcode-cn.com/problems/minimum-number-of-people-to-teach/
 * Problem: Minimum Number of People to Teach
 *               
 */
#include <gtest/gtest.h>
#include "minimum_number_of_people_to_teach.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > languages;
  languages.push_back(vector<int>());
  languages.back().push_back(1);
  languages.push_back(vector<int>());
  languages.back().push_back(2);
  languages.push_back(vector<int>());
  languages.back().push_back(1);
  languages.back().push_back(2);

  vector<vector<int> > friendships;
  friendships.push_back(vector<int>());
  friendships.back().push_back(1);
  friendships.back().push_back(2);
  friendships.push_back(vector<int>());
  friendships.back().push_back(1);
  friendships.back().push_back(3);
  friendships.push_back(vector<int>());
  friendships.back().push_back(2);
  friendships.back().push_back(3);

  EXPECT_EQ(solution_.minimumTeachings(2, languages, friendships), 1);
}

