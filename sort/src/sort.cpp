#include<iostream>
#include<vector>


// Sorting in ascending order


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

template <typename T >
int selectionSort(std::vector<T> &vec){
   const int size = vec.size();
   int count = 0;
   int cmp_count = 0;

   for(int ii = 0; ii < size-1; ++ii){
      T minVal= vec[ii];
      int minIndex = ii;
      for(int jj = ii+1; jj< size; ++jj)
      {
         if(vec[jj]<=minVal){
            minVal = vec[jj];
            minIndex = jj;
         }
         cmp_count ++;
      }
      if(minIndex != ii)
      {
         swap(vec[ii], vec[minIndex]);
         count ++;
      }
   }
   std::cout << "comparison count == " << cmp_count << std::endl;
   std::cout << "swap       count == " << count << std::endl;
   return count+cmp_count;
}

template <typename T>
int insertionSort(std::vector<T> &vec){
   int size = vec.size();
   int count =0;
   int cmp_count = 0;

   for(int ii = 0; ii < size-1; ++ii){
      for(int jj = ii + 1 ; jj >=0 ; --jj){
         cmp_count++;
         if(vec[jj]<vec[jj-1]){
            swap(vec[jj-1], vec[jj]);
            count ++;
         }
         else{
            break;
         }

      }
   }
   std::cout << "comparison count == " << cmp_count << std::endl;
   std::cout << "swap       count == " << count << std::endl;
   return count+cmp_count;
}

template <typename T>
int bubbleSort(std::vector<T> & vec){
   int sz = vec.size();
   int count =0;
   int cmp_count =0;
   for(int ii = 0; ii < sz; ii ++){
      bool swapFlag=false;
      int inner_count=0;
      for(int jj= 0; jj< sz-ii -1; jj++){
         if(vec[jj+1]<vec[jj]){
            swap(vec[jj+1], vec[jj]);
            count ++;
            swapFlag = true;
         }
         cmp_count++;
      }
      if(!swapFlag) break;

   }
   std::cout << "comparison count == " << cmp_count << std::endl;
   std::cout << "swap       count == " << count << std::endl;
   return count+cmp_count;
}
template <typename T>
void mergeMS(const std::vector<T> &vecLeft, const std::vector<T> &vecRight, std::vector<T> &vec)
{
   const int szLeft  = vecLeft.size();
   const int szRight = vecRight.size();

   int count = 0;
   int idxLeft=0;
   int idxRight=0;

   while(idxLeft<szLeft && idxRight<szRight){
      if(vecLeft[idxLeft]<=vecRight[idxRight]){
         vec[count++]=vecLeft[idxLeft++];
      }
      else{
         vec[count++]=vecRight[idxRight++];
      }
   }
   while(idxLeft<szLeft){
      vec[count++]=vecLeft[idxLeft++];
   }
   while(idxRight<szRight){
      vec[count++]=vecRight[idxRight++];
   }

}
template <typename T>
void mergeSort(std::vector<T> &vec ){

   const int sz = vec.size();
   if(sz == 1)
      return;
   const int mid = sz/2;
   
   std::vector<T> leftVec (vec.begin(), vec.begin()+mid);
   std::vector<T> rightVec(vec.begin()+mid, vec.end());
   mergeSort(leftVec);
   mergeSort(rightVec);
   mergeMS(leftVec, rightVec, vec);
}
template <typename T>
int partitionQS(std::vector<T> &vec, const int start, const int end){
   const T pivot = vec[end];
   int idxLeft = start;
   int idxRight = end-1;
   while (idxLeft<=idxRight){
      if(vec[idxLeft]<=pivot){
         idxLeft++; 
      }
      else{
         swap(vec[idxLeft],vec[idxRight]);
         idxRight--;
      }
   }

   swap(vec[idxLeft], vec[end]);
   return idxLeft;

}
template <typename T>
void quickSort(std::vector<T> &vec, const int start, const int end){
   if( start >=end ) return;
   int mid = partitionQS(vec, start, end);
   quickSort(vec, start, mid-1);
   quickSort(vec, mid+1, end);

   return;
}



template <typename T>
void quickSort(std::vector<T> &vec){
   quickSort(vec, 0, vec.size()-1);
}

/*
counting sort: assuming array less than 100; using direct access array, i.e., the value of kk in array AA must be stored at the address of AA+kk
*/

