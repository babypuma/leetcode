/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/23
 *
 * Source : https://leetcode-cn.com/problems/number-of-orders-in-the-backlog/
 * Problem: Number of Orders in the Backlog
 *               
 */
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

struct Order {
  int price;
  int amount;
  Order() : price(0), amount(0) {}
  Order(int p, int a) : price(p), amount(a) {}
};

class HigherPrice {
 public:
   bool operator()(Order& o1, Order& o2) {
     return o1.price > o2.price;
   }
};

class LowerPrice {
 public:
   bool operator()(Order& o1, Order& o2) {
     return o1.price < o2.price;
   }
};

class Solution {
 public:
   int getNumberOfBacklogOrders(vector<vector<int> >& orders) {
     priority_queue<Order, vector<Order>, LowerPrice> buy_queue;
     priority_queue<Order, vector<Order>, HigherPrice> sell_queue;
     int64_t total_buy = 0;
     int64_t total_sell = 0;
     for (auto& order : orders) {
       int price = order[0];
       int amount = order[1];
       int type = order[2];
       if (type == 0) {
         for (;;) {
           if (sell_queue.empty() || sell_queue.top().price > price) {
             buy_queue.push(Order(price, amount));
             total_buy += amount;
             break;
           }
           Order sell_order = sell_queue.top();
           sell_queue.pop();
           total_sell -= sell_order.amount;
           if (sell_order.amount > amount) {
             sell_queue.push(Order(sell_order.price, sell_order.amount - amount));
             total_sell += sell_order.amount - amount;
             break;
           } else if (sell_order.amount < amount) {
             amount -= sell_order.amount;
           } else {
             break;
           }
         }
       } else {
         for (;;) {
           if (buy_queue.empty() || buy_queue.top().price < price) {
             sell_queue.push(Order(price, amount));
             total_sell += amount;
             break;
           }
           Order buy_order = buy_queue.top();
           buy_queue.pop();
           total_buy -= buy_order.amount;
           if (buy_order.amount > amount) {
             buy_queue.push(Order(buy_order.price, buy_order.amount - amount));
             total_buy += buy_order.amount - amount;
             break;
           } else if (buy_order.amount < amount) {
             amount -= buy_order.amount;
           } else {
             break;
           }
         }
       }
     }

     return (total_buy + total_sell) % 1000000007;
   }
};
