// Source : https://leetcode.com/problems/decode-ways/
// Author : Hao Chen
// Date   : 2014-07-16

/********************************************************************************** 
* 91. Decode Ways [Medium]
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
* 
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* 
* Given an encoded message containing digits, determine the total number of ways to decode it.
* 
* Example 1:
* Input: "12"
* Output: 2
* Explanation: It could be decoded as "AB" (1 2) or "L" (12).

* Example 2:
* Input: "226"
* Output: 3
* Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// 4 ms, faster than 100.00% of C++, 8.2 MB, less than 94.57% of C++ 
class Solution {
public:
    int numDecodings(string s) {
        int p = 1, pp, n = s.size();
        for(int i=n-1;i>=0;i--) {
            int cur = s[i]=='0' ? 0 : p;
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) cur+=pp;
            pp = p;
            p = cur;
        }
        return s.empty()? 0 : p;   
    }
};


// 8 ms, faster than 35.66% of C++  8.3 MB, less than 88.29% of C++ 

//Count[i] = Count[i-1]              if S[i-1] is a valid char (not '0')
//         = Count[i-1]+ Count[i-2]  if S[i-1] and S[i-2] together is still a valid char (10 to 26).

int check(char ch){
    //check 0 or not
    return (!isdigit(ch) || ch=='0') ? 0 : 1;
}

int check(char ch1, char ch2){
    //check it's between 10 and 26
    return (ch1=='1' || (ch1=='2' && ch2<='6')) ? 1: 0;
}

int numDecodings(string s) {
    if (s.size()<=0) return 0;
    if (s.size()==1) return check(s[0]);
   
    int* dp = new int[s.size()];
    memset(dp, 0, s.size()*sizeof(int));

    dp[0] = check(s[0]);
    dp[1] = check(s[0]) *  check(s[1]) + check(s[0], s[1]) ;
    for (int i=2; i<s.size(); i++) {
        if (!isdigit(s[i])) break; 
        if (check(s[i])) {
            dp[i] = dp[i-1];
        }
        if (check(s[i-1], s[i])) {
            dp[i] += dp[i-2];
        }
    
    }
    int result = dp[s.size()-1];
    delete[] dp;
    return result;
}


int main(int argc, char**argv)
{
    string s = "123";
    if (argc>1){
        s = argv[1];
    }
    cout << "\"" << s << "\" : " << numDecodings(s) << endl; 
    return 0;
}
