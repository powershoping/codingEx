#include <string>
#include <iostream>
#include <sstream>
#include <vector>

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

   return 0;
}
