#include<bits/stdc++.h>
using namespace std;


int main(){


//inbuild queue //
//	push enter queus object
//front(): to access the front element
// pop(): return void ,remove the element 
//size(), empty()


	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(50);	
	q.push(40);

cout<<q.front()<<endl;
cout<<q.size()<<endl;
while(!q.empty()){
	cout<<q.front()<<endl;
	q.pop();
}



}