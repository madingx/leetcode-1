// Source : https://leetcode.com/problems/valid-palindrome/submissions/
// Author : Hao Chen
// Date   : 2014-06-26

/********************************************************************************** 
* 125. Valid Palindrome [easy]
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
* 
* Note: For the purpose of this problem, we define empty string as valid palindrome.

* Example 1:
* Input: "A man, a plan, a canal: Panama"
* Output: true

* Example 2:
* Input: "race a car"
* Output: false
*               
**********************************************************************************/

class Solution {
public:
    //12 ms 9.6 MB, faster than 77.92% of C++
    bool isPalindrome(string s) {
        s = removeNoise(s);
        for(int i=0; i<s.size()/2; i++){
            if (s[i]!= s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    
    string removeNoise(string& s){
        string d;
        for(int i=0; i<s.size(); i++){
            if(::isalpha(s[i]) || ::isdigit(s[i])){
                d.push_back(::tolower(s[i]));
            }
        }
        return d;
    }
};
