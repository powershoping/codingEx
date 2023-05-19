#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <algorithm>

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
//[leetcode 322](https://leetcode.com/problems/coin-change/) : coin change

int coinChange(std::vector<int> &coins, int amount)
{
   if (amount == 0)
      return 0;
//   std::sort(coins.begin(), coins.end());
   std::vector<int> dp(amount + 1, INT_MAX);
   dp[0] = 0;
   for (int ii = 1; ii < amount + 1; ++ii)
   {
//      for (int jj = 0; jj < coins.size() && amount >= coins[jj]; ++jj)
      for (int jj = 0; jj < coins.size(); ++jj)
      {
         int left = ii - coins[jj];
         if (left >= 0 && dp[left]!=INT_MAX)
         {
            dp[ii] = std::min(dp[ii], 1 + dp[left]);
         }
      }
   }
   return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int main(){

   std::cout<<"Distinct ways to climb to the top= "<<climbStairs(30)<<std::endl;
   std::vector<int> coins{1, 2147483647};
   std::cout<<"Coin Change=" <<coinChange(coins, 2)<<std::endl;
   return 0;
}