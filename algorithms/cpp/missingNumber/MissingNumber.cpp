// Source : https://leetcode.com/problems/missing-number/
// Author : Hao Chen
// Date   : 2015-10-22

/*************************************************************************************** 
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the 
 * one that is missing from the array.
 * 
 * For example,
 * Given nums = [0, 1, 3] return 2.
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using 
 * only constant extra space complexity?
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 ***************************************************************************************/

class Solution {
public:
    
    //vector
    //28 ms   9.8 MB
    int missingNumber_vec(vector<int>& nums) {
        vector<bool> arr(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]=1;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)return i;
        }
        return 0;
    }

    // This problem can be converted to the classic problem --
    //    `There is an array, all of numbers except one appears twice, and that one only appears once`
    // It means, we can combin two arrays together, one is [1..n], another one is `nums`.
    // Then, you know, we can use the XOR solve this problem.

    //28 ms 9.7 MB
    int missingNumber01(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            result ^=  nums[i];
        }
        for(int i=1; i<=nums.size(); i++){
            result ^=(i);
        }
        return result;
    }
    
    //28 ms 9.8 MB
    // We can simplify the previous solution as below
    int missingNumber02(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            result = result ^ (i+1) ^ nums[i];
        }
        return result;
    }
    
    int missingNumber(vector<int>& nums) {
        //By Leetcode running result, they all are same performance
        return missingNumber02(nums); //36ms
        return missingNumber01(nums); //36ms
    }
};
