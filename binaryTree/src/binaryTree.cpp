#include <queue>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <sstream>

#include "binaryTree.h"
#include "linkedList.h"
#include "output_tools.h"

void preorderTrvsl(TreeNode *root, std::vector<int> &preorderVec)
{
   if(root==nullptr) return;
   preorderVec.push_back(root->val);
   preorderTrvsl(root->left,  preorderVec);
   preorderTrvsl(root->right, preorderVec);
   return ;
}
// [leetcode 103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/) : Binary Tree Zigzag Level Order Traversal
std::vector<std::vector<int>> zigZagLevelTranversal(TreeNode* root)
{
   if(!root) return std::vector<std::vector<int>>();
   std::vector<std::vector<int>> levelOrders;
   bool left_to_right = true;
   std::deque<TreeNode*> lqueue;
   lqueue.push_back(root);
   levelOrders.push_back(std::vector<int>(1, root->val));
   while(!lqueue.empty()){
      size_t sz = lqueue.size();
      std::vector<int> lvec;
      
      if(left_to_right){
         for(size_t ii = 0; ii < sz; ++ii){
            auto curNode = lqueue.front();
            lqueue.pop_front();
            if(curNode->right){
               lvec.push_back(curNode->right->val);
               lqueue.push_back(curNode->right);
            }
            if(curNode->left){
               lvec.push_back(curNode->left->val);
               lqueue.push_back(curNode->left);
            }
         }
      }
      else{
         for(size_t ii = 0; ii < sz; ++ii){
            auto curNode = lqueue.back();
            lqueue.pop_back();
            if(curNode->left){
               lvec.push_back(curNode->left->val);
               lqueue.push_front(curNode->left);
            }
            if(curNode->right){
               lvec.push_back(curNode->right->val);
               lqueue.push_front(curNode->right);
            }
         }
      }
      if( lvec.size() ) levelOrders.push_back(lvec);

      left_to_right = left_to_right? false : true;

   }

   return levelOrders;
}
//if find in the left and right of the root, then return root.
// two senario: 1) a split of current node tells the current node is the lca. 2) on one side of the tree, return the root no more deep traversal. 
// [leetcode 236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/) : Lowest Common Ancestor of a Binary Tree
TreeNode *lowestCommonAncestor(TreeNode *root, const int pp, const int qq)
{
   if (!root)
      return nullptr;
   if (root->val == pp || root->val == qq)
   {
      return root;
   }
   auto left = lowestCommonAncestor(root->left, pp, qq);
   auto right = lowestCommonAncestor(root->right, pp, qq);
   if (left && right)
   {
      return root;
   }
   return left != nullptr ? left : right;
}


// [leetcode 124](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/) :  Binary Tree Maximum Path Sum
int maxPathSum(TreeNode *root, int &maxSum){
   if(!root) return 0;

   int ll = maxPathSum(root->left,  maxSum);
   int rr = maxPathSum(root->right, maxSum);

// max among left side + root->val, right side + root->val, and root->val.
   int max1side = std::max(std::max(ll,rr)+root->val, root->val);
// max among the above  and ll + rr + root->val;
   int maxTop   = std::max(max1side, ll+rr+root->val);
   maxSum       = std::max(maxSum, maxTop);

   return max1side;
}

int maxPathSum(TreeNode *root){
   int maxSum = INT_MIN;

   maxPathSum(root, maxSum);

   return maxSum;
}

// [leetcode 687](https://leetcode.com/problems/longest-univalue-path/description/) : the length of the longest path of a binary tree, where each node in the path has the same value.
int longestUnivaluePath(TreeNode *root, int &maxLength)
{
   if (!root)
      return 0;

   int ll = longestUnivaluePath(root->left, maxLength);
   int rr = longestUnivaluePath(root->right, maxLength);
   int leftMax = 0, rightMax = 0;

   if (root->left && root->val == root->left->val)
   {
      leftMax = ll + 1;
   }
   if (root->right && root->val == root->right->val)
   {
      rightMax = rr + 1;
   }

   int max1side = std::max(leftMax, rightMax);
   maxLength = std::max(maxLength, max1side);
   if ((root->left && root->right) && (root->val == root->left->val && root->val == root->right->val))
   {
      maxLength = std::max(maxLength, leftMax + rightMax);
   }

   return max1side;
}

int lengthLongestUnivaluePath(TreeNode *root){
    int length = 0;

    longestUnivaluePath(root, length);
    return length;

}

// [leetcode 112](https://leetcode.com/problems/path-sum/description/) : Path Sum.  A tree has a root-to-leaf path such that the sume of all the nodes along the path equals targetSum.
bool hasPathSum(TreeNode* root, int targetSum){
   if(!root)return false;
   if(root->left == nullptr && root->right == nullptr )
      return targetSum == root->val;
   targetSum -= root->val;
   return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
}

 // backtracking needed as we are passing curPath by reference, so all the nodes share the same curPath. 
 //so pop_back is need if the path does not have a sum of targetSum. 


