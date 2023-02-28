#include<climits>

class dynamicstackArray{
	int * data;
	int nextIndex;
	int capacity;

public:

dynamicstackArray(){
	data=new int[10];
	nextIndex=0;
	capacity=10;
}

int size(){
	return nextIndex;
}


bool isEmpty(){
	return nextIndex==0;
}

void push(int element){
if(nextIndex==capacity){
	int *newarray=new int[2* capacity];
	for(int i=0;i<capacity;i++){
		newarray[i]=data[i];
	}
	capacity*=2;
	delete []data;
	//data now point to new array
	data=newarray;

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