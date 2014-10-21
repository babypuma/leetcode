class Solution {
	public:
	    int atoi(const char *str) { 
			int i = 0;
			while (str[i] == ' ') {
				i++;
			}

			int number = 0;
			int sign = 1;
			if (str[i] == '+') {
				sign = 1;
			}
			else if (str[i] == '-') {
				sign = -1;
			}
			else if (str[i] >= '0' && str[i] <= '9') {
				number = str[i] - '0';
			}
			else {
				return 0;
			}

			const int MY_INT32_MAX = 0x7FFFFFFF;
			const int MY_INT32_MIN = 0x80000000;
			int incr;
			while (str[++i] != '\0') {
				if (str[i] < '0' || str[i] > '9') {
					break;
				}

				if (number > MY_INT32_MAX/10) {
					number = -1;
					break;
				}
				number *= 10;

				incr = str[i] - '0';
				if (number > MY_INT32_MAX - incr) {
					number = -1;
					break;
				}
				number += incr;
			}

			if (number < 0) {
				return sign > 0 ? MY_INT32_MAX : MY_INT32_MIN;
			}
			return number * sign;
		}
};