// [leetcode 113](https://leetcode.com/problems/path-sum-ii/description/) : Path Sum II. all the root-to-leaf paths having the sum equals to target sum. 
void findPathByRef(TreeNode *root, int targetSum, std::vector<int> &curPath, std::vector<std::vector<int>> &paths){
   if(!root)return;

   curPath.push_back(root->val);
   if(root->left == nullptr && root->right == nullptr ){ //find a path (a leaf corresponds to a path)
      if(targetSum == root->val) {
         paths.push_back(curPath);
      }
      curPath.pop_back();
      return;
   }
   targetSum -= root->val;
   findPathByRef(root->left,  targetSum, curPath, paths);
   findPathByRef(root->right, targetSum, curPath, paths);
   curPath.pop_back();
}

std::vector<std::vector<int>>pathSumByRef(TreeNode *root, int targetSum )
{
   std::vector<int> curPath;  //current path
   std::vector<std::vector<int>> paths; //holds all the paths
   findPathByRef(root, targetSum, curPath, paths);

   return paths;
}

 // the beauty of the pass by value in C++, curPath are different for each stack frame, i.e. for each node.
 // so no code for back tracking neccessary. But it is slow this way, as a copy of the curPath needs to be passed to 
 // child node.
void findPath(TreeNode *root, int targetSum, std::vector<int> curPath, std::vector<std::vector<int>> &paths){
   if(!root)return;

   curPath.push_back(root->val);
   if(root->left == nullptr && root->right == nullptr ){ //find a path (a leaf corresponds to a path)
      if(targetSum == root->val) {
         paths.push_back(curPath);
      }
      return;
   }
   targetSum -= root->val;
   findPath(root->left,  targetSum, curPath, paths);
   findPath(root->right, targetSum, curPath, paths);
}
std::vector<std::vector<int>>pathSum(TreeNode *root, int targetSum )
{
   std::vector<int> curPath;  //current path
   std::vector<std::vector<int>> paths; //holds all the paths
   findPath(root, targetSum, curPath, paths);

   return paths;
}


// idea of prefix sum is used here. if(umap[prefixSum[i]-targetSum]) count += umap[prefixSum[i]-targetSum];        
// [leetcode 437](https://leetcode.com/problems/path-sum-iii/description/) : Path Sum III
void pathCountDownWard(TreeNode *root, int targetSum, std::unordered_map<long int, int> &umap, int rSum, int &count){
   if(!root) return;
   rSum += root->val;
   if(umap.find(rSum-targetSum)!=umap.end())
      count += umap[rSum - targetSum];

   umap[rSum] ++;
   pathCountDownWard(root->left, targetSum, umap, rSum, count);
   pathCountDownWard(root->right, targetSum, umap, rSum, count);
   umap[rSum] --;
}
int numDownWardPathsSum(TreeNode *root, int targetSum)
{
   long int rSum=0; //running Sum
   int count = 0;
   std::unordered_map<long int, int> umap;
   umap[0]=1; // if the prefix sum == target, we need to have this as the edge case. 

   pathCountDownWard(root, targetSum, umap, rSum, count);

   return count;
}
// 1, 2, 3, 4, 6, 5, 7, 8 ; single pair of (6,5) in wrong order ==> (5,6) will correct the tree
// 1, 7, 3, 4, 5, 6, 2, 8 ; two pairs (7, 3) and (6, 2), swap 7 and 2 will correct the tree. 
// we need remember pre node/value to compare with current node. if wrong order, the set first to prev, and last to the root(current). if 2nd wrong
// order then just need to set root to last. switch first and last will correct the bst. 
//[leetcode 99](https://leetcode.com/problems/recover-binary-search-tree/description/) : correct a BST tree which has exactly two nodes swapped.
void find2Nodes(TreeNode *root, TreeNode* &prev, TreeNode* &first, TreeNode * &last){
   if(!root) return;
   
   find2Nodes(root->left, prev, first, last);
   if(prev){
      if(root->val < prev->val){
         if(!first){
            first=prev;
            last = root;//handles  1, 3, 2: consective two nodes are wrong
         }
         else{
            last = root; // if there is another one, two wrong nodes are at least one node apart. 
         }
      }
   }
   prev = root;
   find2Nodes(root->right, prev, first, last);
}

void correctBST(TreeNode *root){
   TreeNode *prev=nullptr, *first=nullptr, *last=nullptr;
   find2Nodes(root, prev, first, last );
   int tmp = first->val;
   first->val = last->val;
   last->val = tmp;
}

//[leetCode 1302 ](https://leetcode.com/problems/deepest-leaves-sum/description/) : deepestLevavesSum using BFS and DFS
//using BFS (needs a queue) and DFS
int deepestLeavesSumBFS(TreeNode *root)
{
   if (root == nullptr)
      return 0;
   std::queue<TreeNode *> Queue;
   int sum = 0;
   Queue.push(root);
   while (!Queue.empty())
   {
      sum = 0;
      const int sz = Queue.size();
      for (int ii = 0; ii < sz; ++ii)
      {
         auto curNode = Queue.front();
         Queue.pop();
         sum += curNode->val;
         if (curNode->left)
            Queue.push(curNode->left);
         if (curNode->right)
            Queue.push(curNode->right);
      }
   }
   return sum;
}
int maxDepth(TreeNode *root, std::vector<std::pair<int, int>> &valDepth, int depth)
{
   if (root == nullptr)
      return depth;
   if (root->left == nullptr && root->right == nullptr)
   {
      valDepth.push_back({root->val, depth});
      return depth;
   }
   depth++;
   return std::max(maxDepth(root->left, valDepth, depth), maxDepth(root->right, valDepth, depth));
}

