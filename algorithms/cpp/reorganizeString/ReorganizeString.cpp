// Source : https://leetcode.com/problems/reorganize-string/
// Author : Mading
// Date   : 2019-06-03

/*************************************************************************************** 
 * 767. Reorganize String [Medium]
 * Given a string S, check if the letters can be rearranged so that 
 * two characters that are adjacent to each other are not the same.

 * If possible, output any possible result.  If not possible, return the empty string.

 * Example 1:

 * Input: S = "aab"
 * Output: "aba"
 * Example 2:

 * Input: S = "aaab"
 * Output: ""
 * Note:

 * S will consist of lowercase letters and have length in range [1, 500].
 *               
 ***************************************************************************************/
 

// 0 ms, faster than 100.00% of C++, 8.7 MB, less than 55.38% of C++
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> mp(26);
        int n = S.size();
        for (char c: S) ++mp[c-'a'];
        vector<pair<int, char>> charCounts;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] > (n+1)/2) return "";
            if (mp[i]) charCounts.push_back({mp[i], i+'a'});
        }
        sort(charCounts.rbegin(), charCounts.rend());
        string strSorted;
        for (auto& p: charCounts)
            strSorted += string(p.first, p.second);
        string ans;
        for (int i = 0, j = (n-1)/2+1; i <= (n-1)/2; ++i, ++j) {
            ans += strSorted[i];
            if (j < n) ans += strSorted[j];
        }
        return ans;
    }
};