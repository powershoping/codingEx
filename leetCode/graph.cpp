#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>
#include "../tools/output_tools.h"

const  std::vector<std::pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // right, left, top, down
//[leetcode 994](https://leetcode.com/problems/rotting-oranges/description) : Time for Oranges to get rotten
int orangesRotting(std::vector<std::vector<int>> &grid)
{
   const int mm = grid.size();
   if (mm == 0)
      return -1;
   const int nn = grid[0].size();
   std::queue<std::pair<int, int>> Qrotten;
   bool noOrange = true;
   for (int ii = 0; ii < mm; ++ii)
   {
      for (int jj = 0; jj < nn; ++jj)
      {
         if (grid[ii][jj] == 2)
         {
            Qrotten.push({ii, jj});
         }
         if (grid[ii][jj] != 0)
         {
            noOrange = false;
         }
      }
   }
   if (noOrange)
      return 0;
   if (Qrotten.empty())
      return -1;

   int result = 0;
   while (!Qrotten.empty())
   {
      result++;
      const int sz = Qrotten.size();
      for (int kk = 0; kk < sz; ++kk)
      {
         auto ee = Qrotten.front();
         Qrotten.pop();
         int ii = ee.first;
         int jj = ee.second;
         for (const auto &dd : dir)
         {
            int ii = ee.first + dd.first;
            int jj = ee.second + dd.second;
            if (ii < mm && ii >= 0 && jj < nn && jj >= 0 && grid[ii][jj] == 1)
            {
               Qrotten.push({ii, jj});
               grid[ii][jj] = 2;
            }
         }
      }
   }

   for (int ii = 0; ii < mm; ++ii)
   {
      for (int jj = 0; jj < nn; ++jj)
      {
         if (grid[ii][jj] == 1)
         {
            return -1;
         }
      }
   }
   return result - 1;
}
//[leetcode 200](https://leetcode.com/problems/number-of-islands/description/) : number of islands
int numIslands(std::vector<std::vector<char>> &grid)
{
   const int mm = grid.size();
   if (mm == 0)
      return 0;
   const int nn = grid[0].size();
   std::queue<std::pair<int, int>> QQ;
   int result = 0;
   for (int ii = 0; ii < mm; ++ii)
   {
      for (int jj = 0; jj < nn; ++jj)
      {
         if (grid[ii][jj] == '1')
         {
            result++;
            grid[ii][jj] = 'a';
            QQ.push({ii, jj});
            while (!QQ.empty())
            {
               const int sz = QQ.size();
               for (int ss = 0; ss < sz; ++ss)
               {
                  const auto eq = QQ.front();
                  QQ.pop();
                  for (const auto &dd : dir)
                  {
                     const int iii = eq.first  + dd.first;
                     const int jjj = eq.second + dd.second;
                     if (iii < mm && iii >= 0 && jjj < nn && jjj >= 0 && grid[iii][jjj] == '1')
                     {
                        QQ.push({iii, jjj});
                        grid[iii][jjj] = 'a';
                     }
                  }
               }
            }
         }
      }
   }
   return result;
}
int main()
{

  std::vector<std::vector<int>> vecOranges{{2,1,1},{1,1,0},{0,1,1}};
  std::cout<<"Oranges get rotten in "<<orangesRotting(vecOranges)<<" minutes"<<std::endl;
  std::vector<std::vector<char>> vecIsland{  {'1','1','1','1','0'},
                                             {'1','1','0','1','0'},
                                             {'1','1','0','0','0'},
                                             {'0','0','0','0','0'}};
std::cout<<"number of island is : "<<numIslands(vecIsland)<<std::endl;
}