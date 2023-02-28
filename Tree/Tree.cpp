#include<bits/stdc++.h>
using namespace std;

#include "TreeNode.h"


void print(TreeNode<int>* t) {
	cout << t->data << ":";
	for (int i = 0; i < t->children.size(); i++) {
		cout << t->children[i]->data << ",";
	}
	cout << endl;

	for (int i = 0; i < t->children.size(); i++) {
		print(t->children[i]);
	}
}


TreeNode<int>* takeInput() {
	int data;
	cout << "enter data" << endl;
	cin >> data;
	TreeNode<int>* root = new TreeNode(data);

	cout << "enter number of children of " << data << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}



	return root;

}







TreeNode<int>* takeInputLevelWise() {
//make a queue , enter root in queue , pop element and push its children in queue and now pop other till queue became empty
	int data;
	cout << "enter data" << endl;
	cin >> data;
	TreeNode<int>* root = new TreeNode(data);
	queue<TreeNode<int>*> q;
	q.push(root); //poora node daalo queue main so that we can make pointer also

	while (q.size() != 0) {
		TreeNode<int>* front = q.front();
		q.pop();


		cout << "enter number of children of " << front->data << endl;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int childdata;
			cin >> childdata;
			TreeNode<int>* child = new TreeNode(childdata);
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
	int height=0;
	for(int i=0;i<root->children.size();i++){
		height=max(heighttree(root->children[i]),height);
	}
	return height+1;
}





//number of nodes
//recursion se bol do height laake de de sbki
int number_of_nodes(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int nodes = 1;
	for (int i = 0; i < root->children.size(); i++) {
		nodes += number_of_nodes(root->children[i]);
	}
	return nodes;
}


//print all nodes at depth d or level d


void printAtDepth(TreeNode<int>* root, int  level) {

	if (root == NULL) {
		return ;
	}
	if (level == 0) {

		cout << root->data << endl;
	}

	for (int i = 0; i < root->children.size(); i++) {
		printAtDepth(root->children[i], level - 1);
	}



}



//count number of leaf nodes//
int number_of_leaf(TreeNode<int>* root){
	if(root->children.size()==0){
		return 1;
	}

	int ans=0;
	for (int i=0;i<root->children.size();i++){
		ans=ans+number_of_leaf(root->children[i]);
	}

	return ans;
}


//Tree Traversal//
void preorder(TreeNode<int>* root){

if(root==NULL){
	return ;
}

	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++){
		preorder(root->children[i]);
	}
}


// void inorder(TreeNode<int>* root){

// if(root==NULL){
// 	return ;
// }

// 	for(int i=0;i<root->children.size();i++){
// 		preorder(root->children[i]);
// 	}
// }

void postorder(TreeNode<int>* root){

if(root==NULL){
	return ;
}

	
	for(int i=0;i<root->children.size();i++){
		postorder(root->children[i]);
	}
	cout<<root->data<<" ";
}

//we dont have to diretly delte root node//
void deleteTree(TreeNode<int>* root){
	for(int i=0;i<root->children.size();i++){
		deleteTree(root->children[i]);
	}
	delete root;
}






int main() {
	TreeNode<int>* root = new TreeNode(4);
	TreeNode<int>* node1 = new TreeNode(5);
	TreeNode<int>* node2 = new TreeNode(6);

	root->children.push_back(node1);
	root->children.push_back(node2);

	TreeNode<int>* d = takeInputLevelWise();
	print(d);

	cout << "\nheight of tree is " << heighttree(d) << endl;


	// cout << "number of nodes in tree are " << number_of_nodes(d) << endl;

// 	cout << "elements at depth 2 are " << endl;
// 	printAtDepth(d, 2);


// 	cout<<"number of leaf node in the tree "<<number_of_leaf(d)<<endl;


// postorder(d);
// deleteTree(d);

}