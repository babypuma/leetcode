/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/10
 *
 * Source : https://leetcode.com/problems/implement-queue-using-stacks/
 * Problem:	Implement Queue using Stacks
 * Description: 
 *	Implement the following operations of a queue using stacks.
 *
 * 	push(x) -- Push element x to the back of queue.
 * 	pop() -- Removes the element from in front of queue.
 * 	peek() -- Get the front element.
 * 	empty() -- Return whether the queue is empty.
 * Notes:
 * 	You must use only standard operations of a stack -- which means only push to top, 
 *	peek/pop from top, size, and is empty operations are valid.
 *	Depending on your language, stack may not be supported natively. You may simulate 
 *	a stack by using a list or deque (double-ended queue), as long as you use only 
 *	standard operations of a stack.
 * 	You may assume that all operations are valid (for example, no pop or peek operations 
 *	will be called on an empty queue).
 *
 */
#include <stack>
using std::stack;

class Queue {
	public:
		// Push element x to the back of queue.
		void push(int x) {
			while (!aux_.empty()) {
				master_.push(aux_.top());
				aux_.pop(); 
			} 
			master_.push(x);
		}

		// Removes the element from in front of queue.
		void pop(void) {
			while (!master_.empty()) {
				aux_.push(master_.top());
				master_.pop();
			}
			if (!aux_.empty()) {
				aux_.pop();
			}
		}

		// Get the front element.
		int peek(void) {
			while (!master_.empty()) {
				aux_.push(master_.top());
				master_.pop();
			}
			if (!aux_.empty()) {
				return aux_.top();
			}
		}

		// Return whether the queue is empty.
		bool empty(void) {
			return master_.empty() && aux_.empty();
		}

	private:
		stack<int> master_;
		stack<int> aux_;
};
