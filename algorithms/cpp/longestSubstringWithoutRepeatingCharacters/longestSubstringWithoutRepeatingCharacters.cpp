// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Hao Chen
// Date   : 2014-07-19

/********************************************************************************** 
* Given a string, find the length of the longest substring without repeating characters.

* Example 1:
* Input: "abcabcbb"
* Output: 3 
* Explanation: The answer is "abc", with the length of 3. 

* Example 2:
* Input: "bbbbb"
* Output: 1
* Explanation: The answer is "b", with the length of 1.

* Example 3:
* Input: "pwwkew"
* Output: 3
* Explanation: The answer is "wke", with the length of 3. 
*              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
**********************************************************************************/

#include <string.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
 * Idea:
 * 
 * Using a map store each char's index.
 * 
 * So, we can be easy to know the when duplication and the previous duplicated char's index.
 * 
 * Then we can take out the previous duplicated char, and keep tracking the maxiumn length. 
 * 
 */
int lengthOfLongestSubstring1(string s) {
    map<char, int> m;
    int maxLen = 0;
    int lastRepeatPos = -1;
    for(int i=0; i<s.size(); i++){
        if (m.find(s[i])!=m.end() && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
}
//don't use <map>
//Perfect: Runtime: 16 ms, faster than 99.39% of C++;Memory Usage: 14.7 MB, less than 89.81% of C++.
int lengthOfLongestSubstring(string s) {
    const int MAX_CHARS = 256;
    int m[MAX_CHARS];
    memset(m, -1, sizeof(m));

    int maxLen = 0;
    int lastRepeatPos = -1;
    for(int i=0; i<s.size(); i++){
        if (m[s[i]]!=-1 && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
}

int main(int argc, char** argv)
{
    string s = "abcabcbb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "bbabcdb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    if (argc>1){
        s = argv[1];
        cout << s << " : " << lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
