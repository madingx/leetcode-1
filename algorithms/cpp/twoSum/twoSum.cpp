// Source : https://leetcode.com/problems/two-sum/description/
// Author : Hao Chen
// Date   : 2014-06-17
// 
// Latest Edition
// Editor : Mading
// Date   : 2017-11-12

/********************************************************************************** 
* 1. Two Sum
* 
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* 
* Input: numbers={2, 7, 11, 15}, target=9,
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
* 
**********************************************************************************/

class Solution {
public:
    /*
     *   The easy solution is O(n^2) run-time complexity.
     *   ```
     *       foreach(item1 in array) {
     *           foreach(item2 in array){
     *               if (item1 + item2 == target) {
     *                   return result
     *               }
     *           }
     *   ```
     *   
     *   We can see the nested loop just for searching, 
     *   So, we can use a hashmap to reduce the searching time complexity from O(n) to O(1)
     *   (the map's `key` is the number, the `value` is the position)
     *   
     *   But be careful, if there are duplication numbers in array, 
     *   how the map store the positions for all of same numbers?
     *
     */


    //
    // The implementation as below is bit tricky. but not difficult to understand
    //
    //  1) Traverse the array one by one
    //  2) just put the `target - num[i]`(not `num[i]`) into the map
    //     so, when we checking the next num[i], if we found it is exisited in the map.
    //     which means we found the second one.
    //      
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;

        /*** Solultion one***/
        // for(int i=0; i<nums.size(); i++){
        //     // not found the second one
        //     if (m.find(nums[i])==m.end() ) { 
        //         // store the first one poisition into the second one's key
        //         m[target - nums[i]] = i; 
        //     }else { 
        //         // found the second one
        //         result.push_back(m[nums[i]]);
        //         result.push_back(i);
        //         break;
        //     }
        // }

        /*** Solultion two***/
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t) && m[t] != i) {
                result.push_back(i);
                result.push_back(m[t]);
                break;
            }
        }
        /////////////

        return result;
    }
};
