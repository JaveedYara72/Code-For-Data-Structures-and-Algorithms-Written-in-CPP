int comparator(int a, int b) {
	return a <= b;
}

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int n = sizeof(coins) / sizeof(int);

	int money = 168;

	while (money > 0) {
		int lb = lower_bound(coins, coins + n, money, comparator) - coins - 1; //Subtracting The Address Bro. The Coins Address
		int m = coins[lb];
		cout << money << " ";
		money = money - m;
	}
