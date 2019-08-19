// Source : https://leetcode.com/problems/fibonacci-number/
// Author : Mading,Hao Chen
// Date   : 2019-04-13

/********************************************************************************** 
 * 509. Fibonacci Number [Easy]

 * The Fibonacci numbers, commonly denoted F(n) form a sequence, 
 * called the Fibonacci sequence, such that each number is the sum 
 * of the two preceding ones, starting from 0 and 1. That is,

 * F(0) = 0,   F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), for N > 1.
 * Given N, calculate F(N).

 * Example 1:
 * Input: 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

 * Example 2:
 * Input: 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

 * Example 3:
 * Input: 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

 * Note:
 * 0 ≤ N ≤ 30.
 *               
 **********************************************************************************/

// 4 ms, faster than 100.00% of C++, 8.1 MB, less than 99.76% of C++
class Solution {
public:
    int fib(int N) {
        if(N==0)return 0;
        if(N==1)return 1;
        int a=0,b=1;
        
        while(N>1){
            int tmp = b;
            b = a+b;
            a = tmp;
            N--;
        }
        return b;
        
        
    }
};




class Solution {
public:
    int fib(int N) {
        if (N < 2 )  return N;
        int first = 0, second = 1;

        for ( N-=1; N > 0; N-- ) {
            second += first;
            first = second - first;
        }
        return second;
    }
};
