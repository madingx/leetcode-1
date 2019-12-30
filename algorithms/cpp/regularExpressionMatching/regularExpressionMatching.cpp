// Source : https://leetcode.com/problems/regular-expression-matching/
// Author : Hao Chen, Mading
// Date   : 2014-08-24, 2019-12-30

/********************************************************************************** 
* 10. Regular Expression Matching [Hard]
* Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).

* Note:

* s could be empty and contains only lowercase letters a-z.
* p could be empty and contains only lowercase letters a-z, and characters like . or *.
* Example 1:

* Input:
* s = "aa"
* p = "a"
* Output: false
* Explanation: "a" does not match the entire string "aa".
* Example 2:

* Input:
* s = "aa"
* p = "a*"
* Output: true
* Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
* Example 3:

* Input:
* s = "ab"
* p = ".*"
* Output: true
* Explanation: ".*" means "zero or more (*) of any character (.)".
* Example 4:

* Input:
* s = "aab"
* p = "c*a*b"
* Output: true
* Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
* Example 5:

* Input:
* s = "mississippi"
* p = "mis*is*p*."
* Output: false          
*     
**********************************************************************************/


// 220 ms, faster than 12.84% of C++ 15.4 MB, less than 10.17% of C++
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
        
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            //   0 tims || 1 times
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};

// https://leetcode.com/problems/regular-expression-matching/discuss/5665/My-concise-recursive-and-DP-solutions-with-full-explanation-in-C%2B%2B
// 8 ms, faster than 66.41% of C++, 9 MB, less than 66.10% of C++ 
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        for(int i=1;i<=m;i++){
            dp[i][0] = false;
        }
        for(int j=1;j<=n;j++){
            dp[0][j] = j>1 && '*'==p[j-1] && dp[0][j-2];
        }
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if(p[j-1] != '*'){
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || '.' == p[j-1]);
                }
                else{
                    dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || '.' == p[j-2]) && dp[i-1][j];
                }
            }
        }
            
        return dp[m][n];
        
        
    }
};






#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


bool isMatch(const char *s, const char *p) {

    if (*p=='\0') {
        return *s == '\0';
    }
    //p's length 1 is special case 
    if (*(p+1) == '\0' || *(p+1) !='*' ) {
        if (*s=='\0' || ( *p !='.' && *s != *p )) {
            return false;
        }
        return isMatch(s+1, p+1);
    }
    int len = strlen(s);
    int i = -1;
    while (i < len && (i <0 || *p=='.' || *p==*(s+i)) ){
        if (isMatch(s+i+1, p+2)) {
            return true;
        }
        i++;
    }
    return false;
}


int main(int argc, char** argv)
{
    const char* s = "aaa";
    const char* p = "a.*";

    if (argc>2) {
        s = argv[1];
        p = argv[2];
    }

    cout << s << ", " << p << " : " << isMatch(s,p) << endl;
}
