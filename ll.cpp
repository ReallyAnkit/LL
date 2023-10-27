#include <bits/stdc++.h>
using namespace std;

//LINKED LIST IMPLEMENTATION USING CLASS IN CPP


//NODE DEFINTION USING CLASS
class node
{
public:
	int data;
	node* next;
	node(int data) {
		this->data = data;
	}
	~node() {
		cout << "Destructor Called for " << this->data << endl;
	}
};

//INSERTING A NODE AT STARTING OF LINKED LIST
void insertAtHead(node* &head , int x) {
	//
	node* temp = new node(x);
	temp->next = head;
	head = temp;
}

//INSERTING AT LAST OF LINKED LIST
void insertAtTail(node* &tail , int x) {
	node* temp = new node(x);
	tail->next = temp;
	tail = temp;
}

// INSERTING A NODE AT A GIVEN POSITION
void insertAtPosition(node* &tail , node* &head , int pos , int x) {
	if (pos == 1) {
		insertAtHead(head , x);
		return;
	}
	node* temp = head;
	int cnt = 1;
	while (cnt < pos - 1) {
		temp = temp->next;
		cnt++;
	}
	if (temp -> next == NULL) {
		insertAtTail(tail , x);
		return;
	}
	node* temp1 = new node(x);
	temp1 -> next = temp->next;
	temp -> next = temp1;
}

// TO DISPLAY THE LIST
void printList(node* &head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp -> data << endl;
		temp = temp->next;
	}
}

// DELETE A NODE IN THE LIST AT A GIVEN POSITION
void deleteNode(node* &tail , node* &head , int pos) {

	if (pos == 1) {
		node* temp = head;
		head = head -> next;

		delete temp;
	}
	node* curr = head;
	node* temp = nullptr;
	int cnt = 1;
	while (cnt < pos) {
		temp = curr;
		curr = curr -> next;
		cnt++;
	}
	temp -> next = curr -> next;
	if (temp -> next == NULL) {
		tail = temp;
	}

	delete curr;

}


int main() {
	node* head = new node(10);
	node* tail = head;
	insertAtHead(head , 39);
	insertAtHead(head , 50);
	insertAtTail(tail , 9);
	insertAtPosition(tail, head, 5, 99);
	deleteNode(tail , head , 3);
	printList(head);
}