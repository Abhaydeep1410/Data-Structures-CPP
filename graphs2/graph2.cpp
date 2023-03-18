#include<bits/stdc++.h>
using namespace std;


/* cycle detection using union find algorithm in which we maintain a parent array and initially
make the  all the parent to itself and update the highest parents accordingly , if parents are equal 
for souce and destination then it will be cycle*/

	class Edge{
	public:
			int source;
			int destination;
			int weight;
	};


bool compare(Edge e1,Edge e2){
	return e1.weight<e2.weight;
}

 int findParent(int v,int * parent){
	if(parent[v]==v){
		return v;
	}
	return findParent(parent[v],parent);
}

// to find the minimum spanning tree
void kruskal(Edge * input, int n,int E){
		sort(input,input+E,compare);
		
		// since mst will contain n-1 nodes
		Edge * output=new Edge[n-1];


		// for union find (to detect cycles)
		int *parent =new int[n];
		for(int i=0;i<n;i++){
			parent[i]=i;
		}

		int count=0;  // for nodes
		int i=0; // for egdes

		while(count!=n-1){

		Edge currentedge=input[i];
		// check if we can add currentedge in mst or not
		int sourceparent=findParent(currentedge.source,parent);
		int destparent=findParent(currentedge.destination,parent);
		if(sourceparent!=destparent){
			output[count]=currentedge;
			count++;
			//updating the new parent 
			parent[sourceparent]=destparent;

		}
		i++;

		}


		//print
		for(int i=0;i<n-1;i++){
			// to print in sorted order optional
			if(output[i].source<output[i].destination) cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
			else  cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
		}


		}



int main(){

int n,E;
cin>>n>>E;
// n is number of nodes and E is number of edges
Edge * input =new Edge[E];

for(int i=0;i<E;i++){
	int s,d,w;
	cin>>s>>d>>w;
	input[i].source=s;
	input[i].destination=d;
	input[i].weight=w;
}
kruskal(input,n,E);


}