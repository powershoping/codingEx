#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>
#include "../tools/output_tools.h"

class MedianFinder
{
public:
   std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
   std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;

   MedianFinder()
   {
      minHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>();
      maxHeap = std::priority_queue<int, std::vector<int>, std::less<int>>();
   }

   void addNum(int num)
   { // minHeap.size()>=maxHeap.size();
      if (minHeap.empty())
      {
         minHeap.push(num);
         return;
      }
      if (num < minHeap.top())
      {
         maxHeap.push(num);
      }
      else
      {
         minHeap.push(num);
      }
      if (minHeap.size() == maxHeap.size() + 2)
      {
         maxHeap.push(minHeap.top());
         minHeap.pop();
      }
      if (maxHeap.size() > minHeap.size())
      {
         minHeap.push(maxHeap.top());
         maxHeap.pop();
      }
      return;
   }
   double findMedian()
   {
      if (minHeap.empty() && maxHeap.empty())
         return 0;
      return minHeap.size() == maxHeap.size() ? (minHeap.top() + maxHeap.top()) / 2.0 : minHeap.top();
   }

   void addNum11(int num)
   {
      if (minHeap.empty())
      {
         minHeap.push(num);
         return;
      }
      const int szMin = minHeap.size();
      const int valMin = minHeap.top();
      const int szMax = maxHeap.size();

      if (szMin == szMax)
      {
         if (num > valMin)
         {
            minHeap.push(num);
         }
         else
         {
            maxHeap.push(num);
         }
         return;
      }
      if (szMin > szMax)
      {
         if (num > valMin)
         {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(num);
         }
         else
         {
            maxHeap.push(num);
         }
         return;
      }

      const int valMax = maxHeap.top();

      if (szMin < szMax)
      {
         if (num < valMax)
         {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(num);
         }
         else
         {
            minHeap.push(num);
         }
         return;
      }
   }
   double findMedian11()
   {
      if (minHeap.empty() && maxHeap.empty())
         return 0;
      double mean = 0.0;
      if (minHeap.size() == maxHeap.size())
      {
         mean = (minHeap.top() + maxHeap.top()) / 2.0;
      }
      else
      {
         mean = minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
      }

      return mean;
   }
};

// Runtime 36 ms Beats 99.9% Memory 14.4 MB Beats 90.89%
std::vector<double> medianSlidingWindow11(std::vector<int> &nums, int kk)
{
   const int sz = nums.size();
   if (sz == 0 || kk > sz)
      return {};
   if (kk == sz)
   {
      std::sort(nums.begin(), nums.end());
      return (kk % 2) == 1 ? std::vector<double>{static_cast<double>(nums[kk / 2])} : std::vector<double>{((long)nums[kk / 2] + (long)nums[kk / 2 - 1]) / 2.0};
   }
   if (kk == 1)
      return std::vector<double>(nums.begin(), nums.end());

   std::vector<double> results;
   if(kk ==2){
      for(int ii = 0; ii <sz-1; ++ii){
         results.push_back(((long)nums[ii]+(long)nums[ii+1])/2.0);
      }
   }

   std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // minHeap.size() >= maxHeap.size();
   std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
   std::unordered_map<int, int> umap; // count the removed nums
   for (int ii = 0; ii < kk; ++ii)
   {
      minHeap.push(nums[ii]);
   }
   for (int ii = 0; ii < kk / 2; ++ii)
   {
      maxHeap.push(minHeap.top());
      minHeap.pop();
   }

   int ii = kk;
   while (true)
   {
      if (kk % 2)
      {
         results.push_back(minHeap.top());
      }
      else
      {
         results.push_back((long)(minHeap.top() + (long)maxHeap.top()) / 2.0);
      }

      if (ii == sz)
         break;
      // num Leaving : nums[ii-kk]; We need to know which heap the leaving num is in, and we need to keep track of the balance of each heap regarding the actual elements.
      int balanceMin = 0, balanceMax = 0;

      if (nums[ii - kk] >= minHeap.top())
      {
         --balanceMin;
         if (nums[ii - kk] == minHeap.top())
         {
            minHeap.pop();
         }
         else
         {
            ++umap[nums[ii - kk]];
         }
      }
      else
      {
         --balanceMax;
         if (nums[ii - kk] == maxHeap.top())
         {
            maxHeap.pop();
         }
         else
         {
            ++umap[nums[ii - kk]];
         }
      }

      // numComing   : nums[ii];
      if (!minHeap.empty() && nums[ii] >= minHeap.top())
      {
         ++balanceMin;
         minHeap.push(nums[ii]);
      }
      else
      {
         ++balanceMax;
         maxHeap.push(nums[ii]);
      }
      if (balanceMin == 1)
      { // minHead added a new elements but not removed one. so rebalance needed. then balanceMax ==-1;
         maxHeap.push(minHeap.top());
         minHeap.pop();
      }
      else if (balanceMin == -1)
      { // then balanceMax == 1;
         minHeap.push(maxHeap.top());
         maxHeap.pop();
      }
      // remove removed elements from the heaps if they are on the top of the heaps.
      while (!minHeap.empty() && umap[minHeap.top()])
      {
         --umap[minHeap.top()];
         minHeap.pop();
      }
      while (!maxHeap.empty() && umap[maxHeap.top()])
      {
         --umap[maxHeap.top()];
         maxHeap.pop();
      }

      ii++;
   }

   return results;
}
// Runtime 251 ms Beats 25.91% Memory 15.2 MB Beats 80.99%

