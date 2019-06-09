// Source : https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author : Mading
// Date   : 2019-06-09

/*************************************************************************************** 
 * 1043. Partition Array for Maximum Sum [Medium]
 * Given an integer array A, you partition the array into (contiguous) subarrays 
 * of length at most K.  After partitioning, each subarray has their values changed 
 * to become the maximum value of that subarray.

 * Return the largest sum of the given array after partitioning.

 * Example 1:
 * Input: A = [1,15,7,9,2,5,10], K = 3
 * Output: 84
 * Explanation: A becomes [15,15,15,9,10,10,10]
 
 * Note:
 * 1 <= K <= A.length <= 500
 * 0 <= A[i] <= 10^6
 *       
 ***************************************************************************************/

// 12 ms, faster than 96.08% of C++, 9 MB, less than 100.00% of C++ 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size()+1,0);
        for(int i=0;i<A.size();i++){
            int maxLast = 0;
            for(int j=i; j>=0 && i-j<K;j--){
                maxLast = max(maxLast, A[j]);
                dp[i+1] = max(dp[i+1], dp[j] + maxLast * (i-j+1));
            }
        }
        return dp.back();
    }
};