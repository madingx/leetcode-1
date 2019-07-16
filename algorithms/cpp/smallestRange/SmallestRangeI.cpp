// Source : https://leetcode.com/problems/smallest-range-i/
// Author : Mading
// Date   : 2019-07-16

/********************************************************************************** 
* 908. Smallest Range I [Easy]
* Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
* After this process, we have some array B.

* Return the smallest possible difference between the maximum value of B and the minimum value of B.


* Example 1:
* Input: A = [1], K = 0
* Output: 0
* Explanation: B = [1]

* Example 2:
* Input: A = [0,10], K = 2
* Output: 6
* Explanation: B = [2,8]

* Example 3:
* Input: A = [1,3,6], K = 3
* Output: 0
* Explanation: B = [3,3,3] or B = [4,4,4]
 

* Note:
* 1 <= A.length <= 10000
* 0 <= A[i] <= 10000
* 0 <= K <= 10000
* 
**********************************************************************************/

// 24 ms, faster than 49.14% of C++ 9.6 MB, less than 88.37% of C++
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min1 = A[0],max1 = A[0];
        for(int i=1;i<A.size();i++){
            max1 = max(A[i],max1);
            min1 = min(A[i],min1);
        }
        return (max1-min1 <= 2*K) ? 0 : max1-min1-2*K;
    }
};