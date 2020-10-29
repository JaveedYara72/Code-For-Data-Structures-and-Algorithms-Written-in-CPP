#include <bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>
#include<string>
#include<list>


using namespace std;




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
				p[i] = 0;
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
