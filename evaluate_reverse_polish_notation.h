/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/09
 *
 * Source : https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 * Problem:	Evaluate Reverse Polish Notation
 * Description: 
 *	Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *  Valid operators are +, -, *, /. Each operand may be an integer or another expression.  
 *	Some examples:
 *	["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *	["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 */
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
using std::string;
using std::vector;
using std::stack;

class Solution {
	public:
	    int evalRPN(vector<string> &tokens) {
			stack<int> st;
			size_t length = tokens.size();
			int operand1;
			int operand2;
			for (size_t index = 0; index < length; index++) {
				string token = tokens[index];
				if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
					operand1 = st.top();
					st.pop();
					operand2 = st.top();
					st.pop();
					st.push(evaluate(operand2, operand1, token[0]));	
				} 
				else { 
					st.push(str2int(token.c_str())); 
				}
			}

			return st.top();
		}

		int evaluate(int a, int b, char op) {
			switch (op) {
				case '+':
					return a + b;
				case '-':
					return a - b;
				case '*':
					return a * b;
				case '/':
					return a / b;
				default:
					return 0;
			}
		}

		int str2int(string str) {
			int sign = 1;
			size_t index = 0;
			if (str[index] == '-' || str[index] == '+') {
				sign = (str[index] == '-') ? -1 : 1;
				index = 1;
			}

			int result = 0;
			size_t length = str.size();
			for (; index < length; index++) {
				result *= 10;
				result += str[index] - '0';
			}

			return sign * result;
		}
};
