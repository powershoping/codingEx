#ifndef OUTPUT_TOOLS_H_ 
#define OUTPUT_TOOLS_H_

#include <iostream>
#include <vector>

template<typename T>
std::ostream &operator <<(std::ostream &out, const std::vector<T> vec){
   int ii;
   out<<"[";
   if (vec.size() > 0)
   {
      if (vec.size() == 1)
      {
         out << vec[0];
      }
      else
      {
         for (ii = 0; ii < vec.size() - 1; ii++)
            out << vec[ii] << ",  ";
         out << vec[ii];
      }
   }
   out << "]";
   return out;
}

template<typename T>
std::ostream &operator <<(std::ostream &out, const std::vector<std::vector<T>> vec){
    for( const auto &el : vec)
       out << el << std::endl;

    return out;
}

#endif
