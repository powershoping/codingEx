#ifndef BST_OPERATION_TCC
#define BST_OPERATION_TCC

#include <algorithm>

#include "bst.h"

/**
  search the tree with root=node for data=dd
*/  
template<typename T>
BST<T>* BST<T>::search(BST<T>* node, T dd)
{
   if(!node || node->data == dd ){
      return node;
   }

   if(dd < node->data){
      return search(node->left, dd);
   }
   else{
      return search(node->right, dd);
   }

}

template<typename T>
BST<T>* BST<T>::search(BST<T>* node, T dd, BST<T>* &par)
{
   if(!node || node->data == dd ){
      return node;
   }

   par = node;
   if(dd < node->data){
      return search(node->left, dd, par);
   }
   else{
      return search(node->right, dd, par);
   }

}

template<typename T>
BST<T>* BST<T>::deleteNode(BST<T>* root, T dd)
{
   if(root == nullptr)return root;
   BST<T> *par=root;
   BST<T> *node = search(root, dd, par);
   if(node == par) {
      delete root;
      root = nullptr;
      return nullptr;
   }
   if(node->left){
      auto prev = node;
      auto cur = node->left;
      while(cur->right){
         prev=cur;
         cur=cur->right;
      }
      node->data=cur->data;
      if(prev == node)
      {
         prev->left = cur->left;
      }
      else{
         prev->right = cur->left;
      }
      delete cur;
      cur = nullptr;
   }
   else
   {
      if(par->right &&par->right->data == node->data ){
         par->right=nullptr;
      }
      else
      {
         par->left =nullptr;
      }
      delete node;
   }

   return root;
}
template<typename T>
int BST<T>::computeHeight(BST<T>* node)  
{
   if(!node){
      return 0;
   }

   int leftH  = computeHeight(node->left);
   int rightH = computeHeight(node->right);

   node->height = std::max(leftH, rightH) + 1;

   return node->height;
}


/**
 * @brief sum of all the leaves
 * 
 */
template <typename T>
T BST<T>::sumLeaves(BST<T> *root){

   if(root==nullptr)
      return 0;
   if(root->left==nullptr && root->right==nullptr)
      return root->data;

   return sumLeaves(root->left) + sumLeaves(root->right);
}

// leetcode 404 : https://leetcode.com/problems/sum-of-left-leaves/description/
/**
 * @brief sum of all the left leaves
 * 
 */
template <typename T>
T BST<T>::sumLeftLeaves(BST<T> *root){

   if(root==nullptr)
      return 0;
   if(root->left && root->left->left==nullptr && root->left->right==nullptr)
      return root->left->data + sumLeftLeaves(root->right);

   return sumLeftLeaves(root->left) + sumLeftLeaves(root->right);
}
/**
 * @brief sum of all right leaves
 * 
 */
template <typename T>
T BST<T>::sumRightLeaves(BST<T> *root){

   if(root==nullptr)
      return 0;
   if(root->right && root->right->left==nullptr && root->right->right==nullptr)
      return root->right->data + sumRightLeaves(root->left);

   return sumRightLeaves(root->left) + sumRightLeaves(root->right);
}


/**
 * @brief sum of all children and the root and store the sum to the root
 * 
 */
template <typename T>
T BST<T>::sumTree(BST<T> *root){
   if(root==nullptr)
      return 0;
//   if(root->left==nullptr && root->right==nullptr) { //not necessary. 1st round. 
//      root->sum=root->data;
//   }
      
   root->sum =root->data + sumTree(root->left) + sumTree(root->right);

   return root->sum;
}

// leetcode 114 : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

/**
 * @brief flatten the tree to a single linked list 
 * 
 */
template <typename T>
BST<T> * BST<T>::flatten(BST<T> *root){
  if(root==nullptr)
     return nullptr;

  auto leftTail  = flatten(root->left);
  auto rightTail = flatten(root->right);

  if(root->left){
     leftTail->right = root->right;
     root->right = root->left;
     root->left  = nullptr;
  }
  if(rightTail)return rightTail;
  if(leftTail) return leftTail;
  return root;
}

// leetcode 100 : https://leetcode.com/problems/same-tree/description/

/**
 * @brief compare two trees. identical = true, otherwise = false; 
 *   
 */

template <typename T>
bool BST<T>::isSame1(BST<T> *root1, BST<T>*root2){ // redundant cocde. 1 round. 

   bool identical = false;
   if(root1 == nullptr && root2 == nullptr){
      identical = true;
      return identical;
   }
   if(root1 && root2 == nullptr || root1 == nullptr && root2){
      identical = false;
   }
   else if (root1->data == root2->data){
      identical = true;
   }

  if(identical == true){
     return isSame(root1->left, root2->left) || isSame(root1->right, root2->right);
  }
  else
     return false;
}

template <typename T>
bool BST<T>::isSame(BST<T> *root1, BST<T>*root2){

   if(root1 == nullptr && root2 == nullptr){ //if two Trees come to the nullptr roots, then trees must be the same. 
      return true;
   }
   if(!root1 || !root2){
      return false;
   }
   if(root1 && root2 && root1->data != root2->data){// any data point not the same will lead to the trees not the same. 
      return false;
   }


   return isSame(root1->left, root2->left) || isSame(root1->right, root2->right);
}

#endif