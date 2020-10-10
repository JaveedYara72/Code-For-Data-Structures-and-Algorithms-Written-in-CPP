int binarysearch(int a[], int n, int k) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == k) {
			return mid;
		} else if (a[mid] > k) { //-> Not greater than equal to
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return -1; //-> If did not find anything
}
