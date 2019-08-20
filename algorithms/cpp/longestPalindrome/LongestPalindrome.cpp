// Source : https://leetcode.com/problems/longest-palindrome/
// Author : Hao Chen, Mading
// Date   : 2016-11-13

/*************************************************************************************** 
 * 409. Longest Palindrome [Easy]
 * Given a string which consists of lowercase or uppercase letters, find the length of 
 * the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 ***************************************************************************************/

// 4 ms, faster than 83.12% of C++, 8.6 MB, less than 100.00% of C++
class Solution {
public:
    int longestPalindrome(string s) {
        
        int hashtable[128];
        memset(hashtable, 0, sizeof(hashtable));
        
        for(char ch : s) {
            hashtable[ch]++;
        }
        int result = 0;
        bool hasOdd = false;
        for (int n : hashtable) {
            if ( n%2 == 0 ) {
                result += n;
            } else {
                result += n -1;
                hasOdd = true;
            }
        }
        
        return hasOdd ? result + 1 : result;
    }
};



// 4 ms, faster than 83.12% of C++, 9 MB, less than 33.33% of C++
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> dictmap;
        for(auto c:s)dictmap[c]++;
        int n = 0;
        for(auto item:dictmap){
            if(item.second%2==1)n++;
        }
        return s.size() - (n>0 ? n-1 : 0);
    }
};