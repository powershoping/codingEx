#ifndef BST_TRAVERSAL_HPP
#define BST_TRAVERSAL_HPP

#include <vector>
#include <queue>
#include <iostream>
#include<iomanip>

#include "bst.h"

/**
  compute the inorder of a tree with root=node
*/  
template<typename T>
void BST<T>::inorder(BST<T>* node, std::vector<T>& vec)  
{
   //base case
   if(!node){
      return;
   }
   inorder(node->left, vec);
   vec.push_back(node->data);
   inorder(node->right, vec);
}


/**
  compute the reverse of the inorder of a tree with root=node
*/  
template<typename T>
void BST<T>::reverseInorder(BST<T>* node, std::vector<T>& vec)  
{
   //base case
   if(!node){
      return;
   }
   reverseInorder(node->right, vec);
   vec.push_back(node->data);
   reverseInorder(node->left, vec);

}


/**
  compute the preorder of a tree with root=node
*/  
template<typename T>
void BST<T>::preorder(BST<T>* node, std::vector<T>& vec)  
{
   //base case
   if(!node){
      return;
   }

   vec.push_back(node->data);
   preorder(node->left, vec);
   preorder(node->right, vec);
}

/**
  compute the postorder of a tree with root=node
*/  
template<typename T>
void BST<T>::postorder(BST<T>* node, std::vector<T>& vec)  
{
   //base case
   if(!node){
      return;
   }

   postorder(node->left, vec);
   postorder(node->right, vec);
   vec.push_back(node->data);
}


/**
  print current level of a tree with root=node
*/  
template<typename T>
void BST<T>::currentLevelOrder(BST<T>* node, int level, std::vector<T> &vec)  
{
   if(node == nullptr)
      return;
   if(level == 1)
      vec.push_back(node->data);
   else if(level > 1)
   {
      currentLevelOrder(node->left,  level-1, vec);
      currentLevelOrder(node->right, level-1, vec);
   }

}
/**
  print level order of a tree with root=node O(2^n)
*/  
template<typename T>
void BST<T>::levelOrder(BST<T>* node, std::vector< std::vector<T> > &vec)  
{

   if(node->height==BST<T>::DefaultHeight){
      std::cout<<"Error: the height of the tree is "<<BST<T>::DefaultHeight<<", no tree output;";
      return;
   }
   int height=node->height;
   vec.resize(height);

   for(int level=1; level<=height; ++level)
   {
      currentLevelOrder(node, level, vec[level-1]);
   }
}

/**
  print level order of a tree with root=node using queue
*/  
template<typename T>
void BST<T>::levelOrderUsingQueue(BST<T>* node, std::vector<std::vector<T>> & vec)  
{
   if(!node)
      return;

   if(node->height == BST<T>::DefaultHeight)
      std::cout<<"Error: the height of the tree is "<<BST<T>::DefaultHeight<<", no tree output;";
      return;

   std::queue<BST<T>*> bst_queue;
   bst_queue.push(node);

   while(!bst_queue.empty())
   {
      auto cur_node = bst_queue.front();
      int  cur_ht = cur_node->height;
      bst_queue.pop();

      vec[cur_ht-1].push_back(cur_node->data);

      if(cur_node->left)
         bst_queue.push(cur_node->left);
      if(cur_node->right)
         bst_queue.push(cur_node->right);

   }

   return;

}   

/**
  print leaves of a tree 
*/  
template<typename T>
void BST<T>::leaves(BST<T>* node, std::vector<T> &vec)  
{
   if(!node)
      return;

   if(!node->left && !node->right){
      vec.push_back(node->data);
      return;
   }
   leaves(node->left,  vec);
   leaves(node->right, vec);
}





/**
  print level order of a tree with root=node O(2^n)
*/  
template<typename T>
void BST<T>::printLevelOrder(BST<T>* node)  
{

   if(node->height==BST<T>::DefaultHeight){
      std::cout<<"Error: the height of the tree is "<<BST<T>::DefaultHeight<<", no tee output;";
      return;
   }
   int height=node->height;

   for(int level=1; level<=height; ++level)
   {
      std::cout << "(H =" << std::setw(3) << height-level+1 << ")";
      printCurrentLevelOrder(node, level);
      std::cout<<std::endl;
   }
}

/**
  print current level of a tree with root=node
*/  
template<typename T>
void BST<T>::printCurrentLevelOrder(BST<T>* node, int level)  
{
   if(node == nullptr)
      return;
   if(level == 1)
      std::cout<<std::setw(5)<<node->data;
   else if(level > 1)
   {
      printCurrentLevelOrder(node->left,  level-1);
      printCurrentLevelOrder(node->right, level-1);
   }

}

/**
  print level order of a tree with root=node using queue
*/  
template<typename T>
void BST<T>::printLevelOrderUsingQueue(BST<T>* node)  
{
   if(!node)
      return;


//   std::cout<<std::setw(5);
   std::queue<BST<T>*> bst_queue;
   bst_queue.push(node);
   int saved_ht = node->height;
   int cur_ht;
   if(saved_ht != BST<T>::DefaultHeight)
      printf("(H =%3d)",node->height);
   while(!bst_queue.empty())
   {
      auto cur_node = bst_queue.front();
      bst_queue.pop();
      if(cur_node)
         cur_ht = cur_node->height;

      if(cur_ht != BST<T>::DefaultHeight && cur_ht != saved_ht)
         std::cout<<"\n(H ="<<std::setw(3)<<cur_ht<<")";

      if(cur_node)
         std::cout << std::setw(5) << cur_node->data<<"(sum:"<<std::setw(5)<<cur_node->sum<<")";
      else
         std::cout << std::setw(5) << "null"<<"       ";

      if(cur_node){
         saved_ht = cur_node->height;
         if (cur_node && (cur_node->left == nullptr && cur_node->right == nullptr)){ // leaf
            continue;
         }
         else{
            bst_queue.push(cur_node->left);
            bst_queue.push(cur_node->right);
         }
      }
      else{
         continue;
      }

   }

   std::cout<<std::endl;
   return;

}   


#endif
