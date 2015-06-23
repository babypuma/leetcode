/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/17
 *
 * Source : https://leetcode.com/problems/basic-calculator/
 * Problem:	Basic Calculator
 * Description: 
 *	Implement a basic calculator to evaluate a simple expression string.
 * 	The expression string may contain open ( and closing parentheses ), the plus + 
 *	or minus sign -, non-negative integers and empty spaces .
 *
 * 	You may assume that the given expression is always valid.
 *
 * 	Some examples:
 * 	"1 + 1" = 2
 * 	" 2-1 + 2 " = 3
 * 	"(1+(4+5+2)-3)+(6+8)" = 23
 *
 */
#include <stack>
#include <string>
#include <ctype.h>
#include <assert.h>

using std::stack;
using std::string;

class Solution {
	public: 
		enum CalType {
			E_Number,
			E_Operator,
			E_LeftBracket,
			E_RightBracket
		}; 
		union CalElem { 
			char ch;
			int num;
		};
		struct Item {
			CalType type;
			CalElem elem;
		};

		int calculate(string s) {
			size_t size = s.size();
			int num = 0;
			stack<Item> st;
			for (size_t i = 0; i < size; i++) {
				if (s[i] == '(') {
					st.push(package(E_LeftBracket, s[i]));
				}
				else if (s[i] == ')') {
					while (true) {
						Item operand2 = st.top();
						assert(operand2.type == E_Number);
						st.pop();

						if (st.empty()) {
							st.push(operand2);
							break;
						}

						Item item = st.top(); 
						assert(item.type == E_Operator || item.type == E_LeftBracket);
						st.pop();
						if (item.type == E_LeftBracket) {
							if (!st.empty()) {
								Item preitem = st.top();
								if (preitem.elem.ch == '-') {
									st.pop();
									st.push(package(E_Operator, '+'));
									operand2.elem.num *= -1;
								}
							}
							st.push(operand2);
							break;
						}
						else if (item.type == E_Operator) {
							Item operand1 = st.top();
							st.pop();
							assert(operand1.type == E_Number);
	
							if (item.elem.ch == '+') {
								st.push(package(E_Number, operand1.elem.num + operand2.elem.num));
							}
							else if (item.elem.ch == '-') {
								st.push(package(E_Number, operand1.elem.num - operand2.elem.num));
							}
						}
					}
				}
				else if (s[i] == '+' || s[i] == '-') {
					st.push(package(E_Operator, s[i]));
				}
				else if (isdigit(s[i])) {
					num *= 10;
					num += s[i] - '0';
					if (i == size - 1 || !isdigit(s[i + 1])) {
						if (!st.empty()) {
							Item old_item = st.top(); 
							st.pop();
							if (old_item.type == E_LeftBracket) {
								st.push(old_item);
								st.push(package(E_Number, num));
							}
							else {
								assert(old_item.type == E_Operator); 

								Item operand = st.top();
								st.pop();
								assert(operand.type == E_Number); 

								if (old_item.elem.ch == '+') {
									st.push(package(E_Number, operand.elem.num + num));
								}
								else {
									st.push(package(E_Number, operand.elem.num - num));
								}
							}
						}
						else {
							st.push(package(E_Number, num));
						}
						num = 0;
					}
				}
			}

			while (true) {
				Item operand2 = st.top();
				st.pop();
				if (st.empty()) {
					return operand2.elem.num;
				}
				else {
					Item item = st.top();
					st.pop();
					Item operand1 = st.top();
					st.pop();
					int sign = 1;
					if (!st.empty()) {
						Item pre_item = st.top();
						if (pre_item.elem.ch == '-') {
							st.pop();
							st.push(package(E_Operator, '+'));
							sign = -1;
						} 
					}
					if (item.elem.ch == '+') {
						st.push(package(E_Number, sign * operand1.elem.num + operand2.elem.num));
					}
					else {
						st.push(package(E_Number, sign * operand1.elem.num - operand2.elem.num));
					}
				}
			}	
		}

	private:
		Item package(CalType type, char ch) {
			Item item;
			item.type = type;
			item.elem.ch = ch;
			return item;
		}

		Item package(CalType type, int num) {
			Item item;
			item.type = type;
			item.elem.num = num;
			return item;
		}
};