int deepestLeavesSumDFS(TreeNode *root)
{
   std::vector<std::pair<int, int>> valDepth;
   int max = maxDepth(root, valDepth, 0);

   int sum = 0;
   for (auto &el : valDepth)
   {
      if (el.second == max)
         sum += el.first;
   }
   return sum;
}
//[leetcode 987 ](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/) : vertical traversal of a binary tree. 
// using std::vector< std::pair< std::pair<int, int>, int > >  and a customer's defined comparison functor. std::pair can do lexicographical comparison. 
//
void verticalTraversal(TreeNode *root, std::vector< std::pair< std::pair<int, int>, int > > &vecPairs, int xAxis, int height){
   if(root == nullptr)return;
   verticalTraversal(root->left, vecPairs,  xAxis-1, height+1);
   vecPairs.push_back({{xAxis, height}, root->val});
   verticalTraversal(root->right, vecPairs, xAxis+1, height+1);
   return;
}
std::vector<std::vector<int>> verticalTraversalVec(TreeNode *root)
{
   {
      std::vector<std::pair<std::pair<int, int>, int>> vecPairs; // < <xAxis, Hieght>, nodeVal>
      int xAxis = 0;
      int height = 0;
      if (root == nullptr)
         return std::vector<std::vector<int>>();

      verticalTraversal(root, vecPairs, xAxis, height);

      class vecPairComp
      {
      public:
         bool operator()(std::pair<std::pair<int, int>, int> aa, std::pair<std::pair<int, int>, int> bb) const
         {
            if (aa.first == bb.first)
            {
               return aa.second < bb.second;
            }
            return aa.first < bb.first;
         }
      };

      std::sort(vecPairs.begin(), vecPairs.end(), vecPairComp());

      const size_t sz = vecPairs.size();
      std::vector<int> vec;
      std::vector<std::vector<int>> results;
      xAxis = vecPairs[0].first.first;
      for (size_t ii = 0; ii < sz; ++ii)
      {
         if (xAxis != vecPairs[ii].first.first)
         {
            xAxis = vecPairs[ii].first.first;
            results.push_back(vec);
            vec.clear();
         }
         vec.push_back(vecPairs[ii].second);
      }
      results.push_back(vec);

      return results;
   }
}
// std::map way uses more memory and is not faster than the std::vector way. 
void verticalTraversal(TreeNode *root, std::map<int, std::map<int, std::multiset<int>>> &vtmap, int xAxis, int height)
{
   if (root == nullptr)
      return;
   verticalTraversal(root->left, vtmap, xAxis - 1, height + 1);
   vtmap[xAxis][height].insert(root->val);
   verticalTraversal(root->right, vtmap, xAxis + 1, height + 1);
   return;
}

std::vector<std::vector<int>> verticalTraversalMap(TreeNode *root)
{
   if (root == nullptr)
      return std::vector<std::vector<int>>();
   std::map<int, std::map< int, std::multiset<int> > > vtmap;
   std::vector<std::vector<int>> results;
   int xAxis  =0;
   int height =0;
   verticalTraversal(root, vtmap, xAxis, height);

   const size_t sz = vtmap.size();
   for (const auto el : vtmap)
   {
      std::vector<int> vec;
      for (const auto el0 : el.second)
      {
         vec.insert(vec.end(), el0.second.begin(), el0.second.end() );
      }
      results.push_back(vec);
   }
   return results;
}
//[leetcode 572](https://leetcode.com/problems/subtree-of-another-tree/description/) : Subtree of Another Tree
bool isSameTree(TreeNode *root1, TreeNode *root2)
{
   if (root1 == nullptr && root2 == nullptr)
      return true;
   if (root1 == nullptr || root2 == nullptr)
      return false;
   if (root1->val == root2->val)
   {
      return (isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right));
   }
   return false;
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
   if (subRoot == nullptr)
      return true;
   if (root == nullptr)
      return false;
   if (isSameTree(root, subRoot))
   {
      return true;
   }
   else
   {
      return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
   }
}

//[leetcode 508](https://leetcode.com/problems/most-frequent-subtree-sum/description/) : Most Frequent Subtree Sum

int treeSum(TreeNode *root, std::unordered_map<int, int> &sumMap)
{
   if (root == nullptr)
      return 0;
   int sum = root->val + treeSum(root->left, sumMap) + treeSum(root->right, sumMap);
   sumMap[sum]++;
   return sum;
}

