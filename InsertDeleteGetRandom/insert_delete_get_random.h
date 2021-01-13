/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/13
 *
 * Source : https://leetcode-cn.com/problems/insert-delete-getrandom-o1/
 * Problem: Insert Delete GetRandom O(1)
 *               
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class RandomizedSet {
 public:
   /** Initialize your data structure here. */
   RandomizedSet() {
   }

   /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
   bool insert(int val) {
     if (vmap_.count(val) > 0) {
       return false;
     }
     vec_.push_back(val);
     vmap_[val] = vec_.size() - 1;
     return true;
   }

   /** Removes a value from the set. Returns true if the set contained the specified element. */
   bool remove(int val) {
     if (vmap_.count(val) == 0) {
       return false;
     }
     vec_[vmap_[val]] = vec_.back();
     vmap_[vec_.back()] = vmap_[val];
     vmap_.erase(val);
     vec_.pop_back();
     return true;
   }

   /** Get a random element from the set. */
   int getRandom() {
     srand(clock());
     return vec_[rand() % vec_.size()];
   }

 private:
   unordered_map<int, int> vmap_;
   vector<int> vec_;
};
