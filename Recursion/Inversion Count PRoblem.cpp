// inversion Count Problem.
// Given an Array, return us the the count if arr[i]>arr[j].
// arr = [1,5,3,6,0,2].
//Diivide it into 2 more subarrays
//[1,5,3] and [6,0,2].
// 1 is greater than 0, so +1.
// since 5 is greater than 0, we count all the elments from 5 to be counted
// Total Pairs ->(1,0),(5,2),(5,2),(3,0),(3,2).



void mergeinv(int* arr, int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = (mid + 1);
	int k = s;
	int temp[100000];

	int cnt = 0; //cross inversions

	while (i <= mid and j <= e) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			k++;
			i++;
		} else { //if arr[i] >arr[j] for an array if we find an element in the left array which is lgreater than an element in arr[j] then all the elements from i to the last element of left array would be the count inverions right.
			temp[k++] = arr[j++];
			cnt += mid - i + 1;
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

void inversion_count(int* arr, int s, int e) {
	if (s >= e) {
		return 0;
	}

	//merge sort for this counting inversions
	int mid = (s + e) / 2;
	int x = inversion_count(arr, s, mid);
	int y = inversion_count(arr, mid + 1, e);
	int z = mergeinv(arr, s, e); //cross inversions

	return x + y + z;
}
