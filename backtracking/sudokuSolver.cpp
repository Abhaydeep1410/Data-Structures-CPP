#include <bits/stdc++.h>
using namespace std;
#define N 9


bool isSafeRow(int matrix[N][N],int row,int num){
	for(int i=0;i<N;i++){
		if(matrix[row][i]==num){
			return false;
		}
	}
	return true;
}


bool isSafeCol(int matrix[N][N],int col,int num){
	for(int i=0;i<N;i++){
		if(matrix[i][col]==num){
			return false;
		}
	}
	return true;
}

bool isSafeGrid(int matrix[N][N],int row,int col,int num){

	int rowfactor=row-(row%3);
	int colfactor=col-(col%3);

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		if(matrix[i+rowfactor][j+colfactor]==num){
			return false;
		}
	}
	}
	return true;
}

bool isSafe(int matrix[N][N],int row,int col,int num){
	if(isSafeRow(matrix,row,num) && isSafeCol(matrix,col,num) && isSafeGrid(matrix,row,col,num)){
		return true;
	}
	return false;
}




bool findEmptyLoc(int matrix[N][N],int & row, int & col){
// use & so that row and col will be updated also
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(matrix[i][j]==0){
				row=i;
				col=j;

				return true;
			}
		}
	}
return false;

}



bool sudokuSolver(int matrix[N][N]){

	int row,col;

	if(!findEmptyLoc(matrix,row,col)){
		return true;
	}

for(int i=1;i<=N;i++){

	if(isSafe(matrix,row,col,i)){
			matrix[row][col]=i;
			if(sudokuSolver(matrix))   return true;
			//if not able to put this value
			matrix[row][col]=0;
	}


}

return false; 
}




int main(){

	int matrix[N][N];
	for(int i=0;i<N;i++){
		
		for(int j=0;j<N;j++){
			cin>>matrix[i][j];
		}
	}


	sudokuSolver(matrix);


	for (int i = 0; i < N; ++i)
	{
		for(int j=0;j<N;j++){
			cout<<matrix[i][j];
		}
		cout<<endl;
	}


}