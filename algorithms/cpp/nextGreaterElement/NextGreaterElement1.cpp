// Source : hhttps://leetcode.com/problems/next-greater-element-i/
// Author : Mading
// Date   : 2019-09-28

/*************************************************************************************** 
 * 496. Next Greater Element I [Easy]
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements 
 * are subset of nums2. Find all the next greater numbers for nums1's elements 
 * in the corresponding places of nums2.

 * The Next Greater Number of a number x in nums1 is the first greater number to
 *  its right in nums2. If it does not exist, output -1 for this number.

 * Example 1:
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 *     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
 *     For number 1 in the first array, the next greater number for it in the second array is 3.
 *     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 * Example 2:
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 *     For number 2 in the first array, the next greater number for it in the second array is 3.
 *     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 * Note:
 * All elements in nums1 and nums2 are unique.
 * The length of both nums1 and nums2 would not exceed 1000.
 *               
 ***************************************************************************************/

// 8 ms, faster than 97.44% of C++, 9.3 MB, less than 73.68% of C++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mymap;
        for(int i=0;i<nums2.size();i++){
            mymap[nums2[i]] = -1;
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[j] > nums2[i] ){
                    mymap[nums2[i]] = nums2[j];
                    break;
                }
            }
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i] = mymap[nums1[i]];
        }
        return nums1;
    }
};




// 16 ms, faster than 15.50% of C++, 8.7 MB, less than 100.00% of C++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            int m = nums1[i];
            nums1[i] = -1;
            int k = INT_MAX;
            for(int j=0;j<nums2.size();j++){
                if(nums2[j] == m){
                    k = j;
                }
                if(nums2[j] > m && j > k){
                    nums1[i] = nums2[j];
                    break;
                }
                
            }
            
        }
        return nums1;
    }
};