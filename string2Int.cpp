#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>

int myAtoi(std::string s)
{
   int sz = s.size();
   int result = 0;
   int sign = 1;
   for (int ii = 0; ii < sz; ++ii)
   {
      if (s.at(ii) == '-')
      {
         if (ii == sz - 1)
         {
            return 0;
         }
         else
         {
            if (s.at(ii + 1) < '9' && s.at(ii + 1) > '0')
               sign = -1;
         }
      }
      if (s.at(ii) == '+')
      {
         if (ii == sz - 1)
         {
            return 0;
         }
         else
         {
            if (s.at(ii + 1) < '9' && s.at(ii + 1) > '0')
               sign = 1;
         }
      }
      if (s.at(ii) <= '9' && s.at(ii) >= '0')
      {
         result = result * 10 + (s.at(ii) - '0');
         if (ii < sz - 1)
         {
            if (s.at(ii + 1) > '9' && s.at(ii + 1) < '0')
               break;
         }
      }
   }
   return result * sign;
}

int main()
{
   std::cout << myAtoi("word and 743") << std::endl;
   std::cout << myAtoi("  -43") << std::endl;
   std::cout << myAtoi("4193 with words") << std::endl;
   return 0;
}
