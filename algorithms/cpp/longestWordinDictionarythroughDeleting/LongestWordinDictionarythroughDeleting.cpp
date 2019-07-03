// Source : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// Author : Mading
// Date   : 2019-07-03

/*************************************************************************************** 
 * 524. Longest Word in Dictionary through Deleting [Medium]
 * Given a string and a string dictionary, find the longest string in the dictionary 
 * that can be formed by deleting some characters of the given string. If there are 
 * more than one possible results, return the longest word with the smallest 
 * lexicographical order. If there is no possible result, return the empty string.

 * Example 1:
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]

 * Output: 
 * "apple"
 * Example 2:
 * Input:
 * s = "abpcplea", d = ["a","b","c"]

 * Output: 
 * "a"
 * Note:
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
 ***************************************************************************************/

// 88 ms, faster than 76.79% of C++, 15.9 MB, less than 89.66% of C++ 
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for (int i = 0; i < d.size(); i++) {
            int pi = 0, pj = 0;
            for (; pi < s.size() && pj < d[i].size(); pi++) {
                pj += s[pi] == d[i][pj];
            }
            if (pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
                ans = d[i];
        }
        return ans;
    }
};