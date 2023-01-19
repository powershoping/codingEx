#include<iostream>
#include<vector>
#include<functional>

//heap               
//   idxLeft  = 2*idxParent+1
//   idxRight = 2*idxParent+2
//   idxParent = (idxChild-1)/2
//                 a(0)
//              /       \
//         (1) b         c (2)
//           /   \      /   \
//      (3) d  (4)e  (5)f     g(6)
//        /   \   / 
//     (7)h (8)i j(9) 

// The last index node in the heap must be a leaf, i.e., vec[N-1] is a leaf, where N is the size of the vector. 
//  So its parent must be the last node which has at least a child. Here [9-1]/2 =4, so the vec[4] is the node. Therefore, there
//  are 9-4=5 leaves. 

template<typename T>
std::ostream &operator <<(std::ostream &out, const std::vector<T> vec){
   int ii;
    for( ii =0; ii<vec.size()-1; ii++)
       out << vec[ii] << ",  ";
    out << vec[ii] << std::endl;
    return out;
}

template <typename T>
void swap( T &a1, T &a2)
{
   T tmp = a1;
   a1 = a2;
   a2 = tmp;
}

template<typename T>
bool greater(const T t1, const T t2){
   return t1>t2;
}

template<typename T>
bool smaller(const T t1, const T t2){
   return t1<t2;
}

template <typename T>
void heapfyUp(std::vector<T> &heapVec, const int rootIdx, bool (*compFun)(const T, const T)){
//void heapfyUp(std::vector<T> &heapVec, const int rootIdx, std::function<bool (const T, const T)> compFun){ //not working for std::less and above comp functions
//template <typename T, typename CompType>
//void heapfyUp(std::vector<T> &heapVec, const int rootIdx, CompType compFun){
   const int sz = heapVec.size();
   const int leftIdx  = rootIdx*2+1;
   const int rightIdx = rootIdx*2+2;
   int   extremeIdx = rootIdx;

   if(leftIdx<sz && compFun(heapVec[leftIdx], heapVec[extremeIdx]) ){
      extremeIdx = leftIdx;
   }
   if(rightIdx<sz && compFun(heapVec[rightIdx], heapVec[extremeIdx])){
      extremeIdx = rightIdx;
   }
   if(extremeIdx != rootIdx){
      swap(heapVec[rootIdx], heapVec[extremeIdx]);
      heapfyUp(heapVec, extremeIdx, compFun);
   }

 return;
}
template <typename T>
void buildHeap(std::vector<T> &heapVec, bool (*compFun)(const T, const T)){
//void buildHeap(std::vector<T> &heapVec, std::function< bool (const T, const T)> compFun){ //not working for std::less and above comp functions
//template <typename T, typename CompType>
//void buildHeap(std::vector<T> &heapVec, CompType compFun){ //works for std::less, functor
   const int sz = heapVec.size();

   //the index of the node which has sz-1 as it's child. The nodes with index less than startIdx all have children. 
   // only the node might violate the heap rules. 
   const int startIdx = (sz)/2; //the index of the node which has sz-1 as it's child. The nodes with index less than startIdx all have children. 

   for(int ii = startIdx; ii>=0; --ii )
   {
      heapfyUp(heapVec, ii, compFun);
   }

   return;
}
template <typename T> 
bool isHeap( const std::vector<T> &heapVec, const size_t rootIdx,  bool (*compFun)(const T, const T) ){
   const size_t sz = heapVec.size();
   const size_t leftIdx  = rootIdx*2 + 1;
   const size_t rightIdx = rootIdx*2 + 2;
         size_t extremeIdx = rootIdx;
   if(leftIdx<sz && compFun(heapVec[leftIdx], heapVec[extremeIdx])){
      return false;
   }
   if(rightIdx<sz && compFun(heapVec[rightIdx], heapVec[extremeIdx])){
       return false;
   }
   return true;

}
template <typename T> 
bool isHeap( const std::vector<T> &heapVec, bool (*compFun)(const T, const T) ){
   const size_t sz = heapVec.size();
   if(sz<2)return true;
   const size_t idxMaxHaveChild = (sz)/2;
   for(int ii = idxMaxHaveChild; ii>=0; --ii)
   {
      if(!isHeap(heapVec, ii, compFun))
         return false;
   }
   return true;
}

int main(){

   std::vector<int> vecOrg{4, 3, 1, 8, 2, 6, 18, 12, 7};
   std::cout<<vecOrg<<std::endl;
   std::cout<<"isHeap "<<isHeap(vecOrg, smaller)<<std::endl;
   std::vector<int> maxHeap(vecOrg);
   buildHeap(maxHeap, greater);
   std::cout<<maxHeap<<std::endl;
   std::cout<<"is min Heap "<<isHeap(maxHeap, smaller)<<std::endl;
   std::cout<<"is max Heap "<<isHeap(maxHeap, greater)<<std::endl;

   std::vector<int> minHeap(vecOrg);
   buildHeap(minHeap, smaller);
   std::cout<<minHeap<<std::endl;

//   std::vector<int> minStdHeap(vecOrg);
//   buildHeap(minStdHeap, std::less<int>());
//   std::cout<<minStdHeap<<std::endl;

   return 0;
}
