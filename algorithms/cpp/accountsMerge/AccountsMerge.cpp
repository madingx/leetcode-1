// Source : https://leetcode.com/problems/accounts-merge/
// Author : Mading
// Date   : 2019-07-19

/********************************************************************************** 
 * 721. Accounts Merge [Medium]
 * Given a list accounts, each element accounts[i] is a list of strings, where the 
 * first element accounts[i][0] is a name, and the rest of the elements are emails 
 * representing emails of the account.

 * Now, we would like to merge these accounts. Two accounts definitely belong to 
 * the same person if there is some email that is common to both accounts. 
 * Note that even if two accounts have the same name, they may belong to different 
 * people as people could have the same name. A person can have any number of 
 * accounts initially, but all of their accounts definitely have the same name.

 * After merging the accounts, return the accounts in the following format: the 
 * first element of each account is the name, and the rest of the elements are 
 * emails in sorted order. The accounts themselves can be returned in any order.

 * Example 1:
 * Input: 
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], 
 *             ["John", "johnnybravo@mail.com"], 
 *             ["John", "johnsmith@mail.com", "john_newyork@mail.com"], 
 *             ["Mary", "mary@mail.com"]]
 * Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
 *          ["John", "johnnybravo@mail.com"], 
 *          ["Mary", "mary@mail.com"]]

 * Explanation: 
 * The first and third John's are the same person as they have the common email "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email addresses are used by other accounts.
 * We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], 
 * ['John', 'johnnybravo@mail.com'], ['John', 'john00@mail.com', 'john_newyork@mail.com', 
 * 'johnsmith@mail.com']] would still be accepted.
 
 * Note:
 * The length of accounts will be in the range [1, 1000].
 * The length of accounts[i] will be in the range [1, 10].
 * The length of accounts[i][j] will be in the range [1, 30].
 * 
 **********************************************************************************/

// 1216 ms, faster than 7.36% of C++， 46.9 MB, less than 27.45% of C++
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
private:
    string find(string s, map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
};







// 1500 ms, faster than 5.08% of C++, 46.8 MB, less than 30.46% of C++
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        map<string, string> owner;
        map<string, string> parents;
        function<string(string)> find = [&](string s) {return parents[s] == s ? s : find(parents[s]); };
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1]);
            for (int j = 2; j < acts[i].size(); j++) {
                parents[find(acts[i][j])] = p;
            }
        }
        map<string, set<string>> unions;
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                unions[find(acts[i][j])].insert(acts[i][j]);
            }
        }
        vector<vector<string>> merged;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            merged.push_back(emails);
        }
        return merged;
    }
};