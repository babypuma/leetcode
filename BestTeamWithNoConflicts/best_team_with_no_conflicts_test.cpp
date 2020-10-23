/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/20
 *
 * Source : https://leetcode-cn.com/problems/best-team-with-no-conflicts/
 * Problem:	Best Team With No Conflicts
 *
 */
#include <gtest/gtest.h>
#include "best_team_with_no_conflicts.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, bestTeamScore) {
  int a[] = {1,3,5,10,15};
  int b[] = {1,2,3,4,5};
  vector<int> vec1(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> vec2(b, b + sizeof(b)/sizeof(b[0]));
  EXPECT_EQ(solution_.bestTeamScore(vec1, vec2), 34);
}

TEST_F(SolutionTest, bestTeamScore2) {
  int a[] = {4,5,6,5};
  int b[] = {2,1,2,1};
  vector<int> vec1(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> vec2(b, b + sizeof(b)/sizeof(b[0]));
  EXPECT_EQ(solution_.bestTeamScore(vec1, vec2), 16);
}

TEST_F(SolutionTest, bestTeamScore3) {
  int a[] = {1,2,3,5};
  int b[] = {8,9,10,1};
  vector<int> vec1(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> vec2(b, b + sizeof(b)/sizeof(b[0]));
  EXPECT_EQ(solution_.bestTeamScore(vec1, vec2), 6);
}

TEST_F(SolutionTest, bestTeamScore4) {
  int a[] = {596,277,897,622,500,299,34,536,797,32,264,948,645,537,83,589,770};
  int b[] = {18,52,60,79,72,28,81,33,96,15,18,5,17,96,57,72,72};
  vector<int> vec1(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> vec2(b, b + sizeof(b)/sizeof(b[0]));
  EXPECT_EQ(solution_.bestTeamScore(vec1, vec2), 3287);
}

