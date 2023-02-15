# Bit Manipulation 
1. **NOT(~)**: A unary operator that flips the bits of the current number, i.e., if the current bit is 0, it changes it to 1 and vice versa. ` N=5=0b101; ~N=~(0b101)=0b010=2`. INT_MAX is NOT of INT_MIN, i.e., `INT_MAX = ~INT_MIN`
2. **AND(&)** : If both bits in the compared position of the bit pattern are 1, the bit in the resulting bit pattern is 1, otherwise 0. `A=5=0b101; B=1=0b001; A&B= 0b101 & 0b001 = 0b001 =1`
3. **OR(|)** : If both bits in the compared position of the bit pattern are 0, the bit in the resulting bit pattern is 0, otherwise 1. `A=5=0b101; B=1=0b001; A | B = 0b101 | 0b001 = 0b010 = 101`
4. **XOR(^)** : If both bits are 0 or 1, the result will be zero, other wise 1. Same 0, different 1. 
5. **Left Shift(<<)** : A binary operator which shifts some number of bits to the left and append 0 at the end.  One left shift is equivalent to multiplying the bit pattern with 2. `A=5=0b00101; C=A<<1=0b01010=10; D=A<<2=0b10100=20;`
6. **Right Shift(>>)** : A binary operator which shifts some number of bits to the right and append 0 at the left side. One right shift is equivalent to dividing the bit pattern with 2. `A=5=0b00101; B=A>>1=0b00010=2; C=A>>2=0b00001=1; C=A>>3=0b00000=0;` 

# Single Number Appeared Times Different From Others [Reference](https://leetcode.com/problems/single-number-ii/solutions/43295/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers/)

Given an arrays of intergers, every elements appears `k`(`k>1`) times except for one, which appears `p` times (`p>=1, p%k !=0`). Find the single one. For example, Input: [1,3,4, 2, 2], output: 2. 
- Method 1. Count 1s of each bit of for all the 32-bit numbers in the arrays, this means that for 32-bits intergers, we need 32 couters, i.e. count[0:32] for the lowest bit (0) to the highest bit (0). And then do a modulo operation for each count[i], if the reminder is not equal to zero, this mean that the interger appears `p` times has this ith bit set, otherwise, it has zero in this ith bit.   
Here is the code 
```
     std::vector<int> counts(32, 0); 
      for (auto &ee : nums)
      {
         for (int ii = 0; ii < 32; ++ii)
         {
            if (ee & 1)
               counts[ii]++;
            ee >>= 1;
         }
      }
      int result = 0;
      for (int ii = 0; ii < 32; ++ii)
      {
         if (counts[ii] % k != 0)
         {
            result = result | 1 << ii;
         }
      }
      return result;
```

- Method 2. This method shares the basics of method 1, i.e. using integers to count the bits of each intergers in the arrays. However, instead of employing 32 integers as the counters for each bit, one 32- bit integer counter is used to count 1s in each bit of the array integer, in another word, the couter's bit is used to count the 1s of each bit of the array integer. Let's using 4-bit numbers as an example:, we have [15, 15, 9, 9, 1], as `k=2`, 0 and 1 will be enough to count the set bit in the array. So 1 counter is needed. Initially the counter =0.  When the first 14 is read, the counter is set as `1111` in binary, and when the second 15 is read, the counter now is set as `0000`, when 1st 9 is read, the counter is set `1001`, and after 2nd 9 is read, the counter back to `0000`, and finally, when 1 is read, the count will be `0001` which is the single number. Of course, XOR bit-wise operator is used to do the count. 
However, when k is greater than 2, a single counter is not enough, we need another integers counter to record the number of 1s on each bit position. Thinking like this, each bit of one counter only can count upto 2, and using two bits at the same position from two counters can count upto 4, etc ...... So the number (`m`)of the counter needs to be $log_2^k$, i.e. `c[0:m]`
The other thing to consider is that if $k <2^m-1$, we need to reset the counters to zero if we have seen `k` ones.   A mask is needed, and we can use this mask to do bit-wise add `&` with each counter. We want the mask be zero if `k` is reached and 1 otherwise. `mask = ~(cc[0] & cc[1] & cc[2] .... )$  where $cc[i]=c[i]` if ith bit of `k` is 1, `cc[i]=~c[i]` if the ith bit of `k` is 0. For example, `k=3`, we need two counters, $c_0$ and $c_1$, and `mask = ~(c[0] & c[1])`, while for `k=5`, we need 3 counters, and as `k=101`, so `mask= ~(c[0] & ~c[1] &c[2])`
The final result is $c_1 | c_2 | c_3 ....$
```
int singleNumber(std::vector<int> &nums, int kk){
   {
      int numCCs = 0;
      int kk_saved = kk;
      while (kk)
      {
         numCCs++;
         kk >>= 1;
      }
      bool maskOn = kk == 1 << numCCs ? false : true;
      std::vector<int> cc(numCCs, 0);
      int mask = 0;

      for (const auto &ee : nums)
      {
         for (int ii = numCCs - 1; ii >= 0; --ii)
         {
            int tmp = ee;
            for (int jj = 0; jj < ii; ++jj)
            {
               tmp &= cc[jj];
            }
            cc[ii] ^= tmp;
         }
         if (maskOn)
         {
            int tmp = kk_saved;
            if (tmp & 1)
            {
               mask &= cc[0];
            }
            else
            {
               mask &= ~cc[0];
            }
            tmp >>= 1;
            for (int ii = 1; ii < numCCs; ++ii)
            {
               if (tmp & 1)
               {
                  mask &= cc[ii];
               }
               else
               {
                  mask &= ~cc[ii];
               }
               tmp >>= 1;
            }
            mask = ~mask;
            for (int ii = 0; ii < numCCs; ++ii)
            {
               cc[ii] &= mask;
            }
         }
      }
      int result = cc[0];
      for (int ii = 1; ii < numCCs; ++ii)
      {
         result |= cc[ii];
      }
      return result;
   }
}
```