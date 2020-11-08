//Tower Of Hanoi Problem
void TowerOfHanoi(int n, char src, char helper, char dest ) {
	// Base Case
	if (n == 0) {
		return;
	}

	//recursive Case
	//move  -1 disks from source to helper
	TowerOfHanoi(n - 1, src, dest, helper);
	cout << "Shift Disk " << n << "from " << src << "to " << dest << endl;
	TowerOfHanoi(n - 1, helper, src, dest);

}