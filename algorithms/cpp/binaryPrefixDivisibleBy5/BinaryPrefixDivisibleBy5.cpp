// Source : https://leetcode.com/problems/binary-prefix-divisible-by-5/
// Author : Mading
// Date   : 2019-05-25

/*************************************************************************************** 
 * 1018. Binary Prefix Divisible By 5 [Easy]
 * Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] 
 * interpreted as a binary number (from most-significant-bit to least-significant-bit.)

 * Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

 * Example 1:
 * Input: [0,1,1]
 * Output: [true,false,false]
 * Explanation: 
 * The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  
 * Only the first number is divisible by 5, so answer[0] is true.

 * Example 2:
 * Input: [1,1,1]
 * Output: [false,false,false]

 * Example 3:
 * Input: [0,1,1,1,1,1]
 * Output: [true,false,false,false,true,false]

 * Example 4:
 * Input: [1,1,1,0,1]
 * Output: [false,false,false,false,false]
 
 * Note:
 * 1 <= A.length <= 30000
 * A[i] is 0 or 1
 *               
 ***************************************************************************************/


// 12 ms, faster than 98.38% of C++, 10.8 MB, less than 32.25% of C++
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res(A.size(),false);
        long n = 0;
        for(int i=0;i<A.size();i++){
            n = (n<<1) + A[i];      //  1+1<<1+1  等价于   2<<2
            res[i] = (n%5==0);
            n = n%5;
        }
        return res;

    }
};