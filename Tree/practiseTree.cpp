# include<bits/stdc++.h>
using namespace std;
# include "TreeNode.h"



void print(TreeNode<int> * root){
	if(root==NULL){
		return;
	}
	
	cout<<root->data<<":";
for(int i=0;i<root->children.size();i++){

	cout<<root->children[i]->data<<",";
}
cout<<endl;
	for(int i=0;i<root->children.size();i++){
		print(root->children[i]);

	}


}

TreeNode<int>* takeInput(){
	int n,data;
	cout<<"enter data"<<endl;
	cin>>data;
	TreeNode<int>* root=new TreeNode(data);
	cout<<"enter number of children of "<<data<<endl;
	cin>>n;


for(int i=0;i<n;i++){
	TreeNode<int> * child=takeInput();
	root->children.push_back(child);

}
return root;
}



TreeNode<int>* takeInputBetter(){
	queue<TreeNode<int>*> q;
	int n, data;
	cout<<"enter data"<<":"<<endl;
	cin>> data;
	
	TreeNode<int>* root=new TreeNode(data);
	q.push(root);

	while(q.size()!=0){
		TreeNode<int>*  front=q.front();
		q.pop();
		cout<<"enter number of children of "<<front->data<<endl;
	cin>>n;

		for(int i=0;i<n;i++){
			int childdata;
cin>>childdata;
			TreeNode<int>* child=new TreeNode(childdata);
			q.push(child);
			front->children.push_back(child);
		}

	}


return root;

}


int heighttree(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	if(root->children.size()==0){
		return 1;
	}
int height=0;
for (int i = 0; i < root->children.size(); ++i)
{
	height=max(heighttree(root->children[i]),height);
}
return height+1;


}



int number_of_nodes(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	if(root->children.size()==0){
		return 1;
	}
	int nodes=0;
	for (int i = 0; i < root->children.size(); i++)
	{
		nodes+=number_of_nodes(root->children[i]);
	}
	return nodes+1;
}

void printatlevel(TreeNode<int>* root,int level){
	if(root==NULL){
		return;
	}
	if(level==1){
		cout<<root->data<<",";
	}
	for(int i=0;i<root->children.size();i++){
		printatlevel(root->children[i],level-1);
	}


}


int number_of_leaf(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}

	if(root->children.size()==0){
		return 1;
	}
	int leaf=0;
for (int i = 0; i < root->children.size(); ++i)
{
	leaf=leaf+number_of_leaf(root->children[i]);
}
return leaf;
}


bool containsX(TreeNode<int>* root,int x){
	if(root->data==x){
		return true;
	}
bool ans=false;
	for (int i = 0; i < root->children.size(); ++i)
	{
	  if(containsX(root->children[i],x)==true){
	  	return true;
	  	break;
	  }

	}
	return ans;

}


TreeNode<int>* maxSumNode(TreeNode<int>* root){
	if(root==NULL){
		return;
	}
}


int main(){
TreeNode<int>* root=takeInputBetter();

print(root);

cout<<"height is "<<heighttree(root)<<endl;

cout<<"number of nodes in tree is "<<number_of_nodes(root)<<endl;

printatlevel(root,2);

cout<<endl<<"number of leaves in the tree are "<< number_of_leaf(root)<<endl;

cout<<containsX(root,2)<<endl;
}