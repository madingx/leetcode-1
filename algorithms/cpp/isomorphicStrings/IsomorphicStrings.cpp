// Source : https://leetcode.com/problems/isomorphic-strings/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 205. Isomorphic Strings [Easy]
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while preserving 
 * the order of characters. No two characters may map to the same character but a character
 *  may map to itself.
 * 
 * For example,
 *
 *     Given "egg", "add", return true.
 *     
 *     Given "foo", "bar", return false.
 *     
 *     Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 *               
 **********************************************************************************/

// 4 ms, faster than 99.97% of C++ 9.2 MB, less than 8.95% of C++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size()!=t.size()) return false;
        
        const int MAXCHAR = 256;
        char maps[MAXCHAR]={0}, mapt[MAXCHAR]={0};
        //memset(maps, 0, sizeof(maps));
        //memset(mapt, 0, sizeof(mapt));
        
        for(int i=0; i<s.size(); i++){
            if(maps[s[i]] == 0 && mapt[t[i]] == 0){
                maps[s[i]] = t[i];
                mapt[t[i]] = s[i];
                continue;
            }
            if(maps[s[i]] == t[i] && mapt[t[i]] == s[i]) {
                continue;
            }
            return false;
        }
        return true;
    }
};

// 12 ms, faster than 68.30% of C++, 9.4 MB, less than 7.37% of C++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())return false;
        unordered_map<char,char> map1,map2; 
        for(int i=0;i<s.size();i++){
            if(map1.find(s[i])!=map1.end()){
                if(map1[s[i]] != t[i]) return false;
            }
            else{
                map1[s[i]] = t[i];         
            }
            
            if(map2.find(t[i])!=map2.end()){
                if(map2[t[i]] != s[i]) return false;
            }
            else{
                map2[t[i]] = s[i];        
            }
        }
        return true;
    }
};