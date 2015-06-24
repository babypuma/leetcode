/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/24
 *
 * Source : https://leetcode.com/problems/basic-calculator-ii/
 * Problem:	Basic Calculator II
 * Description: 
 *	Implement a basic calculator to evaluate a simple expression string.  
 *	The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
 *	The integer division should truncate toward zero.
 *
 * 	You may assume that the given expression is always valid.
 * 	Some examples:
 *	"3+2*2" = 7
 *	" 3/2 " = 1
 *	" 3+5 / 2 " = 5
 *
 */
#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
	public: 
		enum CalType {
			T_Number,
			T_Add,
			T_Subtract,
			T_Multiply,
			T_Divide,
		}; 
		struct Item {
			Item(CalType t, int v = 0): type(t), val(v)	{
			}
			CalType type;
			int val;
		};

		int calculate(string s) {
			size_t size = s.size();
			int num = 0;
			stack<Item> st;
			for (size_t i = 0; i < size; i++) {
				if (s[i] == '+') {
					st.push(Item(T_Add));
				}
				else if (s[i] == '-') {
					st.push(Item(T_Subtract));
				}
				else if (s[i] == '*') {
					st.push(Item(T_Multiply));
				}
				else if (s[i] == '/') {
					st.push(Item(T_Divide));
				}
				else if (isdigit(s[i])) {
					num *= 10;
					num += s[i] - '0';
					if (i == size - 1 || !isdigit(s[i + 1])) {
						if (!st.empty()) {
							Item operation = st.top(); 
							if (operation.type == T_Multiply || operation.type == T_Divide) {
								st.pop(); 
								Item operand = st.top(); 
								st.pop();
								switch (operation.type) {
									case T_Multiply:
										st.push(Item(T_Number, operand.val * num));
										break;
									case T_Divide:
										st.push(Item(T_Number, operand.val / num));
										break;
								}
							}
							else {
								st.push(Item(T_Number, num));
							}
						}
						else {
							st.push(Item(T_Number, num));
						}
						num = 0;
					}
				}
			}

			while (true) {
				Item operand2 = st.top();
				st.pop();
				if (st.empty()) {
					return operand2.val;
				}
				else {
					Item operation = st.top();
					st.pop();
					Item operand1 = st.top();
					st.pop();
					int sign = 1;
					if (!st.empty()) {
						Item pre_operation = st.top();
						if (pre_operation.type == T_Subtract) {
							st.pop();
							st.push(Item(T_Add));
							sign = -1;
						} 
					}
					if (operation.type == T_Add) {
						st.push(Item(T_Number, sign * operand1.val + operand2.val));
					}
					else {
						st.push(Item(T_Number, sign * operand1.val - operand2.val));
					}
				}
			}	
		}
};
