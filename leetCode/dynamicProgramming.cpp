#include <string>
#include <iostream>
#include <sstream>
#include <vector>


//[leetcode 70](https://leetcode.com/problems/climbing-stairs/description/) : climb stairs
int climbStairs(int n)
{
   if (n <= 2)
      return n;
   int dp1 = 1;
   int dp2 = 2;
   int result;
   for (int ii = 3; ii < n + 1; ++ii)
   {
      result = dp1 + dp2;
      dp1 = dp2;
      dp2 = result;
   }
   return result;
}
int main(){

   std::cout<<"Distinct ways to climb to the top= "<<climbStairs(30);
   return 0;
}