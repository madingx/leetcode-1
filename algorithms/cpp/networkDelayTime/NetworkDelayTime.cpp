// Source : https://leetcode.com/problems/network-delay-time/
// Author : Mading
// Date   : 2019-06-04

/*************************************************************************************** 
 * 743. Network Delay Time [Medium]
 * 
 * There are N network nodes, labelled 1 to N.

 * Given times, a list of travel times as directed edges times[i] = (u, v, w), 
 * where u is the source node, v is the target node, and w is the time it 
 * takes for a signal to travel from source to target.

 * Now, we send a signal from a certain node K. How long will it take for 
 * all nodes to receive the signal? If it is impossible, return -1.


 * Example 1:

 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 

 * Note:

 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 *               
 ***************************************************************************************/



// 112 ms, faster than 63.71% of C++, 24.2 MB, less than 94.30% of C++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if (times.empty()) return -1;
        vector<int> dp(N+1,INT_MAX);
        dp[K] = 0;
        for (int i=1; i<=N; ++i)
            for(auto& edge : times) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dp[u]!=INT_MAX && dp[u]+w < dp[v])
                    dp[v] = dp[u]+w;
            }
        int res = 0;
        for (int i=1; i<=N; ++i)
            res = max(res, dp[i]);
        return res == INT_MAX? -1 : res;
    }
};
