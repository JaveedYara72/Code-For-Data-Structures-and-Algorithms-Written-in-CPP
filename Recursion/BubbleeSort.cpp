void bubblesort(int* arr, int n) {
	//base case
	if (n == 1) {
		return;
	}

	//recursive case
	for (int j = 0; j < n - 1; j++) {
		if (arr[j] > arr[j + 1]) {
			swap(arr[j], arr[j + 1]);
		}
	}

	bubblesort(arr, n - 1);


}

// Or This one would work as well

void bubblesort_recursive(int* arr, int j, int n) {
	if (n == 1) {
		return;
	}

	if (j == n - 1) {
		// Single pass has not been done yet.
		return bubblesort_recursive(arr, 0, n - 1);
	}

	//recursive case
	if (arr[] > arr[j + 1]) {
		swap(arr[j], arr[j + 1]);
	}
	bubblesort_recursive(arr, j + 1, n);
	return;
}