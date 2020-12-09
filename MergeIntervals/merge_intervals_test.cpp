/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/09
 *
 * Source : https://leetcode-cn.com/problems/merge-intervals/
 * Problem:	Merge Intervals
 *
 */
#include <gtest/gtest.h>
#include "merge_intervals.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > intervals;
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(3);
  intervals.push_back(vec);

  vec.clear();
  vec.push_back(2);
  vec.push_back(6);
  intervals.push_back(vec);

  vec.clear();
  vec.push_back(8);
  vec.push_back(10);
  intervals.push_back(vec);

  vec.clear();
  vec.push_back(15);
  vec.push_back(18);
  intervals.push_back(vec);

  vector<vector<int> > res = solution_.merge(intervals);
  EXPECT_EQ(res.size(), 3);
  EXPECT_EQ(res[0][0], 1);
  EXPECT_EQ(res[0][1], 6);

  EXPECT_EQ(res[1][0], 8);
  EXPECT_EQ(res[1][1], 10);

  EXPECT_EQ(res[2][0], 15);
  EXPECT_EQ(res[2][1], 18);
}

TEST_F(SolutionTest, case2) {
  // [[2,3],[4,5],[6,7],[8,9],[1,10]]
  vector<vector<int> > intervals;
  vector<int> vec;
  vec.push_back(2);
  vec.push_back(3);
  intervals.push_back(vec);

  vec.clear();
  vec.push_back(4);
  vec.push_back(5);
  intervals.push_back(vec);

  vec.clear();
  vec.push_back(6);
  vec.push_back(7);
  intervals.push_back(vec);

  vec.clear();
  vec.push_back(8);
  vec.push_back(9);
  intervals.push_back(vec);

  vec.clear();
  vec.push_back(1);
  vec.push_back(10);
  intervals.push_back(vec);

  vector<vector<int> > res = solution_.merge(intervals);
  EXPECT_EQ(res.size(), 1);
  EXPECT_EQ(res[0][0], 1);
  EXPECT_EQ(res[0][1], 10);
}

TEST_F(SolutionTest, case3) {
  // [[2,3],[4,5],[6,7],[8,9],[1,10]]
  vector<vector<int> > intervals;
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(4);
  intervals.push_back(vec);

  vec.clear();
  vec.push_back(0);
  vec.push_back(0);
  intervals.push_back(vec);

  vector<vector<int> > res = solution_.merge(intervals);
  ASSERT_EQ(res.size(), 2);
  EXPECT_EQ(res[0][0], 0);
  EXPECT_EQ(res[0][1], 0);
  EXPECT_EQ(res[1][0], 1);
  EXPECT_EQ(res[1][1], 4);
}

