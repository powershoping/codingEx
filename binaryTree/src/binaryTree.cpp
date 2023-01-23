#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>


template<typename T>
std::ostream &operator <<(std::ostream &out, const std::vector<T> vec){
   int ii;
   out<<"[";
    for( ii =0; ii<vec.size()-1; ii++)
       out << vec[ii] << ",  ";
    out << vec[ii] << "]";
    return out;
}

template<typename T>
std::ostream &operator <<(std::ostream &out, const std::vector<std::vector<T>> vec){
    for( const auto &el : vec)
       out << el << std::endl;

    return out;
}

class TreeNode{
   public: 
      int val;
      TreeNode* left;
      TreeNode* right;
   TreeNode():val(0), left(nullptr), right(nullptr){} 
   TreeNode(int data): TreeNode(){val = data;}
};


TreeNode* buildUsingLevelOrder(std::vector<int> vecOrg){

   if(vecOrg[0]==INT_MAX){
      std::cout<<"Empty binary tree or invalid binary tree\n";
      return nullptr;
   }
   TreeNode* root = new TreeNode(vecOrg[0]);
   std::queue<TreeNode*> nodeQueue;
   nodeQueue.push(root);

   for(int ii=1; ii<vecOrg.size(); ii +=2){
      auto curNode = nodeQueue.front();
      nodeQueue.pop();
      if(vecOrg[ii]==INT_MAX){
         curNode->left=nullptr;
      }
      else{
         TreeNode* newNode = new TreeNode(vecOrg[ii]);
         nodeQueue.push(newNode);
         curNode->left= newNode;
      }


      if(vecOrg[ii+1]==INT_MAX){
         curNode->right=nullptr;
      }
      else{
         TreeNode* newNode = new TreeNode(vecOrg[ii+1]);
         nodeQueue.push(newNode);
         curNode->right= newNode;
      }
   }
   return root;
}
void printLevelOrder(TreeNode* root)
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
/***END END END END END END END *****************************************************/
/*                                                                                  */
/* Path from the root to a leaf                                                     */
/*                                                                                  */
/************************************************************************************/
 int main(){

   std::vector<int> vec00={5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,INT_MAX,1}; // level order
   auto root00 = buildUsingLevelOrder(vec00);
   printLevelOrder(root00);
   std::cout<<zigZagLevelTranversal(root00)<<std::endl;

   int targetSum = 22;
   std::vector<int> vecOrg={5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,INT_MAX,1}; // level order
   auto root = buildUsingLevelOrder(vecOrg);
   printLevelOrder(root);
   std::cout<<hasPathSum(root, targetSum)<<std::endl;

   std::vector<int> vecPaths={5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,5,1};
   auto root1 = buildUsingLevelOrder(vecPaths);
   printLevelOrder(root1);
   auto paths = pathSum(root1, targetSum);
   std::cout<<paths<<std::endl;

   std::cout<< pathSumByRef(root1, targetSum)<<std::endl;

   std::vector<int> vecDW = {8,5,-3,3,2,INT_MAX,11,8,-2,INT_MAX,1};
   auto root2 = buildUsingLevelOrder(vecDW);

   printLevelOrder(root2);

   std::cout<<numDownWardPathsSum(root2, 8)<<std::endl;

   std::cout<<maxPathSum(root2)<<std::endl;
   
   std::vector<int> vecLCA ={3,5,1,6,2,0,8,INT_MAX,INT_MAX,7,4};
   auto rootLCA = buildUsingLevelOrder(vecLCA);
   std::cout<<lowestCommonAncestor(rootLCA, 5, 1)->val<<std::endl;

   //std::vector<int> vecLUP{5, 4, 5, 1, 1, INT_MAX, 5};
   std::vector<int> vecLUP{1, 4, 5, 4, 4, INT_MAX, 5};
   auto rootLUP = buildUsingLevelOrder(vecLUP);
   std::cout<<lengthLongestUnivaluePath(rootLUP)<<std::endl;

   std::vector<int> vecCorrectBST{2,3,1};
   auto rootCBST=buildUsingLevelOrder(vecCorrectBST);
   printLevelOrder(rootCBST);
   correctBST(rootCBST);
   printLevelOrder(rootCBST);


   std::vector<int> vecCorrectBST1{3,1, 2};
   auto rootCBST1=buildUsingLevelOrder(vecCorrectBST1);
   printLevelOrder(rootCBST1);
   correctBST(rootCBST1);
   printLevelOrder(rootCBST1);

   std::vector<int> vecSumDeepestLeaves{1,2,3,4,5,INT_MAX,6,7,INT_MAX,INT_MAX,INT_MAX, INT_MAX,8};
   auto rootSDL = buildUsingLevelOrder(vecSumDeepestLeaves);
   std::cout<<"deepestLeavesSumBFS= "<<deepestLeavesSumBFS(rootSDL)<<std::endl;
   std::cout<<"deepestLeavesSumDFS= "<<deepestLeavesSumDFS(rootSDL)<<std::endl;
   
   std::vector<int> vecVertTrvsl{3,9,20,INT_MAX,INT_MAX,15,7};
   auto rootVTrsl=buildUsingLevelOrder(vecVertTrvsl);
   std::cout<<verticalTraversalMap(rootVTrsl)<<std::endl;


 }


