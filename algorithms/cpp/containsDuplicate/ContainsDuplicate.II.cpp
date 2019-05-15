// Source : https://leetcode.com/problems/contains-duplicate-ii/
// Author : Hao Chen
// Date   : 2015-06-12

/********************************************************************************** 
 * 219. Contains Duplicate II [Easy]
 * Given an array of integers and an integer k, find out whether there there are 
 * two distinct indices i and j in the array such that nums[i] = nums[j] and 
 * the difference between i and j is at most k.

 * Example 1:
 * Input: nums = [1,2,3,1], k = 3
 * Output: true

 * Example 2:
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 
 * Example 3:
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 *               
 **********************************************************************************/
// 28 ms, faster than 97.26%, 15.6 MB, less than 8.39% of C++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); i++) {
            int n = nums[i];
            if (m.find(n) != m.end() && i - m[n] <= k) {
                return true;
            }
            m[n] = i;
        }
        return false;
    }
};

