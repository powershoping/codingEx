#ifndef BST_BUILD_HPP
#define BST_BUILD_HPP

#include<iostream>
#include<vector>
#include<unordered_map>

#include "bst.h"


template<typename T> int BST<T>::DefaultHeight = -1;

//Constructors
/** 
  construct a empty node
*/  
template<typename T>
BST<T>::BST()     : data(T()), left(nullptr), right(nullptr), height(-1), sum(0)
{}

/**
  construct a node with data
*/  
template<typename T>
BST<T>::BST(T dd) : data(dd),  left(nullptr), right(nullptr), height(-1),sum(0)
{}

/**
  insert a data to the tree with root=node
*/
template<typename T>
BST<T>* BST<T>::insert(BST<T>* node, T dd)
{

   // takes in a node (can be parent.left or parent.right from the caller), 
   // base case: if the node is nullptr, {new} a node with the data and return it then assign it back to parent->left or parent->right in the caller
   if(!node)
   {
      return new BST<T>(dd);
   }

   if(dd < node->data){
      node->left=insert(node->left, dd);
   }
   else if(dd >node->data){
      node->right=insert(node->right,dd);
   }

   return node;
}

//Build tree using all sorts of **orders.
/**
Main drive function for building a binary tree using the preorder and inorder
*/

template<typename T>
BST<T>* BST<T>::buildTreeUsingPreInOrders(std::vector<T>& preorder, std::vector<T>& inorder)
{
   int num = preorder.size();
   if(num != inorder.size())
   {
      printf("Error: the size of preorder and inorder should be the same\n");
      exit(1);
   }

   if(num == 0)
   {
      return nullptr;
   }

   if(num == 1)
     return new BST<T>(preorder[0]); 

   std::unordered_map<T, int> umap;

   for(int ii = 0; ii<num; ++ii)
   {
      umap[ inorder[ii] ] = ii;
   }
   int pre_index =0;

   return buildSubTreeUsingPreInOrders(preorder,  inorder, umap, 0, num-1, pre_index);
}

/**
  recursive function for building a binary tree using the preorder and inorder and the range of the subtree.
*/
// the build follows the pre-order: action, left, right
template<typename T>
BST<T>* BST<T>::buildSubTreeUsingPreInOrders(std::vector<T>& preorder,  std::vector<T>& inorder, std::unordered_map<T, int>& umap, int in_start, int in_end, int& pre_index)
{
   if(in_start>in_end || pre_indx == preorder.size())
      return nullptr;

   T data = preorder[pre_index++];
   auto cur_node = new BST<T>(data); // here post ++ is used as pre_index is used first then increase it by 1. 
   int in_index = umap[data];

   cur_node->left  = buildSubTreeUsingPreInOrders(preorder, inorder, umap, in_start, in_index-1, pre_index); 
   cur_node->right = buildSubTreeUsingPreInOrders(preorder, inorder, umap, in_index+1, in_end, pre_index);

   return cur_node;

}

/**
 * @brief 
 * build a binary tree using postorder and inorder
 * @tparam T  template parameter
 * @param postorder postorder of a binary tree
 * @param inorder   inorder of a binary 
 * @return BST<T>*  the root node of the binary tree
 */
template<typename T>
BST<T>* BST<T>::buildTreeUsingPostInOrders(std::vector<T>& postorder, std::vector<T>& inorder)
{
   int num = postorder.size();
   if(num != inorder.size())
   {
      printf("Error: the size of preorder and inorder should be the same\n");
      exit(1);
   }

   if(num == 0)
   {
      return nullptr;
   }

   if(num == 1)
     return new BST<T>(postorder[0]); 

   std::unordered_map<T, int> umap;

   for(int ii = 0; ii<num; ++ii)
   {
      umap[ inorder[ii] ] = ii;
   }

   return buildSubTreeUsingPostInOrders(postorder,  inorder, umap, 0, num-1);
}

template<typename T>
BST<T>* BST<T>::buildSubTreeUsingPostInOrders(std::vector<T>& postorder, std::vector<T>& inorder, std::unordered_map<T, int>& umap, int in_start, int in_end )
{

   if (in_start > in_end)
      return nullptr;

   static int post_index = postorder.size()-1;
   T data = postorder[post_index--];
   BST<T> *cur_node = new BST<T>(data);
   if (in_start == in_end)
      return cur_node;

   int index = umap[data];
   cur_node->right = buildSubTreeUsingPostInOrders(postorder, inorder, umap, index + 1, in_end);
   cur_node->left = buildSubTreeUsingPostInOrders(postorder, inorder, umap, in_start, index - 1);

   return cur_node; 
}


#endif
