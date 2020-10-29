//7) Factorial problem
// Given 2 Integers n and k, Find n!%(k^x) = 0;
// Find x, such that the above formula or notation becomes true
// 5 and 2. 5 factorial = 120, k = 2.
// highest common factor here is 3 = x;

int t;
cin >> t;
int n, k;

while (t--) {
	cin >> n >> k;

	int ans = INT_MAX;
	//factorization of k
	// p1,p2,p3....pl
	int occ = 0;
	for (int i = 2; i * i <= k; i++) { //prime factorization loop. keep on dividing the n until you get 0 out of it, iterate througn every i to get prime factors
		if (k % i == 0) {
			occ = 0;
			while (k % i == 0) {
				occ++; // Occurences of an number
				k = k / i;
			}
			//find out the powers of i in the n! side by side
			int cnt = 0; // cnt is for the c1,c2,...cn.
			int p = i;
			while (p <= n) { // n! = n/p + n/(p^2) + n/(p^3) +....
				cnt += n / p;
				p = p * i; //p is powers of i
			}

			ans = min(ans, cnt / occ);
		}
		// This Part is For Finding Min(c1/k1,c2/k2,c3/k3/....cl/kl);
	}
	// We may have a case when we still have a primefactor left
	if (k > 1) {
		int cnt = 0;
		long long p = k;
		while (p <= n) {
			cnt += n / p;
			p += k;
		}
		ans = min(ans, cnt);
	}
	// also possible that n factorial doesnt have all the prime factors
	if (ans = INT_MAX) { // n =5 and k = 7. printing 0 should be the answer.
		ans = 0;
	}
	cout << ans << endl;
}
