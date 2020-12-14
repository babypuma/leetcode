/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/group-anagrams/
 * Problem:	Group Anagrams
 *               
 */
#include <gtest/gtest.h>
#include "group_anagrams.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  string a[] = {"eat","tea","tan","ate","nat","bat"};
  vector<string> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<vector<string> > group = solution_.groupAnagrams(vec);
  EXPECT_EQ(group.size(), 3);
}

TEST_F(SolutionTest, case2) {
  string a[] = {"ac", "d"};
  vector<string> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<vector<string> > group = solution_.groupAnagrams(vec);
  EXPECT_EQ(group.size(), 2);
}

TEST_F(SolutionTest, case3) {
  string a[] = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
  vector<string> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<vector<string> > group = solution_.groupAnagrams(vec);
  EXPECT_EQ(group.size(), 10);
}

