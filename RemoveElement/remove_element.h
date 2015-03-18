class Solution {
	public:
	    int removeElement(int A[], int n, int elem) { 
			int back = -1;
			int front = 0;
			for (; front < n; front++) {
				if (A[front] != elem) {
					if (back >= 0) {
						A[back++] = A[front];
					}
					continue;
				}
				if (back < 0) {
					back = front;
				}
			}

			return (back < 0) ? n : back;
		}
};
