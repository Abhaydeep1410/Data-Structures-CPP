#include<bits/stdc++.h>
using namespace std;

vector<int> removeduplicates(int * a,int size){

vector<int> v;
unordered_map<int,int> m;
for(int i=0;i<size;i++){
	if(m.count(a[i])>0){
 continue;
	}
	m[a[i]]++;
	v.push_back(a[i]);
}

return v;
}

int maxfrequencynumber(int* a, int size){
	unordered_map<int,int> m;
for(int i=0;i<size;i++){
	m[a[i]]++;
}
int max=0;
int ans=0;
for (auto i: m){
	if(i.second>max){
			max=i.second;
			ans=i.first;
	}

}
return ans;
}


vector<int> arrayIntersection(int* arr,int * arr2,int size1,int size2){
vector<int> v;
unordered_map<int,int> m;
for (int i = 0; i < size1; ++i)
{	
	m[arr[i]]++;
}
for (int i = 0; i < size2; ++i)
{
	if(m.count(arr2[i])>0){

		v.push_back(arr2[i]);

		m[arr2[i]]--;


	}
}
return v;


}


int pairsum0(int * arr,int size){
unordered_map<int,int> m;

int ans=0;
	for (int i = 0; i < size; ++i)
	{
		if(m.count(m[-1*arr[i]]>0)){
			ans=ans+m[-1*arr[i]];

		}
		m[arr[i]]++;
	}



return ans;

}



int main(){

// unordered_map<string,int> m;



// m["abhay"]=1;

// cout<<m["abhay"]<<endl;
// cout<<m.at("abhay")<<endl;


// // cout<<m.at("abh")<<endl;
// //gives exception
// // cout<<m["ab"]<<endl;
// //automaticallly add ab and 0 in map
// //therefore we use
// if(m.count("ab")>0){
// 	cout<<m["ab"] <<endl;
// 	//or
// 	cout<<m.at("ab")<<endl;
// }


// //erase
// m.erase("abhay");
// cout<<m.size()<<endl;
int a[]={1,2,3,3,2,1,2,4,5,6};
// vector<int> arr=removeduplicates(a,10);
// for(auto i: arr){
// 	cout<<i<<" ";
// }

// cout<<maxfrequencynumber(a,10)<<endl;

// int arr[]={2,6,1,2};
// int arr2[]={1,2,3,4,2};
// vector<int> ans=arrayIntersection(arr,arr2,4,5);
// for(auto i: ans){
// 	cout<< i<<" ";
// }

int arr3[]={2,2,1,2,3,-2};
cout<<pairsum0(arr3,6)<<endl;


}