// making direct class of binarysearchtree
//using binary tree node
// # include "BTreeNode.h"
#include<bits/stdc++.h>
using namespace std;
class BSTT{

	BTreeNode<int> * root;
public:
//constructor
BSTT(){
	root==NULL;
}
//destructor
~BSTT(){
	delete root;
}

//can go on left in hasdata function therefore make a private helper function 
private:
	bool hasdata(int data, BTreeNode<int>* node){
		if(node==NULL){
		return false;
	}
	if(node->data==data){
		return true;
	}
	else if(data<node->data){
		
		return hasdata(data,node->left);
	} 
	else {
		return hasdata(data,node->right);

	}
	}

public:
bool hasdata(int data){
	return hasdata(data,root);
}



private:
	BTreeNode<int> * insert(BTreeNode<int>* node,int data){
		if(node==NULL){
			BTreeNode<int> * newnode=new BTreeNode<int>(data);
			return newnode;
		}
		if(data<node->data){
			node->left= insert(node->left,data);

		}else{
			node->right=insert(node->right,data);
		}
		return node;

	}

public:
	void insert(int data){
		this->root=insert(this->root,data);
	}


private:
	BTreeNode<int> * deletetree(int data,BTreeNode<int>* node){
		if(node==NULL){
			return 	NULL;
		}
// 
//if deleting root three cases:
//1. if left null delete root and  make right root
//2. if right null
//3. if no null the either replace max of left or min or right


		if(data>node->data){
			node->right=deletetree(data,node->right);
		}else if(data<node->data){
			node->left=deletetree(data,node->left);

		}
		else{
			//deleting root
			if(node->left==NULL && node->right==NULL){
				delete node;
				return 	NULL;
			}
			else if(node->left==NULL){
				BTreeNode<int> * temp=node->right;
				node->right=NULL;
				delete node;
				return temp;

			}else if(node->right==NULL){
			BTreeNode<int> * temp=node->left;
				node->left=NULL;
				delete node;
				return temp;				
			}

			else{
				//last case
				//replacing right side minimum
				// go right then left left untill null
				BTreeNode<int> * minnode=node->right;
				while(minnode->left!=NULL){
					minnode=minnode->left;
				}
				int rightmin=minnode->data;
				node->data=rightmin;
				node->right=deletetree(rightmin,node->right);
				
					return node;

			}
	}
return node;
	}

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


public:
	void deletetree(int data){
		root=deletetree(data,root);
	}

	void print(){
print(root);
	}


};