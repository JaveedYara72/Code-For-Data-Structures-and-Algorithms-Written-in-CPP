// Dynamic Memory Allocation
	int n;
	cin >> n;

	int* a = new int[n][0]; //All Elements are Zeroes.

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cout << a[i] << " ";
	}

	//Create 2d Array Dynamically
	int **arr;
	cin>>r>>c;

	arr = new int[r];

	for(int i=0;i<n;i++){
		arr[i] = new int[c];
	}

	for(int i = 0;i<r;i++){
		for(int j=0;i<c;j++){
			cin>>arr[i][j];
		}
	}
