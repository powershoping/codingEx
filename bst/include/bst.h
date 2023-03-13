#ifndef  BINARY_SEARCH_TREE_H_
#define  BINARY_SEARCH_TREE_H_
 
#include<unordered_map>
#include<vector>

template<typename T>
class BST
{

   public:

// member data    
      static int DefaultHeight;
      T data;
      BST* left;
      BST* right;
      int height;
      T sum;
//      node* parent;

// constructors
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
  compute level order of a tree with root=node
*/  
      void levelOrder(BST<T>* node, std::vector<std::vector<T>> &vec);  
      
/**
  compute current level order of a tree with root=node
*/  
      void currentLevelOrder(BST<T>* node, int level, std::vector<T> &vec);  
/**
  compute level order of a tree with root=node using queue
*/  
      void levelOrderUsingQueue(BST<T>* node, std::vector<std::vector<T>> &vec);
/**
  print level order of a tree with root=node
*/  
      void printLevelOrder(BST<T>* node);  
/**
  print level order of a tree with root=node
*/  
      void printCurrentLevelOrder(BST<T>* node, int level);  
      
/**
  print level order of a tree with root=node using queue
*/  
      void printLevelOrderUsingQueue(BST<T>* node);

/**
  compute all the leaves of a tree 
*/
      void leaves(BST<T> *node, std::vector<T> &vec);

 /**
   search the tree with root=node for data=dd
*/
      BST<T> *search(BST<T> *node, T dd);
      BST<T> *search(BST<T> *node, T dd, BST<T>* &par);

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


/**
 * @brief sum of all the leaves
 * 
 */
      T sumLeaves(BST<T> *root);

/**
 * @brief sum of all the left leaves
 * 
 */
      T sumLeftLeaves(BST<T> *root);

/**
 * @brief sum of all leaves
 * 
 */
      T sumRightLeaves(BST<T> *root);

/**
 * @brief sum of all children and itself and stored into the parent/root.
 * 
 */
      T sumTree(BST<T> *root);


/**
 * @brief flatten the tree to a single linked list 
 * 
 */
      BST<T> *flatten(BST<T> *root);


/**
 * @brief compare two trees. identical = true, otherwise = false; 
 * 
 */
      bool isSame(BST<T> *root1, BST<T> *root2);
      bool isSame1(BST<T> *root1, BST<T> *root2);
      











      
};      

#endif