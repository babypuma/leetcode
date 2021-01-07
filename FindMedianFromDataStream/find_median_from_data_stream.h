/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/07
 *
 * Source : https://leetcode-cn.com/problems/find-median-from-data-stream/
 * Problem: Find Median from Data Stream
 *               
 */
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

class MedianFinder {
 public:
   MedianFinder() {
   }

   void addNum(int num) {
     high_.push(num);
     low_.push(high_.top());
     high_.pop();
     if (high_.size() < low_.size()) {
       high_.push(low_.top());
       low_.pop();
     }
   }

   double findMedian() {
     return high_.size() > low_.size() ? high_.top() : (high_.top() + low_.top()) / 2.0;
   }

 private:
   priority_queue<int> high_;
   priority_queue<int, vector<int>, std::greater<int> > low_;
};
