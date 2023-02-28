#include<bits/stdc++.h>
template<typename T>
class BTreeNode{
public:
	T data;
BTreeNode* left;
BTreeNode* right;



BTreeNode(T data){
this->data=data;
left=NULL;
right=NULL;
}


~BTreeNode(){
	delete left;
	delete right;
}
};