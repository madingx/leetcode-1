// Source : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
// Author : Mading
// Date   : 2017-11-12


/********************************************************************************** 
 * 448. Find All Numbers Disappeared in an Array
 * 
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? 
 * You may assume the returned list does not count as extra space.
 *
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [5,6]
 *               
 **********************************************************************************/

//https://www.cnblogs.com/grandyang/p/6222149.html

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
            //第i位为负表示i出现过。
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
