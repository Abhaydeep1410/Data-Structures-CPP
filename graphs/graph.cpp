#include<bits/stdc++.h>
using namespace std;


// minimum number of edges in graph (n-1) and max can be n(n-1)/2

//implementation

/* 1.edge list: o(n*n)
2. adjancy list : o(n)
3. adjancy matrix : easy but takes lot of space 
  (use this)
*/

void printdfs(int ** edges, int n,int sv,bool * visited){

	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv) continue;
		if(edges[sv][i]==1){
		
			if(visited[i]==false){

			printdfs(edges,n,i,visited);
		}else{
			continue;
		}
	}
	}

}


void print_bfs(int ** edges,int n, int sv,bool * visited){

	queue<int> pendingVertices;
	
	pendingVertices.push(sv);
	visited[sv]=true;

while(!pendingVertices.empty()){
	int currentvertex=pendingVertices.front();
	pendingVertices.pop();
	cout<<currentvertex<<endl;
	for(int i=0;i<n;i++){
		if(i==currentvertex) continue;
		if(edges[currentvertex][i]==1 && !visited[i]){
			pendingVertices.push(i);
			visited[i]=true;
		}
	}
}


}


void DFS(int ** edges, int n){
	    // keeping a track of already visisted vertices
bool * visited=new bool[n];
for(int i=0;i<n;i++){
	visited[i]=false;
}
// for to work with dissconnected graphs
for(int i=0;i<n;i++){
		if(visited[i]==false)
			printdfs(edges, n, i, visited);
}

delete [] visited;
}

void BFS(int ** edges, int n){
	    // keeping a track of already visisted vertices
bool * visited=new bool[n];
for(int i=0;i<n;i++){
	visited[i]=false;
}
// for to work with dissconnected graphs
for(int i=0;i<n;i++){
		if(visited[i]==false)
			print_bfs(edges, n, i, visited);
}

delete [] visited;
}



// check if there is path between start and end vertex
bool hasPathhelper(int ** edges, int sv, int ev,int n,bool * visited){


	queue<int> pendingVertices;
	
	pendingVertices.push(sv);
	visited[sv]=true;

while(!pendingVertices.empty()){
	int currentvertex=pendingVertices.front();
	pendingVertices.pop();
	if(currentvertex==ev) return true;
	for(int i=0;i<n;i++){
		if(i==currentvertex) continue;
		if(edges[currentvertex][i]==1 && !visited[i]){
			pendingVertices.push(i);
			visited[i]=true;
		}
	}
}









return false;

}
bool hasPath(int ** edges, int sv, int ev,int n){
	bool* visited= new bool[n];
	for(int i=0;i<n;i++){
	visited[i]=false;}
// can use either bfs or dfs

	if(edges[sv][ev]==1) return true;
	bool ans=hasPathhelper(edges, sv, ev,n,visited);
return ans;
}





//return path  from starting vertex to ending vertex dfs

vector<int>* getpathDFS(int ** edges,int sv,int ev,int n,bool * visited){

	if(sv==ev) {
		vector<int>*  arr=new vector<int>();
		arr->push_back(sv);
		visited[sv]=true;		
		return arr;
	}
	visited[sv]=true;
	
	for(int i=0;i<n;i++){
			if(i==sv) continue;
			if(edges[sv][i]==1 && visited[i]==false){
				vector<int>* arr=getpathDFS(edges,i,ev,n,visited);
				
				
				if(arr!=NULL){
					arr->push_back(sv);
					return arr;
				}


			}

	}
 return NULL;
}


