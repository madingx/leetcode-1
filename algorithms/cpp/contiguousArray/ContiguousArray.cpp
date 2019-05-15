// Source : https://leetcode.com/problems/contiguous-array/
// Author : Mading
// Date   : 2019-05-15

/********************************************************************************** 
 * 525. Contiguous Array [Medium]
 * Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

 * Example 1:
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

 * Example 2:
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 * Note: The length of the given binary array will not exceed 50,000.
 *               
 **********************************************************************************/

// 132 ms, faster than 68.89% of C++, 20.5 MB, less than 62.59% of C++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> myMap;
        map<int, int>::iterator it;
        int sum = 0;
        int maxLen = 0;
        myMap[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] == 0) ? -1 : 1;
            it = myMap.find(sum); 
            if (it != myMap.end())
                maxLen = max(maxLen, i - it->second);
            else
                myMap[sum] = i;
        }
        return maxLen;
    }
};
/*************************
nums  0 1 0 0 1 1 0 1 0 1 1
nums0 1 1 2 3 3 3 4 4 5 6 6
nums1 0 1 1 1 2 3 3 4 4 5 6
minus 1 0 1 2 1 0 1 0 1 1 0
mymap 0=-1, 1=0, 2=3
**************************/


// 76 ms, faster than 99.54% of C++, 16.3 MB, less than 99.43% of C++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size(), ballance = size, max_len = 0;
        int ballances[size * 2 + 1] = {};
        for (auto i = 0; i < size; ++i) {
            ballance += nums[i] == 0 ? -1 : 1; //nums1-nums0
            if (ballance == size) max_len = i + 1;
            else {
                if (ballances[ballance] != 0) max_len = max(max_len, i - ballances[ballance] + 1);
                else ballances[ballance] = i + 1;
            }
        }
        return max_len;
    }
};



    
