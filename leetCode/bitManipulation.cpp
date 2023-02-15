#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
//#include <queue>
//#include <unordered_map>
//#include <set>
#include "../tools/output_tools.h"

// minimal bit flips to make start == goal.
// leetcode 2220:   https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

int minBitFlips(int start, int goal){

   int count =0;
   while (start || goal )
   {
      if ((start&1) != (goal&1) ){
         count ++;
      }
      start >>=1;
      goal  >>=1;
   }

   return count;
}



//nums is arranged as {x1, x2, x3, ..., x(n), y(n+1), y(n+2), ..., y(2n)),using higher 16 bit of x1 to store y1 
// as the range of the element is less than 10^3, i.e. less than 2^16, and the lower 16 bit for x1.
//nums.size() must be an even number.
//leetcode 1470:  https://leetcode.com/problems/shuffle-the-array/description/  
std::vector<size_t> shuffle(std::vector<size_t> &nums)
{
   constexpr size_t SIZE=16;
   if( *std::max_element(nums.begin(), nums.end())> ( ( 1<<SIZE) -1)) {
      std::cout<<__func__<<" can only deal with array elements less than 2^16 -1\n";
      exit(1);
   }
   size_t sz = nums.size();
   if(sz%2!=0){
      std::cout<<"the number of elements in the array must be a even number\n";
      exit(2);
   }
   sz = sz/2;

// make the element pair using the unused higher 16 bits.
   for (size_t ii = 0; ii < sz; ++ii)
   {
      nums[ii] = nums[ii] | (nums[sz+ii] << SIZE);
//      std::cout<<std::hex<<nums[ii]<<std::endl;
   }
   size_t bitMask = (1<<16) -1;
//   std::cout<<std::hex<<bitMask<<std::endl;
   for (int ii = sz - 1; ii >= 0; --ii)
   {
      size_t secondNum = nums[ii] >> SIZE;
      
      nums[2 * ii] = nums[ii] & bitMask;
//      nums[2 * ii + 1] =(size_t) (nums[ii] >> SIZE);
      nums[2 * ii + 1] = secondNum;
   }

   return nums;
}
// sum of two integers without using + or -. 
//leetcode 371 : https://leetcode.com/problems/sum-of-two-integers/description/
int sum(int num1, int num2)
{
   while (num2 != 0)
   {
      size_t carry = num1 & num2;
      num1 = num1 ^ num2;
      num2 = carry << 1;
   }
   return num1;
}
//divide two intergers without using / or *
// leetcode 29 :  https://leetcode.com/problems/divide-two-integers/description/
int divide_copied(int dividend, int divisor)
{
   if (dividend == divisor)
      return 1;
   bool isPositive = (dividend < 0 == divisor < 0); // if both are of same sign, answer is positive
   unsigned int a = abs(dividend);
   unsigned int b = abs(divisor);
   unsigned int ans = 0;
   while (a >= b)
   { // while dividend is greater than or equal to divisor
      short q = 0;
      while (a > (b << (q + 1)))
         q++;
      ans += (1 << q);  // add the power of 2 found to the answer
      a = a - (b << q); // reduce the dividend by divisor * power of 2 found
   }
   if (ans == (1 << 31) and isPositive) // if ans cannot be stored in signed int
      return INT_MAX;
   return isPositive ? ans : -ans;
}

//divide two intergers without using / or *
// leetcode 29 :  https://leetcode.com/problems/divide-two-integers/description/
int divide11(int dividend, int divisor)
{
   if ( dividend == INT_MIN && divisor == -1) // INT_MIN is -2^31 and divided by -1 gives 2^31 which is out bound of INT_MAX. 
      return INT_MAX;
   if (dividend == 0)
      return 0;

   unsigned int sign = 1;
   if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
      sign = -1;
      
   unsigned int ddividend = abs(dividend);
   unsigned int ddivisor = abs(divisor);

   if (ddivisor == 1)
      return sign == 1 ? ddividend : -ddividend;
   if (ddividend < ddivisor)
      return 0;

   size_t tmp = ddivisor;
   size_t res = 1;
   while (tmp <= ddividend)
   {
      tmp <<= 1;
      res <<= 1;
   }
   tmp >>= 1;
   res >>= 1;

   while (tmp <= ddividend)
   {
      tmp += ddivisor;
      res++;
   }
   res = res - 1;
   return sign == 1 ? res : -res;
}

//divide two intergers without using / or *
// leetcode 29 :  https://leetcode.com/problems/divide-two-integers/description/
int divide(int dividend, int divisor)
{
   {
      if (dividend == INT_MIN && divisor == -1) // INT_MIN is -2^31 and divided by -1 gives 2^31 which is out bound of INT_MAX.
         return INT_MAX;
      if (dividend == 0)
         return 0;

      unsigned int sign = 1;
      if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
         sign = -1;

      unsigned int ddividend = abs(dividend);
      unsigned int ddivisor = abs(divisor);

      if (ddivisor == 1)
         return sign == 1 ? ddividend : -ddividend;
      if (ddividend < ddivisor)
         return 0;

      size_t res = 0;
      while (ddividend >= ddivisor)
      {
         size_t tmp = ddivisor;
         unsigned int count = 0;
         while (tmp <= ddividend)
         {
            tmp <<= 1;
            count++;
         }
         res += 1 << (count - 1);

         ddividend = ddividend - (tmp >> 1);
      }

      return sign == 1 ? res : -res;
   }
}

