#ifndef BINARY_TREE_H
#define BINARY_TREE_H 
#include <vector>

class TreeNode{
   public: 
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode():val(0), left(nullptr), right(nullptr){} 
      TreeNode(int data): TreeNode(){val = data;}
};


TreeNode* buildBTUsingLevelOrder(const std::vector<int> &vecOrg);
TreeNode* buildBTUsingLevelOrder(const std::vector<int> &&vecOrg);

void printBTLevelOrder(TreeNode* root);

#endif

