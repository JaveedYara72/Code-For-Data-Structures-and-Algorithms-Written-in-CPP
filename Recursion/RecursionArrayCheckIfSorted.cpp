//2) Use Recurion to check if array is sorted

int funcarr(int a[], int n) {
	if (n == 0 or n == 1) {
		return true;
	}
	// recursive case
	if ((a[0] < a[1]) and funcarr(a + 1, n - 1)) { // The Array Index Increases by 1 and the number of elements gets decreased right. so that is why
		return true;
	}
	return false;
}