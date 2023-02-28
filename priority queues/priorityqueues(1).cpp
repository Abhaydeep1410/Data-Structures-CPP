#include<bits/stdc++.h>
using namespace std;


// priority  queues : bahar nikaloge on basis of priority
//1. min p queue : remvoing element from queue having lowest priority
//2. max p queue

// three imp function 1. insert 2. getmax/getmin 3. remove max/min


/* ways to implement prioity queues
					insert   getmin/max   removemin/max
array(unsorted)		o(1)       o(n)				o(n)			
array(sorted)		o(n)		o(1)			o(n)
LL(unsorted)		o(1)		o(n)			o(n)
LL(sorted)			o(n)		o(1)			o(1)
BST					o(h)		o(h)			o(h)
balanced bst		o(logn)		o(logn)			o(logn)
(best)

we have to maintain balacing factor in balnced bst  and storing was complex(more pointers)
therefore we use a new data structure

HEAPS  
1) compelete binary tree : last level main left to right fill hona chaiye 
2) heap order property


complete binary tree implementation 
implement it in form of arrays left child at 2*i+1 and right at 2*i+2
insert at last and delete next index 
 to find parent from child (ci-2)/2  like (2i+1-1)/2=i