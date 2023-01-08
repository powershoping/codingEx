#include <iostream>
#include <bits/stdc++.h>

void printPowerSet_bitMask(char* set, int set_size)
{
   int num_sets = pow(2, set_size);

   for(int ii = 0; ii<num_sets; ++ii)
   {
      std::cout <<"set of ii="<<ii<<"is {";
      for(int jj =0; jj < set_size; ++jj)
      {
         if(ii & 1<<jj)
         {
            std::cout<< set[jj]; 
         }
      }
      std::cout<<"}"<<std::endl;
   }
}
void printPowerSet_bitMask2(char* set, int set_size)
{
   int num_sets = pow(2, set_size);

   for(int ii = 0; ii<num_sets; ++ii)
   {
      std::cout <<"set of ii="<<ii<<"is {";
      for(int jj =0; jj < set_size; ++jj)
      {
         if(ii>>jj & 1)
         {
            std::cout<< set[jj]; 
         }
      }
      std::cout<<"}"<<std::endl;
   }
}
void printPowerSetRecursive(std::string &set, size_t index, std::string cur_set)
{
   size_t sz = set.size();
   if(index==sz){
      std::cout<<"{"<<cur_set<<"}"<<std::endl;
      return;
   }
   printPowerSetRecursive(set, index+1, cur_set+set[index]);
   printPowerSetRecursive(set, index+1, cur_set);
}
// Will not work. Very complicated algorith. 
void printPowerSet_2loops(const char* set, const int set_size)
{
   for(int ii = 0; ii <set_size; ++ii)
   {
      std::cout<<set[ii]<<std::endl;
      for(int jj=ii+1; jj<set_size; ++jj)
      {
         for(int kk = ii; kk<ii+jj+1; ++kk)
         {
            std::cout<<set[kk];
         }
         std::cout<<std::endl;
      }
   }
}

int main()
{
   char set[]={'a','b','c'};
   printPowerSet_bitMask(set, sizeof(set));
   std::cout<<"2nd method\n";
   printPowerSet_bitMask2(set, sizeof(set));
   printPowerSet_2loops(set, sizeof(set));
   std::cout<<"recursive way\n";
   std::string set2{"abc"};
   printPowerSetRecursive(set2, 0, "");
   return 0;
}
