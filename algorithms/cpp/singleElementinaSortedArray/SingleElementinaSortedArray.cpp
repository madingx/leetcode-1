// Source : https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author : Mading
// Date   : 2019-08-31

/********************************************************************************** 
* 540. Single Element in a Sorted Array [Medium]
* Given a sorted array consisting of only integers where every element appears 
* exactly twice except for one element which appears exactly once. 
* Find this single element that appears only once. 

* Example 1:
* Input: [1,1,2,3,3,4,4,8,8]
* Output: 2

* Example 2:
* Input: [3,3,7,7,10,11,11]
* Output: 10
 

* Note: Your solution should run in O(log n) time and O(1) space.
* [1,3,5,6], 0 → 0
* 
*               
**********************************************************************************/

// 8 ms, faster than 96.52% of C++, 9.5 MB, less than 21.43% of C++
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums[0];
        for(int i=1;i<nums.size();i++){
            n = nums[i] ^ n;
        }
        return n;
    }
};