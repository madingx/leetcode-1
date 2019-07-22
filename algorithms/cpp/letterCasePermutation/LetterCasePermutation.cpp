// Source : https://leetcode.com/problems/letter-case-permutation/
// Author : Mading
// Date   : 2019-07-22

/********************************************************************************** 
 * 784. Letter Case Permutation [Easy]
 * Given a string S, we can transform every letter individually to be lowercase or 
 * uppercase to create another string.  Return a list of all possible strings we could create.

 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]

 * Input: S = "12345"
 * Output: ["12345"]

 * Note:
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
 *               
 **********************************************************************************/

// 12 ms, faster than 63.91% of C++, 13.8 MB, less than 38.84% of C++
class Solution {
public:
    char upper(char a){
        if( a>='a' && a<='z') a = a - 32;
        return a;
    }
    char lower(char a){
        if( a>='A' && a<='Z') a = a + 32;
        return a;
            
    }
    bool isdigit(char a){
        return a>='0' && a<='9';
    }
    void letterCaseResc(string &S,int k,string newS,vector<string> &res) {
        if(k>=S.size()){res.push_back(newS);return;}
        if( isdigit(S[k]) )letterCaseResc(S,k+1,newS + S[k],res);
        else{
            letterCaseResc(S,k+1,newS + lower(S[k]),res);
            letterCaseResc(S,k+1,newS + upper(S[k]),res);
        }
        return;
    }


    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string newS = "";
        letterCaseResc(S,0,newS,res);
        return res;
    }
};