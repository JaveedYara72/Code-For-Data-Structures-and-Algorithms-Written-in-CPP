//3) Recursive Fucntion to Binary Search
int Binarysearch(int *a, int n) {
	int start = a;
	int end = a + n;


	if ((a + n) >= 1) {
		int mid = (start + end) / 2;
		if (a + mid == n) {
			return mid;
		}

		if (a + mid > x) {
			return (Binarysearch(a, a + mid - 1));
		}
		return (Binarysearch(a, a + mid - 1));
	}

	return -1;
}