/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/11
 *
 * Source : https://leetcode-cn.com/problems/search-in-a-sorted-array-of-unknown-size/
 * Problem: Search in a Sorted Array of Unknown Size
 *               
 */
#include <vector>
using std::vector;

class ArrayReader {
 public:
   ArrayReader(vector<int>& v) : vec_(v) {
   }

   int get(int index) const {
     return index >= vec_.size() ? INT32_MAX : vec_[index];
   }

 private:
   vector<int> vec_;
};

class Solution {
 public:
   int search(const ArrayReader& reader, int target) {
     return binarySearch(reader, 0, MAX_SZ - 1, target);
   }

 private:
   int binarySearch(const ArrayReader& reader, int left, int right, int target) {
     if (left > right) {
       return -1;
     }
     int mid = (left + right) / 2;
     if (reader.get(mid) == target) {
       return mid;
     }

     if (reader.get(mid) < target) {
       return binarySearch(reader, mid + 1, right, target);
     } else {
       return binarySearch(reader, left, mid - 1, target);
     }
   }

 private:
   static const int MAX_SZ = 10000;
};
