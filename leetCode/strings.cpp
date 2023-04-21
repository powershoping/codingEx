#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

#include "../tools/output_tools.h"
//[leetcode 71](https://leetcode.com/problems/simplify-path/description/) : simplify path
std::string simplifyPath(std::string path) 
{
   std::istringstream ss(path);
   std::vector<std::string>stk;
   for(std::string str; std::getline(ss, str, '/');){
      if(str=="" || str==".")continue;
      if(str==".."){
         if(stk.size()){
            stk.pop_back();
         }
         continue;
      }
      stk.push_back(str);
   }
   std::string result="";
   for(const auto &ee : stk){
      result +="/"+ee;
   }
   return result==""? "/": result;

}
void readSS(std::istringstream &ss){
   std::string str;
   ss>>str;
   std::cout<<std::stoi(str)<<"  ";
}
//[leetcode 30](https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/) :  Substring with Concatenation of All Words
// This is a wxw length slide window problem, where w is the window length, the first w actually also denotes the number of the starting point of the sliding windows. Here are the algorithm
//  0 +   w, 0 + 2w, 0 + 3w, ... n/w 
//  1 +   w, 1 + 2w, 1 + 3w, ... n/w
//  ...  ... ...
//  (w-1)+w, (w-1)+2w,   (w-1)+3, n/w
//  w +   w, w + 2w, w + 3w ... n/w  !!! This has been solved in the first iteration.  
// O(n*w)   
std::vector<int> findSubstring(std::string str, std::vector<std::string> &words)
{
   {
      if (str.empty() || words.empty())
         return {};

      const int wordLen = words[0].size();
      const int wordsLen = words.size();
      const int stride = wordLen * wordsLen;
      const int strLen = str.size();
      if (stride > strLen)
         return {};

      std::unordered_map<std::string, int> wordCount;
      for (const auto &ee : words)
      {
         ++wordCount[ee];
      }
      std::vector<int> results;
      for (int ii = 0; ii < wordLen; ++ii)
      { // ii being the starting postions of the sliding window.
         std::unordered_map<std::string, int> seen;
         int found = 0;
         int ll = ii; // store the first position that we have a match
         for (int jj = ii; jj < strLen - wordLen+1; jj += wordLen)
         {
            const std::string str1 = str.substr(jj, wordLen);
            auto it1 = wordCount.find(str1);
            if (it1 == wordCount.end())
            {
               seen.clear();
               ll = jj + wordLen;
               found = 0;
               continue;
            }
            ++seen[str1];
            ++found;
            while (seen[str1] > wordCount[str1])
            {
               const std::string tmpStr = str.substr(ll, wordLen);
               --seen[tmpStr];
               ll += wordLen;
               found--;
            }

            if (found == wordsLen)
            {
               results.push_back(ll);
               const std::string tmpStr = str.substr(ll, wordLen);
               --seen[tmpStr];
               ll += wordLen;
               --found;
            }
         }
      }

      return results;
   }
}
// O(nxwxm) n str length, m = words length, w word length
// loop over from 0-n, and then operate on the length of the m*w to see whether there is a match. 
std::vector<int> findSubstring11(std::string str11, std::vector<std::string> &words)
{
   if (str11.empty() || words.empty())
      return {};

   const int wordLen = words[0].size();
   const int wordsLen = words.size();
   const int stride = wordLen * words.size();
   const int strLen = str11.size();
   if (stride > strLen)
      return {};

   std::string_view str1(str11);
   std::unordered_map<std::string_view, int> wordCount;
   for (const auto &el : words)
   {
      ++wordCount[std::string_view(el)];
   }
   std::vector<int> results;
   for (int startIdx = 0; startIdx < strLen - stride + 1; ++startIdx)
   {
      std::unordered_map<std::string_view, int> sCount;
      int found = 0;
      for (int ii = startIdx; ii < startIdx + stride; ii += wordLen)
      {
         std::string_view curStr = str1.substr(ii, wordLen);
         auto it = wordCount.find(curStr);
         if (it == wordCount.end())
            break;
         if (++sCount[curStr] > it->second)
            break;
         found++;
      }
      if (found == wordsLen)
      {
         results.push_back(startIdx);
      }
   }

   return results;
}
int main(){
   std::string tmp;
   std::string path="/home//foo/";
   std::cout<<simplifyPath(path)<<std::endl;

   std::string sInts;
   for(short int ii = 123; ii<123+10; ++ii){
      sInts.append(reinterpret_cast<char *>(&ii),sizeof(ii));
   }
   std::istringstream ss00{sInts};
   for(short int ii; ss00.read(reinterpret_cast<char *>(&ii), sizeof(ii) );){
      std::cout<<ii<<"  ";

   }
   std::cout<<std::endl;

   std::string Ints;
   for(short int ii = 123; ii<123+10; ++ii){
      Ints +=std::to_string(ii)+ " ";
   }

   std::istringstream ss01{Ints};
   ss01>>tmp;
   std::cout<<std::stoi(tmp)<<std::endl;

   for(int ii =0; ii<5; ++ii)
   {
      readSS(ss01);
   }
   std::cout<<std::endl;

   std::string str1{"wordgoodgoodgoodbestword"};
   std::vector<std::string> vecStr00{"word","good","best","good"};
   std::cout<<findSubstring(str1, vecStr00)<<std::endl;
   return 0;
}
