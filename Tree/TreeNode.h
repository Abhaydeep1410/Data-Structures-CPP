#include<bits/stdc++.h>
template<typename T>
class TreeNode{
public:
T data;
vector<TreeNode<T>*> children;

TreeNode(T data){
	this->data=data;
}



//to dele te the tree automatically so that we dont have to call any another function
~TreeNode(){
	for(int i=0;i<children.size();i++){
		delete children[i];
	}
}

};
