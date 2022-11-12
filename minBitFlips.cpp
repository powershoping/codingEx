#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>


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

int main()
{
    std::cout<<minBitFlips(10,7)<<std::endl;
    return 0;
}
