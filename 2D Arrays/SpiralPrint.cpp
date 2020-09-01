int Spiralprint(int a[][1000], int m, int n) {

	// Take the Inout from main, Taking Inout here would Overshadow the Function

	int StartRow = 0;
	int StartColumn = 0;
	int EndRow = m - 1;
	int EndColumn = n - 1;

	//Printing the Spiral
	while (StartRow <= EndRow and StartColumn <= EndColumn) {
		//Print the First Row
		for (int i = StartColumn; i <= EndColumn; i++) {
			cout << a[StartRow][i] << " "; // We are printing the Row Numbers using the Column Variation
		}
		StartRow++;

		// Print The End Column
		for (int i = StartRow; i <= EndRow; i++) {
			cout << a[i][EndColumn] << " ";
		}
		EndColumn--;

		//For Bottom Row
		if (EndRow > StartRow) { // Stops Elements From Repeating
			for (int i = EndColumn; i >= StartColumn; i--) {
				cout << a[EndRow][i] << " ";
			}
			EndRow--;
		}

		//Print the Start Col
		if (EndColumn > StartColumn) { // Stops Elements from Repeating
			for (int i = EndRow; i <= StartRow; i++) {
				cout << a[i][StartColumn] << " ";
			}
			StartColumn++;
		}
	}

}
