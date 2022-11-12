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
   printPowerSet_2loops(set, sizeof(set));
   return 0;
}
