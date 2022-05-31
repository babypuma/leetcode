/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/30
 *
 * Source : https://leetcode.cn/problems/two-best-non-overlapping-events/
 * Problem:	Two Best Non-Overlapping Events
 *
 */
#include <gtest/gtest.h>
#include "two_best_non_overlapping_events.h"

TEST(Solution, testcase) {
  struct TestCase {
    int start_time;
    int end_time;
    int value;
  };
  TestCase test_case[] = {
    {1,3,2},
    {4,5,2},
    {2,4,3},
  };

  vector<vector<int> > events;
  for (size_t i = 0; i < sizeof(test_case)/sizeof(test_case[0]); ++i) {
    events.push_back(vector<int>(3, 0));
    events.back()[0] = test_case[i].start_time;
    events.back()[1] = test_case[i].end_time;
    events.back()[2] = test_case[i].value;
  }

  Solution solution;
  EXPECT_EQ(solution.maxTwoEvents(events), 4);
}

