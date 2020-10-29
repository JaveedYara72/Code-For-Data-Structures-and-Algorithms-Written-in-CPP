// Number Theory
// Prime Sieve
void prime_sieve(int *p) {
	// first mark all odd numbers as prime
	for (int i = 3; i <= 1000000; i += 2) {
		p[i] = 1; // Assume all odds are primes
	}
	// Sieve Code
	for (ll i = 3; i <= 1000000; i += 2) {
		//jumping over all odd Numbers
		// If the Current Number is not marked, then it is prime
		if (p[i] == 1) {
			//mark all the Multiples of i as not prime
			for (ll j = i * i; j <= 1000000; j = j + i) {
				p[j] = 0;
			}
		}
	}

	p[2] = 1;
	p[1] = p[0] = 0;

}

//2) Prime Numbers Problem using prime sieve.
// 66% Pass rate. Find Primes in a range of n
// Print the Number OF primes for the ranges a and b give
// GIven N Number of Queries to be Done, If you do a query till n times, You would get a TLE.
//Precompute a sieve prime array, And According to N's. Save the Number of Primes till the N. for  Eg: 4:2,3->2. 8:2,3,5,7->4
// So In the Given Range 4,8 we have 4-2 that is 2 Prime Numbers between them. Only run the query once for n, but not for n times.
// Each Checking would be 0(1).
void primenumberproblem(int *p) {
	// first mark all odd numbers as prime
	for (int i = 3; i <= 1000000; i += 2) {
		p[i] = 1; // Assume all odds are primes
	}
	// Sieve Code
	for (ll i = 3; i <= 1000000; i += 2) {
		//jumping over all odd Numbers
		// If the Current Number is not marked, then it is prime
		if (p[i] == 1) {
			//mark all the Multiples of i as not prime
			for (ll j = i * i; j <= 1000000; j = j + i) {
				p[j] = 0;
			}
		}
	}

	p[2] = 1;
	p[1] = p[0] = 0;

	// int cumsum[1000005] = {0}; -> Declared it in the main below
	int n;
	cin >> n;

	/*int p[1000005] = {0};
	prime_sieve(p);


	int cumsum[1000005] = {0};
	// precompute the primes upto the index i.


	for (int i = 0; i <= n; i++) { // Mark them 1's if you do not consider them as primes.
		if (p[i] == 1) {
			cout << i << " ";
		}
	}

	int q;
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<cumsum[b] - cumsum[a-1] <<endl;
	}
	}*/