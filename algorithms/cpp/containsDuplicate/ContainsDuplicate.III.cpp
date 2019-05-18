// Source : https://leetcode.com/problems/contains-duplicate-iii/
// Author : Hao Chen
// Date   : 2015-06-12

/********************************************************************************** 
 * 220. Contains Duplicate III [Medium]
 * Given an array of integers, find out whether there are two distinct indices i and j 
 * in the array such that the difference between nums[i] and nums[j] is at most t and 
 * the difference between i and j is at most k.

 * Example 1:
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true

 * Example 2:
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 
 * Example 3:
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false              
 **********************************************************************************/


// 16 ms, faster than 95.48% of C++, 11 MB, less than 16.65% of C++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2 || k == 0) return false;
        int low = 0;
        //maintain a sliding window 
        set<long long> window;
        for (int i=0; i<nums.size(); i++){
            //make sure window size <= k
            if (i - low > k) {
                window.erase(nums[low]);
                low++;
            }
            
            // lower_bound() is the key, 
            // it returns an iterator pointing to the first element >= val 
            auto it = window.lower_bound((long long)nums[i] - (long long)t );
            if (it != window.end() && abs((long long)nums[i] - *it) <= (long long)t) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};