std::vector<double> medianSlidingWindow(std::vector<int> &nums, int kk)
{
   const int sz = nums.size();
   if (sz == 0 || kk > sz)
      return {};
   if (kk == sz)
   {
      std::sort(nums.begin(), nums.end());
      return (kk % 2) == 1 ? std::vector<double>{static_cast<double>(nums[kk / 2])} : std::vector<double>{((long)nums[kk / 2] + (long)nums[kk / 2 - 1]) / 2.0};
   }
   if (kk == 1)
      return std::vector<double>(nums.begin(), nums.end());
   std::vector<double> results;
   std::multiset<int> mset;
   for (int ii = 0; ii < kk; ++ii)
   {
      mset.insert(nums[ii]);
   }
   int ii = kk;
   while (true)
   {
      auto it = mset.begin();
      for (int jj = 0; jj < (kk - 1) / 2; ++jj)
      {
         ++it;
      }
      if (kk % 2)
      {
         results.push_back(*it);
      }
      else
      {
         results.push_back(((long)(*it) + (long)(*(++it))) / 2.0);
      }
      if (ii == sz)
         break;

      mset.erase(mset.find(nums[ii - kk]));
      mset.insert(nums[ii]);
      ii++;
   }
   return results;
}
//Runtime  15 ms Beats 94.19% Memory 13.3 MB Beats 55.50%
int findPairs(std::vector<int> &nums, int k)
{
   std::unordered_map<int, int> umap;
   for (const auto el : nums)
   {
      ++umap[el];
   }
   int count = 0;
   if (k == 0)
   {
      for (const auto el : umap)
      {
         if (el.second > 1)
            count++;
      }
   }
   else
   {
      for (const auto el : umap)
      {
         if (umap.find(el.first + k) != umap.end())
            count++;
      }
   }
   return count;
}

int countKDifference(std::vector<int> &nums, int k)
{
   std::unordered_map<int, int> umap;
   for (const auto el : nums)
   {
      ++umap[el];
   }
   int count = 0;
   if (k == 0)
   {
      for (const auto el : umap)
      {
         if (el.second > 1)
            count++;
      }
   }
   else
   {
      for (const auto el : umap)
      {
         if (umap.find(el.first + k) != umap.end())
            count += umap[el.first + k];
         if (umap.find(el.first-k) != umap.end())
            count += umap[ el.first-k];
      }
   }
   return count;
}

