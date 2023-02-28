#include<bits/stdc++.h>
using namespace std;
#include "BTreeNode.h"
#include "BinarySearchTree.h"

void print(BTreeNode<int>* root) {
	if (root == NULL) {
		return ;
	}
	cout << root->data << " : ";


	if (root->left != NULL) {
		cout << "L" << root->left->data << ",";

	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;

	}
	cout << endl;
	print(root->left);
	print(root->right);

}

BTreeNode<int>* takeInputBetter() {
	int data;
	cout << "enter data" << endl;
	cin >> data;

	if (data == -1) {
		return NULL;
	}
	BTreeNode<int>* root = new BTreeNode(data);

	queue<BTreeNode<int>*> q;
	q.push(root);

	while (q.size() != 0) {
		BTreeNode<int> * front = q.front();
		q.pop();
		int left, right;
		cout << "enter left child of " << front->data << endl;
		cin >> left;

		if (left != -1) {
			BTreeNode<int>* leftchild = new BTreeNode(left);
			q.push(leftchild);
			front->left = leftchild;
		}
		cout << "enter right child of " << front->data << endl;
		cin >> right;

		if (right != -1) {
			BTreeNode<int>* rightchild = new BTreeNode(right);
			q.push(rightchild);
			front->right = rightchild;
		}
	}
	return root;

}



int search(BTreeNode<int>* root , int data){
if(root==NULL){
	return -1;
}
if(root->data==data){
	return root->data;
}
if(root->data<data){
	return search(root->left,data);
}else{
	return search(root->right,data);
}

return -1;

}

//wrong 
// print 20 to 50  range element

void printelementofRange(BTreeNode<int>* root,int lb,int up){
	if(root==NULL){
		return;
	}
if(root->data==lb || root->data==up){
	cout<<root->data<<" ";
}


if(root->data<lb && root->data<up){
	printelementofRange(root->left,lb,up);
}
else if(root->data>lb && root->data>up){
	printelementofRange(root->right,lb,up);
}
else {
	printelementofRange(root->left,lb,root->data);
	printelementofRange(root->right,root->data,up);

}


}
 //10
// 5  12 
//1 6 11 13




//dont call recursion on subtree for check as we have to cmpare rooot with all left
// therefore find largest of left and smallest of right and compare with root 

int maximum(BTreeNode<int>* root){
	if(root==NULL){
		return INT_MIN;
	}
	return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BTreeNode<int>* root){
	if(root==NULL){
		return INT_MAX;
	}
	return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool checkbst(BTreeNode<int>* root){

if(root==NULL){
	return true;
}

int leftmax=maximum(root->left);
int rightmin=minimum(root->right);

if(root->data >leftmax && root->data <=rightmin && checkbst(root->left)==true && checkbst(root->right)==true){
	return true;
}
return false;
}
//more  time compexity nh 
// therefore make a pair or make a class and return min,max, and checkbst


class isBSTReturn{
public:
	bool isBST;
	int minimum;
	int maximum;

};
//or make a pair<bool,pair<int,int>>;

isBSTReturn isBST2(BTreeNode<int>* root){
	if(root==NULL){
		isBSTReturn output;
		output.isBST=true;
		output.maximum=INT_MIN;
		output.minimum=INT_MAX;
		return output;
	}

isBSTReturn leftans=isBST2(root->left);
isBSTReturn rightans=isBST2(root->right);

int minimum=min(root->data,min(leftans.minimum,rightans.minimum));
int maximum=max(root->data,max(leftans.maximum,rightans.maximum));

isBSTReturn output;
output.minimum=minimum;
output.maximum=maximum;
if(root->data>leftans.maximum && root->data<=rightans.minimum && leftans.isBST==true && rightans.isBST==true){
output.isBST=true;
}else{
	output.isBST=false;
}

return output;


}


bool isBST3(BTreeNode<int>* root,int minn=INT_MIN,int maxx=INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data<minn || root->data>maxx){
		return false;
	}
	bool leftans=isBST3(root->left,minn,root->data-1);
	bool rightans=isBST3(root->right,root->data,maxx);
	return leftans && rightans;
}



//construct bst from sorted array
BTreeNode<int> * constructbst_array(int arr[],int low,int high){
if(low<=high){
int mid=(low+high)/2;
BTreeNode<int>* root=new BTreeNode(arr[mid]);

root->left=constructbst_array(arr,low,mid-1);
root->right=constructbst_array(arr,mid+1,high);
return root;

}
return NULL;
}


void preorder(BTreeNode<int>* root){
	if(root==NULL){
		return;
	}

cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);

}


// return path to a node given in binary tree
vector<int>* pathtonode(BTreeNode<int>* root,int data){
	if(root==NULL){
		return NULL;
	}
	if(root->data==data){
vector<int>* v=new vector<int>();
v->push_back(root->data);
return v;
	}

	vector<int>* leftoutput=pathtonode(root->left,data);
	if(leftoutput!=NULL){
		leftoutput->push_back(root->data);
		return leftoutput;
	}
vector<int>* rightoutput=pathtonode(root->right,data);
	if(rightoutput!=NULL){
		rightoutput->push_back(root->data);
		return rightoutput;
	}

return NULL;
}



int main(){

BTreeNode<int>* root=takeInputBetter();
// cout<<search(root,22)<<endl;
// cout<<checkbst(root)<<endl;

// isBSTReturn output=isBST2(root);
// cout<<output.isBST<<endl;

cout<<isBST3(root)<<endl;
// int arr[]={1,2,3,4,5,6,7};
// BTreeNode<int> * root2=constructbst_array(arr,0,6);
// preorder(root2);

// vector<int> * v=pathtonode(root,8);
// for(int i=0;i<v->size();i++){
// 	cout<<v->at(i)<<" ";
// }
// delete v;


// BSTT b;
// b.insert(10);
// b.insert(5);
// b.insert(20);
// b.insert(7);
// b.insert(3);
// b.insert(15);
// b.deletetree(10);
// b.deletetree(100);
// b.print();


}


