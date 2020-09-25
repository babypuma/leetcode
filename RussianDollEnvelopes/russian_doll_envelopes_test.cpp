/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/25
 *
 * Source : https://leetcode-cn.com/problems/russian-doll-envelopes/
 * Problem:	Russian Doll Envelopes
 *
 */
#include <gtest/gtest.h>
#include "russian_doll_envelopes.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, maxEnvelopes) {
  struct TestData {
    int w;
    int h;
  };
  TestData test_data[] = {
    {5, 4},
    {6, 4},
    {6, 7},
    {2, 3},
  };
  vector<vector<int> > vec2;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vector<int> vec;
    vec.push_back(test_data[i].w);
    vec.push_back(test_data[i].h);
    vec2.push_back(vec);
  }
  EXPECT_EQ(solution_.maxEnvelopes(vec2), 3);
}

