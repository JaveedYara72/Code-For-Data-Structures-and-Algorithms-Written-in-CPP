#include <bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
#include<iostream>
#include<string>
#include<list>
#define ll long long
const int N = 100000;
using namespace std;

vector<int> primes; //For stroring all the primes
int p[N] = {0};







//3) Check if the Given Large number is Prime Or Not
// Numbers from 10^12/14/16
// The Sieve we have made has a limitation Problem till 10 power 7
// Include Bitset header file
// const int n = 10000000;
//vector<int> primes;
//bitset<10000005> b;


// Central Idea. if the Number is greater than sieve size.
// iterate over the divisors of N, if it lies in the range of 0 ro root N and it divides it, then it it not prime
int sieve() {
	b[0] = b[1] = 0;

	for (long long int i = 2; i <= n; i++) {
		if (b[i] == 1) {
			primes.push_back(i);
			for (long long int j = i * i; j <= n; j++) {
				b[j] = 0;
			}
		}
	}
}


bool isPrime(long long int No) {
	if (No <= n) {
		return b[No] == 1 ? true : false;
	}

	for (long long int i = 0; (long long)primes[i]*primes[i] <= No; i++) {
		if (No % primes[i] == 0) {
			return false;
		}
	}
	return true;
}