//Runtime 54 ms  Beats 82.7% Memory 31.3 MB Beats 81.99%

int firstMissingPositive(std::vector<int> &nums)
{
   const int sz = nums.size();
   int count0s = 0;
   for (int ii = 0; ii < sz; ++ii)
   {
      if (nums[ii] < 0 || nums[ii] >= sz + 1)
      {
         nums[ii] = 0;
         count0s++;
      }
   }
   if (count0s == sz)
      return 1;
   for (int ii = 0; ii < sz; ++ii)
   {
      if (nums[ii] != 0 && nums[ii] != -(sz + 1))
      {
         int idx = abs(nums[ii]) - 1;
         if (nums[idx] == 0)
            nums[idx] = -(sz + 1);
         if (nums[idx] > 0)
            nums[idx] = -nums[idx];
      }
   }
   int missing = -1;
   for (int ii = 0; ii < sz; ++ii)
   {
      if (nums[ii] >= 0)
      {
         missing = ii + 1;
         break;
      }
   }
   if (missing == -1)
      missing = sz + 1;
   return missing;
}
//[leetcode 179](https://leetcode.com/problems/largest-number/description/) : Largest Number form by an array of integers
std::string largestNumber(std::vector<int> &nums)
{
   if (std::count(nums.begin(), nums.end(), 0) == nums.size())
      return "0";
   std::vector<std::string> strs;
   for (const auto &ii : nums)
   {
      strs.push_back(std::to_string(ii));
   }
   std::sort(strs.begin(), strs.end(), [](const std::string &s1, const std::string &s2)
             { return (s1 + s2 > s2 + s1); });
   std::string result{};
   for (const auto &ss : strs)
      result += ss;
   return result;
}
//[leetcode 2165](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/) :  Smallest Value of the Rearranged Number
long long smallestNumber(long long num)
{
   int sign = 1;

   if (num < 0)
   {
      sign = -1;
      num = -num;
   }
   if (num <= 10)
      return sign * num;
   int count[10];
   for (int ii = 0; ii < 10; ii++)
      count[ii] = 0;
   std::string str = std::to_string(num);
   for (const char &cc : str)
   {
      count[cc - '0']++;
   }
   long long result = 0;
   if (sign == -1)
   {
      for (int ii = 9; ii >= 0; --ii)
      {
         while (count[ii] > 0)
         {
            result = result * 10 + ii;
            count[ii]--;
         }
      }
      return -result;
   }
   else
   {
      if (count[0] > 0)
      {
         int firstNo0;
         for (int ii = 1; ii < 10; ++ii)
         {
            if (count[ii] > 0)
            {
               firstNo0 = ii;
               count[ii]--;
               break;
            }
         }
         result += firstNo0;
      }
      for (int ii = 0; ii < 10; ++ii)
      {
         while (count[ii] > 0)
         {
            result = result * 10 + ii;
            count[ii]--;
         }
      }
      return result;
   }
   return result;
}

long long smallestNumber1(long long num)
{
   int sign = 1;

   if (num < 0)
   {
      sign = -1;
      num = -num;
   }
   if (num <= 10)
      return sign * num;

   std::vector<int> digits;
   while (num != 0)
   {
      digits.push_back(num % 10);
      num /= 10;
   }
   long long result = 0;
   if (sign == -1)
   {
      std::sort(digits.begin(), digits.end(), std::greater<int>());
   }
   else
   {
      std::sort(digits.begin(), digits.end(), std::less<int>());
      if (digits[0] == 0)
      {
         for (int ii = 1; ii < digits.size(); ++ii)
         {
            if (digits[ii] != 0)
            {
               digits[0] = digits[ii];
               digits[ii] = 0;
               break;
            }
         }
      }
   }
   for (int ii = 0; ii < digits.size(); ++ii)
   {
      result = result * 10 + digits[ii];
   }
   result = sign * result;
   return result;
}

