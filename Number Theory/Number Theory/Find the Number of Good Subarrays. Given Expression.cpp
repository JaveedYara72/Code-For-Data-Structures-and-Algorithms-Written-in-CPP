
//9) Given N Elements. Find the Number of Good Sub Arrays
// A good Sub Array is a sub array such that sum of ai+ai+1+ai+2+...+aj is divisible by n
// use Pigeon hole Principle

ll a[1000005], pre[1000005];
int t; //Number of test Cases/ Queries
cin >> t;
while (t--) {
	int n;
	cin >> n;
	memset(pre, 0, sizeof(pre)); //pre is the name of array, which has a sum of 0 initially,. After that we would start taking in input
	pre[0] = 1; //frequncey of 0th element. Now i am actually building the bucket array, whihc counts the frequency
	// read the input
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		sum %= n;
		sum = (sum + n) % n;
		pre[sum]++; // Suppose if Javeed see 1, the pre of first index increases by 1, next time again by 1 and like that.
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int m = pre[i];
		ans += (m) * (m - 1) / 2; //mc2. nummber of subarrays that i can make

	}

	cout << ans << endl;

}