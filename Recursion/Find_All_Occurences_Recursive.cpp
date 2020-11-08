//6) All Occurences Code
// Finds and Prints all Occurences in Key
void alloc(int*a, int i, int n, int key) {
	if (i == n) {
		return;
	}
	if (a[i] == key) {
		cout << a[i] << " ";
	}
	alloc(a, i + 1, n, key);
}