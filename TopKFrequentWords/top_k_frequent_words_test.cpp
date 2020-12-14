/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/top-k-frequent-words/
 * Problem: Top K Frequent Words
 *               
 */
#include <gtest/gtest.h>
#include "top_k_frequent_words.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  string a[] = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> v1(a, a + sizeof(a)/sizeof(a[0]));
  string b[] = {"i", "love"};
  vector<string> v2 = solution_.topKFrequent(v1, 2);
  EXPECT_EQ(v2.size(), 2);
  EXPECT_STREQ(v2[0].c_str(), b[0].c_str());
  EXPECT_STREQ(v2[1].c_str(), b[1].c_str());
}

TEST_F(SolutionTest, case2) {
  string a[] = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
  vector<string> v1(a, a + sizeof(a)/sizeof(a[0]));
  string b[] = {"the", "is", "sunny", "day"};
  size_t sz = sizeof(b)/sizeof(b[0]);
  vector<string> v2 = solution_.topKFrequent(v1, sz);
  EXPECT_EQ(v2.size(), sz);
  for (size_t i = 0; i < sz; ++i) {
    EXPECT_STREQ(v2[i].c_str(), b[i].c_str());
  }
}

TEST_F(SolutionTest, case3) {
  string a[] = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> v1(a, a + sizeof(a)/sizeof(a[0]));
  string b[] = {"i","love","coding"};
  size_t sz = sizeof(b)/sizeof(b[0]);
  vector<string> v2 = solution_.topKFrequent(v1, sz);
  EXPECT_EQ(v2.size(), sz);
  for (size_t i = 0; i < sz; ++i) {
    EXPECT_STREQ(v2[i].c_str(), b[i].c_str());
  }
}

