// Source : https://leetcode.com/problems/jump-game/
// Author : Hao Chen
// Date   : 2014-06-27

/********************************************************************************** 
* 55. Jump Game [Medium]
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* Each element in the array represents your maximum jump length at that position. 
* Determine if you are able to reach the last index.
* 
* Example 1:
* Input: [2,3,1,1,4]
* Output: true
* Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

* Example 2:
* Input: [3,2,1,0,4]
* Output: false
* Explanation: You will always arrive at index 3 no matter what. Its maximum
*              jump length is 0, which makes it impossible to reach the last index.
*               
**********************************************************************************/

class Solution {
public:

    //12 ms 10.2 MB, faster than 98.72% of C++
    bool canJump(vector<int>& nums) {
        if (nums.size()<=0) return false;
        
        // the basic idea is traverse array, maintain the most far can go
        int coverPos=0;
        // the condition i<=coverPos means traverse all of covered position 
        for(int i=0; i<=coverPos && i<nums.size(); i++){
            
            if (coverPos < nums[i] + i){
                coverPos = nums[i] + i;
            }
            
            if (coverPos>=nums.size()-1){
                return true;
            }
        }
        return false;
    }

    //16 ms 10.3 MB, faster than 45.14% of C++
    bool canJump(vector<int>& nums) {
        vector<bool> flags(nums.size(),false);
        int m = 0;
        for(int i=0;i<nums.size();i++){
            if(i>m)return false;
            if((nums[i]+i)>m){m = nums[i]+i;}
            if(m>nums.size())return true;
        }
        return true;
    }
};
