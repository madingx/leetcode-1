// Source : https://leetcode.com/problems/ransom-note/
// Author : Hao Chen
// Date   : 2016-08-24

/*************************************************************************************** 
 * 383. Ransom Note [Easy]
 *  Given  an  arbitrary  ransom  note  string  and  another  string  containing 
 *  letters from  all  the  magazines,  write  a  function  that  will  return  true 
 *  if  the  ransom  
 * note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return 
 *  false.   
 * 
 * Each  letter  in  the  magazine  string  can  only  be  used  once  in  your 
 *  ransom  note.
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 ***************************************************************************************/

// 32 ms, faster than 44.98% of C++ 10.9 MB, less than 67.15% of C++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mymap;
        for(auto c : magazine){
            mymap[c]++;
        }
        for(auto c: ransomNote){
            if(mymap.find(c) == mymap.end() || mymap[c] == 0)return false;
            mymap[c]--;
        }
        return true;
    }
};