//leetcode 7 : https://leetcode.com/problems/reverse-integer/description/
int reverseInt(int org_x)
{
    int rev_x = 0;
    while(org_x!=0)
    {
        int rem = org_x%10;
        org_x = org_x / 10;
        if(rev_x>INT_MAX/10 || rev_x==INT_MAX/10 && rem>7)
            return 0;
        if(rev_x<INT_MIN/10 || rev_x==INT_MIN/10 && rem<-8)
            return 0;
        rev_x = rev_x*10 + rem;
    }
    return rev_x;
}

//leetcode 190 : https://leetcode.com/problems/reverse-bits/description
uint32_t reverseBitInt(uint32_t org_x){

   uint32_t rev_x=0;
   while (org_x)
   {
      std::cout<<(org_x&1)<<std::endl;
      rev_x<<=1;
      if (org_x &1 ){
         rev_x ++;
      }
      org_x=org_x>>1;
   }

   return rev_x;
}

int singleNumber32Counters(std::vector<int> &nums, int k)
{
   {
      std::vector<int> counts(32, 0); 
      for (auto &ee : nums)
      {
         for (int ii = 0; ii < 32; ++ii)
         {
            if (ee & 1)
               counts[ii]++;
            ee >>= 1;
         }
      }
      int result = 0;
      for (int ii = 0; ii < 32; ++ii)
      {
         if (counts[ii] % k != 0)
         {
            result = result | 1 << ii;
         }
      }
      return result;
   }
}
//[leetcode 137](https://leetcode.com/problems/single-number-ii/description/) : single number, a general code
int singleNumber(std::vector<int> &nums, int kk){
   {
      int numCCs = 0;
      int kk_saved = kk;
      while (kk)
      {
         numCCs++;
         kk >>= 1;
      }
      bool maskOn = kk == 1 << numCCs ? false : true;
      std::vector<int> cc(numCCs, 0);
      int mask = 0;

      for (const auto &ee : nums)
      {
         for (int ii = numCCs - 1; ii >= 0; --ii)
         {
            int tmp = ee;
            for (int jj = 0; jj < ii; ++jj)
            {
               tmp &= cc[jj];
            }
            cc[ii] ^= tmp;
         }
         if (maskOn)
         {
            int tmp = kk_saved;
            if (tmp & 1)
            {
               mask &= cc[0];
            }
            else
            {
               mask &= ~cc[0];
            }
            tmp >>= 1;
            for (int ii = 1; ii < numCCs; ++ii)
            {
               if (tmp & 1)
               {
                  mask &= cc[ii];
               }
               else
               {
                  mask &= ~cc[ii];
               }
               tmp >>= 1;
            }
            mask = ~mask;
            for (int ii = 0; ii < numCCs; ++ii)
            {
               cc[ii] &= mask;
            }
         }
      }
      int result = cc[0];
      for (int ii = 1; ii < numCCs; ++ii)
      {
         result |= cc[ii];
      }
      return result;
   }
}

//[leetcode 260](https://leetcode.com/problems/single-number-iii/description/) : Single Number,  exactly two elements appear only once and all the other elements appear exactly twice

//[leetcode 38](https://leetcode.com/problems/counting-bits/description/) : Counting Bits. 0->0, 1->1; 2->10, 3->11; 4->100, 5->101, 6->110, 7->111;
// 8->1000, 9->1001, 10->1010, 11->1011, 12->1100, 13->1101, 14->1110, 15->1111;... [0, 1; 1, 2; 1, 2, 2, 3; 1, 2, 2, 3, 2, 3, 3, 4, ....]
std::vector<int> countBits(int n)
{
   std::vector<int> counts(n + 1, 0);
   counts[0] = 0;
   if (n == 0)
   {
      return counts;
   }
   counts[1] = 1;
   if (n == 1)
      return counts;
   int nc = 2;
   int start = 2;
   while (nc < n + 1)
   {
      for (int ii = start; ii < start << 1; ++ii)
      {
         counts[ii] = 1 + counts[ii - start];
         nc++;
         if (nc > n)
            break;
      }
      start <<= 1;
   }

   return counts;
}
int main()
{
   //
   std::cout << reverseInt(4) << std::endl;
   std::cout << reverseInt(-405) << std::endl;
   std::cout << reverseInt(1147483647) << std::endl;
   std::cout << reverseBitInt(11) << std::endl; // leetcode 190

   std::cout << "Minimum bit flips is" << minBitFlips(10, 7) << std::endl; // leetcode 2220.

   std::vector<size_t> vec1{1, 2, 4, 6, 8, 11, 15, 14, 19, 20};
   std::cout << shuffle(vec1) << std::endl;
   std::cout << sum(12, 5) << std::endl;
   std::cout << divide(31, 2) << std::endl;

   std::vector<int> vec11{1,1,1,2};
   std::cout<<"bbb "<<singleNumber32Counters(vec11, 3)<<std::endl;

   std::vector<int> vec12{30000,500,100,30000,100,30000,100};
   std::cout<<"bbb "<<singleNumber(vec12, 3)<<std::endl;

   unsigned int aa = INT_MAX;
   unsigned int bb = INT_MIN;
   std::cout << aa << "    " << bb << std::endl;
   /*
      constexpr size_t SIZE=16;
      size_t bitMask = (1<<16) -1;
      std::vector<size_t> vec1{0x00070001, 0x00040005, 0x00030002, 0x00000000, 0x00000000, 0x00000000};
      const int sz = vec1.size()/2;
      for(int ii = sz-1; ii>=0; --ii){
         size_t secondNum = vec1[ii] >> SIZE;
         vec1[2 * ii] = vec1[ii] & bitMask;
         vec1[2 * ii + 1] = (vec1[ii] >> SIZE);
   //      vec1[2 * ii + 1] = secondNum;
      }
   */
}
