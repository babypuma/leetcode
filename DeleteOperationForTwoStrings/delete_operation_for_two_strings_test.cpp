/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/14
 *
 * Source : https://leetcode-cn.com/problems/delete-operation-for-two-strings/
 * Problem:	Delete Operation for Two Strings
 *
 */
#include <gtest/gtest.h>
#include "delete_operation_for_two_strings.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, minDistance) {
  struct TestData {
    string str1;
    string str2;
    int dist;
  };
  TestData test_data[] = {
    {"eat", "sea", 2},
    {"beat", "battle", 4},
    {"e", "sea", 2},
    {"", "s", 1},
    {"a", "a", 0},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    int dist = solution_.minDistance(test_data[i].str1, test_data[i].str2);
    EXPECT_EQ(dist, test_data[i].dist);
  } 
}

