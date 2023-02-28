#include <bits/stdc++.h>
using namespace std;

void print(int ** solution, int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<solution[i][j]<<" ";
		}
		cout<<endl;
	}
}
void mazehelper(int maze[][20],int n,int** solution ,int x,int y){

	if(x==n-1 && y==n-1){
		solution[x][y]=1;
		print(solution,n);
		return;
	}
	if(x>=n || x<0 ||y>=n||y<0||solution[x][y]==1 || maze[x][y]==0){
		return;
	}
	solution[x][y]=1;
	mazehelper(maze,n,solution,x-1,y);
	mazehelper(maze,n,solution,x+1,y);
	mazehelper(maze,n,solution,x,y-1);
	mazehelper(maze,n,solution,x,y+1);
	solution[x][y]=0;

	
}



void ratInMaze(int maze[][20] ,int n){

	int ** solution=new int*[n];
	for (int i = 0; i < n; ++i)
	{
		solution[i]=new int[n];
	}
	mazehelper(maze,n,solution,0,0);
}


int main(){
	int n=3;
	int maze[n][20];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>maze[i][j];
		}
	}

ratInMaze(maze,3);




}