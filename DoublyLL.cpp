#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data ;
	Node* prev;
	Node* next;

	Node(int value) {
		this->data = value;
		this->prev = NULL;
		this->next = NULL;
	}
	~Node() {
		cout << "CALLED DESTRUCTOR" << endl;
	}
};

void printList(Node* &head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void insertAtHead(Node* &head , Node* &tail , int val) {

	if (head == NULL) {
		Node* temp = new Node(val);
		head = temp;
		tail = temp;
		return;
	}

	Node* temp = new Node(val);

	head -> prev = temp;
	temp -> next = head;
	head = temp;

}

void insertAtTail(Node* &head , Node* &tail , int val) {
	if (tail == NULL) {
		Node* temp = new Node(val);
		tail = temp;
		head = temp;
		return;
	}
	Node* temp = new Node(val);
	tail -> next = temp;
	temp -> prev = tail ;
	tail = tail-> next;
}

int getLength(Node* &head) {
	int count = 0;
	Node* temp = head;
	while (temp != NULL) {
		count++;
		temp = temp -> next;
	}
	return count;
}

void insertAtPosition (Node* &head , Node* &tail , int pos , int val) {

	if (pos == 1) {
		insertAtHead(head , tail , val);
		return;
	}
	Node* temp = head;
	int count = 1;
	while (count < pos - 1) {
		temp = temp->next;
		count++;
	}
	if (temp -> next == NULL) {
		insertAtTail(head , tail, val);
	}

	Node* temp1 = new Node(val);
	temp1 -> next = temp -> next;
	temp1 -> prev = temp;
	temp -> next -> prev = temp1;
	temp -> next = temp1;

}

int main() {
	Node* head = NULL;
	Node* tail = NULL;
	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (auto i : arr) {
		insertAtTail(head , tail , i);
	}
	printList(head);
	cout << getLength(head) << endl;
}