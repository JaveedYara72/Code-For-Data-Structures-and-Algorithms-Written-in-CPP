void selectionsort(int a[], int n) { //-> N is for how many numbers you want to iterate through
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i; j <= n - 1; j++) {
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		swap(a[i], a[min_index]);
	}

	for (int i = 0; i < n ; i++) {
		cout << a[i] << " ";
	}

}
