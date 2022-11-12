#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>

int reverseInt(int org_x)
{
    int rev_x = 0;
    while(org_x!=0)
    {
        int rem = org_x%10;
        org_x = org_x / 10;
        if(rev_x>INT_MAX/10 || rev_x==INT_MAX/10 && rem>7)
            return 0;
        if(rev_x<INT_MIN/10 || rev_x==INT_MIN/10 && rem<-8)
            return 0;
        rev_x = rev_x*10 + rem;
    }
    return rev_x;
}
uint32_t reverseBitInt(uint32_t org_x){

   uint32_t rev_x=0;
   while (org_x)
   {
      std::cout<<(org_x&1)<<std::endl;
      rev_x<<=1;
      if (org_x &1 ){
         rev_x ++;
      }
      org_x=org_x>>1;
   }

   return rev_x;
}

int main()
{
    std::cout<<reverseInt(4)<<std::endl;
    std::cout<<reverseInt(-405)<<std::endl;
    std::cout<<reverseInt(1147483647)<<std::endl;
    std::cout<<reverseBitInt(11)<<std::endl;
    uint32_t a = 60;
    uint32_t b = 1;
    uint32_t c = a & b;
    if(!(a&b))
    {std::cout<<"dcccc"<<std::endl;}

    std::cout<<c<<std::endl;
    return 0;
}
