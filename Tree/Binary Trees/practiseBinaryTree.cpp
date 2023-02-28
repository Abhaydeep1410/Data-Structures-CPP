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

BTreeNode<int>* takeInput() {

	int data;
	cout << "enter data" << endl;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	BTreeNode<int>* root = new BTreeNode(data);
	cout << "enter left child of " << data << endl;

	BTreeNode<int>* left = takeInput();
	cout << "enter right child of " << data << endl;
	BTreeNode<int>* right = takeInput();


	root->left = left;
	root->right = right;

	return root;


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


int countNodes(BTreeNode<int> * root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	int nodes = 1;
	nodes = nodes + countNodes(root->left) + countNodes(root->right);

	return nodes;
}



int height(BTreeNode<int> * root){
	if (root == NULL) {
		return 0;
	}
	
	int heightans =0;
	heightans=1+max(height(root->left),height(root->right));

	return heightans;
}


bool isNodePresent(BTreeNode<int> * root,int x){
	if(root==NULL){
		return false;
	}
	if(root->data==x){
		return true;
	}
	bool ans=false;
	ans=ans| isNodePresent(root->left,x) | isNodePresent(root->right,x);
	return ans;
}



int sumofNodes(BTreeNode<int>* root){
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	return root->data+sumofNodes(root->left)+sumofNodes(root->right);

}

int diameter(BTreeNode<int> *root){
	if(root==NULL){
		return 0;

	}
	int option1=height(root->left)+height(root->right);
	int option2=diameter(root->left);
	int option3=diameter(root->right);

return max(option1,max(option2,option3));

}

pair<int,int> betterDiameter(BTreeNode<int> * root){
	if(root==NULL){
		pair<int ,int > p;
		p.first=0;
		p.second=0;
		return p;
	}

	pair<int,int> leftans=betterDiameter(root->left);
	pair<int,int> rightans=betterDiameter(root->right);

	int ld=leftans.second;
	int lh=leftans.first;
	int rd=rightans.second;
	int rh=rightans.first;
	

	int height=1+max(lh,rh);
	int diameter=max(lh+rh , max(ld,rd));
	pair<int,int> p;
	p.first=height;
	p.second=diameter;
	return p;


}

pair<int,int> MinMax(BTreeNode<int>* root){

	if(root->left==NULL && root->right==NULL){
		pair<int,int> p;
		p.first=root->data;
		p.second=root->data;
		return p;
	}

	pair<int,int> leftans=MinMax(root->left);
	pair<int,int> rightans=MinMax(root->right);
pair<int,int> p;
	int minn=min(root->data,min(leftans.first,rightans.first));
	int maxn=max(root->data,max(leftans.second,rightans.second));
	p.first=minn;
	p.second=maxn;

return p;

}




int main() {


	BTreeNode<int>* root = takeInputBetter();
	print(root);


	cout << "number of nodes in the tree are " << countNodes(root) << endl;
	cout << "height of the tree is " << height(root) << endl;

	cout<<isNodePresent(root,6)<<endl;

	cout<<"sum of nodes "<<sumofNodes(root)<<endl;


	pair<int,int> p=betterDiameter(root);
cout<<p.second<<endl;

pair<int,int> pq=MinMax(root);
cout<<"min is "<<pq.first<<"  max is "<<pq.second<<endl;


}