vector<int>* getPahtBFS(int ** edges,int sv,int ev,int n,bool * visited){
if(sv==ev){
	vector<int>* arr=new vector<int>();
	arr->push_back(sv);
	visited[sv]=true;
	return arr;
}
visited[sv]=true;
queue<int> q;
q.push(sv);

// storing in map which node is pushed by which parent
unordered_map<int,int> m;

while(!q.empty()){
		int front=q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(i==front) continue;
			if(edges[front][i]==1 && visited[i]==false){
				q.push(i);
				visited[i]=true;
				m[i]=front;

				if(i==ev) break;
			}
		}


}
vector<int>* arr=new vector<int>();
int ans=ev;
arr->push_back(ans);
while(m.find(ans)!=m.end()){
	ans=m[ans];
	arr->push_back(ans);
}
return arr;
}



// is connected : find whether graph is connected or not
void isConnected(int ** edges, int sv, int n ,bool * visited){

	// do the bfs or dfs and check the visited array if any value left in it false the ans is no


	queue<int> pendingVertices;
	
	pendingVertices.push(sv);
	visited[sv]=true;

while(!pendingVertices.empty()){
	int currentvertex=pendingVertices.front();
	pendingVertices.pop();

	for(int i=0;i<n;i++){
		if(i==currentvertex) continue;
		if(edges[currentvertex][i]==1 && !visited[i]){
			pendingVertices.push(i);
			visited[i]=true;
		}
	}
}


}

bool isConnect(int ** edges, int n){
	int sv=0;
	bool * visited=new bool[n];
for(int i=0;i<n;i++){
	visited[i]=false;
}
isConnected(edges,0,n,visited);

for(int i=0;i<n;i++){
	if(visited[i]==false) return false;
}
return true;
}





// all connected components
vector<int> allConnectedComponentsHelper(int ** edges, int sv, int n ,bool * visited){
	vector<int> v;

	queue<int> pendingVertices;
	
	pendingVertices.push(sv);
	visited[sv]=true;

while(!pendingVertices.empty()){
	int currentvertex=pendingVertices.front();
	pendingVertices.pop();
		v.push_back(currentvertex);	
	for(int i=0;i<n;i++){
		if(i==currentvertex) continue;
		if(edges[currentvertex][i]==1 && !visited[i]){
			pendingVertices.push(i);
			visited[i]=true;
		}
	}
}
return v;

}


vector<vector<int>> allConnectedComponents(int ** edges,int n){
		vector<vector<int>> arr;
		bool * visited=new bool[n];
		for(int i=0;i<n;i++){
				visited[i]=false;
		}

for(int i=0;i<n;i++){
	if(visited[i]==false) {
		vector<int> v=allConnectedComponentsHelper(edges,i,n,visited);
		arr.push_back(v);
	}

}
return arr;


}


int main(){
		int n,e;
		cin>>n>>e;
		 	int ** edges= new int * [n];


		 	for (int i = 0; i < n; ++i)
		 	{
		 		edges[i]=new int [n];
		 		for (int j = 0; j < n; ++j)
		 			{
		 		edges[i][j]=0;
		 			}

		 	}
		 	// this is what we are taking input and marking in adjancy matrix as 1
		for(int i=0;i<e;i++){
			int f,s;
			cin>>f>>s;
			edges[f][s]=1;
			edges[s][f]=1;
		}

		// 	cout<<"dfs"<<endl;
		// DFS(edges, n) ;

		// cout<<endl<<"bfs"<<endl;

		// BFS(edges,n);


		// cout<< hasPath(edges,0,3,n);


bool * visited=new bool[n];
for(int i=0;i<n;i++){
	visited[i]=false;
}

// vector<int>* a=getpathDFS(edges,0,4,n,visited);

// for(int i=0;i<a->size();i++){
// 	cout<<a->at(i)<<" ";
// }
// vector<int>* a=getPahtBFS(edges,0,4,n,visited);


// for(int i=0;i<a->size();i++){
// 	cout<<a->at(i)<<" ";
// }
	

cout<<(isConnect(edges,n)==0?"false":"true")<<endl;


vector<vector<int>>  v = allConnectedComponents(edges,n);

cout<<v.size()<<endl;
for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
}






		delete [] visited;
		for(int i=0;i<n;i++){
			delete [] edges[i];
		}
		delete []edges;

 }

