#include <string>
#include <iostream>
#include <stdio.h>

std::string reverseString(std::string input_str)
{
   if(input_str[0] =='\0')
      return "";

   return reverseString(input_str.substr(1)) + input_str[0];
}

bool isPalindrome(std::string input_str)
{
//   std::cout<<input_str<<std::endl;
   const int size = input_str.size();
   if(size==1 || size == 0)
      return true;

   bool is_pal = false;
   if(input_str[0]==input_str[size-1])
      is_pal = true;
   else
      is_pal = false;
   
   return isPalindrome(input_str.substr(1,size-2)) && is_pal;
}

std::string decimalToBinary(int input)
{
   if(input <= 1){
      std::string str1="";
      str1 = str1 + char(input + '0');

      return str1;
   }

   if(input%2)
      return decimalToBinary(input/2) + '1';

   else
      return decimalToBinary(input/2) + '0';

}

int main()
{
   std::string str1="niL efiw ym evol I";
   
   std::cout<<reverseString(str1)<<std::endl;

   std::string str2 ="abckaacba";

   std::cout<<str2<<" is Palindrome? : "<<isPalindrome(str2)<<std::endl;

   std::cout<<decimalToBinary(0)<<std::endl;
   std::cout<<decimalToBinary(1)<<std::endl;
   std::cout<<decimalToBinary(7)<<std::endl;
   std::cout<<decimalToBinary(11)<<std::endl;
   std::cout<<decimalToBinary(6)<<std::endl;


    
   return 0;
}