std::vector<int> findFrequentTreeSum(TreeNode *root)
{
   std::unordered_map<int, int> sumMap;
   treeSum(root, sumMap);
   int maxFreq = INT_MIN;
   for (const auto & [key, value] : sumMap)
   {
      if (value > maxFreq)
         maxFreq = value;
   }
   std::vector<int> results;
   for (const auto & [key, value] : sumMap)
   {
      if (value == maxFreq)
         results.push_back(key);
   }
   return results;
}
// [leetcode 230](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/) : Kth Smallest Element in a BST
void dfs_kth(TreeNode *root, int &kk, int &result)
{
   if (root == nullptr)
      return;

   dfs_kth(root->left, kk, result);
   kk = kk - 1;
   if (kk == 0)
   {
      result = root->val;
      return;
   }
   dfs_kth(root->right, kk, result);
}
int kthSmallest(TreeNode *root, int k)
{

   int result;
   dfs_kth(root, k, result);
   return result;
}
TreeNode *inorderSuccessorBST(TreeNode *root, int vv)
{
   if (root == nullptr || (root->left == nullptr && root->right == nullptr))
      return nullptr;
   TreeNode *succ = nullptr;
   while (root != nullptr)
   {
      if (vv >= root->val)
      {
         root = root->right;
      }
      else
      {
         succ=root;
         root = root->left;
      }
   }
   return succ;
}

TreeNode *inorderPredecessorBST(TreeNode *root, int vv)
{
   if(root==nullptr || (root->right==nullptr && root->left==nullptr))
      return nullptr;
   TreeNode *pred = nullptr;
   while(root!=nullptr){
      if(vv > root->val){
         pred = root;
         root = root->right;
      }
      else{
         root = root->left;
      }
   }
   return pred;
}

TreeNode *inorderSuccessor(TreeNode* root, int &vv){
   if(root==nullptr) return nullptr;
   TreeNode *ll = nullptr;
   TreeNode *rr = nullptr;
   ll = inorderSuccessor(root->left, vv);
   if(ll)return ll;
   if(vv== INT_MAX) {
      return root;
   }
   if(root->val == vv) vv = INT_MAX;
   rr= inorderSuccessor(root->right, vv);
   return rr;
}
//[leetcode 129](https://leetcode.com/problems/sum-root-to-leaf-numbers/description/) : Sum Root to Leaf Numbers
void sumHelper(TreeNode *root, int &sum, std::string str)
{
   if (root == nullptr)
      return;
   str = str + std::to_string(root->val);
   if (root->left == nullptr && root->right == nullptr)
   {
      sum = sum + std::stoi(str);
   }
   sumHelper(root->left, sum, str);
   sumHelper(root->right, sum, str);
}
int sumNumbers(TreeNode *root)
{
   int sum = 0;
   std::string str{};
   sumHelper(root, sum, str);
   return sum;
}

//[leetcode 222](https://leetcode.com/problems/count-complete-tree-nodes/description/) : Count Complete Tree Nodes
int computeLH(TreeNode *root)
{
   int hh = 0;
   root = root->left;
   while (root)
   {
      root = root->left;
      ++hh;
   }
   return hh;
}
int computeRH(TreeNode *root)
{
   int hh = 0;
   root = root->right;
   while (root)
   {
      root = root->right;
      ++hh;
   }
   return hh;
}
int countNodesCompleteTree(TreeNode *root)
{
   if (root == nullptr)
      return 0;
   int lh = computeLH(root);
   int rh = computeRH(root);
   if (lh == rh)
   {
      return (1 << (lh + 1)) - 1;
   }
   else
   {
      return countNodesCompleteTree(root->left) + countNodesCompleteTree(root->right) + 1;
   }

}

