#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"

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

void print(Node *head) {
	//so that list is not lost after working on head
	Node * temp = head;

	while (temp != NULL) {

		cout << temp->data << "-->";

		temp = temp->next;

	}
}



//mid point
int midp(Node* head){
//one method directly find length and do (len-1)/2 for mid 
//else take slow and fast pointer 

	Node*slow=head;
	Node*fast=head;

while(fast!=NULL){
	if(fast->next==NULL){
		//if length is even therefor this if executes
		return slow->data;
	}
	slow=slow->next;
	fast=fast->next->next;

}
return slow->data;
}



//merge two sorted link list
Node* mergell(Node*h1, Node*h2){
// Node *head1=h1;
// Node* head2=h2;

Node* first;
Node*last;
if(h1==NULL){
	return h2;
}else if(h2==NULL){
	return h1;
}

if(h1->data<h2->data){
	first=h1;
	last=h1;
	h1=h1->next;
}else{
	first=h2;
	last=h2;
	h2=h2->next;
}

while(h1!=NULL &&h2!=NULL){
	if(h1->data<h2->data){
		last->next=h1;
			last=h1;
			h1=h1->next;
	}else{
		last->next=h2;
		last=h2;
		h2=h2->next;
	}
}



if(h1!=NULL){
	last->next=h1;
}

if(h2!=NULL){
	last->next=h2;
}

return first;

}



//mergeSort
Node* mergeSort(Node * head){
	//find mid
		if(head==NULL){
			return NULL;
		}
if(head->next==NULL){
	return head;
}



	Node* temp=head;
	int len=0;
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}

	int mid=(len-1)/2;
	Node*temp2=head;
	
int i=0;
	while(i<mid){
temp2=temp2->next;
	i++;
	}

Node*a=temp2->next;
temp2->next=NULL;



	Node*a1=mergeSort(head);
	Node* b=mergeSort(a);
	Node*head4=mergell(a1,b);

return head4;




}







int main(){
	
	Node* head=TakeInputBetter();
	print(head);
cout<<endl;
	// cout<<"\nfound at index "<<findNumber(head,6)<<endl;


	// Node* h2=appendAtFirst(head,2);
	// print(h2);

	
	// Node * h2=reversell(head);
	// print(h2);

	// cout<<"\nmid is "<<midp(h2)<<endl;


// cout<<checkPalindrome(h2);


Node* head2=TakeInputBetter();
print(head2);
cout<<endl;


Node* mergeHead1_head2=mergel(head,head2);
cout<<"merge is"<<endl;
print(mergeHead1_head2);


// Node * h3=mergeSort(head2);
// print(h3);



}
