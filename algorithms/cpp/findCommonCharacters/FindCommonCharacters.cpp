// Source : https://leetcode.com/problems/find-common-characters/
// Author : Mading
// Date   : 2019-04-13

/********************************************************************************** 
 * 1002. Find Common Characters [Easy]

 * Given an array A of strings made only from lowercase letters, return a list of
 * all characters that show up in all strings within the list (including duplicates).
 * For example, if a character occurs 3 times in all strings but not 4 times, 
 * you need to include that character three times in the final answer.

 * You may return the answer in any order.

 * Example 1:
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]

 * Example 2:
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]

 * Note:
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
 *               
 **********************************************************************************/

// 12 ms, faster than 97.87% of C++, 9.5 MB, less than 100.00% of C++
class Solution {
    vector<string> vs;
    enum{ Z = 26 };
public:
    void map(vector<int> &v, const string &s) const {
        for(auto c : s){
            ++v[c - 'a'];
        }
    }

    void reduce(vector<int> &va, const vector<int> &vb) const {
        for(int i = 0; i < Z; ++i){
            va[i] = min(va[i], vb[i]);
        }
    }
    
    void expand(vector<string> &v, const vector<int> &va) const {
        string s(1, 'a');
        for(int i = 0; i < Z; ++i){
            for(int x = va[i]; x > 0; --x){
                s[0] = 'a' + i;
                v.push_back(s);
            }
        }
    }
    
    vector<string>& commonChars(const vector<string>& A) {
        const int n = A.size();
        if(n > 0){
            vector<int> va(Z), vb(Z);
            map(va, A[0]);
            for(int i = 1; i < n; ++i){
                vb.assign(Z, 0);
                map(vb, A[i]);
                reduce(va, vb);
            }
            expand(vs, va);
        }
        return vs;
    }
};