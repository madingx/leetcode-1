// Source : https://leetcode.com/problems/squares-of-a-sorted-array/
// Author : Mading
// Date   : 2019-04-13

/********************************************************************************** 
 * 977. Squares of a Sorted Array [Easy]
 * Given an array of integers A sorted in non-decreasing order, return an array of 
 * the squares of each number, also in sorted non-decreasing order.
 
 * Example 1:
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]

 * Example 2:
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 
 * Note:
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 *               
 **********************************************************************************/

// Runtime: 100 ms, faster than 98.95% of C++, 13.5 MB, less than 99.64% of C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size());
        int l = 0,r = A.size()-1;
        int index = A.size()-1;
        while(l<=r){
            int l_s = A[l]*A[l];
            int r_s = A[r]*A[r];
            if(l_s>=r_s){
                ret[index--] = l_s;
                l++;
            }
            else{
                ret[index--] = r_s;
                r--;
            }
        }
        return ret;
    }
};