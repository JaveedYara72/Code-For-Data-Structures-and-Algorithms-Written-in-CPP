// Strings
// Sort a List of strings Lexographically

bool compare(string a, string b) { // This Comparator is being used
	// Strings for same length then they are sorted lexographically, otherwise
	// Strings get sorted on basis of length
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() > b.length();
	}
}

string stringsort() {
	int n;
	cin >> n;
	cin.get();

	string s[100];

	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}


	sort(s, s + n, compare);

	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}

}

//<---------------------------------------------------->
// Do this whenever a problem asks you to sperate words based off strings and differentiate it on basis of some character
// String Tokeniser. Very Important
// String Token - Break a string into Token of Strings
// It would Look like

// char *strtok(char *s, char *delimiters)
//on the first call make sure you put string as an argument and the char upon you want to divide
// Subsequently make the argument NULL;
// C Compiler points out to The first object in the array and When you pass NULL. It is Gonna Eventually Keep Printing as NULL Keeps being an argument
//At last it would put the last element to \0.

char* stringtoken() { //strtok is an inbuilt function
	char s[100] = "Today is a Rainy Day";

	char* ptr = strtok(s, " "); //Trying to Divide and print the string based on the spaces
	cout << ptr << endl; // Here it is a character array that is being accessed. So no need of convering to a new type.
	/*
		ptr = strtok(NULL, " ");
		cout<<ptr<<endl; //Here it would print "is" only
						 // For Printing Everythin, Initialise with while*/
	while (ptr != NULL) {
		ptr = strtok(NULL, " ");
		cout << ptr << endl;
	}

}

//<------------------------------------------------------------------------------->
//String Problem

string extracttoken(string str, int key) {
	char* s = strtok((char*) str.c_str(), " "); //Apparently The Str has to be COnverted into Char* Prior to Tokenization
	// Also, The String has to be cut in tokens so that it could be tokenized. That is why we use c_str();

	while (key > 1) {
		s = strtok(NULL, " "); // While Loop for making sure that We get the token according to the key
		key--;
	}

	return (string)s;  // type Casting it again back to str.
}

int convertToInt(string s) { // Converts String into an Integer
	int ans = 0;
	int p = 1;

	for (int i = s.length() - 1; i >= 0; i--) {
		ans += ((s[i] - '0') * p);
		p = p * 10;
		return ans;

	}
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return convertToInt(key1) < convertToInt(key2);
}

bool lexiocompare(pair<string, string> s1, pair<string, string> s2) {
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return key1 < key2;
}

string stringsolve() {

	int n;
	cin >> n;
	cin.get();

	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;

	string s[1000];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	//Sort the extracted tokens.
	// Extract the key from a string and store it
	// Make A Pair, As given in like question. Make an array of pairs

	pair<string, string> strpair[100];

	for (int i = 0; i < n; i++) {
		strpair[i].first = s[i];
		strpair[i].second = extracttoken(s[i], key);
	}

	//The Array contains the string and the key
	// We need to sort after that

	//One is Lexographical and the other is numerical

	if (ordering == "numeric") {
		sort(strpair, strpair + n, numericCompare);
	} else {
		sort(strpair, strpair + n, lexiocompare);
	}

	if (reversal == "true") {
		for (int i = 0; i < n / 2; i++) {
			swap(strpair[i], strpair[n - i - 1]); // Reverses the array
		}
	}

	// Print the array
	for (int i = 0 ; i < n; i++) {
		cout << strpair[i].first << endl;
	}



}
