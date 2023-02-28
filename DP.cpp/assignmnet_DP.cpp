# include<bits/stdc++.h>
using namespace std;

int numberOfChocolates(int * a, int size){
	int * arr = new int[size];

	 arr[0]=1;
	 

	for (int i =1; i <size; ++i)
	{
		if(a[i]>a[i-1]){
			arr[i]=arr[i-1]+1;
	}
	else{
		arr[i]=1;
		
	}
	}
// traversing in reverse to check the condition again
for (int i = size-2; i >= 0; --i)
	{
		if(a[i]>a[i+1]){
			arr[i]=arr[i+1]+1;
	}
	else{
		continue;
		
	}
	}
	int sum=0;
	for(int i=0;i<size;i++){
		sum+=arr[i];

		
	}

return sum;
}


// maximum size of square matrix with all zeros
int maxSizeMatrix0(int **arr,int n,int m){
	int** a = new int *[n ];
for(int i=0;i<n;i++){
	a[i]=new int[m];
}
// we have to find max size of matrix ending at (i,j) with all zeros

// put 0 if 1 occurs and 1 if 0 comes on 0th row and coloumn
for(int i=0;i<n;i++){
	if(arr[i][0]==0) a[i][0]=1;
	else a[i][0]=0;

}
for(int i=0;i<m;i++){
	if(arr[0][i]==0) a[0][i]=1;
	else a[0][i]=0;
	
}

for(int i=1;i<n;i++){
	for(int j=1;j<m;j++){
		if(arr[i][j]==1) { a[i][j]=0; }
		else{
				a[i][j]=min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]))+1;
		}
	}
}	

//now finding max in array
int mx=0;
for (int i = 0; i < n; ++i)
{
for (int j = 0; j < m; ++j)
{
	if(a[i][j]>mx) mx=a[i][j];
}
}
delete arr;
return mx;

}

// max amount of money thief can loot , cant loot two consecutive houses//

int loothouse(int * a, int n){

int * arr=new int[n];
arr[0]=a[0];
arr[1]=max(a[0],a[1]);
for(int i=2;i<n;i++){
	arr[i]=max(a[i]+arr[i-2],arr[i-1]);
}

return max(arr[n-1],arr[n-2]);

}

// minimum number of  ways a number  can be represented as sum of squares
// ex. 12 - 2*2 +2*2 +2*2   ans=3
int minCount( int n){
// explanation by pepcoding 

/* agar 11 ka chaiye to pehle usme se 1*1 minus karo 10 aaya matlab 
10th index pe jana padega and plus 1 karna padega = 2+1=3
=> fir usme se 2*2 minus karo  7 bacha 7th index pe jao and plus 1 =4 
=> fir usme se 3*3 minus karo 2 bacha plus 1=3 
> fir teeno ka min return kar skte 
*/

int * arr=new int[n+1];
if(n<=3) return n;
arr[0]=0;
arr[1]=1;

for(int i=2;i<=n;i++){
	int minn=INT_MAX;
	for(int j=1;j*j<=i;j++){
		minn=min(minn, arr[i-j*j]+1);
	
	}
	arr[i]=minn;
}
return arr[n];
}


// boredom: max points we can get  if choose number x then cant choose x-1 and x-2;
int boredom(int * a, int n){



int maxelement=0;
for(int i=0;i<n;i++){
	maxelement=max(maxelement,a[i]);
}
// making frequency array upto max element only
int freq[maxelement+1]={0};
//calculating frequency of number as we will get freq* number points if we choose
for(int i=0;i<n;i++){
	 freq[a[i]]++;
}
int * arr=new int[maxelement+1];
arr[0]=0;
arr[1]= freq[1];
for (int i = 2; i <=maxelement; ++i)
{
	arr[i]= max(arr[i-2]+ freq[i]*i, arr[i-1]);

}



int mx=0;
for(int i=0;i<=maxelement;i++){
	
	mx=max(mx,arr[i]);
}

return mx;
}


// find number of bsts in the range 
// pepcoding (youtube)
int numberOfBST(int n){
  int * arr =new int[n+1];
arr[0]=1;
arr[1]=1;

for (int i = 2; i <= n; ++i)
{	
    arr[i]=0;
	int k=1;
	while(k<=i){
			arr[i]+=arr[k-1]*arr[i-k];
        k++;
	}


}

return arr[n];




}


//find how many ways a int array can represent as codes of letter
 // ex  23  can be bc or w
int alphacode(int * a , int size){

int * arr= new int[size+1];
arr[0]=1;
arr[1]=1;

for(int i=2;i<=size;i++){
	arr[i]=arr[i-1];

	if(a[i-2]*10 + a[i-1]<=26){
		arr[i]+=arr[i-2];
	}

}
return arr[size];

}



int main(){
	// int arr[]={1,4,4,6};
	// cout<<numberOfChocolates(arr,4)<<endl;

// int n=4,m=4;
// 	int ** arr=new int* [n];
// 	for(int i=0;i<n;i++){
// 		arr[i]=new int[m];
// 	}

// for (int i = 0; i < n; ++i)
// {
// 	for(int j=0;j<m;j++){
// 		cin>>arr[i][j];
// 	}
// }
	// cout<<maxSizeMatrix0(arr,3,3);	

int arr[]={10,2,30,20,3,50};

// cout<<loothouse(arr,6)<<endl;

// cout<<minCount(12)<<endl;

// int a[]={1 ,1, 2 ,2 ,2 ,3 ,3};
// cout<<boredom(a,7)<<endl;

// cout<<numberOfBST(4)<<endl;

// int a2[]={2,1,3};
// cout<<alphacode(a2,3)<<endl;

}