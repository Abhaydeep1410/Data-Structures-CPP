#include <bits/stdc++.h>
using namespace std;
#include "priorityQueue.h"


void inplaceheapSort(int pq[],int n){
//build the heap in input array

	for (int i = 1; i < n; ++i)
	{
		
			int childIndex=i;
		while(childIndex>0){
		int parentIndex=(childIndex-1)/2;
		
		if(pq[parentIndex]>pq[childIndex]){
				int temp=pq[parentIndex];
				pq[parentIndex]=pq[childIndex];
				pq[childIndex]=temp;
		}else{
			break;
		}
		childIndex=parentIndex;
		}
	}// now heap is built in the given array

	// now for sort call remove min n times

	int size=n;
	while(size>1){
	int temp=pq[0];
	pq[0]=pq[size-1];
	pq[size-1]=temp;

size--;
//downheapify

int parentIndex=0;
	int leftchildindex=2*parentIndex+1;
	int rightchildindex=2*parentIndex+2;
	while(leftchildindex<size){
		int minindex=parentIndex;
		if(pq[minindex]>pq[leftchildindex]){
			minindex=leftchildindex;
		}
		if(rightchildindex<size && pq[rightchildindex]<pq[minindex]){
			minindex=rightchildindex;
		}
		if(minindex==parentIndex){
			break;
		}

		int temp=pq[minindex];
		pq[minindex]=pq[parentIndex];
		pq[parentIndex]=temp;
		parentIndex=minindex;
		leftchildindex=2*parentIndex+1;
		rightchildindex=2*parentIndex+2;

}

}
}


int main(){

// 	PriorityQueue p;

// p.insert(100);
// p.insert(10);
// p.insert(15);
// p.insert(4);
// p.insert(17);
// p.insert(21);
// p.insert(67);

// cout<<p.size()<<endl;
// 	cout<<p.getMin()<<endl;
// while(!p.isEmpty()){
// 	cout<<p.removeMin()<<" ";
// }
int arr[]={2,3,1,5,6};

inplaceheapSort(arr,5);
for (int i = 0; i < 5; ++i)
{
	cout<<arr[i]<<" ";
}

	
}