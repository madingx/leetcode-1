// Source : https://leetcode.com/problems/evaluate-division/
// Author : Hao Chen
// Date   : 2016-11-05

/*************************************************************************************** 
 * 399. Evaluate Division [Medium]
 * Equations are given in the format A / B = k, where  A and B are variables 
 * represented as strings, and k is a real number (floating point number). Given some 
 * queries, return the answers. If the answer does not exist, return -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e = ?,  a 
 * / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>& values, 
 * vector<pair<string, string>> queries , where equations.size() == values.size(), and 
 * the values are positive. This represents the equations. Return  vector<double>.
 * 
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 * 
 * The input is always valid. You may assume that evaluating the queries will result in 
 * no division by zero and there is no contradiction.
 ***************************************************************************************/


// 4 ms, faster than 85.45% of C++, 9.6 MB, less than 26.70% of C++ 
class Solution {
private:
    bool dfs( unordered_map<string, unordered_map<string, double>>& m, 
              unordered_map<string, bool>& visited, 
              string& start, string& end, double& res  ) {
                 
        if ( m.find(start) == m.end() || m.find(end) == m.end() ) return false;
        if ( start == end ) return true;
        
        for (auto it = m[start].begin(); it != m[start].end(); ++it) {
           
            auto key = it->first;
            auto value = it->second;
            
            // already visited, skip it.
            if (visited.find(key) != visited.end() ) {
                continue;
            }
            
            visited[key] = true;
            double old = res;
            res *= value;
            
            if (dfs(m, visited, key, end, res)) {
                return true;
            }
            //didn't find the result, reset the current result, and go to next one
            res = old;
            visited.erase(key);
        }
        
        return false;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, 
                                vector<double>& values, 
                                vector<pair<string, string>> queries) {
        
        unordered_map<string, unordered_map<string, double>> m;
        for(int i=0; i<equations.size(); i++) {
           auto first = equations[i].first;
           auto second = equations[i].second;
           m[first][second] = values[i];
           m[second][first] = 1.0 / values[i];
        }
        
        
        vector<double> result;
        for(auto q : queries) {
            string start = q.first;
            string end = q.second;
            
            unordered_map<string, bool> visited;
            visited[start] = true;
            double res = 1.0;
            
            if(dfs(m, visited, start, end, res)) {
                result.push_back(res);
            } else {
                result.push_back(-1.0);
            }
        }
        
        return result;
    }
};









// 4 ms, faster than 85.45% of C++, 9.3 MB, less than 84.31% of C++
class Solution {
public:
    vector<double> calcEquation(const vector<vector<string>>& equations, 
                                const vector<double>& values, 
                                const vector<vector<string>>& queries) {
        unordered_map<string, int> val_idx;
        for (const auto& eq : equations) {
            for (const auto& val : eq) {
                auto iter = val_idx.find(val);
                if (iter == val_idx.end()) {
                    val_idx.emplace_hint(iter, val, val_idx.size());
                }
            }
        }
        const size_t N = val_idx.size();
        vector<vector<double>> dp(N, vector<double>(N, -1.0));
        vector<vector<char>> known(N, vector<char>(N, false));
        for (size_t i = 0; i < N; ++i) {
            dp[i][i] = 1;
            known[i][i] = true;
        }
        for (size_t i = 0; i < equations.size(); ++i) {
            const auto& eq = equations[i];
            int from_idx = val_idx[eq[0]];
            int to_idx = val_idx[eq[1]];
            dp[from_idx][to_idx] = values[i];
            known[from_idx][to_idx] = true;
            dp[to_idx][from_idx] = 1 / values[i];
            known[to_idx][from_idx] = true;
        }
        
        // This is the real algorithm
        for (size_t k = 0; k < N; ++k) {
            for (size_t i = 0; i < N; ++i) {
                for (size_t j = 0; j < N; ++j) {
                    if (!known[i][j] && known[i][k] && known[k][j]) {
                        known[i][j] = true;
                        dp[i][j] = dp[i][k] * dp[k][j];
                    }
                }
            }
        }
        // Real algorithm ends here
        
        vector<double> result;
        for (const auto& q : queries) {
            auto fiter = val_idx.find(q[0]);
            auto titer = val_idx.find(q[1]);
            if (fiter == val_idx.end() || titer == val_idx.end()) {
                result.emplace_back(-1.0);
                continue;
            }
            int from_idx = fiter->second;
            int to_idx = titer->second;
            if (known[from_idx][to_idx]) {
                result.emplace_back(dp[from_idx][to_idx]);
            } else {
                result.emplace_back(-1);
            }
        }
        return result;
    }
};