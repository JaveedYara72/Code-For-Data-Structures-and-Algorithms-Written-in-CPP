#include <bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
#include<iostream>
#include<string>
#include<list>
#define ll long long
const int N = 10000000;
using namespace std;

vector<int> primes; //For stroring all the primes
int p[N] = {0};


//4) Segmented Prime Sieve. Number theory popular problem.
// Generate all prime Numbers between 2 Numbers
// Each test Case has m and n. both can be in order of 10 power 9. you can't use a prime sieve.
// Because its range is from 0 to 10 power 7

/*Suppose n = 50 and m = 100. Take an array seperately and transfer all the elements of (50 to 100) to the new array starting from 0th  Index to
50th Index. 0th Index would be m-m, 50th Index would be n-m, numbers between them are i-m for a number at ith index in the original array.
Basically shifitng elements to left by m places.*/
/*vector<int> primes; //For stroring all the primes
int p[N] = {0};*/ // For marking 1's and 0's for the primes

void sieve() {
	for (int i = 2; i <= N; i++) {
		// First, Store the primes
		if (p[i] == 0) {
			primes.push_back(i);
			//mark all the multiples of i as not prime
			for (int j = i; i <= N; j = j + i) {
				p[j] = 1; // Marking all the divisible numbers to 1
			}
		}
	}
}



int main() {
	sieve();

	int t;
	cin >> t; // Number of Test Cases

	while (t--) {
		int n, m;
		cin >> n >> m; // For the Ranges to find the primes in between

		bool segment[n - m + 1];
		for (int i = 0; i <= n - m + 1; i++) {
			segment[i] = 0; //Basically marking every number as prime as of now
		}

		for (auto x : primes) {
			if (x * x > n) {
				break; // Stop the loop if. lets say m = 144, n=12. for n=13, its square is 169 which is way beyond 144. so do it only till root n. that is till 12 in this case
			}

			int start = (m / x) * x;

			if (x >= m and x <= n) {
				start = 2 * x; // Lets say that the prime number exists in the given segmented sieve. Now, upon being in the given range. if you divide it for start point, it would give you 0. So start fresh and start from 2 of x rather tham its original point
			}

			//mark all multiples of x as not primes
			for (int i = start; i <= n; i++) {
				segment[i - m] = 1; // Marking the Multiples as not primes
			}
		}

		for (int i = m; i <= n; i++) {
			if (segment[i - m] == 0 and i != 1) {
				cout << i << endl;
			}
		}
	}



	cout << endl;
//}

}