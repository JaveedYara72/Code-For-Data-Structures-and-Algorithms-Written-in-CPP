int LinearSearchusingKey(int *a, int n, int key) {
	if (n == 0) { // no elements found at all
		return -1;
	}

	if (a[0] == key) {
		return 0;
	}
	int i = LinearSearchusingKey(a + 1, n - 1, key);
	if (i == -1) {
		return -1;
	}
	return i + 1;
}

int Linearsearchusingforloop(int* a, int i, int n, int key) {
	if ( i == n) {
		return -1; // n is the max number of elements or the number of elements present in this array
	}

	if (a[i]  == n) {
		return i;
	} else {
		return Linearsearchusingforloop(a, i + 1, n, key);
	}
}
