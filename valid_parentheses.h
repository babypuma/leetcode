#include <string>
#include <stack>
using std::string;
using std::stack;

class Solution {
	public:
	    bool isValid(string s) {
			stack<char> st;
			size_t length = s.size();
			for (size_t i = 0; i < length; i++) {
				char ch = s[i];
				if (ch == '(' || ch == '[' || ch == '{') {
					st.push(ch);
				}
				else {
					switch (ch) {
						case ')':
							if (st.empty() || st.top() != '(') {
								return false;
							}
							st.pop();
							break;
						case ']':
							if (st.empty() || st.top() != '[') {
								return false;
							}
							st.pop();
							break;
						case '}':
							if (st.empty() || st.top() != '{') {
								return false;
							}
							st.pop();
							break;
						default:
							return false;
							break;
					}
				}
			} 
			
			return st.empty();
		}
};
