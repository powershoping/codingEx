#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<unordered_map>


#include<iomanip>

constexpr int WIDTH_INT=4;

template<typename T>
class BST
{

   public:
      static int DefaultHeight;
      T data;
      BST* left;
      BST* right;
      int height;
//      node* parent;

/** 
  construct a empty node
*/  
      BST();

/**
  construct a node with data
*/  
      BST(T dd);

/**
  insert a data to the tree with root=node
*/
      BST<T>* insert(BST<T>* node, T dd);

/**
  compute inorder of a tree with root = node and store the order to vec.
*/  
      void inorder(BST<T>* node, std::vector<T>& vec);

/**
  compute the reverse of the inorder of a tree with root=node
*/  
      void reverseInorder(BST<T>* node, std::vector<T>& vec);

/**
  compute the preorder of a tree with root=node
*/  
      void preorder(BST<T>* node, std::vector<T>& vec);

/**
  compute the postorder of a tree with root=node
*/  
      void postorder(BST<T>* node, std::vector<T>& vec);

/**
  compute height of a tree with root=node
*/  
      int computeHeight(BST<T>* node); 

/**
  print level order of a tree with root=node
*/  
      void printLevelOrder(BST<T>* node);  
      
/**
  print current level order of a tree with root=node
*/  
      void printCurrentLevel(BST<T>* node, int level);
      
/**
  print level order of a tree with root=node using queue
*/  
      void printLevelOrderUsingQueue(BST<T>* node);

/**
  print leaves of a tree 
*/
      void printLeaves(BST<T> *node);

 /**
   search the tree with root=node for data=dd
*/
      BST<T> *search(BST<T> *node, T dd);

      BST<T>* deleteNode(BST<T>* node, T dd);

/**
Main drive function for building a binary tree using the preorder and inorder
*/
      BST<T>* buildTreeUsingPreInOrders(std::vector<T>& preorder, std::vector<T>& inorder);

/**
  recursive function for building a binary tree using the preorder and inorder and the range of the subtree.
*/
      BST<T>* buildSubTreeUsingPreInOrders(std::vector<T>& preorder,  std::vector<T>& inorder, std::unordered_map<T, int>& umap, int in_start, int in_end, int& pre_index);

      BST<T>* buildTreeUsingPostInOrders(std::vector<T>& postorder, std::vector<T>& inorder);

      BST<T>* buildSubTreeUsingPostInOrders(std::vector<T>& postorder,  std::vector<T>& inorder, std::unordered_map<T, int>& umap, int in_start, int in_end);
};

/** 
  construct a empty node
*/  
template<typename T>
BST<T>::BST()     : data(T()), left(nullptr), right(nullptr), height(-1)
{}

/**
  construct a node with data
*/  
template<typename T>
BST<T>::BST(T dd) : data(dd),  left(nullptr), right(nullptr), height(-1)
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
  compute height of a tree with root=node
*/  
template<typename T>
int BST<T>::computeHeight(BST<T>* node)  
{
   if(!node){
      return 0;
   }

   int leftH  = computeHeight(node->left);
   int rightH = computeHeight(node->right);

   if(leftH>rightH)
      node->height = leftH+1;
   else
      node->height = rightH+1;

   return node->height;
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
      printCurrentLevel(node, level);
      std::cout<<std::endl;
   }
}

