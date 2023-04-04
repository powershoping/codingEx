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

std::vector<std::vector<int>> getAdjacency(std::vector<int> &parents)
{
   const int sz = parents.size();
   std::vector<std::vector<int>> adj(sz, std::vector<int>{});
   for (int ii = 1; ii < parents.size(); ++ii)
   {
      adj[parents[ii]].push_back(ii);
   }
   return adj;
}
int getNodeCountDFS(const std::vector<std::vector<int>> &adj, const int nodeIdx, std::vector<int> &nodeCount)
{
   for(const auto ee : adj[nodeIdx]){
      nodeCount[nodeIdx] += getNodeCountDFS(adj, ee, nodeCount);
   }
   nodeCount[nodeIdx] ++;
   return nodeCount[nodeIdx];

}
//[leetcode 2049](https://leetcode.com/problems/count-nodes-with-the-highest-score/description/) : Count Nodes With the Highest Score
int countHighestScoreNodes(std::vector<int> &&parents)
{
   const int sz = parents.size();
   const auto &adj = getAdjacency(parents);
   std::vector<int> nodeCount(sz, 0);
   std::vector<int> score(sz, 0);
   getNodeCountDFS(adj, 0, nodeCount);
   int maxScore=1;
   for(const int ee: adj[0]){
      maxScore *=nodeCount[ee];
   }
   score[0]=maxScore;

   for(int ii =1; ii<sz; ++ii ){
      if (adj[ii].size() > 0)
      {
         int count = 1;
         for (const int ee : adj[ii])
         {
            count *= nodeCount[ee];
         }
         score[ii] = count * (nodeCount[0] - nodeCount[ii]);
      }
      else{
         score[ii] = nodeCount[0]-1;
      }
      maxScore = std::max(maxScore,score[ii]);
   }
   int result=0;
   for(int ii=0; ii<sz; ++ii)
   {
      if(score[ii] == maxScore) result++;
   }
   return result;
}

int longestPath(const std::vector<int> &parent, const std::vector<std::vector<int>> &adj, const int node, int &maxLen, const std::string &s)
{
   int longest1 = 0, longest2 = 0;

   for (const auto child : adj[node])
   {
      int len = longestPath(parent, adj, child, maxLen, s);
      if (s[node] != s[child])
      {
         if (len > longest1)
         {
            longest2 = longest1;
            longest1 = len;
         }
         else if (len > longest2)
         {
            longest2 = len;
         }
      }
   }
   maxLen = std::max(maxLen, longest1 + longest2 + 1);
   return std::max(longest1, longest2) + 1;
}
//[2246](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/) :  Longest Path With Different Adjacent Characters
int longestPath(std::vector<int> &&parent, std::string &&s)
{
   if (parent.size() < 2)
      return 1;
   std::vector<std::vector<int>> adj;
   adj = getAdjacency(parent);
   int node = 0, maxLen = 1;
   longestPath(parent, adj, node, maxLen, s);
   return maxLen;
}

int main()
{

  std::vector<std::vector<int>> vecOranges{{2,1,1},{1,1,0},{0,1,1}};
  std::cout<<"Oranges get rotten in "<<orangesRotting(vecOranges)<<" minutes"<<std::endl;
  std::vector<std::vector<char>> vecIsland{  {'1','1','1','1','0'},
                                             {'1','1','0','1','0'},
                                             {'1','1','0','0','0'},
                                             {'0','0','0','0','0'}};
  std::cout << "number of island is : " << numIslands(vecIsland) << std::endl;
  std::cout<<"Highest score is: "<<countHighestScoreNodes({-1,3,3,5,7,6,0,0})<<std::endl;
  std::cout<<"LongestPath is: "<<longestPath({-1,0,0,1,1,2}, "abacbe")<<std::endl;

  return 0;
}