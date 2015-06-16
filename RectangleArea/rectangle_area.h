/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/rectangle-area/
 * Problem:	Rectangle Area
 * Description: 
 *	Find the total area covered by two rectilinear rectangles in a 2D plane.  
 * 	Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * 	Assume that the total area is never beyond the maximum possible value of int.
 *
 */
class Solution {
	public: 
		int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
			int area1 = rectangleArea(C - A, D - B);
			int area2 = rectangleArea(G - E, H - F);
			int area3 = intersectionArea(A, B, C, D, E, F, G, H);
			return area1 + area2 - area3;
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
