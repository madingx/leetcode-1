// Source : hhttps://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Author : Mading
// Date   : 2019-06-23

/*************************************************************************************** 
 * 1047. Remove All Adjacent Duplicates In String [Easy]
 * Given a string S of lowercase letters, a duplicate removal consists of choosing 
 * two adjacent and equal letters, and removing them.

 * We repeatedly make duplicate removals on S until we no longer can.

 * Return the final string after all such duplicate removals have been made.  
 * It is guaranteed the answer is unique.

 

 * Example 1:

 * Input: "abbaca"
 * Output: "ca"
 * Explanation: 
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, 
 * and this is the only possible move.  The result of this move is that the string is "aaca", 
 * of which only "aa" is possible, so the final string is "ca".
 

 * Note:

 * 1 <= S.length <= 20000
 * S consists only of English lowercase letters.
 ***************************************************************************************/




// 24 ms, faster than 66.53% of C++, 12.3 MB, less than 100.00% of C++
class Solution {
public:
    string removeDuplicates(string S) {
    string out;
    for (auto i = 0; i < S.size(); i++)
    {
        if (out.size() !=0 && out[out.size() -1] == S[i])
        {
            out.pop_back();
            continue;
        }
        out.push_back(S[i]);
    }

    return out;   
    }
}; 


// 52 ms, faster than 29.68% of C++, 14 MB, less than 100.00% of C++ 
class Solution {
public:
    
    string removeDuplicatescall(string S)
    {
        int s=S.size();
        for(int i=0;i<s-1;i++)
        {
            
            if(S[i+1]==S[i])
            {
               S.erase(i,2);
            }
        }
        return S;
    }
    string removeDuplicates(string S)
    {
        
        string finalString=S;
        for(int i=0;i<5;i++)
        {
             finalString=removeDuplicatescall(finalString);
        }
        return finalString;
    }
};