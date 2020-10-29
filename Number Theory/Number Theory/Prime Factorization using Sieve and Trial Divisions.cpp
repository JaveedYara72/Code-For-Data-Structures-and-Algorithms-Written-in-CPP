//5) Prime factorization using sieve
vector<int> factorize(int m, vector<int> &primes) {
	vector<int> factors;
	factors.clear();

	int i = 0;
	int p = primes[0];

	while (p * p <= m) {
		if (m % p == 0) {
			factors.push_back(p);
			while (m % p == 0) {
				m = m / p;
			}
		}

		i++;
		p = primes[i];
	}
	if (m != 1) {
		factors.push_back(m);
	}

	return factors;
}

// Main Code
int main() {
	int n = 10000;
	int p[n] = {0};
	vector<int > primes = primesieve(p, 100);

	int t;
	cin >> t;

	while (t--) {
		int no;
		cin >> no;

		vector<int> factors = factorize(no, primes);

		for (auto& it : factors) {
			cout << it << " " << endl;
		}
	}

	return 0;

}


//5)Prime Factorization Using Trial Divisions

void printFactors(int n) {
	vector<pair<int, int>>factors;
	int cnt;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0  ) {
				cnt++;
				n = n / i;
			}
			factors.push_back(make_pair(i, cnt));
		}
	}
	if (n != 1) {
		factors.push_back(make_pair(n, 1));
	}

	for (auto p : factors) {
		cout << p.first << " " << p.second << endl;
	}

	return;
}