//[leetcode 904](https://leetcode.com/problems/fruit-into-baskets/description/) : Fruit Into Baskets
int totalFruit(std::vector<int> &&fruits)
{
   std::unordered_map<int, int> umap;
   int maxf = 0, count = 0;
   int lp = 0, rp = 0;
   while (rp < fruits.size())
   {
      if (umap.size() != 3)
      {
         umap[fruits[rp]]++;
         rp++;
         count++;
      }
      if (umap.size() == 3)
      {
         maxf = std::max(maxf, count - 1);
      }
      while (umap.size() == 3)
      {
         umap[fruits[lp]]--;
         count--;
         if (umap[fruits[lp]] == 0)
         {
            umap.erase(fruits[lp]);
         }
         lp++;
      }
   }
   maxf = std::max(maxf, count);
   return maxf;
}
//[leetcode 287](https://leetcode.com/problems/find-the-duplicate-number/description/) : Find the duplicated number in an array of integers containing n + 1 integers where each integer is in the range [1, n] inclusive.
int findDuplicate(std::vector<int> &&nums)
{
   int slow = 0, fast = 0;

   while (true)
   {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast)
         break;
   }
   slow = 0;
   while (true)
   {
      slow = nums[slow];
      fast = nums[fast];
      if (fast == slow)
         break;
   }
   return slow;
}
int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(-1);
    std::cout<<obj->findMedian()<<std::endl;
    obj->addNum(-2);
    std::cout<<obj->findMedian()<<std::endl;
    obj->addNum(-3);
    std::cout<<obj->findMedian()<<std::endl;
    obj->addNum(-4);
    std::cout<<obj->findMedian()<<std::endl;
    obj->addNum(-5);
    std::cout<<obj->findMedian()<<std::endl;

    std::vector<int> vecInt{5,5,8,1,4,7,1,3,8,4};

    std::cout << medianSlidingWindow(vecInt, 8) << std::endl;

