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
#include <stack>
using std::stack;

class MinStack {
	public:
		MinStack() {
		}

		void push(int x) {
			all_.push(x);
			if (min_.empty() || x <= min_.top()) {
				min_.push(x);
			}
		}

		void pop() {
			if (all_.top() == min_.top()) {
				all_.pop();
				min_.pop();
			}
			else {
				all_.pop();
			}
		}

		int top() {
			return all_.top();
		}

		int getMin() {
			return min_.top();
		}

	private:
		stack<int> all_;
		stack<int> min_;
};
