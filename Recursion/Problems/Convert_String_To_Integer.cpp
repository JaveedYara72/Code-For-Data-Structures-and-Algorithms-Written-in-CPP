// Recursive Fucntion to Convert String to an Integer
int Stringtoint(char *a, int n) {
	// do the same thing just keep the alphabets array for numbers
	// Get the Recursive function for
	if (n == 0) {
		return 0;
	}

	int digit  = a[n - 1] - '0'; // last Digit. According  to ascii values they will workout
	int small_ans = Stringtoint(a, n - 1);

	return small_ans * 10 + digit;
}