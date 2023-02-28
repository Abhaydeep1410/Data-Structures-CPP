#include<vector>

class PriorityQueue{
vector<int> pq;
public:

	//using min heap property
	PriorityQueue(){

	}

	int size(){
		return pq.size();
	}


	bool isEmpty(){
		return pq.size()==0;
	}

	int getMin(){

		if(isEmpty()){
			return 0 ;// priority queue is empty

		}
		return pq[0];
	}


	void insert(int element){
		pq.push_back(element);
		int childIndex=pq.size()-1;
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
	}

int removeMin(){

	int min=pq[0];
	pq[0]=pq[pq.size()-1];
	pq.pop_back();
//downheapify
	// now check for heap properties
	int parentIndex=0;
	int leftchildindex=2*parentIndex+1;
	int rightchildindex=2*parentIndex+2;
	while(leftchildindex<pq.size()){
		int minindex=parentIndex;
		if(pq[minindex]>pq[leftchildindex]){
			minindex=leftchildindex;
		}
		if(rightchildindex<pq.size() && pq[rightchildindex]<pq[minindex]){
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
	return min;
}


};
