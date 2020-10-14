//Bit Manipulation
// Problems

// given a Unique number in the form 2N+1.
// Given a list of numbers where every number occurs twice except one, Find that unique number
// Hint: A XOR B, if A and b have same value then they would cancel out.

// int n;
// cin>>n;
// int n0;
// int ans = 0;

// for(int i=0;i<n;i++){
// 	cin>>n0;
// 	ans = ans^n0;
// }

// cout<<ans<<endl;

//<->
// Common Bit Tasks
//1) If a Number is even or odd
bool isOdd(int n) {
	return (n & 1); // Returns a Bool Value That would check is the number is odd. Returns True if the Number is Odd
}
//2) How to find the ith Bit From the right Side

int getbit(int n, int i) {
	int mask = 1 << i;
	int ans = (n & mask) > 0 ? 1 : 0;
	return ans;
}
//3) SetBit of a Number to 1
int Setbit(int n, int i) {
	int mask = 1 << i;
	int ans = n | mask;
	return ans; //  if that bit was 0, it would be set to 1. If the bit was 1, it would be set to 1 itself.
}
// Remove the bit
int ClearBit(int n, int i) {
	int mask = ~(1 << i);
	n = (n & mask);
	return n;
}
//4) Update the Bit with given v and at the ith Position
int UpdateBit(int n, int i, int v) {
	int mask = ~(1 << i);
	int cleared_n = n & mask;
	n = cleared_n | (v << i);
	return n;
}
//5) Clear the last I Bits From the end
int ClearlastBits(int n, int i) {
	int mask = (-1 << i);
	n  = n & mask;
	return n;
}

//6) Update the Range of Bits from ith index to Jth Index in the number, i coming from Right end
int clearRangeofBits(int n, int i, int j) {
	int ones = (~0);
	int a = ones << (j + 1);
	int b = (1 << i) - 1;
	int mask = a | b;
	int ans = n & mask;
	return ans;
}

//7) Replace Bits by N and M
//Given two 32 Bit NUmbers. N and M are 2 Bit Positions
// M Becomes a substring of N located at i and starting at j

int problem1(int n, int m, int i, int j) {
	/*int ones = (~0);
	int a = ones << (j + 1);
	int b = (1 << i) - 1;
	int mask = a | b;
	int ans = n & mask;
	return ans;*/
	int clear = clearRangeofBits(n, i, j); // Clearing the N Bits
	int ans = clear | (m << i); // Clearing the N Bits and pushing this m forward into the m
	return ans;
}

