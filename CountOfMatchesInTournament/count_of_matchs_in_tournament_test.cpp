/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/13
 *
 * Source : https://leetcode-cn.com/problems/count-of-matches-in-tournament/
 * Problem:	Count of Matches in Tournament
 *               
 */
#include <gtest/gtest.h>
#include "count_of_matchs_in_tournament.h"

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
    int n;
    int m;
  };
  TestData test_data[] = {
    {7, 6},
    {14, 13},
    {1, 0},
  };

  for (int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.numberOfMatches(test_data[i].n), test_data[i].m);
  }
}

