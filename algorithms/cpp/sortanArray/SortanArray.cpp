// Source : https://leetcode.com/problems/sort-an-array/
// Author : Mading
// Date   : 2019-08-14

/********************************************************************************** 
 * 912. Sort an Array [Medium]
 * Given an array of integers nums, sort the array in ascending order. 

 * Example 1:
 * Input: [5,2,3,1]
 * Output: [1,2,3,5]

 * Example 2:
 * Input: [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 
 * Note:
 * 1 <= A.length <= 10000
 * -50000 <= A[i] <= 50000
 *               
 **********************************************************************************/、


// Quick sort
// 60 ms, faster than 87.86% of C++, 12.5 MB, less than 94.44% of C++ 
class Solution {
    int partition(vector<int>& nums,int low,int high) {
        int temp = nums[low];
        int i = 0;
        while(low<high){
            if(i%2 == 1){                
                if(nums[low] > temp){
                    nums[high] = nums[low];
                    high--;
                    i++;
                }
                else{
                    low++;
                }
            }
            if(i%2 == 0){                
                if(nums[high] < temp){
                    nums[low] = nums[high];
                    low++;
                    i++;
                }
                else{
                    high--;
                }
            }
            
        }
        nums[low] = temp;
        return low;        
    }
    
    void sortArrayResc(vector<int>& nums,int low,int high) {
        if(low >= high) return;
        int mid = partition(nums,low,high);
        sortArrayResc(nums,low,mid-1);
        sortArrayResc(nums,mid+1,high); 
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        sortArrayResc(nums,0,nums.size()-1);
        return nums;
    }
};

