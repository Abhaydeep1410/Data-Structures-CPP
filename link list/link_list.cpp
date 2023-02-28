# include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"



Node* takeInput() {
	int  data;
	cin >> data;
	Node* head = NULL;
	while (data != -1) {
// creating newnode  dynamically since if created statically its scope will be within while loop
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
		} else {

			// creating temp pointer to traverse the list till null find and add the element
			Node * temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}

		cin >> data;
	}

	return head;

}


Node* TakeInputBetter() {
	int  data;
	cin >> data;
	Node* head = NULL;
	Node* tail = NULL;
	while (data != -1) {

		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = tail->next;




		}

		cin >> data;
	}

	return head;

}


int length(Node* head) {
	Node* temp = head;
	int len = 0;
	while (temp != NULL) {
		len++;
		temp = temp->next;
	}
	return len;
}

//print data at ith node
int printAt_i(Node *head, int i) {
	Node* temp = head;
	int k = 0;
	while (temp != NULL) {
		if (k == i) {
			return temp->data;

		}
		k++;
		temp = temp->next;
	}
	return -1;

}











Node* insertAtIthPos(Node* head, int i, int data) {

	Node* newNode = new Node(data);
	Node* temp = head;

	if (i == 0) {
		newNode->next = head;
		head = newNode;
		return head;
	}

	int count = 0;
	while (temp != NULL && count < i - 1) {

		temp = temp->next;
		count++;
	}
//temp gets to the postion before the index

	if (temp != NULL) {
		Node* a = temp->next;

		temp->next = newNode;
		newNode->next = a;


	}
	return head;
}




Node* deleteAtI(Node *head, int i) {


	Node* temp = head;

	if (i == 0) {
		temp = temp->next;
		head = temp;
		return head;
	}

	int count = 0;
	while (temp != NULL && count < i - 1) {

		temp = temp->next;
		count++;
	}
//temp gets to the postion before the index

	if (temp != NULL) {
		Node* a = temp->next;

		temp->next = a->next;
		delete a;


	}
	return head;


}


void print(Node *head) {
	//so that list is not lost after working on head
	Node * temp = head;

	while (temp != NULL) {

		cout << temp->data << "-->";

		temp = temp->next;

	}


}

int recursiveLenght(Node* head) {
	if (head == NULL) {
		return 0;
	}
	if (head->next == NULL) {
		return 1;
	}


	return 1 + recursiveLenght(head->next);
}


Node* insertingNodeRecursion(Node* head, int pos, int data) {
	if (head == NULL) {
		return head;
	}
	if (pos == 0) {
		Node * newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		return head;
	}
	Node*x = insertingNodeRecursion(head->next, pos - 1, data);
	head->next = x;
	return head;
}


Node * deleteRecursive(Node* head, int pos) {

	if (head == NULL) {
		return head;

	}

	if (pos == 0) {
		head = head->next;
		return head;
	}
	Node* x = deleteRecursive(head->next, pos - 1);
	head->next = x;
	return head;

}


int main() {
// //statically
// Node n1(1);
// // Node *head=&n1;
// Node n2(3);
// n1.next=&n2;

// //dynamically//
// Node *n3=new Node(5);
// Node *head=n3;


// Node *n4=new Node(20);
// n3->next=n4;

// cout<<n3->data;





//print the link list
	Node n1(1);
	Node *head = &n1;
	Node n2(2);
	Node n3(3);
	Node n4(4);


	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;








	Node *h2 = TakeInputBetter();

	print(h2);
// 	cout << "\nlength is " << length(h2);
// 	cout << "\nvalue at ith position is " << printAt_i(h2, 2)<<endl;



Node *h3=insertAtIthPos(h2,0,99);
print(h3);

	// cout << "\nafter delete  " << endl;
	// Node* h4 = deleteAtI(h2, 0);
	// print(h4);

	// cout << "length is " << recursiveLenght(h4) << endl;


// Node* h5=insertingNodeRecursion(h2,2,99);
// print(h5);


	// Node* h5 = deleteRecursive(h2, 0);
	// print(h5);
	// inserte(h5,1,99);
	// print(h5);



}