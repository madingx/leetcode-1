// Source : https://leetcode.com/problems/find-eventual-safe-states/
// Author : Mading
// Date   : 2019-06-17

/********************************************************************************** 
* 802. Find Eventual Safe States [Medium]
* In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  
* If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

* Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  
* More specifically, there exists a natural number K so that for any choice of where to walk, we must have 
* stopped at a terminal node in less than K steps.

* Which nodes are eventually safe?  Return them as an array in sorted order.

* The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  
* The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is 
* a directed edge of the graph.

* Example:
* Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
* Output: [2,4,5,6]
* Here is a diagram of the above graph.

*             2>------------>5
*   0<------------<3
*   0>------->2   
*   0 -> 1 -> 2    3    4 -> 5    6   
*        1>------->3
* 

* Note:

* graph will have length at most 10000.
* The number of edges in the graph will not exceed 32000.
* Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].
* 
*               
**********************************************************************************/


// 164 ms, faster than 93.50% of C++, 32 MB, less than 63.43% of C++
class Solution {
public:
    // topological sorting with dp
    bool dfs(vector<vector<int>>& graph, vector<int> &dp, int src) {
       if(dp[src])
           return 1 == dp[src];

        dp[src] = -1; // by default mark it as "cannnot be topologically sorted"
        for(auto node : graph[src])
            if(false == dfs(graph, dp, node))
                return false;
        return dp[src] = 1; // next node with zero outdegree
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int total_nodes = graph.size();
        vector<int> result, dp(total_nodes, 0);
        for(int i = 0; i < total_nodes; i++)
            if(dfs(graph, dp, i))
                result.push_back(i);

        return result;
    }  
};


// 392 ms, faster than 11.00% of C++, 99.6 MB, less than 6.78% of C++
class Solution {
public:
    using vvi = vector<vector<int>>;
    using usi = unordered_set<int>;

    usi cycle_nodes;
    usi safe_nodes;

    bool dfs (const vvi& g, int i, usi visited_nodes) 
    {    
        if (safe_nodes.find (i)  != safe_nodes.end ())  return true;  // we know safe already
        if (cycle_nodes.find (i) != cycle_nodes.end ()) return false; // we know in cycle already

        if (visited_nodes.find (i) != visited_nodes.end ()) {         // we have determined node is in cycle
            cycle_nodes.insert (i);
            return false;
        }

        visited_nodes.insert (i); // keep track of nodes we've visited already

        for (int node : g[i]) {
            if (!dfs (g, node, visited_nodes)) {
                cycle_nodes.insert (i); // if child is in cycle, parent must be too
                return false;
            }
        }

        safe_nodes.insert (i); // we know node is safe now

        return true;
    }

    vector<int> eventualSafeNodes(vvi& graph) 
    {
        vector<int> ans;
        usi visited_nodes;

        for (int i = 0; i < graph.size (); i++) {
            if (dfs (graph, i, visited_nodes)) ans.push_back (i);
        }

        return ans;
    }
};