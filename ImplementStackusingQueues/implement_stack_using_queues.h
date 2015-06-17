/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/implement-stack-using-queues/
 * Problem:	Implement Stack using Queues
 * Description: 
 *	Implement the following operations of a stack using queues.
 * 	- push(x) -- Push element x onto stack.
 *  - pop() -- Removes the element on top of the stack.
 *  - top() -- Get the top element.
 *  - empty() -- Return whether the stack is empty.
 *
 *	Notes:
 * 	You must use only standard operations of a queue -- which means only push to back, 
 *	peek/pop from front, size, and is empty operations are valid.
 * 	Depending on your language, queue may not be supported natively. You may simulate a queue 
 *	by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * 	You may assume that all operations are valid 
 *	(for example, no pop or top operations will be called on an empty stack).
 *
 */
#include <queue>

using std::queue;

class Stack {
	public:
		// Push element x onto stack.
		void push(int x) {
			qu_.push(x);
		}

		// Removes the element on top of the stack.
		void pop() {
			if (empty()) {
				return;
			}

			queue<int> q;
			while (!qu_.empty()) {
				int n = qu_.front();
				qu_.pop();
				if (!qu_.empty()) {
					q.push(n);
				}
			}

			while (!q.empty()) {
				qu_.push(q.front());
				q.pop();
			}
		}

		// Get the top element.
		int top() {
			return qu_.back();
		}

		// Return whether the stack is empty.
		bool empty() {
			return qu_.empty();
		}
	private:
		queue<int> qu_;	
};
