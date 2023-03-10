#include <queue>
#include <limits.h>
#include <iostream>

#include "binaryTree.h"

TreeNode *buildBTUsingLevelOrder(const std::vector<int> &&vecOrg)
{
   return buildBTUsingLevelOrder(vecOrg);
}
TreeNode *buildBTUsingLevelOrder(const std::vector<int> &vecOrg)
{

   if (vecOrg[0] == INT_MAX)
   {
      std::cout << "Empty binary tree or invalid binary tree\n";
      return nullptr;
   }
   TreeNode *root = new TreeNode(vecOrg[0]);
   std::queue<TreeNode *> nodeQueue;
   nodeQueue.push(root);

   for (int ii = 1; ii < vecOrg.size(); ii += 2)
   {
      auto curNode = nodeQueue.front();
      nodeQueue.pop();
      if (vecOrg[ii] == INT_MAX)
      {
         curNode->left = nullptr;
      }
      else
      {
         TreeNode *newNode = new TreeNode(vecOrg[ii]);
         nodeQueue.push(newNode);
         curNode->left = newNode;
      }

      if (vecOrg[ii + 1] == INT_MAX)
      {
         curNode->right = nullptr;
      }
      else
      {
         TreeNode *newNode = new TreeNode(vecOrg[ii + 1]);
         nodeQueue.push(newNode);
         curNode->right = newNode;
      }
   }
   return root;
}

void printBTLevelOrder(TreeNode* root)
{
   if(root==nullptr)
      std::cout << "null\n";

   std::queue<TreeNode*> nodeQueue;
   nodeQueue.push(root);
   std::cout<<"[";
   int count=0;
   while(!nodeQueue.empty()){
      auto curNode= nodeQueue.front();
      nodeQueue.pop();
      if(count>0)std::cout<<", ";
      if(curNode){
         std::cout << curNode->val;
      }
      else{
         std::cout <<"null";
         continue;
      }

      count++;
      nodeQueue.push(curNode->left);
      nodeQueue.push(curNode->right);
   }
   std::cout<<"]\n";
}


