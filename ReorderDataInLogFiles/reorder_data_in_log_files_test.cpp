/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/11
 *
 * Source : https://leetcode-cn.com/problems/reorder-data-in-log-files/
 * Problem:	Reorder Data in Log Files
 *               
 */
#include <gtest/gtest.h>
#include "reorder_data_in_log_files.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  string a[] = {
    "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"
  };
  vector<string> input(a, a + sizeof(a)/sizeof(a[0]));
  vector<string> output = solution_.reorderLogFiles(input);
  EXPECT_EQ(output.size(), 5);
  EXPECT_STREQ(output[0].c_str(), "let1 art can");
  EXPECT_STREQ(output[1].c_str(), "let3 art zero");
  EXPECT_STREQ(output[2].c_str(), "let2 own kit dig");
  EXPECT_STREQ(output[3].c_str(), "dig1 8 1 5 1");
  EXPECT_STREQ(output[4].c_str(), "dig2 3 6");
}

TEST_F(SolutionTest, case2) {
  string a[] = {
    "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"
  };
  vector<string> input(a, a + sizeof(a)/sizeof(a[0]));
  vector<string> output = solution_.reorderLogFiles(input);
  EXPECT_EQ(output.size(), 6);
  EXPECT_STREQ(output[0].c_str(), "a2 act car");
  EXPECT_STREQ(output[1].c_str(), "g1 act car");
  EXPECT_STREQ(output[2].c_str(), "a8 act zoo");
  EXPECT_STREQ(output[3].c_str(), "ab1 off key dog");
  EXPECT_STREQ(output[4].c_str(), "a1 9 2 3 1");
  EXPECT_STREQ(output[5].c_str(), "zo4 4 7");
}

