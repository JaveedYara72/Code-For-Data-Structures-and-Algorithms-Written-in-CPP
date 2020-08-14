#include<iostream>

using namespace std;

class node {
public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void inserthead(node* &head, int data) {
	node* n = new node(data);
	n->next = head;
	head = n;
}

void inserttail(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;

	}
	temp->next = new node(data);
	return;
}

int length(node * head) {
	int cnt = 0;
	while (head != NULL) {
		head = head->next;
		cnt++;
	}
	return cnt;
}

void insertmidddle(node* &head, int data, int pos) {
	if (head == NULL || pos == 0) {
		inserthead(head, data);
	} else if (pos > length(head)) {
		inserttail(head, data);
	} else {
		int jumps = 1;
		node* temp = head;
		node* n = new node(data);

		while (jumps <= pos - 1) {
			temp = temp->next;
			jumps++;
		}
		n->next = temp->next;
		temp->next = n;

	}
}


void print(node * head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "-->";
		temp = temp-> next;
	}
}

void deletehead(node* &head) {
	if (head == NULL) {
		return;
	}
	node* temp = head;
	head = head->next;
	delete temp;
	return;
}

void deletetail(node* &head) {
	node* temp = head;
	node* prev = NULL;

	while (temp->next != NULL) {
		prev = temp;
		temp = temp -> next;
	}

	delete temp;
	prev -> next = NULL;
	return;
}

void deletemiddle(node* &head, int pos) {
	node* prev = NULL;
	node* temp = head;

	int jumps = 1;
	if (pos == 1) { //It would work perfectly even without that if condition
		deletehead(head);
		return;
	}
	else if (pos > 1) {
		while (jumps <= pos - 1) {
			prev = temp;
			temp = temp->next;
			jumps ++;
		}
	}
	prev -> next = temp->next;
	delete(temp);
	return;
}

bool nodesearch(node * head, int key) {
	if (head == NULL) {
		return false;
	}
	if (head->data == key ) {
		return true;
	} else {
		head = head->next;
		nodesearch(head->next, data);
	}

}

int nodesearchiterative(node * head, int key) {
	for (int i = 0; i < length(head); i++) {
		if (head == NULL) {
			return -1;
		} else if (head->data == key) {
			return i;
		}
		head = head -> next;
	}

}

// Take Input a List of Number at tail of Linkedin List
void buildlist(node* &head) {
	int data;
	cin >> data;

	while (data != -1) {
		inserttail(head, data); //-> So that the Upper Inputted data Goes in first
		cin >> data;

	}
}

//-> Operator Overloading. Suppose if we put "<<head" it should take in complete linked list
// -> Very Important

istream& operator>>(istream & is, node* &head) {
	buildlist(head);
	return is;
}

ostream& operator<<(ostream & os, node * head) {
	print(head);
	return os;
}

void reverse(node * head) {
	node* c = head;
	node* p = NULL;
	node* n = NULL;

	while (c != NULL) {
		n = c->next;
		c->next = p;

		p = c;
		c = n;
	}
	head = p;
}

node* middlepoint(node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	node* fast = head->next;
	node* slow = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}
