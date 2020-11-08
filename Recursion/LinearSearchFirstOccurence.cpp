//4) Using Recursion Find The Element using Linear Search for the first occurenc of an elementv
int LinearSearch(int *a, int n) {
	if (n == 0 or n == 1) {
		return n;
	} else {
		if (a == n) {
			return a;
		} else {
			LinearSearch(a + 1, n);
		}
	}

}