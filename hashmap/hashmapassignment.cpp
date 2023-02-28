#include<bits/stdc++.h>
using namespace std;

string extractUniqueCharacters(string s){
map<char,int> m;
string s2="";
for(auto i:s){
	m[i]++;
}
for(auto i:m){
	s2+=i.first;
}

return s2;
}


//longest consecutive subsequence





//pairs with sum k
int pairsumk(int * arr,int size,int k){
int ans=0;

unordered_map<int,int> m;

for(int i=0;i<size;i++){

	if(m.find(k-arr[i]) !=m.end()){
		ans=ans+m[k-arr[i]];
	}
	m[arr[i]]++;

}

return ans;


}


//length of longest subset sum 0
int longestSubsetSum0(int * arr, int size){

unordered_map<int,int> m;
int sum=0;
int ans=0;
for (int i = 0; i < size; ++i)
{	
	sum=sum+arr[i];
	if(m.find(sum) ==m.end()){
		ans=max(i,ans);
	}
	else if(sum==0){
		ans=max(i,ans);
	}

	m[sum]=i;


}
return ans;
}



int main(){
cout<<extractUniqueCharacters("abcdabc")<<endl;

int arr[]={1,2,3,-6,5,9};
// int arr[]={6,1,5,-8,-4,2};
cout<<pairsumk(arr,7,3)<<endl;


cout<<longestSubsetSum0(arr,6)<<endl;
}