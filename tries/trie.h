#include "trieNode.h"

class Trie{
TrieNode * root;

public:


	Trie(){
		root=new TrieNode('\0');

	}
private:
void insertWord(TrieNode* root,string word){
	//base case
	if(word.size()==0){
		root->isTerminal=true;
		return ;
	}
	// small calculation
	int index=word[0]-'a';
	TrieNode * child;
if(root->children[index]!=NULL){
	// means a node is present with starting character
child=root->children[index];
}else{
// means no node is present therfore make a new node
	child=new TrieNode(word[0]);
	root->children[index]=child;
}

//recursive call
insertWord(child,word.substr(1));

}
public:
void insertWord(string word){
	insertWord(root,word);
}

private:
bool search(TrieNode * root, string word){
	if(word.size()==0){
		return root->isTerminal;

	}
// small calculation
	int index=word[0]-'a';
	TrieNode * child;
if(root->children[index]!=NULL){
child=root->children[index];
}else{
return false;}

return search(child,word.substr(1));

}
public:
bool search(string word){
	return search(root, word);
}





private:
void remove(TrieNode* root, string word){
	if(word.size()==0){
		root->isTerminal=false;
		return ;
	}

//small calculation
	TrieNode* child;
	int index=word[0]-'a';
	if(root->children[index]!=NULL){
child=root->children[index];
	}else{
		// word not found
		return ;
	}

//recursion
	remove(child,word.substr(1));


	// remove child if it is useless

	if(child->isTerminal==false){
		for(int i=0;i<26 ;i++){
			//checking if it has any child 
			if(root->children[index]!=NULL){
				return ;
			}
		}
		delete child;
		root->children[index]=NULL;
	}

}

public:
void remove(string word){
	remove( root, word);
}



};