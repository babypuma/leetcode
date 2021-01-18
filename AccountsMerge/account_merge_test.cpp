/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/18
 *
 * Source : https://leetcode-cn.com/problems/accounts-merge/
 * Problem: Accounts Merge
 *               
 */
#include <gtest/gtest.h>
#include "account_merge.h"

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
    "John", "johnsmith@mail.com", "john00@mail.com",
  };
  string b[] = {
    "John", "johnnybravo@mail.com",
  };
  string c[] = {
    "John", "johnsmith@mail.com", "john_newyork@mail.com",
  };
  string d[] = {
    "Mary", "mary@mail.com",
  };
  vector<vector<string> > accounts;
  accounts.push_back(vector<string>());
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    accounts.back().push_back(a[i]);
  }
  accounts.push_back(vector<string>());
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    accounts.back().push_back(b[i]);
  }
  accounts.push_back(vector<string>());
  for (size_t i = 0; i < sizeof(c)/sizeof(c[0]); ++i) {
    accounts.back().push_back(c[i]);
  }
  accounts.push_back(vector<string>());
  for (size_t i = 0; i < sizeof(d)/sizeof(d[0]); ++i) {
    accounts.back().push_back(d[i]);
  }
  vector<vector<string> > merged_accounts = solution_.accountsMerge(accounts);
  EXPECT_EQ(merged_accounts.size(), 3);
  EXPECT_EQ(merged_accounts[0].size(), 4);
  EXPECT_EQ(merged_accounts[1].size(), 2);
  EXPECT_EQ(merged_accounts[2].size(), 2);
}

