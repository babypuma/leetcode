/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/09
 *
 * Source : https://leetcode-cn.com/problems/design-hit-counter/
 * Problem: Design Hit Counter
 *               
 */
#include <queue>
using std::queue;

class HitCounter {
 public:
   HitCounter() {
   }

   void hit(int timestamp) {
     que_.push(timestamp);
     if (que_.front() + SECS <= timestamp) {
       que_.pop();
     }
   }

   int getHits(int timestamp) {
     while (!que_.empty() && que_.front() + SECS <= timestamp) {
       que_.pop();
     }
     return que_.size();
   }

 private:
   queue<int> que_;
   static const int SECS = 300;
};
