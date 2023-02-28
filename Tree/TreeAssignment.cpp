#include<bits/stdc++.h>
using  namespace std;
#include "TreeNode.h"

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



//contains x
bool containsX(TreeNode<int>* root,int x){

if(root->data==x){
	return true;
}

for (int i = 0; i < root->children.size(); ++i)
{
if(containsX(root->children[i],x)==true){
	return true;
break;

}


}

return false;
}


//node with max sum of children //
//note: here chidren are nodes just below that node
// pair<TreeNode<int>* ,int> maxSumNode(TreeNode<int>* root){
// 	int ans=root->data;
// 	//suppose ans is root and now compare with other
// 	pair<TreeNode<int>* ,int> p;

// 	int sumroot=0;
// 	for(int i=0;i<root->children.size();i++){
// 		sumroot+=root->children[i]->data;
// 	}

// 	for (int i = 0; i < root->children.size(); ++i)
// 	{
// 		TreeNode<int>* node;
// 		int nodesum;
// 		node=maxSumNode(root->children[i]).first;
// 		nodesum=maxSumNode(root->children[i]).second;


// 		if()
// 	}
// return p;
// }



//checking if two trees are identical//
bool identicalTree(TreeNode<int>* tree1,TreeNode<int>* tree2){
	if(tree1->data!=tree2->data || tree1->children.size()==tree2->children.size()){
		return false;
	}

	for(int i=0,j=0;i<tree1->children.size(),j<tree2->children.size();i++,j++){
		bool x=identicalTree(tree1->children[i],tree2->children[j]);

		if(x==false ){
			return false;
		}

	}

return true;
}





int main(){


TreeNode<int>* d=takeInputLevelWise();
cout<<"enter tree2 " <<endl;
TreeNode<int>* d2=takeInputLevelWise();
cout<<(containsX(d,10)==0?"false":"true")<<endl;



cout<<(identicalTree(d,d2)==0?"false":"true")<<endl;


}