/**
  print current level of a tree with root=node
*/  
template<typename T>
void BST<T>::printCurrentLevel(BST<T>* node, int level)  
{
   if(node == nullptr)
      return;
   if(level == 1)
      std::cout<<std::setw(5)<<node->data;
   else if(level > 1)
   {
      printCurrentLevel(node->left,  level-1);
      printCurrentLevel(node->right, level-1);
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
   if(saved_ht != BST<T>::DefaultHeight)
      printf("(H =%3d)",node->height);
   while(!bst_queue.empty())
   {
      auto cur_node = bst_queue.front();
      int  cur_ht = cur_node->height;
      bst_queue.pop();

      if(cur_ht != BST<T>::DefaultHeight && cur_ht != saved_ht)
         std::cout<<"\n(H ="<<std::setw(3)<<cur_ht<<")";

      std::cout<<std::setw(5)<<cur_node->data;
      saved_ht = cur_node->height;

      if(cur_node->left)
         bst_queue.push(cur_node->left);
      if(cur_node->right)
         bst_queue.push(cur_node->right);

   }

   std::cout<<std::endl;
   return;

}   

/**
  print leaves of a tree 
*/  
template<typename T>
void BST<T>::printLeaves(BST<T>* node)  
{
   if(!node)
      return;

   if(!node->left && !node->right){
      std::cout<<std::setw(5)<<node->data;
      return;
   }
   printLeaves(node->left);
   printLeaves(node->right);
}

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
   if(in_start>in_end)
      return nullptr;

   T data = preorder[pre_index];
   std::cout<<"pre_index"<<pre_index<<std::endl;
   pre_index ++;
   auto cur_node = new BST<T>(data); // here post ++ is used as pre_index is used first then increase it by 1. 
   int in_index = umap[data];

   if(in_start == in_end) 
      return cur_node;

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
/**
 * @brief 
 * Initialize the static variable of the BST class
 * @tparam T 
 */
template<typename T> int BST<T>::DefaultHeight = -1;

int main()
{
   BST<int>* root=nullptr;
   BST<int>  bst_head;//empty object, used to as a handle to access the BST methods.
   std::vector<int> vec_org{25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 99};
   //   std::vector<int> vec_org{1,2};
   //   std::vector<int> vec_org{25,15,50,10,35,70,4,12,31,44,66,99};

   std::cout<<"original order of the vector"<<std::endl;
   for(auto item : vec_org)
   {
      std::cout<<item<<"  ";
   }
   std::cout<<std::endl;

   root = bst_head.insert(root, vec_org[0]);
   for(int ii =1; ii <vec_org.size(); ++ii)
   {
      bst_head.insert(root, vec_org[ii]);
   }

   bst_head.computeHeight(root);

   std::cout<<"Level Order Using recursive method\n";
   bst_head.printLevelOrder(root);
   std::cout<<"Level Order Using Queue\n";
   bst_head.printLevelOrderUsingQueue(root);


   std::vector<int> vec_in;
   bst_head.inorder(root, vec_in);

   std::cout<<std::endl;

   std::cout<<"Inorder of the tree"<<std::endl;
   for(auto item : vec_in)
   {
      std::cout<<item<<"  ";
   }
   std::cout<<std::endl;


   std::vector<int> vec_pre;
   bst_head.preorder(root, vec_pre);

   std::cout<<"preorder of the tree"<<std::endl;
   for(auto item : vec_pre)
   {
      std::cout<<item<<"  ";
   }
   std::cout<<std::endl;


   std::vector<int> vec_post;
   bst_head.postorder(root, vec_post);

   std::cout<<"postorder of the tree"<<std::endl;
   for(auto item : vec_post)
   {
      std::cout<<item<<"  ";
   }
   std::cout<<std::endl;


   std::cout<<"Build the tree using pre and in orders"<<std::endl;

   BST<int>* root1=nullptr;
   BST<int>  bst_head1;//empty object, used to as a handle to access the BST methods.
   std::vector<int> vec_pre1={1,2};
   std::vector<int> vec_in1={2,1};
   root1 = bst_head1.buildTreeUsingPreInOrders(vec_pre1, vec_in1);
   //root1=bst_head1.buildTreeUsingPostInOrders(vec_post,vec_in);

   bst_head1.computeHeight(root1);

   std::cout<<"Level Order Using recursive method\n";
   bst_head1.printLevelOrder(root1);
   std::cout<<"Level Order Using Queue\n";
   bst_head1.printLevelOrderUsingQueue(root1);

   std::cout<<"All the leaves"<<std::endl;
   bst_head1.printLeaves(root1);
   std::cout<<std::endl;

   std::cout<<bst_head.search(root, 2)<<std::endl;
   std::cout<<bst_head.search(root, 123)<<std::endl;

}
