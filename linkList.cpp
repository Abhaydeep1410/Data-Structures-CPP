# include<bits/stdc++.h>
using namespace std;
 
/* link list use instead of vector when we want to add , delete something from 
begning as for vector we need to iterate */

// list in stl is like doubly link list 
/* functions - push_back, push_front,pop_back, pop_front, insert, erase(idx),
               remove(z) */

 int main(){
 list<string> l1={"apple","mango","guava"};
 // for(auto i: l1){
 //    cout<<"-->"<<i;
 // }
l1.push_back("pineapple");

// for(string  i: l1){
//     cout<<"-->"<<i;
//  }



// l1.sort();
// for(string  i: l1){
//     cout<<"-->"<<i;
//  }




// l1.reverse();
// for(auto i: l1){
//     cout<<"-->"<<i;
// }


// cout<<l1.front()<<endl;
// l1.pop_front();
// for(auto i: l1){
//     cout<<"-->"<<i;
// }

// cout<<l1.back()<<endl;
// l1.pop_back();
// for(auto i: l1){
//     cout<<"-->"<<i;
// }




// remove a particular item
// l1.remove("mango");
// for(auto i: l1){
//     cout<<"-->"<<i;
// }


//erase one or more elements at particular index
// auto it=l1.begin()+3; 
// we cant do +3 since memory is not linear;
// auto it=l1.begin(); 
// it++;
// it++;

// l1.erase(it);
// for(auto i: l1){
//     cout<<"-->"<<i;
// }

list<int> l2={1,2,4};
l1.push_back(l2);

auto it=l1.begin();
it++;
l1.insert(it,"new fruit");
for(auto i: l1){
    cout<<"-->"<<i;
}





 }