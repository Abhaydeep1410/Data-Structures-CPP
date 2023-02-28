#include "BTreeNode.h"
#include "BinarySearchTree.h"
#include <bits/stdc++.h>
using namespace std;


BTreeNode<int>* takeInputLevelWise() {

	cout << "enter data " << endl;
	int data;
	cin >> data;

	BTreeNode<int>* root = new BTreeNode(data);
	if (root->data == -1) {
		return NULL;
	}
	queue<BTreeNode<int>*> q;
	q.push(root);

	while (!q.empty()) {
		BTreeNode<int>* x = q.front();
		q.pop();

		cout << "enter left child of " << x->data << endl;
		int left;
		cin >> left;
		if (left != -1) {
			BTreeNode<int>* leftchild = new BTreeNode(left);
			q.push(leftchild);
			x->left = leftchild;


		}

		cout << "enter right child of " << x->data << endl;
		int right;
		cin >> right;
		if (right != -1) {
			BTreeNode<int>* rightchild = new BTreeNode(right);
			q.push(rightchild);
			x->right = rightchild;


		}
	}
	return root;

}

void levelorderTraversal(BTreeNode<int>* root){

	if(root==NULL){
		return;
	}
queue<BTreeNode<int>*> q;

q.push(root);
q.push(NULL);

while(q.size()!=0){
BTreeNode<int>* front=q.front();
q.pop();


if(front!=NULL){
	cout<<front->data<<" ";
	if(front->left !=NULL){q.push(front->left);}
	if(front->right!=NULL){q.push(front->right);}
	
}else{
	if(q.size()==0){
	break;
}
	cout<<endl;
	q.push(NULL);
}


}


}


 BTreeNode<int> * insertDuplicate(BTreeNode<int>* root){
 	if(root==NULL){
 		return NULL;

 	}
 	BTreeNode<int>* newnode=new BTreeNode(root->data);

 	BTreeNode<int>* leftans=insertDuplicate(root->left);
 	BTreeNode<int>* rightans=insertDuplicate(root->right);

 	
 	
 	root->left=newnode;
 	root->right=rightans;
 	newnode->left=leftans;

 	
 	return root;



 }

//better approach convert the tree into array and sort it and use two
 // use two pointers and check if pair sum is equal
vector<int>* pairSumBinaryTreeHelper(BTreeNode<int>* root){
	if(root==NULL){
		return NULL;
	}

vector<int>* arr=new vector<int>();
arr->push_back(root->data);

if(root->left!=NULL){
vector<int>* left=pairSumBinaryTreeHelper(root->left);
for (int i = 0; i < left->size(); ++i)
{
	arr->push_back(left->at(i));
}


}

if(root->right!=NULL){
vector<int>* right=pairSumBinaryTreeHelper(root->right);

for (int i = 0; i < right->size(); ++i)
{
	arr->push_back(right->at(i));
}


}
return arr;
}


void pairSumBinaryTree(BTreeNode<int> * root,int sum){
	vector<int>* v=pairSumBinaryTreeHelper(root);

	sort(v->begin(),v->end());
	int arr[v->size()];
	for(int i=0;i<v->size();i++){
		arr[i]=v->at(i);
	}
int size=v->size();
	delete v;


	int i=0,j=size;
while(i<=j){

	if(arr[i]+arr[j]==sum){
		cout<<arr[i]<<" "<<arr[j]<<endl;
		i++;
		j--;
	}else if(arr[i]+arr[j]<sum){
		i++;
	}else{
		j--;
	}
}
}

//find lca lowest common ancestor
BTreeNode<int>* ancestor(BTreeNode<int>* root,int n1,int n2){
if(root==NULL){
	return NULL;
}
if(root->data==n1 || root->data==n2){
	return root;
}

BTreeNode<int>* ans1=ancestor(root->left,n1,n2);
BTreeNode<int>* ans2=ancestor(root->right,n1,n2);

if(ans1==NULL && ans2 !=NULL){
	return ans2;
}
else if(ans2==NULL && ans1!=NULL){
	return ans1;
} else if(ans1==NULL && ans2 ==NULL){
	return NULL;
}
else{

	//when both are not null
	return root;
}


}




//largest bst subtree in a  binary tree
// to calculate we will return 4 values min,max,isbst, height
///   wrong//////
pair<pair<int,int>, pair<bool,int>> largestbst(BTreeNode<int>* root,int minn=INT_MIN,int maxx=INT_MAX){
	if(root==NULL){
		pair<pair<int,int>, pair<bool,int>> p;
		p.first.first=minn;
		p.first.second=maxx;
		p.second.first=true;
		p.second.second=0;
		return p;
	}
	if(root->data<minn || root->data>maxx){
		pair<pair<int,int>, pair<bool,int>> p;
		p.first.first=minn;
		p.first.second=maxx;
		p.second.first=false;
		p.second.second=0;
		return p;	
	}
	 	pair<pair<int,int>, pair<bool,int>> leftans=largestbst(root->left,minn,root->data-1);
		pair<pair<int,int>, pair<bool,int>> rightans=largestbst(root->right,root->data,maxx);
	
		pair<pair<int,int>, pair<bool,int>> ans;
if(root->data>leftans.first.second && root->data<=rightans.first.first && leftans.second.first && rightans.second.first ){
		ans.first.first=leftans.first.first;
		ans.first.second=rightans.first.second;
		ans.second.first= leftans.second.first && rightans.second.first;
		ans.second.second=1+max(leftans.second.second,rightans.second.second);
		return ans;
}
else if(leftans.second.second>rightans.second.second) {
return leftans;
}else{
	return rightans;
}

}






int main(){
BTreeNode<int> * root=takeInputLevelWise();
// root=insertDuplicate(root);
// levelorderTraversal(root);

// pairSumBinaryTree(root,50);
// BTreeNode<int>* ans=ancestor(root,60,30);
// cout<<ans->data<<endl;



pair<pair<int,int>, pair<bool,int>> p=largestbst(root);
cout<<p.second.second;

}