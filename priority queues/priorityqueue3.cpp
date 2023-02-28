#include <bits/stdc++.h>

using namespace std;


void ksmallestelement(int * arr,int size,int k){

// one method to sort the array and return first k indeces but it takes O(nlogn)
	// we want slightly better 

priority_queue<int> q;
//insert first k elements and assume them as mininum elements

for(int i=0;i<k;i++){
	q.push(arr[i]);
}

for(int i=k;i<size;i++){
	if(arr[i]<q.top()){
		// if element is smaller than max of that heap
		q.pop();
		q.push(arr[i]);
	}
}


while(!q.empty()){
	cout<<q.top()<<" ";
	q.pop();
}
}




int main(){
	// inbuilt priority queue  (max priority queue)
/* functions empty(), size(), push(element), T top()(get min), 
	void pop() ( remove min) */



priority_queue<int> q;
// if we want a min priority queue
// priority_queue<int,vector<int>,greater<int>> q;
q.push(10);

// q.push(12);
// q.push(13);
// q.push(14);
// q.push(4);



// cout<<q.size()<<endl;

// cout<<q.top()<<endl;


// while(!q.empty()){
// 	cout<<q.top()<<endl;
// 	q.pop();
// }



int arr[]={1,2,8,3,4,1};
ksmallestelement(arr,6,4);



}