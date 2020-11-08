//7) Fast Power Recursion
int power(int a, int n) {
	if (n == 0) {
		//- 0(n).
		return 1;
	}
	return a * power(a, n - 1);
}

int fastpower(int a, int n) { // -> Ologn
	if (n == 0) {
		return 0;
	}

	//recursion case
	int smaller_ans = fastpower(a, n / 2);
	smaller_ans *= smaller_ans;

	if (n & 1) {
		return smaller_ans * a;
	}
	return smaller_ans;
}
