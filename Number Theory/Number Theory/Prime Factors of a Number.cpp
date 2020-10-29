//4)Prime Factorization of a number
vector<int> primesieve(int*p, int n) {
	p[0] = p[1] = 0;
	p[2] = 1;

	for (int i = 3; i <= n; i = i + 2) {
		p[i] = 1;
	}

	for (int i = 3; i <= n; i = i + 2) {
		if (p[i]) {
			for (int j = i * i; j <= n; j = j + 2 * i) {
				p[j] = 0;
			}
		}

	}

	vector<int> primes;
	primes.push_back(2);


	for (int i = 3; i <= n; i++) {
		if (p[i]) {
			primes.push_back(i);
		}
	}

	return primes;
}

int main() {
	int N = 1000000;
	int p[N];

	for (int i = 0; i < N; i++) {
		p[i] = 0;
	}
	vector<int>primes = primesieve(p, 10000);

	int t;
	cin >> t;

	while (t--) {
		int n0;
		cin >> n0;
		int divs = factorize(n0, primes);
	}

	return 0;
}