//[leetcode 109](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/) : Convert Sorted List to Binary Search Tree
ListNode *findPrevMid(ListNode *head)
{
   if (!head || !(head->next))
   {  
      return head;
   }
   ListNode *slow = head;
   ListNode *prev = slow;
   ListNode *fast = slow->next->next;
   while (fast)
   {
      prev = slow;
      slow = slow->next;
      if (fast->next)
      {
         fast = fast->next->next;
      }
      else
      {
         break;
      }
   }

   return prev;
}
TreeNode *sortedListToBST11(ListNode *head)
{
   if (head == nullptr)
      return nullptr;
   ListNode *prevMid = findPrevMid(head);
   if(prevMid == nullptr ) return nullptr;
   TreeNode *root  = nullptr;
   ListNode *rHead = nullptr;
   if(prevMid->next==nullptr){
      root = new TreeNode(prevMid->val);
      return root;
   }

   if(prevMid->next->next ==nullptr){
      root = new TreeNode(prevMid->val);
      head = nullptr;
      rHead = prevMid->next;
   }
   else{
      root = new TreeNode(prevMid->next->val);
      rHead = prevMid->next->next;
      prevMid->next->next=nullptr;
      prevMid->next =nullptr;
   }

   root->left  = sortedListToBST11(head);
   root->right = sortedListToBST11(rHead);
   return root;
}
TreeNode *sortedListToBST(ListNode *head)
{
   if (head == nullptr)
      return nullptr;
   ListNode *slow = head, *fast = head, *prev = nullptr;
   while (fast && fast->next)
   {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
   }
   ListNode *rhead = slow->next;
   slow->next = nullptr;
   if (prev)
      prev->next = nullptr;
   if (slow == head)
      head = nullptr;
   TreeNode *root = new TreeNode(slow->val);
   root->left = sortedListToBST(head);
   root->right = sortedListToBST(rhead);
   return root;
}
//[leetcode 108](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/) : Convert Sorted Array to Binary Search Tree
TreeNode *sortedArrayToBST(std::vector<int> &nums, int ll, int rr)
{
   if (ll > rr)
      return nullptr;
   if (ll == rr)
      return (new TreeNode(nums[ll]));
   int mid = (ll + rr+1) / 2;
   TreeNode *root = new TreeNode(nums[mid]);
   root->left = sortedArrayToBST(nums, ll, mid - 1);
   root->right = sortedArrayToBST(nums, mid + 1, rr);

   return root;
}
//[leetcode 2196](https://leetcode.com/problems/create-binary-tree-from-descriptions/description/) : Create Binary Tree From Descriptions 
TreeNode *createBinaryTreeFromDescription(std::vector<std::vector<int>> &&descriptions)
{
   std::unordered_map<int, std::pair<TreeNode *, bool>> umap; // bool == true mean child.

   for (const auto &ee : descriptions)
   {
      TreeNode *par = nullptr;
      TreeNode *chi = nullptr;
      auto itPar = umap.find(ee[0]);
      if (itPar == umap.end())
      {
         par = new TreeNode(ee[0]);
         umap[ee[0]] = {par, false};
      }
      else
      {
         par = umap[ee[0]].first;
      }

      auto itChi = umap.find(ee[1]);
      if (itChi == umap.end())
      {
         chi = new TreeNode(ee[1]);
         umap[ee[1]] = {chi, true};
      }
      else
      {
         chi = umap[ee[1]].first;
         umap[ee[1]].second = true;
      }
      if (ee[2] == 1)
      {
         par->left = chi;
      }
      else
      {
         par->right = chi;
      }
   }
   for (const auto &ee : umap)
   {
      if (!ee.second.second)
      {
         return ee.second.first;
      }
   }
   return nullptr;
}
//[leetcode 199](https://leetcode.com/problems/binary-tree-right-side-view/description/) : binary tree right side view.
void rightSideView(TreeNode *root, std::vector<int> &ans, int hh)
{
   if (root == nullptr)
      return;

   hh++;
   if (ans.size() < hh)
      ans.push_back(root->val);
   rightSideView(root->right, ans, hh);
   rightSideView(root->left, ans, hh);
}
std::vector<int> rightSideView(TreeNode *root)
{
   std::vector<int> ans;
   int hh = 0;
   rightSideView(root, ans, hh);
   return ans;
}
// find node in a BST tree. 

TreeNode *findNode(TreeNode *root, int key, TreeNode *&par)
{
   if (root == nullptr)
      return nullptr;
   if (root->val == key)
   {
      return root;
   }
   par = root;
   if (key < root->val)
   {
      return findNode(root->left, key, par);
   }
   else
   {
      return findNode(root->right, key, par);
   }
}
//[leetcode 450](https://leetcode.com/problems/delete-node-in-a-bst/description/) : delete a node in a binary search tree
// can be used to delete node in binary tree and maintain inorder tranversal. 
TreeNode *deleteNode(TreeNode *root, int key)
{
   if (root == nullptr)
      return root;
   TreeNode *par = root;
   TreeNode *node = findNode(root, key, par);
   if (node == nullptr)
      return root;
   if (node == par && !par->left && !par->right)
   {
      return nullptr;
   }

   if (node->left)
   {
      auto prev = node;
      auto cur = node->left;
      while (cur->right)
      {
         prev = cur;
         cur = cur->right;
      }
      node->val = cur->val;
      if (prev == node)
      {
         prev->left = cur->left;
      }
      else
      {
         prev->right = cur->left;
      }
      delete cur;
   }
   else if (node->right)
   {
      auto prev = node;
      auto cur = node->right;
      while (cur->left)
      {
         prev = cur;
         cur = cur->left;
      }
      node->val = cur->val;
      if (prev == node)
      {
         prev->right = cur->right;
      }
      else
      {
         prev->left = cur->right;
      }
      delete cur;
   }
   else
   {
      if (par->right && par->right->val == node->val)
      {
         par->right = nullptr;
      }
      else
      {
         par->left = nullptr;
      }
      delete node;
   }

   return root;
}



void pruneTree11(TreeNode *root, TreeNode *par, bool ll)
{
   if (root == nullptr)
      return;
   pruneTree11(root->left, root, true);
   pruneTree11(root->right, root, false);

   if (root->val == 0 && root->left == nullptr && root->right == nullptr)
   {
      if (ll)
      {
         par->left = nullptr;
      }
      else
      {
         par->right = nullptr;
      }

      delete root;
      return;
   }
}
//[leetcode 1325](https://leetcode.com/problems/delete-leaves-with-a-given-value/description/) : Delete Leaves With a Given Value
TreeNode *pruneTree(TreeNode *root)
{
   if (root == nullptr )
      return nullptr;
   root->left  = pruneTree(root->left);
   root->right = pruneTree(root->right);
   if(!root->left && !root->right && root->val ==0){
      return nullptr;
   }
   return root;
}
TreeNode *removeLeafNodes(TreeNode *root, int target)
{
   if (root == nullptr)
      return root;
   root->left = removeLeafNodes(root->left, target);
   root->right = removeLeafNodes(root->right, target);
   if (!root->left && !root->right && root->val == target)
   {
      delete root;
      root = nullptr;
      return nullptr;
   }
   return root;
}
//[leetcode 542](https://leetcode.com/problems/diameter-of-binary-tree/description/) : diameter of a binary tree
int diameterOfBinaryTree(TreeNode *root, int &maxD)
{
   if (root == nullptr)
      return -1;
   int ll = diameterOfBinaryTree(root->left, maxD) + 1;
   int rr = diameterOfBinaryTree(root->right, maxD) + 1;
   maxD = std::max(ll + rr, maxD);
   return std::max(ll, rr);
}
int diameterOfBinaryTree(TreeNode *root)
{
   int maxD = -1;
   diameterOfBinaryTree(root, maxD);
   return maxD;
}

