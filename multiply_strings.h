#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
	public:
		Solution() {
			for (int i = 0; i < 10; i++) {
				digit2char[i] = '0' + i;
			}
		}

	    string multiply(string num1, string num2) { 
			size_t length1 = num1.size();	
			size_t length2 = num2.size();	
			vector<string> sum;
			size_t max_length = 0;
			for (size_t i = 0; i < length1; i++) {
				string m = doMultiply(num1[i], num2, length2);
				sum.push_back(m);
			}
			size_t length = sum.size();
			for (size_t i = 1; i < length; i++) {
				sum[i] = string(i, '0') + sum[i];
				if (sum[i].size() > max_length) {
					max_length = sum[i].size();
				}
			} 

			return add(sum, max_length);
		}

		string doMultiply(char ch, string num, size_t length) {
			if (ch == '0') {
				return string("0");
			}
			
			string mul;
			char flag = '0';
			for (size_t i = 0; i < length; i++) {
				mul += charMultiply(ch, num[i], flag);
			}
			if (flag != '0') {
				mul += flag;
			}

			return mul;
		}

		char charMultiply(char ch1, char ch2, char &flag) {
			int mul = (ch1 - '0') * (ch2 - '0') + (flag - '0');
			flag = digit2char[mul / 10];
			return digit2char[mul % 10];
		}

		string add(vector<string> &num, size_t max_length) {
			size_t num_length = num.size();
			if (num_length == 0 || max_length == 0) {
				return string("0");
			}
			string sum;
			int s;
			int flag = '0';
			for (size_t i = 0; i < max_length; i++) {
				s = 0;
				for (size_t j = 0; j < num_length; j++) {
					if (num[j].size() > i) {
						s += num[j][i] - '0';
					}
				}
				s += flag - '0';
				sum += digit2char[s % 10];
				flag = digit2char[s / 10];
				//printf("%s\n", sum.c_str());
			}
			if (flag != '0') {
				sum += flag - '0';
			}

			return sum;
		}

	private:
		char digit2char[10];
};
