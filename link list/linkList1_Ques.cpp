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



//recursive
int findNumber2(Node* head,int number){
		Node * temp=head;
		if(temp->next==NULL){
			return -1;
		}else{
		
		if(temp->data==number){
			return 0; 
		}

		int numbers=1+findNumber2(head->next,number);

return numbers;}
return -1;

}





//find a number in a link list and print its index
int findNumber(Node * head,int number){
	Node* temp=head;
	int index=0;
	if(head==NULL){
		return -1;
	}
	while(temp!=NULL){

			if(temp->data==number){
				return index;
			}
			temp=temp->next;
			index++;
	}

return -1;
}






//append n list at first ex. 12345 ,n=3 ans=34512
Node* appendAtFirst(Node * head,int n){
	if(n==0){
		return head;
	}
	Node * tm=head;
	int length=1;
	while(tm->next!=NULL){
		tm=tm->next;
		length++;
	}
	
	
int i=0;


Node* temp=head;
while(i<length-n-1){
temp=temp->next;
i++;
}

Node* newhead=temp->next;  // 3 is new head now
temp->next=NULL; // 1-2-NULL


// as tm already on 5 otherwise make looj until new head not null and find last elemtn and connect it with 1
tm->next=head;
return newhead;
}



//remove duplicates from sorted link list
Node * removeduplicates(Node * head){
	
	Node* p=head;
	Node* q;
	if(p==NULL){
		return head;
	}
	while(p->next!=NULL){

		if(p->data==p->next->data){
			q=p->next->next;
			
			p->next=q;
		}
		else{
			p=p->next;
		}
	}
	
	return head;

}



//print reverse link list//
Node* reversell(Node* head){
	if(head==NULL || head->next==NULL){
	return head;
}

Node * smallans=reversell(head->next);
//gives 2 3 4 5 reverse  5 4 3 2 , now attach 1 to last

Node*temp=smallans;
while(temp->next!=NULL){
	temp=temp->next;
}
temp->next=head;
head->next=NULL;

return smallans;
}




//print reverse link list//
//in linklist2
Node*  reversellBetter(Node* head){
if(head==NULL || head->next==NULL){
	return head;
}

Node * smallans=reversellBetter(head->next);
Node*tail=head->next;
tail->next=head;
head->next=NULL;
return smallans;
}

//palindrome check
bool checkPalindrome(Node* head){
//one method to reverse the link list and compare it with original but takes more space


//second method
//find length and break link list into two parts 
//first part should be equal to second part reverse

Node* temp=head;
int len=0;
while(temp!=NULL){
	temp=temp->next;
	len++;
}
int i=0;
Node* first=head;
while(i+1<(len-1)/2){
first=first->next;
	i++;
}
Node * second=first->next;
first->next=NULL;


second=reversell(second);

int flag=0;
while(first->next!=NULL && second->next!=NULL){
	if(first->data==second->data){
		flag=0;
		first=first->next;
		second=second->next;
	}
	else{
	flag=1;
	break;	
	}
}


return flag==0?true:false;


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

Node* rotateByk(Node* head,int k){
	 if(head==NULL) return NULL;
        if(head->next==NULL ||k==0) return head;
        Node* temp=head;
        Node* head1=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        //if len is multiple of k
        if(k%len==0 &&k!=1) return head;
        
        int lastindex=len-(k%len);
        temp=head;
        Node* x=NULL;
        int i=1;
        while(i<=lastindex){
            x=temp;
            temp=temp->next;
            i++;
        }
        
        Node*p=x->next;
        x->next=NULL;
        head=p;
        while(p->next){
            p=p->next;
        }
        p->next=head1;
            return head;
        
        
}



int main(){
	
	Node* head=TakeInputBetter();
	print(head);
cout<<endl;
	cout<<"\nfound at index "<<findNumber(head,1)<<endl;

// Node* hr=removeduplicates(head);
// print(hr);


	// Node* h2=appendAtFirst(head,4);
	// print(h2);

	
	// Node * h2=reversellBetter(head);
	// print(h2);

	// cout<<"\nmid is "<<midp(h2)<<endl;


// cout<<checkPalindrome(h2);


// Node* head2=TakeInputBetter();
// print(head2);
// cout<<endl;


// Node* mergeHead1_head2=mergell(head,head2);
// print(mergeHead1_head2);


Node* h3=rotateByk(head,10);
print(h3);



}
