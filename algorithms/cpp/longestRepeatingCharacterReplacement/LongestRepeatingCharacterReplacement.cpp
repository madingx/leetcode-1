// Source : https://leetcode.com/problems/longest-repeating-character-replacement/
// Author : Mading
// Date   : 2019-6-29

/*************************************************************************************** 
 * 424. Longest Repeating Character Replacement [Medium]
 * Given a string that consists of only uppercase English letters, you can replace 
 * any letter in the string with another letter at most k times. Find the length 
 * of a longest substring containing all repeating letters you can get after 
 * performing the above operations.

 * Note:
 * Both the string's length and k will not exceed 104.

 * Example 1:

 * Input:
 * s = "ABAB", k = 2

 * Output:
 * 4

 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * Example 2:

 * Input:
 * s = "AABABBA", k = 1

 * Output:
 * 4

 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 ***************************************************************************************/


// 16 ms, faster than 58.86% of C++, 9.3 MB, less than 52.35% of C++ 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int start = 0; int end = 0; int localMaxFreq = 0; 
        for(; end<size; end++){
            count[s[end]-'A'] += 1;
            localMaxFreq = max(localMaxFreq, count[s[end]-'A']);
            if((end-start+1)-localMaxFreq > k) {
                ret = max(ret, (end-start));
                count[s[start]-'A'] -= 1;
                start += 1;
                localMaxFreq = *(max_element(count.begin(), count.end()));
            }
        }
        return max(ret, end-start);
    }
};


// 8 ms, faster than 96.55% of C++, 9.4 MB, less than 36.69% of C++
class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int start = 0; int end = 0; int globalMaxFreq = 0; 
        for(; end<size; end++){
            count[s[end]-'A'] += 1;
            globalMaxFreq = max(globalMaxFreq, count[s[end]-'A']);
            if((end-start+1)-globalMaxFreq > k) {
                ret = max(ret, (end-start));
                count[s[start]-'A'] -= 1;
                start += 1;
            }
        }
        return max(ret, end-start);
    }
};