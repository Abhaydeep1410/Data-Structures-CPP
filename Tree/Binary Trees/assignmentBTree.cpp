#include<bits/stdc++.h>
using namespace std;
#include "BTreeNode.h"


void print(BTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";

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


BTreeNode<int>* removeLeafNodes(BTreeNode<int>* root){
	if(root->left==NULL && root->right==NULL){
		return NULL;
	}
	if(root->left!=NULL){
	root->left=removeLeafNodes(root->left);}
	if(root->right!=NULL){
	root->right=removeLeafNodes(root->right);}
	return root;

}


int height(BTreeNode<int> * root){
	if (root == NULL) {
		return 0;
	}
	
	int heightans =0;
	heightans=1+max(height(root->left),height(root->right));

	return heightans;
}


//check balanced binary tree 
//condition:  leftheight -rightheight <=1

bool balancedTree(BTreeNode<int> * root){
if(root->left==NULL && root->right==NULL){
	return true;
}

if(height(root->left) - height(root->right)>1){
	return false;
}

bool ans1=balancedTree(root->left);
bool ans2=balancedTree(root->right);
if(ans1 & ans2 ==false){
	return false;
}
return true;
// n* height time complexity 

}
//more time complexity


pair<int,bool> balancedTreeBetter(BTreeNode<int> * root){
	if(root==NULL){
				pair<int,bool> p;
				p.first=0;
				p.second=true;
				return p;
		}


pair<int,bool> leftans=balancedTreeBetter(root->left);
pair<int,bool> rightans=balancedTreeBetter(root->right);


int leftheight=leftans.first;
int height=1+max(leftans.first,rightans.first);

pair<int,bool> p;
if(leftans.first- rightans.first <=1){
	p.second=true;
}else{
	p.second=false;
}

p.first=height;

return p;




}







int main(){

BTreeNode<int> * root=takeInputBetter();



root=removeLeafNodes(root);
// print(root);
levelorderTraversal(root);
// print(root);
// cout<<balancedTree(root)<<endl;

// pair<int,bool> p=balancedTreeBetter(root);
// cout<<p.second<<endl;



}