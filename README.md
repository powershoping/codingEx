# README.md
Coding Examples

## Trees
1. Binary (Search) Tree: [binaryTree.md]
    - [BST Tree Build](https://github.com/powershoping/codingEx/blob/master/bst/include/bstBuild.tcc) :  insert, build using different orders (post-order, in-order, pre-order) 
    - [BST Tree Traversal](https://github.com/powershoping/codingEx/blob/master/bst/include/bstTraversal.tcc) : post-order, in-order, pre-order tranversal
    - [BST Tree Operations](https://github.com/powershoping/codingEx/blob/master/bst/include/bstOperation.tcc) : search, height, sum of leaves, sum, flatten, 
    compare, 
    - [Binary Tree](https://github.com/powershoping/codingEx/blob/master/binaryTree/src/binaryTree.cpp): some information [binaryTree.md](https://github.com/powershoping/codingEx/blob/master/binaryTree/binaryTree.md)
       - [leetCode 1302 ](https://leetcode.com/problems/deepest-leaves-sum/description/) : deepestLevavesSum using BFS and DFS
       - [leetcode 103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/) : Binary Tree Zigzag Level Order Traversal
       - [leetcode 236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/) : Lowest Common Ancestor of a Binary Tree
       - [leetcode 124](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/) :  Binary Tree Maximum Path Sum; Similar to leetcode 687
       - [leetcode 687](https://leetcode.com/problems/longest-univalue-path/description/) : The length of the longest path of a binary tree, where each node in the path has the same value.
       - [leetcode 112](https://leetcode.com/problems/path-sum/description/) : Path Sum.  A tree has a root-to-leaf path such that the sume of all the nodes along the path equals targetSum.
       - [leetcode 113](https://leetcode.com/problems/path-sum-ii/description/) : Path Sum II. all the root-to-leaf paths having the sum equals to target sum. 
       - [leetcode 437](https://leetcode.com/problems/path-sum-iii/description/) : Path Sum III
       - [leetcode 99](https://leetcode.com/problems/recover-binary-search-tree/description/) : correct a BST tree which has exactly two nodes swapped.
       - [leetcode 987 ](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/) : vertical traversal of a binary tree. std::map of std::map std::multiset; and std::vector of std::pair
       - [leetcode 572](https://leetcode.com/problems/subtree-of-another-tree/description/) : Subtree of Another Tree
       - [leetcode 508](https://leetcode.com/problems/most-frequent-subtree-sum/description/) : Most Frequent Subtree Sum
       - [leetcode 230](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/) : Kth Smallest Element in a BST
       - [leetcode 129](https://leetcode.com/problems/sum-root-to-leaf-numbers/description/) : Sum Root to Leaf Numbers
       - [leetcode 222](https://leetcode.com/problems/count-complete-tree-nodes/description/) : Count Complete Tree Nodes
       - [leetcode 108](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/) : Convert Sorted Array to Binary Search Tree
       - [leetcode 109](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/) : Convert Sorted List to Binary Search Tree
       - [leetcode 2196](https://leetcode.com/problems/create-binary-tree-from-descriptions/description/) : Create Binary Tree From Descriptions 
       - [leetcode 199](https://leetcode.com/problems/binary-tree-right-side-view/description/) : binary tree right side view
       - [leetcode 450](https://leetcode.com/problems/delete-node-in-a-bst/description/) : delete a node in a binary search tree

2. Sorting method:    
    - [Sort ](https://github.com/powershoping/codingEx/blob/master/sort/src/sort.cpp) :Selection sort, insertion sort, bubble sort, merge sort, quick sort, counting sort, and radix sort
3. Bit manipulation : [bitManipulation.cpp]( https://github.com/powershoping/codingEx/blob/master/leetCode/bitManipulation.cpp) and [bitManipulation.md](https://github.com/powershoping/codingEx/blob/master/leetCode/bitManipulation.md) 
    -  [leetcode 370 ]( https://leetcode.com/problems/sum-of-two-integers/description/) : Sum of two integers
    -  [leetcode 29  ]( https://leetcode.com/problems/divide-two-integers/description/)  : Division of two intergers
    -  [leetcode 2220](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/) :  Minimum number of bit-flips to make two integers the same
    -  [leetcode 1470]( https://leetcode.com/problems/shuffle-the-array/description/ ) : Shuffle array A of length 2N so that A[i] and A[N+i] are neigbors
    -  [leetcode 7   ](https://leetcode.com/problems/reverse-integer/description/)  : Reverse the interger, e.g. 123==>321
    -  [leetcode 190 ](https://leetcode.com/problems/reverse-bits/description)  : Reverse the binary, e.g. 100110(38) ==> 011001(25)
    -  [leetcode 137](https://leetcode.com/problems/single-number-ii/description/) : single number, a general code
    -  [leetcode 38](https://leetcode.com/problems/counting-bits/description/) : Counting Bits. 0->0, 1->1; 2->10, 3->11; 4->100, 5->101, 6->110, 7->111;8->1000, 9->1001, 10->1010, 11->1011, 12->1100, 13->1101, 14->1110, 15->1111;... [0, 1; 1, 2; 1, 2, 2, 3; 1, 2, 2, 3, 2, 3, 3, 4, ....]
4. Heap: buidHeap, heapfyUp, isHeap [heap.cpp](https://github.com/powershoping/codingEx/blob/master/heap/src/heap.cpp)

5. LinkedList : build and merge k lists [LinkedList.cpp](https://github.com/powershoping/codingEx/blob/master/leetCode/LinkedList.cpp)
    -  [leetcode 61](https://leetcode.com/problems/rotate-list/description/) : Rotate a linked list
    -  [leetcode 25](https://leetcode.com/problems/reverse-nodes-in-k-group/description/) :Reverse Nodes in k-Group in a linked list (O(n+2))
    -  [leetcode 23](https://leetcode.com/problems/merge-k-sorted-lists/description/) : Merge k Sorted Lists (binary-tree 2-leaves merges)
    -  [leetcode 147](https://leetcode.com/problems/insertion-sort-list/description/) : Insertion Sort List

5. Data stream and arrays of data : [dataStream.cpp](https://github.com/powershoping/codingEx/blob/master/leetCode/dataStream.cpp)
    - [leetcode 179](https://leetcode.com/problems/largest-number/description/) : Largest number formed by an array of integers
    - [leetcode 2165](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/) :  Smallest value of the rearranged number
    - [leetcode 143](https://leetcode.com/problems/reorder-list/description/) : reorder the linked list
    - [leetcode 904](https://leetcode.com/problems/fruit-into-baskets/description/) : Fruit Into Baskets
    - [leetcode 287](https://leetcode.com/problems/find-the-duplicate-number/description/) : Find the duplicated number in an array of integers containing n + 1 integers where each integer is in the range [1, n] inclusive.
