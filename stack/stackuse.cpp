#include<bits/stdc++.h>
using namespace std;
#include "stack.cpp"
#include "dynamicArrayStack.cpp"


void balancedParanthesis(string string){
stack<char> s;
for (int i=0;i<s.size();i++){
if(string[i]=='{' || string[i]=='(' || string[i]=='['){
	s.push(i);
}
else if((s.top()=='{' && string[i]=='}') ||(s.top()=='(' && string[i]==')')||(s.top()=='[' && string[i]==']') ){
	s.pop();
}
else{
	continue;
}


}

cout<<(s.size()==0?"yes":"no");

}





int main(){

	// stackArray s(4);
	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);
	// s.push(5);
//cout<<s.size()<<endl;
// 	// s.push(5);
// cout<<"top is "<<s.top()<<endl;
// 	while(!s.isEmpty()){
// 		cout<<s.pop()<<endl;
// 	}
// cout<<(s.isEmpty()==1?"true":"false")<<endl;



// dynamicstackArray s;
// s.push(4);
// s.push(4);
// s.push(4);
// s.push(4);
// s.push(4);
// s.push(4);
// s.push(4);
// s.push(4);
// s.push(4);
// s.push(4);
// s.push(4);
// while(!s.isEmpty()){
// 	cout<<s.pop();
// }
// cout<<"\nsize is " <<s.size()<<endl;



//inbuild stack//  ////pop dont return anything in pop // and instead of isEmpty it is empty()
// stack<int> s;
// s.push(10);
// s.push(20);
// s.push(30);
// s.push(40);

// cout<<"size is "<<s.size()<<endl;

// while(!s.empty()){
// 	cout<<s.top()<<" ";
// 	s.pop();
// }

string st="{s+(b+c}";
string s="a+";
balancedParanthesis(s);





}
