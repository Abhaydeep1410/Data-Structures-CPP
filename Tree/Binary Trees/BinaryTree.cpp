#include<bits/stdc++.h>
using namespace std;
#include "BTreeNode.h"


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



BTreeNode<int>* takeInput() {
	cout << "enter data " << endl;
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	BTreeNode<int>* root = new BTreeNode(data);

	cout << "enter leftchild of " << data << endl;
	BTreeNode<int>* leftchild = takeInput();

	cout << "enter rightchild of " << data << endl;
	BTreeNode<int>* rightchild = takeInput();

	root->left = leftchild;
	root->right = rightchild;
	return root;
}


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



int countNodes(BTreeNode<int>* root){
	if(root==NULL){
		return 0;

	}

	//this condition not compulsory
	if(root->left==NULL && root->right==NULL){
		return 1;
	}



return 1+countNodes(root->left)+countNodes(root->right);

}



int height(BTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}

	return 1+max(height(root->left),height(root->right));

}


bool isNodePresent(BTreeNode<int>*  root,int x){
	if(root==NULL){
		return false;
	}
	if((root->data==x) ){
		return true;
	}
	bool ans1=isNodePresent(root->left,x);
	bool ans2=isNodePresent(root->right,x);
	
	if((ans1 | ans2)==true){
		return true;
	}
return false;

}

//to return mirror image of a binary tree
BTreeNode<int>* mirror_tree(BTreeNode<int>* root){

if(root==NULL){
	return root;
}

BTreeNode<int>* temp=mirror_tree(root->left);
root->left=mirror_tree(root->right);
root->right=temp;
	
return root;



}


void inorder(BTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(BTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
//similarly preorder


//generate tree from preorder and inorder

BTreeNode<int>* generateFrom_Pre_IN(int* in, int* pre,int inS,int inE,int preS ,int preE){

	if(inS>inE){
		return NULL;
	}
	int root=pre[preS];
	int rootIdx=-1;
	for(int i=inS;i<=inE;i++){
		if(in[i]==root){
			rootIdx=i;
			break;
		}
	}

	int LpreS=preS+1;
	
	
	int LinS=inS;
	int LinE=rootIdx-1;

	//left preE-left preS= left inE- left inS
	int LpreE=LinE-LinS+LpreS;


	int RpreS=LpreE+1;
	int RpreE=preE;
	int RinS=rootIdx+1;
	int RinE=inE;

	BTreeNode<int>* rootnode=new BTreeNode(root);
	rootnode->left=generateFrom_Pre_IN(in,pre,LinS,LinE,LpreS,LpreE);
	rootnode->right=generateFrom_Pre_IN(in,pre,RinS,RinE,RpreS,RpreE);
	return rootnode;
}

BTreeNode<int>* treeBuilder(int* in, int* pre,int size){
	return generateFrom_Pre_IN(in,pre,0,size-1,0,size-1);
}

// diameter if max distance between any two nodes
int diameter(BTreeNode<int> *root){
	if(root==NULL){
		return 0;

	}
	int option1=height(root->left)+height(root->right);
	int option2=diameter(root->left);
	int option3=diameter(root->right);

return max(option1,max(option2,option3));

}
//time complexity more due to option 1 

// therefore lets get diameter and height in one call, hence make a pair class



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
// BTreeNode<int>* root=new BTreeNode(2);
// BTreeNode<int>* node1=new BTreeNode(3);
// BTreeNode<int>* node2=new BTreeNode(4);

// root->left=node1;
// root->right=node2;
// delete root;

// BTreeNode<int>* r1=takeInput();

	BTreeNode<int>* r1 = takeInputLevelWise();

	print(r1);

	
	// cout<<"number of nodes in tree "<<countNodes(r1)<<endl;

	// cout<<"height of tree is "<<height(r1)<<endl;

	// cout<<(isNodePresent(r1,5)==0?"false":"true")<<endl;

	// cout<<endl;
	// BTreeNode<int>* r2=mirror_tree(r1);
	// print(r2);


// cout<<"inorder traversal"<<endl;
// 	inorder(r1);
// cout<<endl;

// cout<<"postorder traversal"<<endl;
// 	postorder(r1);




int in[]={4,2,5 ,1 ,8,6,9,3,7};
int pre[]={1,2,4,5,3,6,8,9,7};
BTreeNode<int>* r2=treeBuilder(in,pre,9);
print(r2);

delete r1;

}