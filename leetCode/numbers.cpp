#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <vector>

// Catalan Number : C_{n+1} = sum_0^n{C_i*C_{n-i}}. C_3 = C_0*C_2 + C_*C_1 * C_2*C_0; C_4= C_0*C_3 + C_1*C_2 + C_2*C_1 + C_3*C_0;
//[leetcode 96](https://leetcode.com/problems/unique-binary-search-trees/description/) : Unique Binary Search Trees. Catalan Number
int numTrees(int n)
{
    std::vector<int> num_trees(n + 1, 0);

    num_trees[0] = 1;
    num_trees[1] = 1;
    if (n <= 1)
    {
        return 1;
    }

    for (int ii = 2; ii < n + 1; ++ii)
    {
        for (int jj = 0; jj < ii ; ++jj)
        {
            num_trees[ii] += num_trees[jj] * num_trees[ii - jj -1];
        }
    }
    return num_trees[n];
}

int main()
{
    std::cout<<numTrees(3)<<std::endl;
}
