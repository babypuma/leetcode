/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/03
 *
 * Source : https://leetcode.com/problems/restore-ip-addresses/
 * Problem:	Restore IP Addresses
 *
 */
#include <gtest/gtest.h>
#include "restore_ip_addresses.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, restoreIpAddresses) {
  struct TestData {
    string str;
    size_t sz;
  };
  TestData test_data[] = {
    {"25525511135", 2},
    {"0000", 1},
    {"1111", 1},
    {"010010", 2},
    {"101023", 5},
    {"25525511135", 2},
  };

  Solution solution;
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    vector<string> vec = solution.restoreIpAddresses(test_data[i].str);
    EXPECT_EQ(vec.size(), test_data[i].sz);
  }
}

