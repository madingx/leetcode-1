// Source : https://leetcode.com/problems/integer-break/
// Author : Hao Chen
// Date   : 2016-05-29

/*************************************************************************************** 
 * 343. Integer Break [Medium]
 * Given a positive integer n, break it into the sum of at least two positive integers 
 * and maximize the product of those integers. Return the maximum product you can get.

 * Example 1:
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.

 * Example 2:
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

 * Note: You may assume that n is not less than 2 and not larger than 58.
 ***************************************************************************************/

class Solution {
public:
    // As the hint said, checking the n with ranging from 7 to 10 to discover the regularities.
    // n = 7,    3*4 = 12
    // n = 8,  3*3*2 = 18
    // n = 9,  3*3*3 = 27
    // n = 10, 3*3*4 = 36
    // n = 11, 3*3*3*2 = 54
    //
    // we can see we can break the number by 3 if it is greater than 4;
    // O(n) solution
    // Runtime: 4 ms, faster than 100.00% of C++, 8.3 MB, less than 69.32% of C++
    int integerBreak(int n) {
        if ( n == 2 ) return 1;
        if ( n == 3 ) return 2;
        int result = 1;
        while( n > 4 ) {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }

    // O(1) solution
    // 4 ms, faster than 100.00% of C++, 8.4 MB, less than 42.04% of C++ 
    int integerBreak(int n) {
        if (n==2)
            return 1;
        if (n==3)
            return 2;
        if (n%3 == 0)
        {
            return pow(3,n/3);
        }
        if (n%3 == 2)
        {
            return pow(3,n/3)*2;
        }
        return pow(3,(n/3)-1)*4;
        
    }
    /*
        2 - 1,1
        3 - 1,2
        4 - 2,2
        5 - 3,2
        6 - 3,3
        7 - 3,4
        8 - 3,3,2
        9 - 3,3,3
        10 - 3,3,4
        11 - 3,3,3,2
        12 - 3,3,3,3
        13 - 3,3,3,4
*/

};

