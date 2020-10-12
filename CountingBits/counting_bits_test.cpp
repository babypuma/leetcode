/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/12
 *
 * Source : https://leetcode-cn.com/problems/counting-bits/
 * Problem:	Counting Bits
 *
 */
#include <gtest/gtest.h>
#include <string>
#include "counting_bits.h"

using std::string;

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, countBits) {
  struct TestData {
    string str;
    int num;
  };
  TestData test_data[] = {
    {"0,1,1", 2},
    {"0,1,1,2,1,2", 5},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    vector<int> vec = solution_.countBits(test_data[i].num);
    string str = std::to_string(vec[0]);
    for (size_t j = 1; j < vec.size(); ++j) {
      str.append(",");
      str.append(std::to_string(vec[j]));
    }
    EXPECT_STREQ(str.c_str(), test_data[i].str.c_str());
  } 
}