//8) Given a Number N, Find the Number of Set Bits, THat is to count all the Ones present in the number
int problem2(int n) {
	// 3 Total Approaches
	// First Approach
	int ans = 0;
	while (n > 0) {
		ans += (n & 1);
		n = n >> 1; //Right Shifting it will push the number right and get us the value
	}

}
//Second Approach
int problem21(int n) {
	int ans = 0;
	while (n > 0) {
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

//Third Approach
/*__builtin_popcount(n); Prints us the Number of set bits in the number*/

//8) Convert Decimal to binary
int convert(int n) { // THis Function prints the number in reverse, but we add these conditions in while loop to Get it printed Correctly.
	int ans = 0;
	int p = 1;
	while (n > 0) {
		ans += p * (n & 1); //The NUmber gets added according to the ones and gets multiplied by 10
		n = n >> 1; // The Number starts left shifting to remove the ones left
		p = p * 10; // This One Multiplies the Number So that it could be in order, it increases like 1,10,100,100 and so on.
	}
}

//9)Convert Binary to Decimal
int convertbinarytodec(int n) {
	int ans = 0;
	int base = 1;
	int temp = n;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;
		ans += last_digit * base;
		base = base * 2;
	}

	return ans;
}

//10) Unique Number Problem 2
// Given an array find the 2 digits that have not been repeated
// Linear Time and Constant Space
int unique2(int a[], int n) {
	int xor1 = 0;
	// Do Xor of all Numbers
	// When you Xor everything, You will get a value, which is never 0. So find the Numbers which have a relation with the Result of XOR
	// For Example an array like [5,1,2,1,2,3,5,7]
	// You Will get 3 and 7 which Xors to 4 -> 0100
	// Find for the number which has a setbit at 2nd position, add them to the list. [5,5,7]. Now XOR Them again, you will get 7.
	// Founded the First Unique Number, So XOR it again with every value of remained array so that you get the 3
	for (int i = 0; i < n; i++) {
		int n0;
		cin >> n0;
		a[i] = n0;
		xor1 = xor1 ^ n0;
	} // at this point it might have xor'ed every number leaving the xor of unique numbers only.

	int temp = xor1;
	int pos = 0;
	// Finding setbits
	while ((temp & 1) != 1) {
		pos++;
		temp = temp >> 1;
	}
	// The first setbit from the right is at pos variable.
	// creating a mask. 1<< pos. 100 -> 1<<2;
	int mask = (1 << pos);
	int x = 0;
	int y = 0;
	// find those numbers which has setbit at position pos;
	for (int i = 0; i < n; i++) {
		if ((a[i] > mask) > 0) {
			x = x ^ a[i];
		}
	}
	// a[i] & mask > 0. that means it has a set bit.
	y = xor1 ^ x;
	// Now Keep Xor ing in the list that we have created
	cout << min(x, y) << " " << max(x, y);
}

//11) Unique Number - 3
int unique3() {
	int cnt[64] = {0};

	int n, no;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> no;
		// Update the cnt array by extracting bits
		int j = 0;
		while (no > 0) {
			int last_bit = (no & 1);
			cnt[j] += last_bit;
			j++;
			no = no >> 1;
			// suppose no = 5, initially all the counts are 0.
			// if you see 1 at first index, then j[i] would be increased by 1. same goes to all indices
		}
	}

	int p = 1;
	int ans = 0;

	// print the array
	for (int i = 0; i < 64; i++) {
		cnt[i] %= 3; // An array which has the binary of unique number
		ans += (cnt[i] * p);
		p = p << 1;
	}

	cout << ans << endl;


}

//12) Exponentiation Using Bitwise Manipulation
int power_optimised(int a, int n) {
	int ans = 1;
	while (n > 0) {
		int last_bit = (n & 1);
		if (last_bit) {
			ans *= a;
		}
		a = a * a;
		n = n >> 1;
	}

	return ans;

}
//13) Find Number of Substrings in a given string
int sub_String(int n, char a[]) {
	int j = 0;
	while (n > 0) {
		int last_bit = (n & 1);
		if (last_bit == 1) {
			cout << a[j];
		}
		j++;
		n = n >> 1;
	}
	cout << endl;
}

void printSubset(char a[]) {
	int n = strlen(a);
	for (int i = 0; i < (1 << n); i++) {
		sub_String(i, a);
	}
	return;
}

//14) Inclusion Exclusion Concept - implementation
// #) define ll long long
int32_t main() {
	ll t;
	cin >> t;

	ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	ll ans = 0;
	while (t--) {
		ll n;
		cin >> n;

		ll subsets = (1 << 8) - 1 ; // Number of Subsets are denoted by 2 raised to the power 8. execpt one that is 0.
		// Create Subsets
		for (ll i = 1; i < subsets; i++) {
			ll denominator = 1ll;
			ll setbits1 = __builtin_popcount(i); // Find the Setbits.
			// FInd that ith rown of jth Column and Multiply it with N/(max product);
			if (i & (i << j)) {
				denominator = denominator * primes[j]; // Multpilying the denominator with all these values.
			}
		}
		if (setbits1 & 1) { // Tells us the Number is odd or even. This if case is for odd
			ans += n / denominator;
		} else {
			ans -= n / denominator;
		}

	}

	cout << ans << endl;
	return 0;
}


// Code For Find the Unique Element in the array
/*int n;
	cin >> n;
	int n0;
	int ans = 0;
	// Bitwise XOR
	for (int i = 0; i < n; i++) {
		cin >> n0;
		ans = ans ^ n0;
	}
	cout << ans << endl;*/

