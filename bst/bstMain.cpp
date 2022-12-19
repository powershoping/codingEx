#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<unordered_map>

#include "bst.h"


template<typename T>
std::ostream &operator <<(std::ostream &out, const std::vector<T> vec){
    for(auto &item : vec)
       out << item << "  ";
    return out;
}

constexpr int WIDTH_INT=4;

/**
 * @brief 
 * Initialize the static variable of the BST class
 * @tparam T 
 */

int main()
{
   BST<int>* root=nullptr;
   BST<int>  bst_head;//empty object, used to as a handle to access the BST methods.
   std::vector<int> vec_org{25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 99};
   //   std::vector<int> vec_org{1,2};
   //   std::vector<int> vec_org{25,15,50,10,35,70,4,12,31,44,66,99};

   std::cout<<"original order of the vector"<<std::endl;
   std::cout<<vec_org<<std::endl;

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

   std::cout<<"Inorder of the tree"<<std::endl;
   std::cout<<vec_in<<std::endl;


   std::vector<int> vec_pre;
   bst_head.preorder(root, vec_pre);

   std::cout<<"preorder of the tree"<<std::endl;
   std::cout<<vec_pre<<std::endl;


   std::vector<int> vec_post;
   bst_head.postorder(root, vec_post);

   std::cout<<"postorder of the tree"<<std::endl;
   std::cout<<vec_post<<std::endl;


   std::cout<<"Build the tree using pre and in orders"<<std::endl;

   BST<int>* root1=nullptr;
   BST<int>  bst_head1;//empty object, used to as a handle to access the BST methods.
//   std::vector<int> vec_pre1={1,2};
//   std::vector<int> vec_in1={2,1};
//   root1 = bst_head1.buildTreeUsingPreInOrders(vec_pre1, vec_in1);
//   vec_post.push_back(123);
//   vec_in.push_back(123);
   root1=bst_head1.buildTreeUsingPostInOrders(vec_post,vec_in);

   bst_head1.computeHeight(root1);
   bst_head1.sumTree(root1);

   std::cout<<"Level Order Using recursive method\n";
   bst_head1.printLevelOrder(root1);
   std::cout<<"Level Order Using Queue\n";
   bst_head1.printLevelOrderUsingQueue(root1);

   std::vector<int> vec_leaves;
   bst_head1.leaves(root1,vec_leaves);
   std::cout<<"All the leaves"<<std::endl;
   std::cout<<vec_leaves<<std::endl;

   std::cout<<"Sum of all the leaves = "<<bst_head1.sumLeaves(root1)<<std::endl;
   std::cout<<"Sum of all the Left leaves = "<<bst_head1.sumLeftLeaves(root1)<<std::endl;
   std::cout<<"Sum of all the Right leaves = "<<bst_head1.sumRightLeaves(root1)<<std::endl;

//   bst_head1.flatten(root1);
//   bst_head1.computeHeight(root1);
   bst_head1.printLevelOrderUsingQueue(root1);
   std::cout<< bst_head1.isSame(root, root1)<<std::endl;

   std::cout<<bst_head.search(root, 2)<<std::endl;
   std::cout<<bst_head.search(root, 123)<<std::endl;

}
