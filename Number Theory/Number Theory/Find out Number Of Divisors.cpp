//6) Same Question, with same code but find out number of divisors n.
// For a number 60, the divisors are 1,2,3,4,5,6,10,12,15,20,30,60
// So, Find the Prime Factors. Look at 30, it is(2^1(3^1)5^1).It can be done in many ways just like this
// For every 2^2(it is 2^0,(2^1),2^2). For 3^1(Either 3^0 or 3^1). Selection is Most Important

int no_of_divisors(int m, vector<int> &primes) {
	int i = 0;
	int p = primes[0];
	int ans = 1;

	while (p * p <= m) {
		if (m % p == 0) {
			int cnt = 0;

			while (m % p == 0) {
				cnt++; //cnt denotes the power here
				m = m / p;
			}
			ans = ans * (cnt - 1);
		}
		//Go to Next Position
		i++;
		p = primes[i];
	}

	if (m != 1) {
		ans = ans * 2;
	}

	return ans;

}