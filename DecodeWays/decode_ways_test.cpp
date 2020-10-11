/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/11
 *
 * Source : https://leetcode-cn.com/problems/decode-ways/
 * Problem:	Decode Ways
 *
 */
#include <gtest/gtest.h>
#include "decode_ways.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, numDecodings) {
  struct TestData {
    string str;
    int sz;
  };
  TestData test_data[] = {
    {"12", 2},
    {"226", 3},
    {"0", 0},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    int sz = solution_.numDecodings(test_data[i].str);
    EXPECT_EQ(sz, test_data[i].sz);
  } 
}

