#include <vector>
#include <string>
using std::vector;
using std::string;
using std::pair;

class Solution {
	public:
	    vector<string> generateParenthesis(int n) {
			pair<int, int> counter(n, n);
			char buffer[2*n + 1];

			generate(buffer, 0, counter);
			return vec;
		}

		void generate(char buffer[], int num, pair<int, int> &rest) {
			if (rest.first == 0 && rest.second == 0) {
				vec.push_back(string(buffer, num));
				return;
			}
			
			if (rest.first > 0) {
				buffer[num] = '(';
				rest.first--;
				generate(buffer, num + 1, rest);
				rest.first++;
			}
			if (rest.second > rest.first) {
				buffer[num] = ')';
				rest.second--;
				generate(buffer, num + 1, rest);
				rest.second++;
			}
		}
	private:
		vector<string> vec;
};
