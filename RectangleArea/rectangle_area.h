/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 * Update : 2021/01/18
 *
 * Source : https://leetcode-cn.com/problems/rectangle-area/
 * Problem:	Rectangle Area
 *
 */
class Solution {
	public: 
		int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
			int area1 = rectangleArea(C - A, D - B);
			int area2 = rectangleArea(G - E, H - F);
			int area3 = intersectionArea(A, B, C, D, E, F, G, H);
			return area1 - area3 + area2;
		}

		int rectangleArea(int x, int y) {
			return x * y;
		}

		int intersectionArea(int a, int b, int c, int d, int e, int f, int g, int h) {
			if (c <= e || g <= a || h <= b || d <= f) {
				return 0;
			}
			
			return intersectionLength(a, c, e, g) * intersectionLength(b, d, f, h);
		}

		int intersectionLength(int u, int v, int x, int y) {
			int array[4] = {u, v, x, y};
      // insertion sort
			for (int i = 1; i < 4; i++) {
				int tmp = array[i];
				int j = i;
				for (; j > 0; j--) {
					if (tmp > array[j - 1]) {
						break;
					} 
					array[j] = array[j - 1];
				}
				array[j] = tmp;
			}

			return array[2] - array[1];
		}
};
