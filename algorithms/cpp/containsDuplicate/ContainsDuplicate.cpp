// Source : https://leetcode.com/problems/contains-duplicate/
// Author : Hao Chen
// Date   : 2015-06-11

/********************************************************************************** 
 * 217. Contains Duplicate [Easy]
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.

 * Example 1:
 * Input: [1,2,3,1]
 * Output: true

 * Example 2:
 * Input: [1,2,3,4]
 * Output: false

 * Example 3:
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *               
 **********************************************************************************/


class Solution {
public:
    // 48 ms, faster than 42.63% of C++, 16.4 MB, less than 55.53% of C++ 
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (auto item : nums) {
            if (m.find(item) != m.end()) return true;
            m[item]=true;
        }
        return false;
    }

    // 72 ms, faster than 7.88% of C++, 16.6 MB, less than 21.30% of C++ 
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> a;
        for(int i=0;i<nums.size();i++){
            if(a.find(nums[i]) != a.end()){
                return true;
            }
            else{
                a[nums[i]] = 1;
            }
        }
        return false;
    }

};
