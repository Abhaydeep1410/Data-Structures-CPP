#include <bits/stdc++.h>
using namespace std;
#include "trie.h"

//pattern matching 
// pick a word and insert all sufixes of that word in the tree
/* ex. for tree add ree , ee, e in the trie 
or other method remove condition of isTerminal from the trie */





int main(){
/* better than hashmap  for dictornary in terms of 
1. space 
2.fast searching
*/

Trie t;
t.insertWord("and");
t.insertWord("abhay");
t.insertWord("nacy");


cout<<t.search("abha");

t.remove("abhay");
cout<<t.search("abhay")<<endl;


cout<<patternMatching("abc def ghi cba",4);



}