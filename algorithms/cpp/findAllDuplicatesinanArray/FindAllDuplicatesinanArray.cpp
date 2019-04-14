// Source : https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Author : Mading
// Date   : 2019-04-14


/********************************************************************************** 
 * 442. Find All Duplicates in an Array [Medium]
 * 
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * Find all the elements that appear twice in this array.
 * Could you do it without extra space and in O(n) runtime?

 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [2,3]
 *               
 **********************************************************************************/

// 116 ms, faster than 95.87% of C++, 14.9 MB, less than 97.81% of C++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {        
        vector<int> ret;
        int n = nums.size();
        for(int i=1;i<=n;i++){
            if(nums[i-1] == i){
                continue;
            } 
            //swap
            int tmp = nums[i-1];
            nums[i-1] = 0;
            int j = tmp;
            while(j>0){
                if(j == nums[j-1]){
                    ret.push_back(j);
                    break;
                }
                else{
                    //swap
                    tmp = nums[j-1];
                    nums[j-1] = j;
                    j = tmp;
                }
            }
        }
        return ret;
    }
};