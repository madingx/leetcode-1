// Source : https://leetcode.com/problems/split-array-largest-sum/
// Author : Mading
// Date   : 2019-06-07

/*************************************************************************************** 
 * 659. Split Array into Consecutive Subsequences [Medium]
 * You are given an integer array sorted in ascending order (may contain duplicates),
 * you need to split them into several subsequences, where each subsequences consist 
 * of at least 3 consecutive integers. Return whether you can make such a split.

 * Example 1:
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3
 * 3, 4, 5

 * Example 2:
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3, 4, 5
 * 3, 4, 5

 * Example 3:
 * Input: [1,2,3,4,4,5]
 * Output: False

 * Note:
 * The length of the input is in range of [1, 10000]
 ***************************************************************************************/

// 240 ms, faster than 16.19% of C++, 31.9 MB, less than 15.06% of C++
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>,std::greater<int>>> mp;
        int consective=0;
        for(auto num:nums)
        {
            if(mp[num-1].empty()) //不能使用mp.find(num-1)==mp.end()
            {
                mp[num].push(1);
                consective++;
            }
            else
            {
               int size = mp[num-1].top();
                mp[num-1].pop();
                size++;
                mp[num].push(size);
                if(size==3) consective--;
            }
        }
        return consective==0?true:false;
    }
};