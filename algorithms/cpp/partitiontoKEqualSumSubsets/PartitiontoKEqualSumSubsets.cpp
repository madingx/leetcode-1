// Source : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Author : Mading
// Date   : 2019-09-03

/********************************************************************************** 
* 698. Partition to K Equal Sum Subsets [Medium]
* Given an array of integers nums and a positive integer k, find whether it's 
* possible to divide this array into k non-empty subsets whose sums are all equal.


* Example 1:

* Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
* Output: True
* Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

* Note:

* 1 <= k <= len(nums) <= 16.
* 0 < nums[i] < 10000.
* 
*               
**********************************************************************************/


// 8 ms, faster than 63.78% of C++, 8.3 MB, less than 75.00% of C++
class Solution {
    bool dfs(vector<int>& nums, int start, vector<bool>& visited, int k, int rem, int s) {
    if (rem < 0) return false;
    if (rem == 0) { --k; rem = s; start = 0; } // Restart from index 0
    if (k == 0) return true;
    
    int n = visited.size();
    for (int i = start; i< n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        if (dfs(nums, i, visited, k, rem - nums[i], s)) return true;
        visited[i] = false;
    }
    
    return false;
}
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() < k)return false;
        int s = 0;
        for(auto n:nums){s+=n;}
        if(s%k != 0)return false;
        vector<bool> visited(nums.size());
        return dfs(nums, 0, visited, k,s/k, s/k);
    }
};