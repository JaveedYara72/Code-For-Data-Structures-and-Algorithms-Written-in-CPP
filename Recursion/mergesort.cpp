
void merge(int* arr, int s, int e) {
	int mid = (s + e) / 2;

	int i = s;
	int j = mid + 1;
	int k = s;

	int temp[100];

	while (i <= mid and j <= e) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}

		while (i <= mid) {
			temp[k++] = arr[i++];
		}
		while (j <= e) {
			temp[k++] = arr[j++];
		}

		//copy them into the original array

		for (int i = s; i <= e; i++) {
			arr[i] = temp[i];
		}
	}
}

void mergesort(int* arr, int s, int e) {
	if (s == e) {
		return;
	}

	int mid = (s + e) / 2;

	//recursively  divide the array into 2 parts
	mergesort(arr, s, mid + 1);
	mergesort(arr, mid + 1, e);

	//merge the 2 Parts
	merge(arr, s, e)

}