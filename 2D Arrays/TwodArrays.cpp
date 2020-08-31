// 2D Arrays

// int a[Rows][Columns]
// Linear Array Storage inside the Storage

// Input and Output
int twodarray() {
	int b[5][3] = {0}; // Assigning all of them to 0's. Or You COuld Input them as well
	int m, n;
	cin >> m >> n;

	int val = 1;

	for (int i = 0 ; i <= 4; i++) { //Here if User Input is Wanted then, It Should be m-1

		for (int j = 0; j <= 2; j++) { // If User Input is to be Taken. n-1 is supposed to happen
			b[i][j] = val;
			val = val + 1; //First value is 1 and it keeps on adding 1 till m-1,n-1th Position
			cin >> b[i][j]; // For Taking Input
			cout << b[i][j] << " " ;

		}
		cout << endl;
	}
}

// This Is the Code for Printing The Array in TopDown Format if Column is Even else in Bottomup If Column is ODD.
int Wavprint() {
	int c[1000][1000] = {0};
	int m, n;
	cin >> m >> n;

	int val = 1;

	for (int i = 0; i <= m - 1; i++) {
		for (int j = 0; j <= n - 1; j++) {
			c[i][j] = val;
			val += 1;
			cout << c[i][j] << " ";
		}
		cout << endl;
	}//This Part is all Input 

	// Keep The Column Fixed and Print the Row
	for (int col = 0; col < n; col++) {
		if (col % 2 == 0) { //Even Column Top DOwn. Else Bottom Up
			for (int row = 0; row < m; row++) {
				cout << c[row][col] << " "; // TopDown Printing. Row Getting Printed
			}
		} else {
			for (int row = m - 1; row >= 0 ; row--) {
				cout << c[row][col] << " ";// Bottom Up Printing. Column Getting Printed
			}
		}
	}
}
