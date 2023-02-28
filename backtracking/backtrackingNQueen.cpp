#include <bits/stdc++.h>
using namespace std;

int board[10][10]={0};

void print(int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}

}



bool placeQueen(int n,int i,int j){

	

	//upper col
	for(int k=i-1;k>=0;k--){
		if(board[k][j]==1) return false;
	}

	//upper left diagonal 
	for(int l=i-1,p=j-1;l>=0 && p>=0;l--,p--){
		if(board[l][p]==1) return false;
	}
	//upper right diagonal
	for(int l=i-1,p=j+1;l>=0 && p<=n;l--,p++){
		if(board[l][p]==1) return false;
	}
	// if(i==n-1 && j==n-1){
	// 	print(n);
	// }
	return true;

}

void NQueenHelper(int n,int row){

if(row==n) {
print(n);
cout<<endl;
return;
}
for(int j=0;j<n;j++){
	if(placeQueen(n,row,j)==true){
		board[row][j]=1;
		NQueenHelper(n,row+1);
		board[row][j]=0;
	}
}
return;

}

int main(){

	NQueenHelper(4,0);

}