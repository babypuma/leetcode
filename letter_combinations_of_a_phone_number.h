#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
	public:
		Solution() {
			digit2letter[0] = "";
			digit2letter[1] = "";
			digit2letter[2] = "abc";
			digit2letter[3] = "def";
			digit2letter[4] = "ghi";
			digit2letter[5] = "jkl";
			digit2letter[6] = "mno";
			digit2letter[7] = "pqrs";
			digit2letter[8] = "tuv";
			digit2letter[9] = "wxyz";
		}

	    vector<string> letterCombinations(string digits) {
			size_t length = digits.size() + 1;
			char buffer[length];
			char number[length];
			strcpy(number, digits.c_str());
			generateLetters(number, 0, buffer);

			return combinations;
		}

		void generateLetters(char number[], int pos, char buffer[]) {
			if (number[pos] == '\0') {
				combinations.push_back(string(buffer, pos));
				return;
			}
			
			char ch;
			for (int i = 0; (ch = getLetter(number[pos], i)) != '\0'; i++) {
				buffer[pos] = ch;	
				generateLetters(number, pos + 1, buffer);
			}
		}

		char getLetter(char digit, int pos) {
			return digit2letter[digit - '0'][pos];
		}

	private:
		char *digit2letter[10];
		vector<string> combinations;
};
