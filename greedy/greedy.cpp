#include <bits/stdc++.h>
using namespace std;

// in greedy we try to pick up the best possible solution



//minimum absolute difference between two numbers in array
// sort the array min will be diff between any two consecutives
int minAbsDiff(int * arr,int size){

	sort(arr,arr+size);
	int mn=INT_MAX;
	for(int i=0;i<size-1;i++){
		if(arr[i+1]-arr[i]){
			mn=min((arr[i+1]-arr[i]),mn);
		}
	}
return mn;
}

//nikunj and donuts
// nikunk has to walk 2^j*k miles j is number of donuts already eaten and k is calorie of donut
//find minimum miles he have to walk
// can eat in any order ->  given calorie array  sort the array in decreasing order
// so that large number will multiply by 2^0 and second larger with 2^1 ...

int nikunjDonuts(int * arr, int n){
	sort(arr,arr+n,greater<int>());
int ans=0;
	for(int i=0;i<n;i++){
			ans+=pow(2,i)*arr[i];
	}
	return ans;
}

 







// activity selection 
// sort it according to time  and select first 
int activitySelection(int * arr,int size){

}



int main(){

// int arr[]={2,9,0,4,5};
// cout<<minAbsDiff(arr,5)<<endl;

int arr[]={1,3,2};
cout<<nikunjDonuts(arr,3)<<endl;

int n;
cin>>n;


}