//    std::vector<int> vecPairs{3,1,4,1,5};
   
    std::vector<int> vecPairs{492,190,396,236,89,352,49,240,464,334,52,419,241,428,130,313,337,7,414,415,451,78,66,135,134,259,55,41,399,446,338,376,302,383,347,186,223,311,169,430,520,436,183,249,42,266,315,8,15,256,207,415,321,156,404,315,9,497,390,49,275,485,455,4,327,504,119,336,220,502,197,384,421,210,85,240,119,473,36,26,147,370,347,354,198,172,86,213,256,401,385,58,251,409,424,284,293,239,112,189,327,506,478,175,221,465,26,118,426,215,252,103,373,195,342,194,192,420,11,178,57,301,48,151,95,491,238,63,113,207,494,422,226,38,280,283,464,222,28,270,195,414,487,257,477,200,9,216,396,446,456,282,329,309,357,496,26,473,438,230,43,285,63,308,181,127,272,447,323,300,286,377,8,125,115,198,159,370,236,18,474,365,153,261,70,482,467,204,178,202,512,464,209,521,244,191,80,51,453,495,318,285,519,308,501,525,39,164,91,454,417,299,319,197,191,241,253,81,259,249,142,113,64,184,345,469,152,260,329,97,501,434,445,388,463,224,412,503,347,45,279,311,349,201,53,316,284,360,248,305,204,165,479,321,66,30,2,484,150,129,38,275,445,357,263,497,37,514,164,214,34,61,54,334,257,179,398,18,63,471,151,471,504,443,416,510,439,160,462,108,293,117,318,88,133,271,279,36,152,143,324,12,116,159,435,34,77,95,260,469,104,249,353,266,343,459,222,415,464,91,35,326,237,59,185,95,423,355,294,237,285,434,114,26,291,100,92,289,480,212,410,11,387,371,184,38,295,10,495,367,58,331,281,392,315,304,48,374,195,314,465,393,305,425,35,23,187,133,440,108,199,509,161,78,54,306,218,22,94,11,110,440,293,465,481,210,182,112,455,454,208,498,119,377,503,140,81,105,500,374,157,139,354,173,135,495,364,99,137,53,356,415,64,82,47,386,393,498,191,398,277,295,245,45,350,132,509,338,94,300,52,252,313,396,418,169,316,59,413,410,481,411,422,222,245,485,290,463,523,172,400,395,113,175,133,368,521,255,205,391,74,128,161,339,386,331,479,66,205,269,301,280,361,357,300,85,228,465,150,335,246,385,313,523,194,175,56,504,466,437,360,474,393,81,4,229,24,260,76,2,359,133,312,104,289,298,376,397,64,80,254,174,465,424,451,382,392,73,488,135,219,48,427,354,250,216,339,65,82,8,77,218,193,100,179,427,474,80,76,122,185,52,436,4,70,287,110,106,441,488,439,235,244,521,256,413,141,273,101,51,287,331,444,461,260,456,43,370,227,279,305,304,359,103,293,222,373,233,260,80,11,294,499,265,516,519,346,235,402,0,406,518,67,143,445,147,96,297,415,298,93,317,72,117,42,296,311,200,442,422,452,172,461,33,216,240,520,198,146,186,116,293,424,480,51,255,383,507,43,102,150,509,300,290,147,333,91,482,0,128,11,327,271,362,475,475,265,268,34,490,109,304,524,217,317,147,207,202,220,340,248,67,169,433,184,313,133,317,382,386,220,523,183,173,223,390,483,336,376,508,413,428,359,382,311,514,159,117,489,256,11,322,135,492,199,313,164,503,492,21,211,371,321,462,428,52,350,179,103,424,390,5,412,285,443,121,458,166,352,168,371,198,32,309,81,463,252,495,343,3,187,265,219,479,192,401,401,254,99,62,192,339,403,321,511,193,345,361,509,387,15,176,36,390,313,228,156,435,141,296,73,371,245,97,301,465,454,337,245,255,39,220,281,33,224,495,93,91,513,11,201,299,143,193,140,321,246,309,193,153,388,393,461,228,220,333,231,123,360,381,460,96,330,425,403,295,201,349,162,225,342,110,252,376,276,99,26,228,33,440,399,175,371,394,272,176,86,290,219,205,145,482,18,459,290,208,336,271,200,455,261,183,292,439,245,0,177,471,460,473,432,377,205,6,168,491,385,438,422,438,40,144,514,9,90,144,469,460,93,177,392,475,238,162,291,410,83,477,249,261,247,521,334,221,407,444,243,252,53,320,111,240,492,180,151,253,6,354,480,178,217,64,350,454,126,114,185,299,383,99,254,136,377,208,65,296,313,272,57,336,207,109,406,250,245,457,159,455,261,328,394,274,525,36,415,142,472,16,241,157,206,306,467,81,128,104,91,518,270,271,64,503,521,430,506,140,271,177,494,34,441,524,51,305,265,410,460,455,420,189,464,30,263,198,148,167,38,383,158,239,410,410,454,392,446,220,338,284,232,204,222,242,317,452,469,79,117,106,363,434};
    std::cout<< findPairs(vecPairs, 196)<<std::endl;

    std::vector<int> vecKD{3,2,1,5,4};
    std::cout<<countKDifference(vecKD, 2)<<std::endl;



    std::vector<int> vecFMP{1,2,3,4,5,6,7,8,9,10,11,12,23,20};
    std::cout<<firstMissingPositive(vecFMP)<<std::endl;


    std::vector<int> lgVec={3,30,34,5,9};
    std::cout<<largestNumber(lgVec)<<std::endl;

    std::cout<<smallestNumber1(310)<<std::endl;
    std::cout<<smallestNumber(-1740)<<std::endl;

    std::cout<<"Total Fruits= "<<totalFruit({1,2,1})<<std::endl;
    std::cout<<"Duplicate integer is: "<<findDuplicate({1,3,4,2,5,2})<<std::endl;


}
