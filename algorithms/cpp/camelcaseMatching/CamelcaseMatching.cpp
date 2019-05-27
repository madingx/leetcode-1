// Source : https://leetcode.com/problems/camelcase-matching/
// Author : Mading
// Date   : 2019-05-24

/*************************************************************************************** 
 * 1023. Camelcase Matching [Medium]
 * A query word matches a given pattern if we can insert lowercase letters to 
 * the pattern word so that it equals the query. (We may insert each character
 * at any position, and may insert 0 characters.)

 * Given a list of queries, and a pattern, return an answer list of booleans, 
 * where answer[i] is true if and only if queries[i] matches the pattern.

 * Example 1:

 * Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
 * Output: [true,false,true,true,false]
 * Explanation: 
 * "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
 * "FootBall" can be generated like this "F" + "oot" + "B" + "all".
 * "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

 * Example 2:

 * Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
 * Output: [true,false,true,false,false]
 * Explanation: 
 * "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
 * "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

 * Example 3:

 * Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
 * Output: [false,true,false,false,false]
 * Explanation: 
 * "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

 * Note:

 * 1 <= queries.length <= 100
 * 1 <= queries[i].length <= 100
 * 1 <= pattern.length <= 100
 * All strings consists only of lower and upper case English letters.
 *               
 ***************************************************************************************/

// 0 ms, faster than 100.00% of C++, 8.5 MB, less than 54.78% of C++
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> results(queries.size());
        vector<string> queriesPattern;
        int patternIndex = 0; // use a pointer to indicate the position of pattern
        for(int i = 0; i<queries.size(); i++) {
            patternIndex = 0;
            results[i] = true; //assumed to be true 
            for(int j = 0; j < queries[i].length(); j++) {
                if(queries[i][j] == pattern[patternIndex])
                {
                    patternIndex++;
                    continue;
                }
                // If small case
                if(!checkUpperCase(queries[i][j])) {
                    continue;
                }
                
                if(checkUpperCase(queries[i][j])) {
                    if (patternIndex >= pattern.length() || queries[i][j] != pattern[patternIndex]){
                        results[i] = false;
                        break;
                    }
                }
            }
            //If a query is done, still not reach the end of pattern, return false
            if(patternIndex < pattern.length())
                results[i] = false;
        }
        return results;
    }
    
    bool checkUpperCase(char letter) {
        if(letter >= 'A' && letter <= 'Z') {
            return true;
        } else {
            return false;
        }
    }
};