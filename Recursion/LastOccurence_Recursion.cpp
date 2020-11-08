
//5) Last Occurence using recursion
int lastoccurence(int *a, int n, int key) {
	if (n == 0) {
		return -1;
	}

	int i = lastoccurence(a + 1, n - 1, key);
	if ( i == -1) {
		if (a [0] == key) {
			return 0;
		} else {
			return -1;
		}
	}
	// otherwise i returned by i is not -1.
	return i + 1;
}