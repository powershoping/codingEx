#ifndef BINARY_TREE_H
#define BINARY_TREE_H 
#include <vector>
#include <stack>

class TreeNode{
   public: 
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode():val(0), left(nullptr), right(nullptr){} 
      TreeNode(int data): TreeNode(){val = data;}
};

class BSTIterator{
   private:
      std::stack<TreeNode *> stk;
      void pushToStack(TreeNode *root)
      {
         while (root)
         {
            stk.push(root);
            root = root->left;
         }
      }

   public:
      BSTIterator(TreeNode *root)
      {
         pushToStack(root);
      }

      int next()
      {
         auto res = stk.top();
         if (res == nullptr)
            return -1;
         stk.pop();
         if (res->right)
         {
            stk.push(res->right);
            pushToStack(res->right->left);
         }

         return res->val;
      }

      bool hasNext()
      {
         return !stk.empty();
      }
};

TreeNode* buildBTUsingLevelOrder(const std::vector<int> &vecOrg);
TreeNode* buildBTUsingLevelOrder(const std::vector<int> &&vecOrg);

void printBTLevelOrder(TreeNode* root);

#endif

