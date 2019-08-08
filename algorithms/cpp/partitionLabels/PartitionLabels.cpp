// Source : https://leetcode.com/problems/partition-labels/
// Author : Mading
// Date   : 2019-08-08

/********************************************************************************** 
* 763. Partition Labels [Medium]
* A string S of lowercase letters is given. We want to partition this string into 
* as many parts as possible so that each letter appears in at most one part, and 
* return a list of integers representing the size of these parts.

* Example 1:
* Input: S = "ababcbacadefegdehijhklij"
* Output: [9,7,8]
* Explanation:
* The partition is "ababcbaca", "defegde", "hijhklij".
* This is a partition so that each letter appears in at most one part.
* A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

* Note:
* S will have length in range [1, 500].
* S will consist of lowercase letters ('a' to 'z') only.
*               
**********************************************************************************/


// 4 ms, faster than 92.87% of C++, 8.9 MB, less than 35.48% of C++ 
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> mapend;
        for(int i = 0;i<S.size();i++){
            mapend[S[i]] = i;
        }
        vector<int> res;
        int left = 0,right = 0;
        while(right <= S.size()-1){
            for(int i = left;i <= right && i < S.size();i++){
               right = max(mapend[S[i]],right); 
            }
            res.push_back(right-left+1);
            left = right + 1;
            right = left;
        }
        return res;    
    }
};