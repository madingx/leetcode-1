// Source : https://leetcode.com/problems/target-sum/description/
// Author : Mading
// Date   : 2017-11-18
// 
// Latest Edition
// Editor : Mading
// Date   : 2017-11-18

/********************************************************************************** 
 * 494. Target Sum
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target,S. 
 * Now you have 2 symbols + and -. 
 * For each integer, you should choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 *
 * Example 1:
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * Note:
 * 1.The length of the given array is positive and will not exceed 20.
 * 2.The sum of elements in the given array will not exceed 1000.
 * 3.Your output answer is guaranteed to be fitted in a 32-bit integer.
 *               
 **********************************************************************************/

//http://blog.csdn.net/hit0803107/article/details/54894227
class Solution {
public:
        int findTargetSumWays(std::vector<int>& nums, int S) {  
            int sum = std::accumulate(nums.begin(), nums.end(), 0);  
            return sum < S || (S + sum) & 1 ? 0 : subsetSum(nums, (S+sum) >> 1);  
        }  
  
        int subsetSum(std::vector<int>& nums, int s) {  
            int dp[s+1];  
            memset(dp, 0, sizeof(int)*(s+1));  
            dp[0] = 1;  
            for(int n: nums) {  
                for (int i = s; i >= n; --i) {  
                    dp[i] += dp[i-n];  
                }  
            }  
            return dp[s];  
        }  
};