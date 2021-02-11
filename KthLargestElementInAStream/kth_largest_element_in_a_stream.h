/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/11
 *
 * Source : https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
 * Problem: Kth Largest Element in a Stream
 *               
 */
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

class KthLargest {
 public:
   KthLargest(int k, vector<int>& nums) : k_(k) {
     for (auto& n : nums) {
       if (min_que_.size() == k_ && n <= min_que_.top()) {
         max_que_.push(n);
         continue;
       }

       min_que_.push(n);
       if (min_que_.size() > k_) {
         max_que_.push(min_que_.top());
         min_que_.pop();
       }
     }
   }

   int add(int val) {
     if (min_que_.size() == k_ && val <= min_que_.top()) {
       max_que_.push(val);
     } else {
       min_que_.push(val);
       if (min_que_.size() > k_) {
         max_que_.push(min_que_.top());
         min_que_.pop();
       }
     }
     return min_que_.top();
   }

 private:
   int k_;
   priority_queue<int, vector<int>, std::greater<int> > min_que_;
   priority_queue<int> max_que_;
};
