#include<climits>

class stackArray{
	int * data;
	int nextIndex;
	int capacity;

public:

stackArray(int totalSize){
	data=new int[totalSize];
	nextIndex=0;
	capacity=totalSize;
}

int size(){
	return nextIndex;
}


bool isEmpty(){
	return nextIndex==0;
}

void push(int element){
if(nextIndex==capacity){
	cout<<"stack is full"<<endl;
	return ;

}

data[nextIndex]=element;
nextIndex++;

}


int pop(){
	if(capacity==0){
		cout<<"already empty"<<endl;
		return -1;
	}
	
	nextIndex--;
	return data[nextIndex];
}

int top(){
	if(isEmpty()){
		cout<<"stack is empty"<<endl;
		return -1;
	}
	return data[nextIndex-1];
}



};