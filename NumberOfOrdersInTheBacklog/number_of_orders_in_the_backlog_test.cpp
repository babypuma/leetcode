/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/23
 *
 * Source : https://leetcode-cn.com/problems/number-of-orders-in-the-backlog/
 * Problem: Number of Orders in the Backlog
 *               
 */
#include <gtest/gtest.h>
#include "number_of_orders_in_the_backlog.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  struct TestData {
    int price;
    int amount;
    int type;
  };
  TestData test_data[] = {
    {10,5,0},{15,2,1},{25,1,1},{30,4,0}
  };

  vector<vector<int> > orders;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    orders.push_back(vector<int>());
    orders.back().push_back(test_data[i].price);
    orders.back().push_back(test_data[i].amount);
    orders.back().push_back(test_data[i].type);
  }
  EXPECT_EQ(solution_.getNumberOfBacklogOrders(orders), 6);
}

