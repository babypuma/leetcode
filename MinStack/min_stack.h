/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/12
 *
 * Source : https://oj.leetcode.com/problems/min-stack/
 * Problem:	Min Stack
 * Description:
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * - push(x) -- Push element x onto stack.
 * - pop() -- Removes the element on top of the stack.
 * - top() -- Get the top element.
 * - getMin() -- Retrieve the minimum element in the stack.
 *
 */
#include <vector>

using std::vector;

class MinStack {
	public:
		MinStack() {
			min_ = INT32_MAX;
		}

		void push(int x) {
			vec_.push_back(x);
			if (x < min_) {
				min_ = x;
			}
		}

		void pop() {
			if (vec_.empty()) {
				return;
			}
			int back = top();
			vec_.pop_back();

			if (back == min_) {
				findMin();
			}
		}

		int top() {
			if (vec_.empty()) {
				return INT32_MAX;
			} 
			
			return vec_.back();
		}

		int getMin() {
			return min_;
		}

	private:
		void findMin() {
			size_t size = vec_.size();
			if (size == 0) {
				min_ = INT32_MAX;
				return;
			}

			min_ = vec_[0];
			for (size_t i = 1; i < size; i++) {
				if (vec_[i] < min_) {
					min_ = vec_[i];
				}
			}
		}

		vector<int> vec_;
		int min_;
};