template <typename T, typename = typename std::enable_if<std::is_unsigned<T>::value>::type >
std::vector<T> countingSort(const std::vector<T> &vec){

   const int sz = vec.size();
   std::vector<T> result=std::vector<T>(sz, 0);
// maxVal used to decide the size of direct access array's size.   
   T maxVal=vec[0];
   for(int ii = 1; ii < sz; ++ii){
      if(vec[ii]>maxVal)maxVal = vec[ii];
   }
   maxVal ++;
   std::vector<T> dAArrays = std::vector<T>(maxVal);
   for(int ii = 0; ii < sz; ++ii){
      dAArrays[vec[ii]] ++;
   }
   for(int ii = 0; ii < maxVal-1; ++ii){
      dAArrays[ii+1] += dAArrays[ii];
   }

   for(int ii = sz-1; ii >=0; --ii){
      result[--dAArrays[vec[ii]]] = vec[ii];
   }

   return result;
   
}

/*
radix sort
*/

template <typename T, typename = typename std::enable_if<std::is_unsigned<T>::value>::type >
void radixSort(std::vector<T> &vec, int exp){
   const int sz = vec.size();
   std::vector<int> idx(sz,0);
   std::vector<T> result(sz,0);
   const int base = 10;
   std::vector<int> dAArrays(base,0);
// maxVal decides the sweeps of the counting sort.    
   for(int ii = 0; ii < sz; ++ii){
      idx [ii] = (vec[ii]/exp)%base; 
      dAArrays[ idx[ii] ] ++;
   }
   for(int ii = 0; ii < base-1; ++ii){ // e.g., base = 10. i.e., 0-9, so ii here will be 0- 8;
      dAArrays[ii+1] += dAArrays[ii];
   }

   for(int ii = sz-1; ii >= 0; --ii){
      result[--dAArrays[idx[ii]]] = vec[ii];
   }
   vec=result;

}
template <typename T, typename = typename std::enable_if<std::is_unsigned<T>::value>::type >
void radixSort(std::vector<T> &vec){
   int sz = vec.size();
// maxVal decides the sweeps of the counting sort.    
   T maxVal = vec[0];
   for(int ii = 1; ii < sz; ++ii){
      if(vec[ii]>maxVal)maxVal = vec[ii];
   }

   for(int exp = 1; maxVal/exp>0; exp *=10){
      radixSort(vec, exp);
   }

}
/*
template <typename T>
void mergeSort(std::vector<T> vec){

     mergeSort(vec, 0, vec.size() );
}
*/

int main(){

   std::vector<int> vec_org{4, 3, 1, 8, 2, 6, 18, 12, 7};
//   std::vector<int> vec_org{1,  2,  3,  4,  6,  7,  8,  12,  18};
//   std::vector<int> vec_org{18,   12,   8,   7,   6,   4,   3,   2,   1};
   std::cout<<vec_org<<std::endl;
   std::cout<<"selection sort\n";
   std::vector<int> vec_sl = vec_org;
   selectionSort(vec_sl);
   std::cout<<vec_sl<<std::endl;

   std::cout << "insertion sort\n";
   std::vector<int> vec_in = vec_org;
   insertionSort(vec_in);
   std::cout<<vec_in<<std::endl;

   std::cout << "bubble sort\n";
   std::vector<int> vec_bb = vec_org;
   bubbleSort(vec_bb);
   std::cout<<vec_bb<<std::endl;

   std::cout << "merge sort\n";
   std::vector<int> vec_mg = vec_org;
   mergeSort(vec_mg);
   std::cout<<vec_mg<<std::endl;


   std::cout << "quick sort\n";
   std::vector<int> vec_qs = vec_org;
   quickSort(vec_qs);
   std::cout<<vec_qs<<std::endl;

   std::cout << "counting sort\n";
   std::vector< unsigned > vec_unsigned ={3, 4, 1, 3, 5, 4, 8 };
   std::cout<<vec_unsigned<<std::endl;
   std::cout<<countingSort(vec_unsigned);

   std::cout << "radix sort\n";
   std::vector< unsigned > vec_rs = { 170, 45, 75, 90, 802, 24, 2, 66 };
   std::cout<<vec_rs<<std::endl;
   radixSort(vec_rs);
   std::cout<<vec_rs<<std::endl;


   return 0;
}
