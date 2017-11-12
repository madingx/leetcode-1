// Source : https://leetcode.com/problems/palindromic-substrings/description/
// Author : Mading
// Date   : 2017-11-12

/********************************************************************************** 
* 647. Palindromic Substrings  //回文
* 
* Given a string, your task is to count how many palindromic substrings in this string.
* The substrings with different start indexes or end indexes are counted as different 
* substrings even they consist of same characters.

* Example 1:
* Input: "abc"
* Output: 3
* Explanation: Three palindromic strings: "a", "b", "c".
* 
* Example 2:
* Input: "aaa"
* Output: 6
* Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
* 
* Note:
* The input string length won't exceed 1000.
*               
**********************************************************************************/

//http://blog.csdn.net/lishichengyan/article/details/77103324
//另外一种DP的方式是：定义d[i][j]：若从i到j的字符串为回文，
//则为真（1），否则为假（0），那么d[i][j]为真的前提是：
//头尾两个字符串相同并且去掉头尾以后的字串也是回文（即d[i+1][j-1]为真），
//这里面要注意特殊情况，即：去掉头尾以后为空串，所以如果j-i<3，并且头尾相等，也是回文的。
//这样就得到了下面的关键代码：
//dp[i][j]=((s[i]==s[j])&&(j-i<3||dp[i+1][j-1]));  
//

class Solution {
public:
    int countSubstrings(string s) {
        int len=s.size(),res=0;  
        vector<vector<int>> dp(len,vector<int>(len,0));  
        for(int i=len-1;i>=0;i--){  
            for(int j=i;j<len;j++){  
                dp[i][j]=((s[i]==s[j])&&(j-i<3||dp[i+1][j-1]));  
                if(dp[i][j])  
                    res++;  
            }  
        }  
        return res; 
    }
};


//此题可以搜到很多种解法