bool isValidSerialization(std::string preorder)
{
   const int sz = preorder.size();
   if(sz==0) return true;
   return false;
   
}
int countNode(TreeNode *root)
{
   if (root == nullptr)
      return 0;
   return countNode(root->left) + countNode(root->right) + 1;
}

// Encodes a tree to a single string.
std::vector<int> serialize(TreeNode *root)
{
   if (root == nullptr)
      return std::vector<int>{};
   const unsigned int ll = 1  << 12;
   const unsigned int rr = ll << 1;
   std::vector<int> res;
   res.resize(countNode(root));

   std::queue<TreeNode *> myQ;
   myQ.push(root);
   int count = 0;
   int val;
   while (!myQ.empty())
   {
      const int sz = myQ.size();
      for (int ii = 0; ii < sz; ++ii)
      {
         auto cur = myQ.front();
         myQ.pop();
         val = cur->val;
         if (cur->left)
         {
            myQ.push(cur->left);
            val |= ll;
         }
         if (cur->right)
         {
            myQ.push(cur->right);
            val |= rr;
         }
         res[count] =val;
         count ++;
      }
   }
   return res;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(std::vector<int> data)
{
   if (data.size() == 0)
      return nullptr;
   unsigned int ll = 1  << 12;
   unsigned int rr = ll << 1;
   std::queue<TreeNode *> myQ;
   const int sz = data.size();
   int val=data[0];
   TreeNode *root = new TreeNode(val);
   myQ.push(root);
   int count = 1;
   while (count < sz)
   {
      const int szz = myQ.size();
      for (int ii = 0; ii < szz; ++ii)
      {
         auto cur = myQ.front();
         myQ.pop();
         val = cur->val;
         if (val & ll)
         {
            val &= ~ll;
            int tmp=data[count];
            TreeNode *newnode = new TreeNode(tmp);
            cur->left = newnode;
            myQ.push(newnode);
            count ++;
         }
         if (val & rr)
         {
            val &= ~rr;
            int tmp=data[count];
            TreeNode *newnode = new TreeNode(tmp);
            cur->right = newnode;
            myQ.push(newnode);
            count ++;
         }
         cur->val = val;
      }
   }

   return root;
}
std::string serializeStr(TreeNode *root){
  if(root==nullptr) return "#";
  return std::to_string(root->val)+" "+serializeStr(root->left)+" "+serializeStr(root->right);
//   return !root ? " null" : " " + std::to_string(root->val) + serializeStr(root->left) + serializeStr(root->right);
}
TreeNode *deserializeStr(std::istringstream  &ss){
   std::string str1;
   ss>>str1;
   if(str1=="#")
      return nullptr;
   TreeNode *root = new TreeNode(std::stoi(str1));
   root->left  = deserializeStr(ss);
   root->right = deserializeStr(ss);
   return root;
}
TreeNode *deserializeStr(std::string &str){
   if(str.size()<3) return nullptr;
   std::istringstream ss(str);

   return deserializeStr(ss);
}
    // Encodes a tree to a single string.
void serializeStrSHRT(TreeNode *root, std::string &str)
{
   short int val;
   if (root == nullptr)
   {
      val = SHRT_MAX;
      str.append(reinterpret_cast<char *>(&val), sizeof(val));
      return;
   }
   val = root->val;
   str.append(reinterpret_cast<char *>(&val), sizeof(val));
   serializeStrSHRT(root->left, str);
   serializeStrSHRT(root->right, str);
   return;
}
std::string serializeStrSHRT(TreeNode *root)
{
   std::string str;
   serializeStrSHRT(root, str);
   return str;
}
TreeNode *deserializeStrSHRT(std::istringstream &ss)
{
   short int val;
   ss.read(reinterpret_cast<char *>(&val), sizeof(val));
   if (val == SHRT_MAX)
      return nullptr;
   TreeNode *root = new TreeNode(val);
   root->left = deserializeStrSHRT(ss);
   root->right = deserializeStrSHRT(ss);
   return root;
}
    // Decodes your encoded data to tree.
TreeNode *deserializeStrSHRT(std::string data)
{
   if (data.size() < 3)
      return nullptr;
   std::istringstream ss(data);
   return deserializeStrSHRT(ss);
}
//[leetcode 1008](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/) : build BST tree using preorder tranversal
TreeNode *bstFromPreorder(const std::vector<int> &preorder, int minVal, int maxVal, int &pidx)
{
   if (pidx == preorder.size())
      return nullptr;
   const int val = preorder[pidx++];
   if (val > maxVal || val < minVal)
   {
      --pidx;
      return nullptr;
   }

   TreeNode *root = new TreeNode(val);
   root->left = bstFromPreorder(preorder, minVal, val, pidx);
   root->right = bstFromPreorder(preorder, val, maxVal, pidx);

   return root;
}
TreeNode *bstFromPreorder(std::vector<int> &preorder)
{
   if (preorder.size() == 0)
      return nullptr;
   int minVal = INT_MIN, maxVal = INT_MAX;
   int pidx = 0;
   return bstFromPreorder(preorder, minVal, maxVal, pidx);
}
/***END END END END END END END *****************************************************/
/*                                                                                  */
/* Path from the root to a leaf                                                     */
/*                                                                                  */
/************************************************************************************/
 int main(){

   std::vector<int> vec00={5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,INT_MAX,1}; // level order
   auto root00 = buildBTUsingLevelOrder(vec00);
   printBTLevelOrder(root00);
   std::cout<<"Zig-zag level tranversal : "<<std::endl;
   std::cout<<zigZagLevelTranversal(root00)<<std::endl;
   std::cout<<"Diameter of a tree: "<<diameterOfBinaryTree(root00)<<std::endl;

   int targetSum = 22;
   std::vector<int> vecOrg={5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,INT_MAX,1}; // level order
   auto root = buildBTUsingLevelOrder(vecOrg);
   printBTLevelOrder(root);
   std::cout<<hasPathSum(root, targetSum)<<std::endl;

   std::vector<int> vecPaths={5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,5,1};
   auto root1 = buildBTUsingLevelOrder(vecPaths);
   printBTLevelOrder(root1);
   auto paths = pathSum(root1, targetSum);
   std::cout<<paths<<std::endl;
   std::cout<< pathSumByRef(root1, targetSum)<<std::endl;

   std::vector<int> vecDW = {8,5,-3,3,2,INT_MAX,11,8,-2,INT_MAX,1};
   auto root2 = buildBTUsingLevelOrder(vecDW);

   printBTLevelOrder(root2);

   std::cout<<numDownWardPathsSum(root2, 8)<<std::endl;

   std::cout<<maxPathSum(root2)<<std::endl;
   
   std::vector<int> vecLCA ={3,5,1,6,2,0,8,INT_MAX,INT_MAX,7,4};
   auto rootLCA = buildBTUsingLevelOrder(vecLCA);
   std::cout<<lowestCommonAncestor(rootLCA, 5, 1)->val<<std::endl;

   //std::vector<int> vecLUP{5, 4, 5, 1, 1, INT_MAX, 5};
   std::vector<int> vecLUP{1, 4, 5, 4, 4, INT_MAX, 5};
   auto rootLUP = buildBTUsingLevelOrder(vecLUP);
   std::cout<<lengthLongestUnivaluePath(rootLUP)<<std::endl;

   std::vector<int> vecCorrectBST{2,3,1};
   auto rootCBST=buildBTUsingLevelOrder(vecCorrectBST);
   printBTLevelOrder(rootCBST);
   correctBST(rootCBST);
   printBTLevelOrder(rootCBST);


   std::vector<int> vecCorrectBST1{3,1, 2};
   auto rootCBST1=buildBTUsingLevelOrder(vecCorrectBST1);
   printBTLevelOrder(rootCBST1);
   correctBST(rootCBST1);
   printBTLevelOrder(rootCBST1);

   std::vector<int> vecSumDeepestLeaves{1,2,3,4,5,INT_MAX,6,7,INT_MAX,INT_MAX,INT_MAX, INT_MAX,8};
   auto rootSDL = buildBTUsingLevelOrder(vecSumDeepestLeaves);
   std::cout<<"deepestLeavesSumBFS= "<<deepestLeavesSumBFS(rootSDL)<<std::endl;
   std::cout<<"deepestLeavesSumDFS= "<<deepestLeavesSumDFS(rootSDL)<<std::endl;
   std::cout<<"rootToLeafSum=       "<<sumNumbers(rootSDL)<<std::endl;
   
   std::vector<int> vecVertTrvsl{3,9,20,INT_MAX,INT_MAX,15,7};
   auto rootVTrsl=buildBTUsingLevelOrder(vecVertTrvsl);
   std::cout<<verticalTraversalMap(rootVTrsl)<<std::endl;

   std::vector<int> vecTree1{3,4,5,1,2};
   std::vector<int> vecTree2{4,1,2};
   auto r1 = buildBTUsingLevelOrder(vecTree1);
   auto r2 = buildBTUsingLevelOrder(vecTree2);
   printBTLevelOrder(r1);
   printBTLevelOrder(r2);
   std::cout << std::boolalpha;   
   std::cout<<isSubtree(r1, r2)<<std::endl;

   std::vector<int> vecFreqSum{5,2,-3};
   auto rFreqSum = buildBTUsingLevelOrder(vecFreqSum);
   std::cout<<findFrequentTreeSum(rFreqSum)<<std::endl;

   std::vector<int> vecKth{3,1,4,INT_MAX,2};
   auto rKth = buildBTUsingLevelOrder(vecKth);
   std::cout<<"aa="<<kthSmallest(rKth, 1)<<std::endl;

   std::vector<int> vecSucc{20,8,22,4,12, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 10, 14};
   auto rSucc = buildBTUsingLevelOrder(vecSucc);
   printBTLevelOrder(rSucc);
   int curInt = 14;
   auto nd11 = inorderSuccessorBST(rSucc,curInt );
   if(nd11) std::cout<<curInt<<" BST successor is "<<nd11->val<<std::endl;

   nd11 = inorderPredecessorBST(rSucc,14 );
   if(nd11) std::cout<<curInt<<" BST predecessor is "<<nd11->val<<std::endl;

   curInt = 14;
   nd11 = inorderSuccessor(rSucc,curInt );
   if(nd11) std::cout<<curInt<<"  successor is "<<nd11->val<<std::endl;

   std::vector<int>vecCpltTree{1,2,3,4,5,6, INT_MAX};
   std::cout<<"Number of Nodes of the Complete tree is: "<<countNodesCompleteTree(buildBTUsingLevelOrder(vecCpltTree))<<std::endl;
   
   ListNode* head1 = buildLinkedList({-10,-3,0,5,9});
   printLinkedList(head1);
   printBTLevelOrder(sortedListToBST(head1));

   std::vector<int> vec2BST{-10,-3,0,5,9};
   printBTLevelOrder(sortedArrayToBST(vec2BST, 0, vec2BST.size()-1));


   printBTLevelOrder(createBinaryTreeFromDescription({{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}}));
   auto rRSW = buildBTUsingLevelOrder({1,2,3,INT_MAX,5,INT_MAX,4});
   std::cout<<rightSideView(rRSW)<<std::endl;
   
   std::vector<int> vecAA{20,8,22,4,12, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 10, 14};
   auto rAA = buildBTUsingLevelOrder(vecAA);
   printBTLevelOrder(deleteNode(rAA, 4));

   auto rAA2 = buildBTUsingLevelOrder(vecAA);
   printBTLevelOrder(deleteNode(rAA2, 22));

   auto rIter = buildBTUsingLevelOrder(vecAA);
   
   std::vector<int> vecPT{0,INT_MAX,0,0,0};
   auto rPT = buildBTUsingLevelOrder(vecPT);
   printBTLevelOrder(pruneTree(rPT));

   

   std::vector<int> vecRmLeaves{1,1,1};
   auto rRmL = buildBTUsingLevelOrder(vecRmLeaves);
   printBTLevelOrder(removeLeafNodes(rRmL, 1));


   std::vector<int> vec01{1,2,3,INT_MAX,INT_MAX,4,5};
   auto rt01 = buildBTUsingLevelOrder(vec01);
   std::cout<<"serialize tree"<<std::endl;
   printBTLevelOrder(rt01);
   auto vecInt1 = serialize(rt01);
   auto rt011=deserialize(vecInt1);
   printBTLevelOrder(rt011);

   auto str2=serializeStr(rt01);
   std::cout<<"serialized to string: "<<str2<<std::endl;
   printBTLevelOrder(deserializeStr(str2));
   str2=serializeStrSHRT(rt01);
//   std::cout<<"serialized to string: "<<str2<<std::endl;
   printBTLevelOrder(deserializeStrSHRT(str2));
//   nd11 = inorderPredecessorBST(rSucc,14 );
//   if(nd11) std::cout<<curInt<<"  predecessor is "<<nd11->val<<std::endl;

   std::vector<int> vec02{8,5,10,1,7,INT_MAX,12};
   auto rt02 = buildBTUsingLevelOrder(vec02);
   std::vector<int> preorderVec;
   preorderTrvsl(rt02, preorderVec);
   std::cout<<"preorderVec"<<preorderVec<<std::endl;
   printBTLevelOrder(bstFromPreorder(preorderVec));

  std::string bstr0, bstr1;
  bstr0.resize(12);
  
  int ii1=124, ii2=8956, ii3=13456;
  memcpy(bstr0.data(),&ii1,sizeof(int));
  memcpy(bstr0.data()+sizeof(int),&ii2,sizeof(int));
  memcpy(bstr0.data()+2*sizeof(int),&ii3,sizeof(int));
  bstr1.append(reinterpret_cast<char *>(&ii1),sizeof(int));
  bstr1.append(reinterpret_cast<char *>(&ii2),sizeof(int));
  bstr1.append(reinterpret_cast<char *>(&ii3),sizeof(int));
  std::cout<<bstr0.size()<<"    "<<bstr1.size()<<std::endl;
  std::cout<<sizeof(char)<<"   "<<sizeof(int)<<std::endl;

  int val =*reinterpret_cast<const int*>(bstr1.data());
  int tmp;
  memcpy(&tmp, bstr0.data(),sizeof(int));
  memcpy(&tmp, bstr0.data()+sizeof(int),sizeof(int));
  memcpy(&tmp, bstr0.data()+2*sizeof(int),sizeof(int));
  std::istringstream ss01(bstr1);
  ss01.read(reinterpret_cast< char *>(&tmp), sizeof(int));
  ss01.read(reinterpret_cast< char *>(&tmp), sizeof(int));
  ss01.read(reinterpret_cast< char *>(&tmp), sizeof(int));
 }


