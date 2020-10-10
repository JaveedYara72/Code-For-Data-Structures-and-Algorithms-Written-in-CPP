// How To Make a Generic Function i.e to make a template. THis search will work for all kinds of functions
template<typename T>
int search(T arr[], int n, T key) { // Must pass the array as T
	for (int p = 0; p < n; p++) { //n is number of buckets
		if (arr[p] == key) {
			return p;
		}
	}
	return n;
}

int arr[] = {1, 2, 3, 4};
	int n = sizeof(arr) / sizeof(int);
	int key = 4;

	cout << search(arr, n, key);
This search can go through array of strings,characters etc.
//<--------------------------------------------------------->
//THis is A Template + Interior - Free from Data Types and Containers. Make and array of strings and just put them in the container


template<class ForwardIterator, class T> // These 2 classes are different Mind You.
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key) { //Accepts the Begin and end of the container

	while (start != end) {
		if (*start == key) {
			return start;
		}
		start++;
	}
	return end;
}

	list<int> l;

	l.push_back(4);
	l.push_back(6);
	l.push_back(5);
	l.push_back(2);

	auto it = search(l.begin(), l.end(), 1); //Finds the element and returns the same element
	if (it ==  l.end()) {
		cout << "Element Not Present";
	} else {
		cout << *it << endl; //Derefering. Understand the concept
	}


//<--------------------------------------------------------->
// Comparator + Template +  Iterator -  Heaven
// Sample Problem of Finding a Book now with the Given Price

template<class ForwardIterator, class T, class Compare> // These 2 classes are different Mind You.
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp) { //Accepts the Begin and end of the container

	while (start != end) {
		if (cmp(*start, key)) {
			return start;
		}
		start++;
	}
	return end;
}

class Book {
public:
	string name;
	int price;

	Book() {

	}

	Book(string name, int price) {
		this->name = name;
		this->price = price;
	}
};

class BookCompare {
public:
	bool operator()(Book A, Book B) {
		if (A.name == B.name) {
			return true;
		}
		return false;
	}
};


int main(){
    Book b1("C++", 110);
	Book b2("Python", 110);
	Book b3("Java", 110);
	Book b4("C++", 110);

	list<Book> l;

	l.push_back(b1);
	l.push_back(b2);
	l.push_back(b3);

	BookCompare cmp;
	auto it = search(l.begin(), l.end(), b4, cmp);
	if (it != l.end()) {
		cout << "Yes they are available";
	} else {
		cout << "No they are not";
	}
 
 return 0;
 
 }
