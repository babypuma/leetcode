/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/13
 *
 * Source : https://leetcode-cn.com/problems/meeting-rooms-ii/
 * Problem:	Meeting Rooms II
 *               
 */
#include <gtest/gtest.h>
#include "meeting_rooms_ii.h"

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
  intervals.push_back(vector<int>());
  intervals.back().push_back(0);
  intervals.back().push_back(30);
  intervals.push_back(vector<int>());
  intervals.back().push_back(5);
  intervals.back().push_back(10);
  intervals.push_back(vector<int>());
  intervals.back().push_back(15);
  intervals.back().push_back(20);
  EXPECT_EQ(solution_.minMeetingRooms(intervals), 2);
}

TEST_F(SolutionTest, case2) {
  vector<vector<int> > intervals;
  intervals.push_back(vector<int>());
  intervals.back().push_back(7);
  intervals.back().push_back(10);
  intervals.push_back(vector<int>());
  intervals.back().push_back(2);
  intervals.back().push_back(4);
  EXPECT_EQ(solution_.minMeetingRooms(intervals), 1);
}

TEST_F(SolutionTest, case3) {
  vector<vector<int> > intervals;
  intervals.push_back(vector<int>());
  intervals.back().push_back(13);
  intervals.back().push_back(24);
  intervals.push_back(vector<int>());
  intervals.back().push_back(1);
  intervals.back().push_back(13);
  EXPECT_EQ(solution_.minMeetingRooms(intervals), 1);
}

TEST_F(SolutionTest, case4) {
  vector<vector<int> > intervals;
  intervals.push_back(vector<int>());
  intervals.back().push_back(928);
  intervals.back().push_back(5032);
  intervals.push_back(vector<int>());
  intervals.back().push_back(3072);
  intervals.back().push_back(3741);
  intervals.push_back(vector<int>());
  intervals.back().push_back(3960);
  intervals.back().push_back(4588);
  intervals.push_back(vector<int>());
  intervals.back().push_back(482);
  intervals.back().push_back(2269);
  intervals.push_back(vector<int>());
  intervals.back().push_back(2030);
  intervals.back().push_back(4360);
  intervals.push_back(vector<int>());
  intervals.back().push_back(150);
  intervals.back().push_back(772);
  EXPECT_EQ(solution_.minMeetingRooms(intervals), 3);
}

TEST_F(SolutionTest, case5) {
  vector<vector<int> > intervals;
  EXPECT_EQ(solution_.minMeetingRooms(intervals), 0);
}

